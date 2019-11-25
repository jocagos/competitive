#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> bpy;

void init(){
  int year = 1960;
  for( int i = 0; i <= 200; ++ i ){
    bpy[year + i] = 4 << (i/10);
  }
}

int main(){
  init();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  while( cin >> n, n ){
    long double p = bpy[n] * log10(2);
    // cerr << "p is " << p << endl;
    long double tmp {}, a {};
    int i {1};
    while( tmp < p ){
      long double tt = log10( i );
      tmp += tt;
      // cerr << "currently: i = " << i << "\ttmp = " << tmp << "\ta = " << a << "\ttt = " << tt << endl;
      if( tmp < p ) a += tt;
      ++ i;
    }
    cout << (--i - 1) << '\n';
  }
  return 0;
}
