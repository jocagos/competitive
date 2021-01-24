#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <utility>
#include <functional>

using namespace std;
constexpr int MAXN = 110;

vector<tuple<int, int, int>> ants( MAXN );

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  int L {}, W {}, H {};
  while( cin >> n, n ){
    for( int i = 0; i < n; ++ i ){
      cin >> L >> W >> H;
      ants[i] = make_tuple( L, W, H );
    }
    sort( ants.begin(), ants.begin() + n,
	  []( tuple<int, int, int>& lhs, tuple<int, int, int>& rhs ) -> bool {
	    int LL, WL, HL, LR, WR, HR;
	    int VL, VR;
	    double FL, FR;
	    tie( LL, WL, HL ) = lhs;
	    tie( LR, WR, HR ) = rhs;
	    VL = LL * WL * HL;
	    VR = LR * WR * HR;
	    FL = (2 * HL - 1.) / (2 * HL);
	    FR = (2 * HR - 1.) / (2 * HR);
	    if( FL != FR )
	      return FL > FR;
	    else
	      return VL > VR;
	  });
    tie( L, W, H ) = ants[0];
    cout << (L * W * H) << '\n';
  }
  return 0;
}
