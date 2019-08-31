#include <bits/stdc++.h>
#define FOR( var, from, to ) for( int var(from); var < to; ++ var )
#define REP( var, to ) FOR( var, 0, to )

using namespace std;

constexpr int MAXN = 50500;
string lydia;

int main(){
  int tc;
  cin >> tc;
  FOR( _, 1, tc + 1 ){
    int n;
    cin >> n;
    cin >> lydia;
    string path( lydia );
    REP( i, (int)path.length() )
      if( path[i] == 'S' ) path[i] = 'E';
      else path[i] = 'S';
    cout << "Case #" << _ << ": " << path << '\n';
  }
  return 0;
}
