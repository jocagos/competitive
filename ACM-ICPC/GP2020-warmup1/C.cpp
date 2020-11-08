#include <iostream>

using namespace std;

int main(){
  int A {}, C {};
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> A;
  cin >> C;
  cout << (2 * C - A) << '\n';
  return 0;
}
