#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;
constexpr int MAXN = 100;
constexpr char ops[] = {'*', '/', '+', '-'};
int precedence[255] {};

inline bool is_in( char c ){
  for( char o : ops )
    if( c == o ) return true;
  return false;
}

int main(){
  precedence['*'] = precedence['/'] = 1; // we do not need to set another precedence
  char buf[MAXN] {}; // line buffer
  int tc {};
  fgets( buf, MAXN, stdin );
  sscanf( buf, "%d", &tc );
  fgets( buf, MAXN, stdin ); // read blank
  while( tc -- ){
    fgets( buf, MAXN, stdin );
    stack<char> operators {};
    while( buf[0] != '\n' ){ // blank
      if( '0' <= buf[0] and buf[0] <= '9' )
	printf("%c", buf[0]);
      else if( buf[0] == '*' or buf[0] == '/' or buf[0] == '+' or buf[0] == '-' ){
	while( not operators.empty() and is_in( operators.top() ) and
	       ( (precedence[(int)operators.top()] > precedence[(int)buf[0]])
		 or (precedence[(int)operators.top()] == precedence[(int)buf[0]]))){
	  printf("%c", operators.top());
	  operators.pop();
	}
	operators.emplace( buf[0] );
      }
      else if( buf[0] == '(' )
	operators.emplace( buf[0] );
      else if( buf[0] == ')' ){
	while( not operators.empty() and operators.top() != '(' ){
	  printf("%c", operators.top());
	  operators.pop();
	}
	if( not operators.empty() and operators.top() == '(' )
	  operators.pop();
      }
      auto x = fgets( buf, MAXN, stdin );
      if( x == NULL ) break;
    }
    while( not operators.empty() ){
      printf("%c", operators.top());
      operators.pop();
    }
    printf("\n");
    if( tc )
      printf("\n");
  }
  return 0;
}
