class Graph(object):
    def __init__(self, weighted=False, undirected=False):
        self.adj_list = {}
        self.vertices = set()
        self.weighted = weighted
        self.undirected = undirected

    def add_edge(self, u, v, weight=None):
        if not self.weighted:
            self.adj_list[u] = self.adj_list.get(u, [])
            self.adj_list[u].append(v)

            if self.undirected:
                self.adj_list[v] = self.adj_list.get(v, [])
                self.adj_list[v].append(u)

        else:
            # for weighted graphs
            self.adj_list[u] = self.adj_list.get(u, {})
            self.adj_list[u][v] = weight

            if self.undirected:
                self.adj_list[v] = self.adj_list.get(v, {})
                self.adj_list[v][u] = weight

        self.vertices.add(u)
        self.vertices.add(v)

    def neighbours(self, vertex):
        return self.adj_list.get(vertex, iter([]))


from collections import deque

class BFSResult():
    def __init__(self):
        self.parent = {}
        self.level = {}


def bfs(g, s):
    '''Queue-based implementation of BFS.'''
    results = BFSResult()
    results.parent[s] = None
    results.level[s] = 0

    queue = deque()
    queue.append(s)

    while queue:
        v = queue.popleft()
        for neighbour in g.neighbours(v):
            if neighbour not in results.level:
                results.parent[neighbour] = v
                results.level[neighbour] = results.level[v] + 1
                queue.append(neighbour)

    return results


if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(T):
        N, M = map(int, raw_input().split())
        g = Graph(undirected=True)
        for i in xrange(M):
            x, y = map(int, raw_input().split())
            g.add_edge(x, y)
        S = int(raw_input())
        bfs_result = bfs(g, S)
        levels = bfs_result.level
        distances = []
        for i in xrange(1, N+1):
            if i == S:
                continue
            if i not in levels:
                distances.append(-1)
                continue
            distances.append(6 * levels[i])
        ans = ' '.join([str(x) for x in distances])
        print ans

