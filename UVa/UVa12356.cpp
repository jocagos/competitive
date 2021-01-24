#include <iostream>

using namespace std;
constexpr int MAXN = 100100;
constexpr int NONE = -1;
int P[MAXN] {}, N[MAXN] {}; // prev, next

// using 1-based indexing
void init( int n = MAXN ){
  for( int i = 1; i <= n; ++ i ){
    P[i] = i - 1;
    N[i] = i + 1;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int s {}, b {};
  while( cin >> s >> b, s | b ){
    init( s );
    int L {}, R {};
    for( int i = 0; i < b; ++ i ){
      cin >> L >> R;
      int prev_tmp_L = P[L];
      int next_tmp_R = N[R];
      N[prev_tmp_L] = next_tmp_R;
      P[next_tmp_R] = prev_tmp_L;
      if( prev_tmp_L > 0 )
	cout << prev_tmp_L;
      else
	cout << "*";
      cout << " ";
      if( next_tmp_R <= s )
	cout << next_tmp_R;
      else
	cout << "*";
      cout << '\n';
    }
    cout << "-\n";
  }
  return 0;
}
