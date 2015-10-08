
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
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;
vi taken;
priority_queue<ii, vii, greater<ii > > pq;

void process(int vtx){
    taken[vtx] = 1;
    forall(i, 0, AdjList[vtx].size()){
        ii v = AdjList[vtx][i];
        if(!taken[v.first]){
            pq.push(ii(v.second, v.first));
        }
    }
}

int main()
{
    int N, M;
    s(N);s(M);
    AdjList.assign(N, vii());
    REP(i, M){
        int x, y, r;
        s(x);s(y);s(r);
        x--;y--;
        AdjList[x].pb(ii(y,r));
        AdjList[y].pb(ii(x,r));
    }
    int S;
    s(S); S--;
    taken.assign(N, 0);
    process(S);
    int mst_cost = 0;
    int tree_vertices = 1;
    while(tree_vertices < N and !pq.empty()){
        ii front = pq.top(); pq.pop();
        if(!taken[front.second]){
            mst_cost += front.first; 
            process(front.second);
            tree_vertices++;
        }
    }
    cout << mst_cost << endl;
}

