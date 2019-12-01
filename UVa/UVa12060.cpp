#include <bits/stdc++.h>

using namespace std;

void print_num( int a, int b, int c ){
  // cerr << "a: " << a << "\tb: " << b << "\tc: " << c << endl;
  if( b != 0 ){
    bool neg = a < 0 or (a == 0 and (b < 0 or c < 0) and not(b < 0 and c < 0) );
    int wid = ( neg ? 2 : 0 ) + ceil(log10( abs(a) + 1 )) + ceil(log10( abs(c) + 1 ));
    
    // cerr << "wid is " << wid << endl;
    string s, as = a != 0 ? to_string( abs(a) ) : "";
    s = ( neg ? "- " : "") + as + string(wid - (neg ? 2 : 0) - as.length(), '-');
    cout << setw( wid ) << right << abs( b ) << '\n';
    cout << s << '\n';
    cout << setw( wid ) << right << abs( c ) << '\n';
  }
  else{
    if( a < 0 ) cout << "- ";
    cout << abs(a) << '\n';
  }
}

void get_vals( int su, int n ){
  int a = su / n, b = su % n, c = n;
  int den = __gcd( b, c );
  b = b / den;
  c = c / den;
  print_num( a, b, c );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, TC {};
  while( cin >> n, n ){
    int tmp {}, s {}, k {n};
    while( k -- ){
      cin >> tmp;
      s += tmp;
    }
    cout << "Case " << ++ TC << ":\n";
    get_vals( s, n );
  }
  return 0;
}
