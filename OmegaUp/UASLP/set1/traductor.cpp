#include <iostream>
#include <cstring>

using namespace std;
constexpr int MAX_VAL = 10010;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int d {}, w {}, lhs {}, rhs {};
  int num[MAX_VAL] {}, ent[MAX_VAL] {};
  memset( num, -1, sizeof num );
  memset( ent, -1, sizeof ent );
  cin >> d >> w;
  for( int i = 0; i < d; ++ i ){
    cin >> lhs >> rhs;
    num[lhs] = rhs;
    ent[rhs] = lhs;
  }
  for( int i = 0; i < w; ++ i ){
    cin >> lhs;
    if( num[lhs] >= 0 )
      cout << num[lhs] << '\n';
    else
      cout << "C?\n";
  }
  return 0;
}
