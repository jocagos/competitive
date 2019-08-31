// Lazy Propagation in Segment/Fenwick Tree to answer online queries
#include <bits/stdc++.h>
#define LSOne(S) ((S) & (-(S)))
#define MOD 1000000007

using namespace std;
typedef long long ll;
ll ft[100010], aux[100010]; // extra space just in case
/*
void updateFT( ll * FT, ll at, ll by ){
  while( at < n + 1 ){
    FT[at] += by;
    at |= at + 1;
  }
}

ll query( ll * FT, ll at ){
  ll sum = 0;
  while( at >= 0 ){
    sum = (sum + FT[at]) % MOD;
    at = ( at & (at + 1) ) - 1;
  }
  return sum;
}
*/

inline ll sum( int x ){ // get sum from ft and aux
  return getSum( ft, x ) * x - getSum( aux, x );
}

inline ll getSum( ll * FT, ll idx ){ // actual `getSum`
  ll sum = 0;
  idx ++;
  while( idx > 0 ){
    sum += FT[idx];
    sum %= MOD;
    idx -= LSOne(idx);
  }
  return sum;
}

inline void updateFT( ll * FT, ll n, ll idx, ll val ){
  idx ++;
  // classic FT update
  while( idx <= n ){
    FT[idx] += val;
    idx += LSOne( idx );
  }
}

inline void updateRange( ll * FT, ll * AFT, ll n, ll val, ll L, ll R ){
  // Just update corner values but from both ends so we actually do
  // a Lazy Propagation from the two points
  updateFT( FT, n, L, val );
  updateFT( FT, n, R + 1, -val );
  updateFT( AFT, n, L, val * (L - 1) );
  updateFT( AFT, n, R + 1, -val * R );
}

inline ll rangeSum( ll L, ll R ){
  return sum( R ) - sum( L - 1 );
}

int tc, n, q, type, l, r, d;
vector<ll> lucas( 100001, 0);
vector<ll> vals( 50001, 0 );

void init(){
  lucas[0] = 0;
  lucas[1] = 2;
  lucas[2] = 3;
  for( int i = 3; i < 100001; ++ i ) // BigIntegers here or clever modulo use
    lucas[i] = (lucas[i - 1] + lucas[i - 2] + lucas[i - 3]) % MOD;
}

int main(){
  init();
  ios_base::sync_with_stdio( false );
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  while( tc -- ){
    cin >> n;
    for( int i = 0; i < n; ++ i ) cin >> vals[i];
    cin >> q;
    memset( ft, 0, sizeof ft ), memset( aux, 0, sizeof, ft ); // reset the FTs
    updateRange( ft, aux, n, VAL, l, n - 1 );
    /*for( int i = 0; i < n; ++ i ){
      ft[i + 1] = lucas[vals[i]];
      aux[i + 1] = lucas[vals[i]];
      }*/
    for( int i = 1; i <= n; ++ i ){ // O(n)
      int j = i + LSOne( i );
      int k = i + LSOne( i );
      if( j <= n ) ft[j] += ft[i];
      if( k <= n ) aux[k] += aux[i];
    } // fill FT, AUX
    while( q -- ){
      cin >> type >> l >> r; // get query
      if( type == 1 ){
	cout << ";";
      }
      else{ // type 2, skip a comparison
	// update with LP
	cin >> d; // grab d
	
      }
    }
  }
  return 0;
}
