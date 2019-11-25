#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, A {}, B {}, gender {}, prev_member {}, prev_team {};
  bool violation = false;
  char team {};
  string s {};
  cin >> n;
  while( n -- ){
    cin >> s;
    if( s[0] == 'A' ){
      ++ A;
      if( prev_team ){
	if( (abs( gender ) == max(A, B) and abs( gender ) > 1) or A == 4 ){
	  violation = true;
	  team = prev_team;
	  break;
	}
      }
      B = 0;
    }
    else{
      ++ B;
      if( prev_team ){
	if( (abs( gender ) == max(A, B) and abs( gender ) > 1) or B == 4 ){
	  violation = true;
	  team = prev_team;
	  break;
	}
      }
      A = 0;
    }
    if( A > 3 or B > 3 ){
      violation = true;
      team = s[0];
      break;
    }
    if( prev_team == s[0] ){
      if( abs( prev_member ) == s[1] ){
	violation = true;
	team = s[0];
	break;
      }
      gender += ( s[2] == 'W' ? 1 : -1 );
    }
    else{
      gender = ( s[2] == 'W' ? 1 : -1 );
    }
    prev_team = s[0];
    prev_member = s[1];
    if( s[0] == 'B' ) prev_member *= -1;
  }
  if( max(A, B) == abs(gender) and max(A, B) > 1 ){
    violation = true;
    team = ( A == abs(gender) ? 'A' : 'B' );
  }
  if( violation )
    cout << team << endl;
  else
    cout << "No violation" << endl;
  return 0;
}
