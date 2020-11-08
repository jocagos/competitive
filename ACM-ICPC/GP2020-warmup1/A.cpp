#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
  int C {}, A {};
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> C;
  cin >> A;
  cout << int(ceil(A/ (C - 1.0))) << '\n';
  return 0;
}
