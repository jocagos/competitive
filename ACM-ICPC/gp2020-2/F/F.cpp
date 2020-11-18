#include <bits/stdc++.h>

using namespace std;

int main(){
  int L[2] {}, R[2] {};
  string S;
  cin >> S;
  bool left_serves = true;
  for( int i = 0; i < (int)S.length(); ++ i ){
    char c = S[i];
    if( (L[1] == 2 or R[1] == 2) and c != 'Q' )
      continue;
    if( (L[0] >= 5 and L[0] - R[0] >= 2) or L[0] == 10 ){
      L[1] ++;
      L[0] = R[0] = 0;
      left_serves = true;
    }
    else if( (R[0] >= 5 and R[0] - L[0] >= 2) or R[0] == 10 ){
      R[1] ++;
      R[0] = L[0] = 0;
      left_serves = false;
    }
    if( c == 'S' ){
      ( left_serves ? L[0] ++ : R[0] ++ );
    }
    else if( c == 'R' ){
      ( left_serves ? R[0] ++ : L[0] ++ );
      left_serves = (not left_serves);
    }
    else if( c == 'Q' ){
      if( i + 1 == (int)S.length() ){ // last
	if( L[0] > R[0] ) L[1] ++, L[0] = R[0] = 0;
	else if( R[0] > L[0] ) R[1] ++, L[0] = R[0] = 0;
      }
      if( L[1] == 2 ){
	cout << L[1] << " (winner) - " << R[1] << "\n";
      }
      else if( R[1] == 2 ){
	cout << L[1] << " - " << R[1] << " (winner)\n";
      }
      else{
	cout << L[1] << " (" << L[0] << ( left_serves ? "*" : "") << ") - "
	     << R[1] << " (" << R[0] << ( left_serves ? "" : "*" ) << ")\n";
      }
    }
  }
  return 0;
}
