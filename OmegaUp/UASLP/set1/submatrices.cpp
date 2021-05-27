#include <iostream>

using namespace std;
constexpr int MAXD = 1010;
int vals[MAXD][MAXD] {};
int sub[MAXD][MAXD] {};
bool valid[MAXD][MAXD] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int R {}, C {}, r {}, c {};
  cin >> R >> C;
  for( int i = 0; i < R; ++ i ){
    for( int j = 0; j < C; ++ j ){
      cin >> vals[i][j];
    }
  }
  cin >> r >> c;
  for( int i = 0; i < r; ++ i ){
    for( int j = 0; j < c; ++ j ){
      cin >> sub[i][j];
    }
  }
  for( int i = 0; i < R - r + 1; ++ i ){
    for( int j = 0; j < C - c + 1; ++ j ){
      bool able = true;
      for( int K = i; (K < r + i) and able; ++ K ){
	for( int L = j; (L < c + j) and able; ++ L ){
	  able = (vals[K][L] == sub[K - i][L - j]);
	}
      }
      if( able ){
	for( int K = i; (K < r + i) and able; ++ K ){
	  for( int L = j; (L < c + j) and able; ++ L ){
	    valid[K][L] = true;
	  }
	}
      }
    }
  }
  for( int i = 0; i < R; ++ i ){
    for( int j = 0; j < C; ++ j ){
      cout << valid[i][j] << (j + 1 == C ? "\n" : " ");
    }
  }
  return 0;
}
