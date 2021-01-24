#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
constexpr int MAXP = 3030;
int periods[MAXP] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s {};
  int reg {};
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> registers;
  while( cin >> s, s != "#" ){
    cin >> reg;
    cin >> periods[reg];
    registers.emplace( periods[reg], reg );
  }
  cin >> reg;
  while( not registers.empty() and reg -- ){
    auto tmp = registers.top();
    registers.pop();
    cout << tmp.second << '\n';
    tmp.first += periods[tmp.second];
    registers.push( tmp );
  }
  return 0;
}
