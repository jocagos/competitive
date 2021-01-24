#include <iostream>

using namespace std;
constexpr int MAXN = 11;
int n {};
char orig[MAXN][MAXN] {},
  cpy[MAXN][MAXN] {},
  tmp[MAXN][MAXN] {};

inline bool reflection(){ // vertical
  bool ans = true;
  for( int i = 0; i < n; ++ i )
    for( int j = 0; j < n; ++ j )
      ans = (ans and (cpy[n - i - 1][j] == orig[i][j]));
  return ans;
}

inline bool rotation( int degrees, bool use_tmp = false ){
  bool ans = true;
  int X {}, Y {};
  auto TARGET = (use_tmp ? tmp : orig);
  if( degrees == 90 ){
    for( int i = 0; i < n; ++ i ){
      for( int j = 0; j < n; ++ j ){
	X = j;
	Y = n - i - 1;
	ans = (ans and cpy[X][Y] == TARGET[i][j]);
      }
    }
  }
  else if( degrees == 180 ){
    for( int i = 0; i < n; ++ i ){
      for( int j = 0; j < n; ++ j ){
	X = n - i - 1;
	Y = n - j - 1;
	ans = (ans and cpy[X][Y] == TARGET[i][j]);
      }
    }
  }
  else if( degrees == 270 ){
    for( int i = 0; i < n; ++ i ){
      for( int j = 0; j < n; ++ j ){
	X = n - j - 1;
	Y = i;
	ans = (ans and cpy[X][Y] == TARGET[i][j]);
      }
    }
  }
  return ans;
}

inline bool combination( int degrees ){
  return rotation( degrees, true );
}

inline bool self(){
  bool ans = true;
  for( int i = 0; i < n; ++ i ){
    for( int j = 0; j < n; ++ j ){
      if( not ans )
	return ans;
      ans = (ans and orig[i][j] == cpy[i][j]);
    }
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int CASE {1};
  while( cin >> n ){
    for( int i = 0; i < n; ++ i )
      cin >> orig[i] >> cpy[i];
    // make reflection
    for( int i = 0; i < n; ++ i )
      for( int j = 0; j < n; ++ j )
	tmp[n - i - 1][j] = orig[i][j];

    cout << "Pattern " << CASE << " was ";
    if( self() )
      cout << "preserved.\n";
    else if( rotation( 90 ) )
      cout << "rotated 90 degrees.\n";
    else if( rotation( 180 ) )
      cout << "rotated 180 degrees.\n";
    else if( rotation( 270 ) )
      cout << "rotated 270 degrees.\n";
    else if( reflection() )
      cout << "reflected vertically.\n";
    else if( combination( 90 ) )
      cout << "reflected vertically and rotated 90 degrees.\n";
    else if( combination( 180 ) )
      cout << "reflected vertically and rotated 180 degrees.\n";
    else if( combination( 270 ) )
      cout << "reflected vertically and rotated 270 degrees.\n";
    else
      cout << "improperly transformed.\n";
    CASE ++;
  }
  return 0;
}
