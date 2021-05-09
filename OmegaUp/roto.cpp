#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  stack<pair<int, int>> st {};
  queue<pair<int, int>> qu {};
  string line {};
  getline( cin, line );
  bool use_head {};
  int L {};
  int last = line.find_last_of( "[]" );
  pair<int, int> indexes {};
  for( int i = 0; i < (int)line.length(); ++ i ){
    if( line[i] == '[' ){
      if( use_head )
	st.emplace( L, i - 1 );
      else
	qu.emplace( L, i - 1 );
      use_head = true;
      L = i + 1;
    }
    else if( line[i] == ']' ){
      if( use_head )
	st.emplace( L, i - 1 );
      else
	qu.emplace( L, i - 1 );
      use_head = false;
      L = i + 1;
    }
  }
  if( last >= 0 and last < L ){
    if( use_head )
      st.emplace( L, (int)line.length() - 1 );
    else
      qu.emplace( L, (int)line.length() - 1 );
  }
  while( not st.empty() ){
    indexes = st.top();
    st.pop();
    for( int i = indexes.first; i <= indexes.second; ++ i )
      cout << line[i];
  }
  while( not qu.empty() ){
    indexes = qu.front();
    qu.pop();
    for( int i = indexes.first; i <= indexes.second; ++ i )
      cout << line[i];
  }
  cout << '\n';
  return 0;
}
