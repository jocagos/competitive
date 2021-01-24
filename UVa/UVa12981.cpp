#include <iostream>

using namespace std;
int orig[4] {}, gotten[4] {};

bool check_mats(){
  return ( orig[0] == gotten[0] and orig[1] == gotten[1] and orig[2] == gotten[2] and orig[3] == gotten[3] )
    or
    ( orig[0] == gotten[1] and orig[1] == gotten[3] and orig[2] == gotten[0] and orig[3] == gotten[2] )
    or
    ( orig[0] == gotten[2] and orig[1] == gotten[0] and orig[2] == gotten[3] and orig[3] == gotten[1] )
    or
    ( orig[0] == gotten[3] and orig[1] == gotten[2] and orig[2] == gotten[1] and orig[3] == gotten[0] );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    cin >> orig[0] >> orig[1] >> orig[2] >> orig[3];
    cin >> gotten[0] >> gotten[1] >> gotten[2] >> gotten[3];
    cout << "Case #" << CASE << ": ";
    if( not check_mats() )
      cout << "IM";
    cout << "POSSIBLE\n";
  }
  return 0;
}
