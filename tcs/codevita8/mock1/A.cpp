#include <bits/stdc++.h>

using namespace std;
unordered_map<char, int> vals {};

auto lambda = []( char left, char right ) -> bool {
		return vals[left] < vals[right];
	      };

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  cin >> n;
  while( n -- ){
    string order {}, s {};
    cin >> order;
    cin >> s;
    for( unsigned int i = 0; i < order.length(); ++ i ) vals[order[i]] = i;
    sort( s.begin(), s.end(), lambda );
    cout << s << '\n';
  }
  return 0;
}
