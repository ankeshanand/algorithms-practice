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
            self.adj_list[u][v] = min(self.adj_list[u].get(v, float('inf')), weight)

            if self.undirected:
                self.adj_list[v] = self.adj_list.get(v, {})
                self.adj_list[v][u] = min(self.adj_list[v].get(u, float('inf')), weight)

        self.vertices.add(u)
        self.vertices.add(v)

    def neighbours(self, vertex):
        return self.adj_list.get(vertex, iter([]))

class DjikstraResult():
    def __init__(self):
        self.dist = {}
        self.parent = {}


def djikstra(g, s):
    """ Djikstra implementation without Priority Queues.
    Complexity: O(|V|*deletemin + (|V+E|)*insert) = O(|V|^2)

    Couldn't use priority queue because Python doesn't provide a
    decrease key method and it's tough to implement.
    """

    results = DjikstraResult()
    results.dist = {x: float('inf') for x in g.vertices}
    results.dist[s] = 0
    results.parent[s] = None

    unvisited = g.vertices

    while unvisited:
        # get vertex with minimum distance (Extract Min)
        nv = None
        for v in results.dist:
            if v in unvisited:
                if results.dist[v] < results.dist.get(nv, float('inf')):
                    nv = v

        if nv is None:
            break

        unvisited.remove(nv)

        for n in g.neighbours(nv):
            if results.dist[n] > results.dist[nv] + g.adj_list[nv][n]:
                # Relax(nv, n, weight)
                results.dist[n] = results.dist[nv] + g.adj_list[nv][n]
                results.parent[n] = nv

    return results


if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(T):
        N, M = map(int, raw_input().split())
        g = Graph(undirected=True, weighted=True)
        for i in xrange(M):
            x, y, r = map(int, raw_input().split())
            g.add_edge(x, y, r)
        S = int(raw_input())
        djikstra_result = djikstra(g, S)
        dist = djikstra_result.dist
        distances = []
        for i in xrange(1, N+1):
            if i == S:
                continue
            if i not in dist:
                distances.append(-1)
                continue
            if dist[i] == float('inf'):
                distances.append(-1)
                continue
            distances.append(dist[i])
        ans = ' '.join([str(x) for x in distances])
        print ans

