#include <bits/stdc++.h>

using namespace std;

pair<int, int> gcdlcm( int a, int b ){
  long long ab = a * b;
  int g = gcd( a, b );
  return { g, ab/g };
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  double burger {};
  cin >> burger;
  int r = burger * 100;
  auto p = gcdlcm( r, 36000 );
  // cout << "f( " << r << " ) = " << p.second / r << "\ng( " << r << " ) = " << 36000 / p.first << endl;
  cout << p.second / r << endl;
  return 0;
}
