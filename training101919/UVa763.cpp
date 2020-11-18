#include <bits/stdc++.h>

using namespace std;
constexpr int MAXF = 110;

long long fib[MAXF] {};

long long to_fib( string s ){
  long long ans = 0;
  for( int i = 0; i < s.length(); ++ i ){
    // cerr << "pos[" << i << "] = " << s[i] << " and fib[" << i + 1 << "] = " << fib[i + 1] << endl;
    ans += fib[(s[i] == '1' ? s.length() - i : 0)];
  }
  return ans;
}

string fib_to_str( long long n ){
  string s( MAXF, '0' );
  int msd{-1};
  // cerr << "Converting " << n << " to fibinary:" << endl;
  while( n > 0 ){
    // cerr << "n = " << n << " d = ";
    int d = upper_bound( fib, fib + n, n ) - fib;
    // cerr << d << endl;
    if( n < fib[d] ){
      s[d - 1] = '1';
      n -= fib[d - 1];
    }
    else{
      s[d] = '1';
      n -= fib[d];
    }
    if( msd == -1 ) msd = d;
  }
  // trim
  string t = s.substr( 0, msd );
  string r( t.rbegin(), t.rend() - 1 );
  // cerr << "CONVERSION: " << n << " TO " << r << endl;
  return r;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fib[0] = 0;
  fib[1] = 1;
  fib[2] = 2;
  for( int i = 3; i < MAXF; ++ i ) fib[i] = fib[i - 1] + fib[i - 2];
  string a, b, tmp;
  bool first = false;
  while( cin >> a >> b ){
    // cerr << "GOT >" << a << "<\n>" << b << "<" << endl;
    if( first ) cout << '\n';
    else first = true;
    long long A = to_fib( a ), B = to_fib( b );
    // cerr << "TO FIB:\n" << A << "\n" << B << endl;
    cout << fib_to_str( A + B ) << '\n';
  }
  return 0;
}
