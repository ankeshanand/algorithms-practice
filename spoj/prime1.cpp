
//#define DEBUG       //comment when you have to disable all debug macros.
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <climits>
#include <ctime>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <list>
#include <deque>
#include <sys/time.h>
#include <iomanip>
#include <cstdarg>
#include <utility> //std::pair
#include <cassert>

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

#define ll long long int //data types used often, but you don't want to type them time by time_t

// Useful container manipulation / traversal macros
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

int main()
{
    int t;
    cin >> t;
    vector<bool> isprime;
    for(int j=0;j<t;j++){
        
        ll m,n;
        sl(m);sl(n);
        isprime.resize(n-m+1,true);
        if(m == 1)
            isprime[0] = false;
        int th = int(sqrt(n))+1;
        for(int i=2;i<th;i++){
            ll cur;
            if(m <= i)
                cur = 2*i;
            else if(m % i == 0)
                cur = m;
            else
                cur = m + (i-(m%i));
            while(cur <= n){
                isprime[cur-m] = false;
                cur += i;
            }
        }
        for(int i=0;i<isprime.size();i++){
            if(isprime[i])
                printf("%lld\n",i+m);
        }
        isprime.clear();
    }
}

