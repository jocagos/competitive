// SQRT Decomposition, sort queries then answer them offline, lastly just re-arrange them
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int tc, n, q;
vector<ll> lucas( 100001, 0 );
vecto<ll> vals( 50001, 0 );

void init(){
  lucas[0] = 0;
  lucas[1] = 2;
  lucas[2] = 3;
  for( int i = 3; i < 100001; ++ i )
    lucas[i] = lucas[i - 1] + lucas[i - 2] + lucas[i - 3];
}

int main(){
  ios_base::sync_with_stdio( false );
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  while( tc -- ){
    cin >> n;
    for( int i = 0; i < n; ++ i ) cin >> vals[i];
    
  }
  return 0;
}
