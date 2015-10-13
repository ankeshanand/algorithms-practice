
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
typedef vector<long long int> vl;
typedef vector<vector<long long int> > vll;
typedef pair<int, int> ii;

vll dp(101, vl(101,0));
vll start0(101, vl(101,0));
vll start1(101, vl(101,0));
int main()
{
    int p;
    s(p);
    dp[1][0] = 2;
    start0[1][0] = 1;
    start1[1][0] = 1;

    FOR(i,2, 100){
        REP(j, i){
            dp[i][j] = dp[i-1][j] + start0[i-1][j] + (j > 0 ? start1[i-1][j-1] : 0);
            start0[i][j] = dp[i-1][j];
            start1[i][j] = dp[i][j] - dp[i-1][j];
        }
    }
    REP(t, p){
        int idx, n, k;
        s(idx);s(n);s(k);
        if(k >= n){
            cout << idx << " " << 0 << endl;
            continue;
        }
        cout << idx << " " << dp[n][k] << endl;
    }
}

