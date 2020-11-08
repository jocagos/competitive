#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
constexpr int MAXR = 90000000;

inline int f( int m, int d ){
  return (6 - m) * (6 - m) + abs(d - 15);
}

int main(){
  int N {}, TV {}, NOTV {}, R {}, ans {}, tv_rooms {};
  int patients[366] {};
  // fill patients
  int curr_day = 1, curr_month = 1, max_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  for( int i = 0; i < 366; ++ i ){
    patients[i] = f( curr_month, curr_day );
    // cerr << "DATE: "
    // 	 << setfill('0') << setw(2) << right << curr_day
    // 	 << "/"
    // 	 << setfill('0') << setw(2) << right << curr_month
    // 	 << '\t' << patients[i] << endl;
    curr_day ++;
    if( curr_day > max_days[curr_month - 1] ){
      curr_day = 1;
      curr_month ++;
    }
  }
  // optimize io
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // input
  cin >> N;
  cin >> TV >> NOTV;
  cin >> R;

  // solution
  while( tv_rooms <= N and ans < R ){
    ans = 0;
    for( int d = 0; d < 365; ++ d ){
      int r_day {};
      int Q = N - tv_rooms;
      if( patients[d] < Q )
	r_day = patients[d] * NOTV;
      else if( patients[d] >= Q and patients[d] < N )
	r_day = Q * NOTV + min( patients[d] - Q, tv_rooms ) * TV;
      else // patients[d] >= N
	r_day = Q * NOTV + tv_rooms * TV;
      ans += r_day;
    }
    tv_rooms ++;
  }
  
  // output
  cout << (ans >= R ? tv_rooms - 1 : N ) << endl;
  return 0;
}
