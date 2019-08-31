#include <bits/stdc++.h>
#define FOR( var, from, to ) for( int var(from); var < to; ++ var )
#define REP( var, to ) FOR( var, 0, to )

using namespace std;

int main(){
  string a;
  int tc;
  cin >> a;
  tc = stoi( a );
  FOR( _, 1, tc + 1 ){
    cin >> a;
    string b(a), c(a);
    // cerr << "CASE " << _ << " WAS >" << a << "<" << endl;
    REP( i, (int)a.length() ){
      int d = a[i] - '0';
      if( d == 0 ) b[i] = c[i] = '0';
      else if( d == 1 ) b[i] = a[i], c[i] = '0';
      else if( d % 2 == 0 ){ // 2, 4, 6, 8
	b[i] = '1';
	c[i] = a[i] - 1;
      }
      else{
	b[i] = '2';
	c[i] = a[i] - 2;
      }
    }
    int idx = c.find_first_not_of( '0' );
    c = c.substr( idx );
    cout << "Case #" << _ << ": " << c << " " << b << '\n';
  }
  return 0;
}
