#include <cstdio>
#include <ctime>

using namespace std;

typedef long long ll;

ll xp(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y >>= 1;
        x = (x*x) % p;  
    }
    return res;
}
/*

ll xp( ll base, ll exp, ll mod = 1000000007LL ){
  if( base == 0 ) return 0;
  if( base == 1 or exp == 0 ) return 1LL;
  if( exp == 1 ) return base % mod;
  if( exp == 2 ) return (base * base) % mod;
  if( exp % 2 ) return (xp( base, exp / 2 ) % mod) * (xp(base, exp/2 + 1) % mod ) % mod;
  else return (xp( base, exp / 2 ) % mod) * (xp(base, exp/2) % mod ) % mod;
}

*/
int main(){
  ll t, n, m = 1000000007LL;
  scanf("%lld", &t);
  while( t -- ) {
    scanf("%lld", &n);
    ll ans = (xp( n, n + 1, m ) - n + 1) % m;
    printf("%lld\n", ans);
  }
  return 0;
}
