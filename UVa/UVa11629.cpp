#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  char dot {};
  int lhs {}, rhs {}, p {}, g {};
  string party {};
  cin >> p >> g;
  unordered_map<string, int> parties;
  for( int i = 0; i < p; ++ i ){
    cin >> party >> lhs >> dot >> rhs;
    parties[party] = lhs * 10 + rhs;
  }
  for( int i = 0; i < g; ++ i ){
    string op {};
    int total {};
    cin >> party;
    total += parties[party];
    cin >> op;
    while( op == "+" ){
      cin >> party;
      total += parties[party];
      cin >> op;
    }
    cin >> rhs;
    rhs *= 10;
    bool ok {};
    if( op == ">" )
      ok = (total > rhs);
    else if( op == "<" )
      ok = (total < rhs);
    else if( op == ">=" )
      ok = (total >= rhs );
    else if( op == "<=" )
      ok = (total <= rhs );
    else if( op == "=" )
      ok = (total == rhs);
    cout << "Guess #" << (i + 1) << " was " << (ok ? "" : "in") << "correct.\n";
  }
  return 0;
}
