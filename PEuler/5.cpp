#include <bits/stdc++.h>

using namespace std;

int main(){
  vector<int> v;
  int n = 2520;
  for( int i = 1; i < 11; ++ i ) cout << "gcd( " << n << ", " << i << ") = " << __gcd(n, i) << endl;
  return 0;
}
