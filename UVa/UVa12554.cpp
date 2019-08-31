#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  string s;
  bool once = false;
  vector<string> song = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you" };
  cin >> n;
  vector<string> vs(n);
  for( int i = 0; i < n; ++i ){
    cin >> vs[i];
  }
  for( int i = 0, j = 0; j < 16 || !once; ++i, ++j){
    j %= 16;
    cout << vs[i] << ": " << song[j] << endl;
    if( i == n - 1 ) i = -1, once = true;
  }
  return 0;
}
