#include <iostream>

using namespace std;
constexpr int MAXM = 220, MAXN = 100;
constexpr int NINF = -1e9;
int arr[MAXM][MAXM] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line {};
  int n {}, CASE {1};
  while( cin >> n, n ){
    for( int i = 0; i < n; ++ i ){
      cin >> line;
      for( int j = 0; j < (int)line.length(); ++ j ){
      	if( line[j] == '-' )
      	  arr[i][j + i] = 1;
      	else
      	  arr[i][j + i] = NINF;
      }
    }
    int max_start = -1, area = 0;
    for( int i = 0; i < n; ++ i ){
      for( int j = i; j < 2 * (n - i) - 1; j += 2 ){
	area = arr[i][j];
	for( int k = j + 1; k < 2 * (n - i) - 1; ++ k ){
	  
	}
      }
    }
  }
  return 0;
}
