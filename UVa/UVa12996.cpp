#include <iostream>

using namespace std;
constexpr int MAXN = 11;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tc {}, n {}, l {};
  int mangos[MAXN] {}, limangos[MAXN] {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    bool ans = true;
    cin >> n >> l;
    int total {};
    for( int i = 0; i < n; ++ i ){
      cin >> mangos[i];
      total += mangos[i];
    }
    if( total > l ) ans = false;
    for( int i = 0; i < n; ++ i ){
      cin >> limangos[i];
      if( mangos[i] > limangos[i] )
	ans = false;
    }
    cout << "Case " << CASE << ": " << (ans ? "Yes\n" : "No\n");
  }
  return 0;
}
