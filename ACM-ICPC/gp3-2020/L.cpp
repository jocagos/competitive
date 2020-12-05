#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  cin >> n;
  vector<string> vs( n );
  for( int i = 0; i < n; ++ i )
    cin >> vs[i];
  unordered_map<string, int> keys;
  bool used[1000] {};
  int keys_used = {};
  for( int i = 0; i < n; ++ i ){
    if( used[i] ) continue;
    string k = vs[i] + vs[i];
    int L = (int)vs[i].length();
    used[i] = true;
    keys[k] = 1;
    ++ keys_used;
    for( int j = i + 1; j < n; ++ j ){
      if( (int)vs[j].length() == L and k.find( vs[j] ) != string::npos ){
	used[j] = true;
	keys[k] ++;
      }
    }
  }
  cout << keys_used << '\n';
  return 0;
}
