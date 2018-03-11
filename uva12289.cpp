#include <iostream>
#include <string>

#define optimize_ios() ios_base::sync_with_stdio(0);cin.tie(0)

using namespace std;

int main(){
  int n;
  string s;
  cin >> n;
  while(n--){
    cin >> s;
    if( s.length() == 3 ){
      if( s.at(0) == 'o' and s.at(2) == 'e' or s.at(1) == 'n' and s.at(2) == 'e' or s.at(0) == 'o' and s.at(1) == 'n')
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
    else
      cout << 3 << endl;
  }
  return 0;
}
