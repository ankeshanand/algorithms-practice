
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
    int t;
    s(t);
    REP(cases, t){
        ll n, m;
        sl(n);sl(m);
        ll prices[n][m], discounts[n][m];
        REP(i, n){
            REP(j, m){
                sl(prices[i][j]);
            }
        }

        REP(i, n){
            REP(j, m){
                sl(discounts[i][j]);
            }
        }

        ll dp[n][m], last_min = LLONG_MAX, last_min2;
        REP(j, m){
            dp[0][j] = prices[0][j];
            last_min = min(last_min, dp[0][j]);
        }
        forall(i, 1, n){
            last_min2 = LLONG_MAX;
            REP(j, m){
                dp[i][j] = min(dp[i-1][j] + max(0LL, prices[i][j] - discounts[i-1][j]), last_min + prices[i][j]);
                last_min2 = min(last_min2, dp[i][j]);
            }
            last_min = last_min2;
        }
        ll ans = LLONG_MAX;
        REP(j,m){
            ans = min(ans, dp[n-1][j]);
        }
        cout << ans << endl;
    }
}

