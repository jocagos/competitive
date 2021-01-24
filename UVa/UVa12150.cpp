#include <iostream>
#include <vector>

using namespace std;
constexpr int MAXN = 100100;
constexpr int DUMMY = -9999999;
int cars[MAXN] {};

void init(){
  for( int i = 0; i < MAXN; ++ i )
    cars[i] = DUMMY;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  while( cin >> n, n ){
    init();
    bool able = true;
    int a {}, b {};
    for( int i = 0; i < n; ++ i ){
      cin >> a >> b;
      if( not able )
	continue;
      if( b + i >= n or b + i < 0 )
	able = false;
      if( cars[i + b] != DUMMY )
	able = false;
      if( able )
	cars[i + b] = a;
    }
    if( not able )
      cout << "-1\n";
    else{
      for( int i = 0; i < n; ++ i )
	cout << cars[i] << ( i + 1 == n ? '\n' : ' ' );
    }
  }
  return 0;
}
