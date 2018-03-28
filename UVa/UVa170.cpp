#include <bits/stdc++.h>

using namespace std;

typedef pair<int, char> ic;

int main(){
  vector<stack<ic>> clk(13);
  map<char, int> _atoi;
  _atoi['A'] = 0; _atoi['2'] = 1;_atoi['3'] = 2; _atoi['4'] = 3;_atoi['5'] = 4; _atoi['6'] = 5;
  _atoi['7'] = 6; _atoi['8'] = 7;_atoi['9'] = 8; _atoi['T'] = 9;_atoi['J'] = 10; _atoi['Q'] = 11;
  _atoi['K'] = 12;
  string s;
  vector<string> vs;
  while( cin >> s ){
    if( s == "#" ) break;
    vs.clear();
    vs.push_back(s);
    // Clear stacks
    for( int i = 0; i < clk.size(); ++i ){
      while( !clk[i].empty() ) clk[i].pop();
    }
    // Fill deck
    for( int i = 0; i < 51; ++i ){
      cin >> s;
      vs.push_back(s);
    }
    // Fill stacks
    for( int i = 51, j = 0; i >= 0; --i, ++j ){
      s = vs[i];
      ic tmp = { _atoi[s[0]], s[1] };
      clk[j%13].push(tmp);
    }
    // Play the game
    int count = 0;
    ic tmp; int idx = 12;
    while( true  ){
      if( clk[idx].empty() ) break;
      tmp = clk[idx].top();
      clk[idx].pop();
      idx = tmp.first;
      count++;
    }
    char key;
    for( auto it = _atoi.begin(); it != _atoi.end(); it++ ) if( it->second == idx ) key = it->first;
    if( count < 10 ) cout << "0";
    cout << count << "," << key << tmp.second << endl;
  }
  return 0;
}
