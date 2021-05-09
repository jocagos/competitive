#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q {};
  cin >> q;
  string query {}, person {};
  stack<string> st {};
  while( q -- ){
    cin >> query;
    if( query[0] == 'S' ){
      cin >> person;
      st.emplace( person );
    }
    else if( query[0] == 'K' ){
      if( not st.empty() )
	st.pop();
    }
    else if( query[0] == 'T' ){
      if( not st.empty() )
	cout << st.top() << '\n';
      else
	cout << "Not in a dream\n";
    }
  }
  return 0;
}
