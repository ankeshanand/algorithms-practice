
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

vector<int> p; //parents

int dsu(int x){
    return p[x] = (x == p[x] ? x : dsu(p[x]));
}

void print_parents(){
    REP(i, p.size()){
        cout << p[i] << " ";
    }
    cout << endl;
}

bool custom_comp(pair<int, ii> a, pair<int, ii> b){
    if(a.first < b.first)
        return true;
    if(a.first == b.first)
        return a.second.first + a.second.second < b.second.first + b.second.second;
    return false;
}

int main()
{
    vector<pair<int, ii> > EdgeList;
    int N, M, mst_cost = 0;
    s(N);s(M);
    REP(i, M){
        int x, y, r;
        s(x);s(y);s(r);
        x--;y--;
        EdgeList.pb(mp(r, ii(x,y)));
    }
    int S;
    s(S);
    S--;
    sort(EdgeList.begin(), EdgeList.end(), custom_comp);
    p.assign(N,0);
    REP(i, N){
        p[i] = i;
    }
    REP(i, EdgeList.size()){
        // print_parents();
        pair<int, ii> front = EdgeList[i];
        int x = front.second.first, y = front.second.second;
        int weight = front.first;
        int px = dsu(x);
        int py = dsu(y);
        debug(x,y,px,py);
        if(px != py){
            mst_cost += weight;
            p[px]= py;
        }
    }
    cout << mst_cost << endl;
}

