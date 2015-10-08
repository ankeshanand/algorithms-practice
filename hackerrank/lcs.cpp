
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

int main()
{
    int n, m;
    s(n);s(m);
    int A[n+5], B[m+5];
    A[0] = 0;
    B[0] = 0;
    REP(i,n){
        s(A[i+1]);
    }
    REP(i,m){
        s(B[i+1]);
    }

    int LCS[1005][1005] = {0};

    FOR(i, 1, n){
        FOR(j, 1, m){
            LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            if(A[i] == B[j])
                LCS[i][j] = max(LCS[i][j], 1 + LCS[i-1][j-1]);
        }
    }

    int u = n, v = m;
    vector<int> result;
    while(u > 0 && v > 0){
        if(LCS[u-1][v-1] >= max(LCS[u-1][v], LCS[u][v-1]) && A[u] == B[v]){
            result.pb(A[u]);
            u--;v--;
        }
        else if(LCS[u-1][v] > LCS[u][v-1]){
            u--;
        }
        else{
            v--;
        }
    }
    reverse(result.begin(), result.end());
    REP(i, result.size()){
        cout << result[i];
        if(i != result.size() - 1)
            cout << " ";
    }
}

