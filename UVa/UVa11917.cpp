#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    int n {}, hours {};
    string sub {};
    cin >> n;
    unordered_map<string, int> subjects;
    while( n -- ){
      cin >> sub >> hours;
      subjects[sub] = hours;
    }
    cin >> n;
    cin >> sub;
    cout << "Case " << CASE << ": ";
    if( subjects.find( sub ) == subjects.end() )
      cout << "Do your own homework!\n";
    else if( subjects[sub] <= n )
      cout << "Yesss\n";
    else if( subjects[sub] <= n + 5 )
      cout << "Late\n";
    else
      cout << "Do your own homework!\n";
  }
  return 0;
}
