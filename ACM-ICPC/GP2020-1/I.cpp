#include <bits/stdc++.h>

using namespace std;
constexpr int REJECTED = 2, WEAK = 3, GOOD = 4, STRONG = 5;

int check( string& str ){
  bool LEN {}, NUM {}, SP {}, UP {}, LW {};
  int N = str.length();
  LEN = (N >= 10);
  for( int i = 0; i < N and !(SP and UP and LW and NUM); ++ i ){
    if( not SP ){
      if( str[i] == '.' or str[i] == ',' or str[i] == '#' or
	  str[i] == '$' or str[i] == '%' or str[i] == '/' or
	  str[i] == '(' or str[i] == '&' or str[i] == ')'
	)
	SP = true;
    }
    if( not UP ){
      if( 'A' <= str[i] and str[i] <= 'Z' ) UP = true;
    }
    if( not LW ){
      if( 'a' <= str[i] and str[i] <= 'z' ) LW = true;
    }
    if( not NUM ){
      if( '0' <= str[i] and str[i] <= '9' ) NUM = true;
    }
  }

  for( int i = 1; i < N and NUM; ++ i ){
    if( '0' <= str[i - 1] and str[i - 1] <= '9'
	and
	'0' <= str[i] and str[i] <= '9'
	and
	(int)str[i] - (int)str[i - 1] != 1
      )
      NUM = false;
  }
  int ans = (int)LEN + (int)NUM + (int)LW + (int)UP + (int)SP;
  return ans;
}

int main(){
  int n {};
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for( int CASE = 1; CASE <= n; ++ CASE ){
    string str;
    cin >> str;
    int ans = check( str );
    cout << "Assertion number #" << CASE << ": ";
    if( ans == WEAK ) cout << "Weak";
    else if( ans == GOOD ) cout << "Good";
    else if( ans == STRONG ) cout << "Strong";
    else if( ans <= REJECTED ) cout << "Rejected";
    cout << '\n';
  }
  return 0;
}
