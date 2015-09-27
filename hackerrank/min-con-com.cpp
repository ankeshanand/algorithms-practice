
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

const int N = 200004;
int p[N], w[N];
int dsu(int x){
    return p[x] = (x == p[x] ? x : dsu(p[x]));
}

int main()
{
    int n, q;
    s(n);s(q);
    multiset<int> S;
    FOR(i, 1, n){
        int weight;
        s(weight);
        w[i] = weight;
        p[i] = i;
        S.insert(weight);
    }
    FOR(i, 1, q){
        int u, v;
        s(u);s(v);
        int pu = dsu(u);
        int pv = dsu(v);
        if(pu != pv){
            // u and v are not in the same components
            S.erase(S.find(w[pu]));
            S.erase(S.find(w[pv]));
            w[pu] += w[pv];
            w[pv] = 0; // not necessary since we will always look at parent weights only
            S.insert(w[pu]);
            p[pv] = pu;
        }

        printf("%d\n", *S.begin());
    }
}

