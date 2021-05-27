#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long a {}, b {};
  cin >> a >> b;
  long long c = a / b;
  long long num = a - c * b;
  if( num != 0LL ){
    cout << c << " " << num << "/" << b << '\n';
  }
  else
    cout << c << '\n';
  return 0;
}
