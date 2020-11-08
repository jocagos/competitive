#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int TC {}, N {};
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> TC;
  while( TC -- ){
    cin >> N;
    cout << int(floor(log2(N)) + 1) << '\n';
  }
  return 0;
}
