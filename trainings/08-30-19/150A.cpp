#include <bits/stdc++.h>
constexpr long long MAXN = 1000001;
using namespace std;

long long first_div( long long n ){
  for( long long i = 2; i*i <= n; ++ i )
    if( n % i == 0 ) return i;
    // else cerr << "Used " << i << endl;
  return -1;
}

int main(){
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);
  long long n {};
  cin >> n;
  long long p = first_div( n );
  if( p == -1 ){
    cout << "1\n0\n";
    return 0;
  }
  else{
    long long q = first_div( n / p );
    if( q != -1 ){
      cout << "1\n" << p * q << "\n";
      return 0;
    }
    else{
      cout << "2\n";
      return 0;
    }
  }
  return 0;
}
