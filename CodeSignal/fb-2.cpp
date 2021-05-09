#include <bits/stdc++.h>
// as n is up to 10e9, its divisors can be up to sqrt(10e9)
// but there is no need to compute them all or similar!
// since there are at most 9 digits, and there are
// only len(n) - k + 1 values to test
// still, we need a small hash_set
using namespace std;

int divisorSubstrings(long long n, int k) {
  unordered_set<long long> valid {};
  long long len = 0, tmp = n;
  while( tmp ){
    tmp /= 10;
    ++ len;
  }
  int pw = pow(10, k);
  tmp = n;
  for( int _ = 0; _ < len  - k + 1; ++ _ ){
    if( tmp % pw == 0 ){
      tmp /= 10;
      continue;
    }
    if( n % (tmp % pw) == 0 )
      valid.emplace( tmp % pw );
    tmp /= 10;
  }
  return valid.size();
}

int main(){
  long long n {};
  int k {};
  cin >> n >> k;
  cout << divisorSubstrings( n, k ) << endl;
  return 0;
}
