#include <iostream>
#include <algorithm>

using namespace std;
int a[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};

int main(){
  int n {}, k {};
  cin >> n >> k;
  for( int i = 1; i < 10; ++ i )
    a[i] += a[i - 1];
  int at = upper_bound( a, a + 10, 240 - k ) - a;
  cout << (at > n ? n : at) << '\n';
  return 0;
}
