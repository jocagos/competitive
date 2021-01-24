#include <iostream>
#include <string>
#include <vector>

using namespace std;
constexpr int MAXM = 55, MAXN = 1010, MAXC = 256;
constexpr char dna[] = {'A', 'C', 'G', 'T'};
char code[MAXC] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {}, n {}, m {};
  int vals[4] {};
  char str[MAXN] {};
  code['A'] = 0;
  code['C'] = 1;
  code['G'] = 2;
  code['T'] = 3;
  vector<string> vs( MAXM );
  cin >> tc;
  while( tc -- ){
    int hamming {};
    cin >> m >> n;
    for( int i = 0; i < m; ++ i )
      cin >> vs[i];
    // hamming is greedy
    for( int i = 0; i < n; ++ i ){
      vals[0] = vals[1] = vals[2] = vals[3] = 0;
      for( auto c : dna ){
	for( int j = 0; j < m; ++ j ){
	  if( vs[j][i] != c )
	    vals[code[c]] ++;
	}
      }
      if( vals[0] <= vals[1] and vals[0] <= vals[2] and vals[0] <= vals[3] ){
	str[i] = 'A';
	hamming += vals[0];
      }
      else if( vals[1] <= vals[0] and vals[1] <= vals[2] and vals[1] <= vals[3] ){
	str[i] = 'C';
	hamming += vals[1];
      }
      else if( vals[2] <= vals[0] and vals[2] <= vals[1] and vals[2] <= vals[3] ){
	str[i] = 'G';
	hamming += vals[2];
      }
      else if( vals[3] <= vals[0] and vals[3] <= vals[2] and vals[3] <= vals[1] ){
	str[i] = 'T';
	hamming += vals[3];
      }
    }
    str[n] = '\0';
    cout << str << '\n' << hamming << '\n';
  }
  return 0;
}
