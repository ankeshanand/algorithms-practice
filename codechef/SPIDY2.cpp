
//#define DEBUG       //comment when you have to disable all debug macros.
#include <bits/stdc++.h>
using namespace std;

// Input macros
#define s(n)    scanf("%d",&n)
#define sc(n)   scanf("%c",&n)
#define sl(n)   scanf("%lld",&n)
#define sf(n)   scanf("%lf",&n)
#define ss(n)   scanf("%s",n)
#define MAX 1000000000

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
typedef vector<ll> vl;


vl powers2;
ll p = 1;

void compute_powers2(){
while(p <= MAX){
    powers2.pb(p);
    p = p * 2;
}
}


int main()
{
    compute_powers2();
    ll n;
    sl(n);
    vl h(n);
    REP(i,n)
        sl(h[i]);
    vl dp(n, LLONG_MAX);
    dp[0] = 0;
    FOR(i, 1, n){
        int idx = 0;
        ll j = powers2[idx];
        while(i-j >= 0){
            dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
            idx++;
            j = powers2[idx];
        }
    }
    cout << dp[n-1];
}

