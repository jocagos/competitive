#include <bits/stdc++.h>

using namespace std;

int t {}, n {}, k {};
string s {};
map<string, string> patterns {};
map<string, int> lengths {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line {};
  getline( cin, line );
  t = stoi( line );
  while( t -- ){
    getline( cin, line );
    istringstream iss( line );
    iss >> s >> k >> n;
    for( int i = 0; i < k; ++ i ){
      getline( cin, line );
      istringstream _iss( line );
      string from {}, to {};
      _iss >> from >> to;
      patterns[from] = to;
      lengths[from];
    }
  }
  return 0;
}
