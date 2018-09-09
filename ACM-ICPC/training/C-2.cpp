#include <bits/stdc++.h>
#define MOD 100000007

using namespace std;

typedef long long ll;

long double s3(sqrt(3));

ll p( ll n ){
  return (ll)ceil( exp( M_PI * sqrt( 2 * n / 3 ) ) / (4 * n * s3 ) );
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n;
  while( cin >> n ) cout << p( n ) << '\n';
  return 0;
}
