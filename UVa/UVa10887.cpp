#include <unordered_set>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
constexpr int MAXN = 1515;
vector<string> vals( MAXN );

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {}, n {}, m {};
  string line {};
  getline( cin, line );
  tc = stoi( line );
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    unordered_set<string> ans;
    getline( cin, line );
    istringstream iss( line );
    iss >> n >> m;
    for( int i = 0; i < n; ++ i )
      getline( cin, vals[i] );
    for( int i = 0; i < m; ++ i ){
      getline( cin, line );
      for( int i = 0; i < n; ++ i )
	ans.emplace( vals[i] + line );
    }
    cout << "Case " << CASE << ": " << ans.size() << '\n';
  }
  return 0;
}
