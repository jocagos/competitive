#include <iostream>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  string line {};
  getline( cin, line );
  tc = stoi( line );
  while( tc -- ){
    getline( cin, line );
    unsigned long long num_low {}, den_low {1}, num_high {1}, den_high {0};
    unsigned long long num_med = num_low + num_high;
    unsigned long long  den_med = den_low + den_high;
    for( int i = 0; i < (int)line.length(); ++ i ){
      if( line[i] == 'L' ){
	num_high = num_med;
	den_high = den_med;
      }
      else{
	num_low = num_med;
	den_low = den_med;
      }
      num_med = num_low + num_high;
      den_med = den_low + den_high;
    }
    cout << num_med << "/" << den_med << '\n';
  }
  return 0;
}
