#include <bits/stdc++.h>

using namespace std;

long long bin_exp( long long a, long long b ){
  long long r{1};
  while( b > 0 ){
    if( b & 1 ) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return r;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long a {}, b {};
  while( cin >> a >> b, a | b ){
    long long m = log( 1.0 * b / a ) / log( 
  }
  return 0;
}
