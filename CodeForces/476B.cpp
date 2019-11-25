#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1 << 10;
constexpr int INF = -999999;
int memo[MAXN] {};

void init(){
  for( int i = 0; i < MAXN; ++ i )
    memo[i] = -INF;
}

int to_bitmask( string& s ){
  int bitmask = 0;
  for( unsigned i = 0; i < s.length(); ++ i )
    if( s[i] == '+' ) bitmask |= (1 << i);
  return bitmask;
}

int val( string& s ){
  int ans = 0;
  for( char c : s ){
    if( c == '+' ) ans ++;
    else ans --;
  }
  return ans;
}

void do_the_harlem_shake( string& s ){
  if( 0 == count( begin( s ), end( s ), '?' ) ){
    memo[to_bitmask(s)] = val(s);
  }
  else{
    int idx = s.find_first_of( '?' );
    string t1 = s, t2 = s;
    t1[idx] = '-';
    t2[idx] = '+';
    do_the_harlem_shake( t1 );
    do_the_harlem_shake( t2 );
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  string s{}, t{};
  getline( cin, s );
  getline( cin, t );
  int marks = count( begin( t ), end( t ), '?' );
  long double ans{};
  if( marks ){
    int total = 1 << marks;
    do_the_harlem_shake( t );
    int matches = count( memo, memo + MAXN, val( s ) );
    ans = 1.0L * matches / total;
  }
  else{
    if( val( s ) == val( t ) )
      ans = 1;
  }
  cout << setprecision(12) << fixed << ans << endl;
  return 0;
}
