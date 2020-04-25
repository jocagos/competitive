#include <bits/stdc++.h>

using namespace std;

int main(){
  int n {}, k {};
  cin >> n >> k;
  vector<double> dists( n );
  for( int i = 0; i < n; ++ i ){
    double x {}, y {}, z {};
    cin >> x >> y >> z;
    dists[i] = sqrt( x * x + y * y + z * z );
  }
  sort( dists.begin(), dists.end() );
  cout << setw(8) << fixed << dists[k - 1] << endl;
  return 0;
}
