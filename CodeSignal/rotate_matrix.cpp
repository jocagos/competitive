#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector<vector<int>> rotateImage(vector<vector<int>>& a) {
  int n = a.size();
  for( int i = 0; i < n - 1 - i; ++ i ){
    int off = 0;
    for( int j = i; j < n - 1 - i; ++ j, ++ off ){
      if( i == j or j == (n - 1 - i) ) continue;
      int A = a[i][j], B = a[j][n - i - 1], C = a[n - i - 1][n - i - 1 - off], D = a[n - 1 - i - off][i];
      a[i][j] = D;
      a[j][n - i - 1] = A;
      a[n - i - 1][n - 1 - i - off] = B;
      a[n - i - 1 - off][i] = C;
    }
  }
  return std::move( a );
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N {};
  cin >> N;
  vector<vector<int>> img( N, vector<int>( N, 0 ) );
  for( int i = 0; i < N; ++ i ){
    for( int j = 0; j < N; ++ j ){
      cin >> img[i][j];
    }
  }
  for( int i = 0; i < N; ++ i ){
    for( int j = 0; j < N; ++ j ){
      cout << setw(3) << setfill(' ') << img[i][j] << " ";
    }
    cout << endl;
  }
  cout << "********************\n";
  img = rotateImage(img);
  for( int i = 0; i < N; ++ i ){
    for( int j = 0; j < N; ++ j ){
      cout << setw(3) << setfill(' ') << img[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
