#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
#include <utility>
#include <cstring>
#include <vector>

using namespace std;

int main(){
  string line;
  int periods[3001];
  memset(periods, 0, sizeof periods);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> registers;
  while( getline(cin, line), line != "#" and line != "#\r" ){
    istringstream iss(line);
    int idx, p;
    iss >> line >> idx >> p;
    periods[idx] = p;
    registers.emplace(p, idx);
  }

  int p = 0, k;
  scanf("%d", &k);
  while( !registers.empty() and k-- ){
    auto tmp = registers.top();
    registers.pop();
    cout << tmp.second << endl;
    tmp.first += periods[tmp.second];
    registers.push(tmp);
  }
  return 0;
}
