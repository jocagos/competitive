#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  string s {};
  getline( cin, s );
  tc = stoi( s );
  while( tc -- ){
    getline( cin, s );
    stack<int> pars;
    bool valid = true;
    for( int i = 0; i < (int)s.length() and valid; ++ i ){
      if( s[i] == '(' or s[i] == '[' )
	pars.push( i );
      else if( s[i] == ')' ){
	if( pars.empty() )
	  valid = false;
	else{
	  char c = s[pars.top()];
	  pars.pop();
	  if( c != '(' )
	    valid = false;
	}
      }
      else if( s[i] == ']' ){
	if( pars.empty() )
	    valid = false;
	else{
	  char c = s[pars.top()];
	  pars.pop();
	  if( c != '[' )
	    valid = false;
	}
      }
    }
    if( not pars.empty() )
      valid = false;
    if( valid )
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
