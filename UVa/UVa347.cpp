#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;
constexpr int MAXN {10000000};
set<long> runaways {};
bitset<MAXN> used {};
bool is_runaway( long n ){
  if( used[n] and runaways.find( n ) != runaways.end() )
    return true;
  else if( used[n] )
    return false;
  // Save the number as an implicit graph
  long digits {}, tmp {n};
  while( tmp ){
    digits ++;
    tmp /= 10;
  }
  vector<int> num( digits, 0 );
  long p = 10;
  for( int i = digits - 1; i >= 0; -- i ){
    num[i] = (n % p) / (p / 10);
    p *= 10;
  }
  vector<bool> visited( digits, false );
  int i = 0;
  while( not visited[i] ){
    i = (i + num[i]) % digits;
    visited[i] = true;
  }
  bool ans = true;
  for( int j = 0; j < digits and ans; ++ j )
    ans = (ans or visited[j]);
  used[n] = 1;
  if( ans )
    runaways.emplace( n );
  return ans;
}

int main(){
  long n {}, CASE {};
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while( cin >> n ){
    if( n ){
      ++ CASE;
      if( is_runaway( n ) )
	std::cout << "Case " << CASE << ": " << n << '\n';
      else{
	auto closest = runaways.upper_bound( n );
	std::cout << "Case " << CASE << ": " << closest << '\n';
      }
    }
    else exit(0);
  }
  return 0;
}
