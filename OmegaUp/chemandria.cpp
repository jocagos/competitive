#include <iostream>
#include <string>
#include <queue>

using namespace std;
constexpr int MAXN = 501, MAX_VAL = 1e7;
int buckets[MAXN] {};
int earliest[MAXN] {};
int latest[MAXN] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for( int i = 0; i < MAXN; ++ i )
    earliest[i] = latest[i] = MAX_VAL;
  int n {}, a {}, b {};
  int E {}, L {};
  string s {};
  cin >> n;
  while( n -- ){
    cin >> s;
    if( s[0] == 'A' ){ // push_back
      cin >> a;
      if( earliest[a] == MAX_VAL )
	earliest[a] = 
    }
  }
  return 0;
}
