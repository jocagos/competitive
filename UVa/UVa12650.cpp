#include <iostream>
#include <bitset>

using namespace std;
constexpr int MAXN = 10010;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  bitset<MAXN> divers;
  int n {}, r {};
  while( cin >> n >> r ){
    divers.reset();
    int tmp {};
    for( int i = 0; i < r; ++ i ){
      cin >> tmp;
      divers[tmp] = 1;
    }
    if( n == r )
      cout << "*";
    else
      for( int i = 1; i <= n; ++ i )
	if( not divers[i] )
	  cout << i << " ";
    cout << '\n';
  }
  return 0;
}
