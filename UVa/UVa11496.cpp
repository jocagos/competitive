#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
  int n;
  while( scanf("%d", &n), n ){
    vector<int> v(n+1);
    for( int i = 0; i < n; ++ i ) scanf("%d", &v[i]), cout << v[i] << '\t';
    v[n] = v[0], cout << v[n] << '\n';
    int peaks = 0, prev = INT_MAX;
    bool up = false, down = false;
    for( int i = 0; i <= n; ++ i ){
      if( prev != INT_MAX ){
	if( (up and prev > v[i]) or (down and prev < v[i] ) ) peaks++;
	if( prev < v[i] ) up = true, down = false;
	else down = true, up = false;
	prev = v[i];
      }
      else{
	prev = v[0];
      }
    }
    cout << peaks << "\n";
  }
  cout.flush();
  return 0;
}
