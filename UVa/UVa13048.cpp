#include <iostream>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line {};
  getline( cin, line );
  int tc = stoi( line );
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    int cnt {};
    getline( cin, line );
    int n = (int)line.length();
    for( int i = 0; i < n; ++ i ){
      bool possible = ( line[i] != 'D' and line[i] != 'S' and line[i] != 'B' );
      if( i > 0 )
	possible = (possible and line[i - 1] != 'S' );
      if( i + 1 < n )
	possible = (possible and line[i + 1] != 'B' and line[i + 1] != 'S' );
      if( i + 2 < n )
	possible = (possible and line[i + 2] != 'B' );
      if( possible )
	++ cnt;
    }
    cout << "Case " << CASE << ": " << cnt << '\n';
  }
  return 0;
}
