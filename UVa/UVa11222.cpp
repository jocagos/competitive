#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
constexpr int MAXS = 10010;
constexpr int MAXP = 10010;
int people[MAXS] {};
int problems[3][MAXP] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {}, s {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    memset( people, 0, sizeof(people) );
    memset( problems, 0, sizeof(problems) );
    for( int i = 0; i < 3; ++ i ){
      cin >> s;
      int tmp {};
      for( int j = 1; j <= s; ++ j ){
	cin >> tmp;
	if( people[tmp] & (1 << i) )
	  ;
	else{
	  ++ problems[i][0];
	  int idx = problems[i][0];
	  problems[i][idx] = tmp;
	  people[problems[i][idx]] |= (1 << i); // bitmask
	}
      }
      sort( &(problems[i][1]), &(problems[i][1 + problems[i][0]]) );
    }
    int best {};
    int unis[3] {};
    for( int i = 0; i < 3; ++ i ){
      for( int j = 1; j <= problems[i][0]; ++ j )
	if( people[problems[i][j]] == (1 << i) )
	  ++ unis[i];
      best = ( unis[i] > best ? unis[i] : best );
    }
    cout << "Case #" << CASE << ":\n";
    for( int i = 0; i < 3; ++ i ){
      if( unis[i] == best ){
	cout << i + 1 << " " << unis[i];
	for( int k = 1; k <= problems[i][0]; ++ k )
	  if( people[problems[i][k]] == (1 << i) )
	    cout << " " << problems[i][k];
	cout << '\n';
      }
    }
  }
  return 0;
}
