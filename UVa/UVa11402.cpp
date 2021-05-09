/* Ahoy, Pirates!
 * Simulating a BIT with a bitset
 */

#include <iostream>
#include <string>

using namespace std;

constexpr int MAXN = 1024000;
constexpr int BIT_STR = 64;
unsigned long long vals[MAXN / BIT_STR + 1] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TC {}, Q {}, M {}, N {}, t {};
  string s {};
  cin >> TC;
  for( int _ = 1; _ <= TC; ++ _ ){
    N = 0;
    cin >> M;
    while( M -- ){
      cin >> t >> s;
      int idx {};
      for( int i = 0; i < (int)s.length(); ++ i ){
	vals[idx] |= ((s[i] - '0') << 
      }
    }
    cout << "Case " << _ << ":\n";
  }
  return 0;
}
