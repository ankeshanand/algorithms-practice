
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
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define forall(i,a,b)               for(int i=a;i<=b;i++)
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

ll dp[13][100] = {0};

void compute_dp_matrix(){
    dp[1][0] = 1;
    FOR(i, 2, 13){
        REP(j, (i*(i-1))/2 + 1){
            int d = max(i-1, ((i-1)*(i-2))/2);
            if(j > d){
                dp[i][j] = 1;
                continue;
            }
            REP(k, j+1){
                dp[i][j] += dp[i-1][k];
            }
        }
    }
}

int main()
{
    int d;
    s(d);
    compute_dp_matrix();
    REP(i,d){
        int n, k;
        s(n);s(k);
        cout << dp[n][k] << endl;
    }
}

