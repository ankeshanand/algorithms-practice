
//#define DEBUG       //comment when you have to disable all debug macros.
#include <bits/stdc++.h>
using namespace std;

// Input macros
#define s(n)    scanf("%d",&n)
#define sc(n)   scanf("%c",&n)
#define sl(n)   scanf("%lld",&n)
#define sf(n)   scanf("%lf",&n)
#define ss(n)   scanf("%s",n)

//Pair macros
#define mp make_pair // useful for working with pairs
#define fi first
#define se second

#define ll long long int//data types used often, but you don't want to type them time by time_t

// Useful container manipulation / traversal macros
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#ifdef DEBUG
     #define debug(args...)            {cerr << #args << ": ";dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define RV(c,it) for(vii::iterator it=(c).begin(); it!=(c).end(); it++)
vector<vii> adj;

/* Djikstra Implementation */
vl d;
vector<bool> mark;
ll fast_dijkstra(int v, int target){
	fill(d.begin(),d.end(), INT_MAX);
	fill(mark.begin(), mark.end(), false);
	d[v] = 0;
	int u;
	priority_queue<pair<ll,int>,vector<pair<ll,int> >, greater<pair<ll,int> > > pq;
	pq.push({d[v], v});
	while(!pq.empty()){
		u = pq.top().second;
		pq.pop();
		if(mark[u])
			continue;
		mark[u] = true;
        if(u == target){
            return d[u];
        }
		for(auto p : adj[u]) //adj[v][i] = pair(vertex, weight)
			if(d[p.first] > d[u] + p.second){
				d[p.first] = d[u] + p.second;
				pq.push({d[p.first], p.first});
			}
	}
}

int main()
{
    int cases;
    cin >> cases;
    REP(t, cases){
        int n;s(n);
        adj.resize(n);
        d.resize(n);
        mark.resize(n);
        unordered_map<string, int> cn;
        REP(j,n){
            char name[20];
            scanf("%s", name);
            cn[name] = j;
            int p;
            s(p);
            REP(k, p){
                int city, cost;
                s(city);s(cost);
                city--;
                adj[j].pb(ii(city, cost));
            }
        }
        int r;s(r);
        REP(i,r){
            char name1[20], name2[20];
            scanf("%s", name1);
            scanf("%s", name2);
            int x = cn[name1], y = cn[name2];
            ll distance = fast_dijkstra(x, y);
            printf("%lld\n", distance);
        }
        adj.clear();
        d.clear();
        mark.clear();
    }
}

