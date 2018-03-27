#include <bits/stdc++.h>

using namespace std;

typedef pair<int, char> ic;

int main(){
  vector<stack<ic>> clk(13);
  string s;
  for( int i = 0; i < 52; ++i ){
    cin >> s;
    ic tmp = { (isdigit(s[0]) ? s[0]-'0' : (s[0] == 'T' ? 10 : (s[0] == 'J' ? 11 : (s[0] == 'Q' ? 12 : ( s[0] == 'K' ? 13 : 1 ) ) ) ) ), s[1] };
    clk[i%13].push(tmp);
  }
  // Next routine will print out ALL the elements in the stacks!
  /*
  for( int i = 0; i < clk.size(); ++i ){
    cout << "Stack " << i+1 << "\t";
    while( !clk[i].empty() ){
      cout << "(" << clk[i].top().first << ", " << clk[i].top().second << ") ";
      clk[i].pop();
    }
    cout << endl;
  }
  */
  bool game = true;
  int count = 0;
  ic tmp = clk[12].top(); clk[12].pop(); count++;
  while( game ){
    int idx = tmp.first-1;
    if( !clk[idx].empty() ){
      tmp = clk[idx].top();
      clk[idx].pop();
      count++;
    }
    else game = false;
  }
  printf("%d,%c%c\n", count,
	 ( tmp.first == 13 ? 'K' : ( tmp.first == 12 ? 'Q' : (tmp.first == 11 ? 'J' : ( tmp. first == 10 ? 'T' : (tmp.first == 1 ? 'A' : (char) tmp.first + '0' ) ) ) ) ), tmp.second);
  return 0;
}
