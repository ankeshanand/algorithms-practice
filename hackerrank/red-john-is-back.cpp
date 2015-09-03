
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

vector<int> primes_upto(220007, 0);

void calculate_primes_upto(){
    primes_upto[2] = 1;
    vector<int> primes;
    primes.pb(2);
    FOR(i, 3, 220000){
        primes_upto[i] = primes_upto[i-1];
        bool is_prime = true;
        REP(j, primes.size()){
            if(i % primes[j] == 0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            primes.pb(i);
            primes_upto[i]++;
        }
    }
}

int main()
{
    calculate_primes_upto();
    int cases;
    cin >> cases;
    REP(t, cases){
        int n;
        cin >> n;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        FOR(i, 1, n){
            dp[i] += dp[i-1];
            if(i >= 4)
                dp[i] += dp[i-4];
        }
        int ways = dp[n];
        printf("%d\n", primes_upto[ways]);
    }
}

