#include <iostream>
#include <string>
#include <vector>
#include <utility>
// this is to make our life easier at the query part
#include <unordered_map>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int arrs {}, q {};
  cin >> arrs >> q;
  vector<string> names( arrs );
  vector<int> // self explanatory
    addresses( arrs ),
    data_sizes( arrs );
  vector<vector<int>> constants( arrs );
  vector<vector<pair<int, int>>> dimensions( arrs );
  unordered_map<string, int> get_idx;
  string arr_name;
  int D {}, L {}, R {};
  for( int i = 0; i < arrs; ++ i ){
    cin >> names[i] >> addresses[i] >> data_sizes[i] >> D;
    get_idx[names[i]] = i; // so we can use the index later
    dimensions[i].resize( D );
    for( int j = 0; j < D; ++ j ){
      cin >> L >> R;
      dimensions[i][j] = make_pair( L, R );
    }
    constants[i].assign( D + 1, 0 );
    constants[i][D] = data_sizes[i]; // C_sub_D
    for( int j = D - 1; j > 0; -- j )
      // use formula
      constants[i][j] = constants[i][j + 1] * (dimensions[i][j].second - dimensions[i][j].first + 1);
    constants[i][0] = addresses[i];
    // compute the C_sub_0
    for( int j = 1; j <= D; ++ j )
      constants[i][0] -= constants[i][j] * dimensions[i][j - 1].first;
  }
  int pos {};
  // for every query
  while( q -- ){
    cin >> arr_name;
    int idx = get_idx[arr_name];
    int D = dimensions[idx].size();
    cout << arr_name << "[";
    int ans = constants[idx][0];
    
    for( int i = 0; i < D; ++ i ){
      cin >> pos;
      cout << pos << ( i + 1 == D ? "] = " : ", " );
      ans += pos * constants[idx][i + 1];
    }
    cout << ans << '\n';
  }
  return 0;
}
