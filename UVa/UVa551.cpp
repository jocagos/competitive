#include <iostream>
#include <string>
#include <stack>

using namespace std;
constexpr char OPEN_PAREN = '#', CLOSED_PAREN = '$';
// constexpr int MAX_LEN = 3030;

int main(){
  // char buf[MAX_LEN] {};
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string buf {};
  while( getline( cin, buf ) ){
    int idx {}, pos {1}, len = buf.length();
    string str( len, '.' );
    for( int i = 0; i < len; ++ i ){
      if( buf[i] == '(' and i + 1 < len and buf[i + 1] == '*' ){
	if( i + 2 < len and buf[i + 2] == ')' ){
	  str[idx] = OPEN_PAREN;
	  str[idx + 1] = ')';
	  idx += 2;
	  i += 2;
	}
	else{
	  str[idx] = OPEN_PAREN;
	  ++ idx;
	  ++ i;
	}
      }
      else if( buf[i] == '*' and i + 1 < len and buf[i + 1] == ')' ){
	str[idx] = CLOSED_PAREN;
	++ idx;
	++ i;
      }
      else
	str[idx ++] = buf[i];
    }
    len = idx;
    str = str.substr( 0, idx );
    idx = 0;
    stack<char> st {};
    bool able = true;
    for( idx = 0; idx < len and able; ++ idx, ++ pos ){
      // cerr << str << endl;
      // for( int i = 0; i < idx; ++ i )
      // 	cerr << " ";
      // cerr << "^" << endl;
      // if( not st.empty() )
      // 	cerr << "Top: " << st.top() << endl;
      // else
      // 	cerr << "Empty stack" << endl;
      if( str[idx] == '<' or str[idx] == '{' or str[idx] == '[' or str[idx] == '(' or str[idx] == '#' )
	st.emplace( str[idx] );
      else if( str[idx] == '>' ){
	if( (not st.empty()) and (st.top() == '<') )
	  st.pop();
	else
	  able = false;
      } // end if c == '>'
      else if( str[idx] == '}' ){
	if( (not st.empty()) and (st.top() == '{') )
	  st.pop();
	else
	  able = false;
      } // end if c == '}'
      else if( str[idx] == ']' ){
	if( (not st.empty()) and (st.top() == '[') )
	  st.pop();
	else
	  able = false;
      } // end if c == ']'
      else if( str[idx] == '$' ){
	if( (not st.empty()) and (st.top() == '#') )
	  st.pop();
	else
	  able = false;
      } // end if c == '$'
      else if( str[idx] == ')' ){
	if( (not st.empty()) and (st.top() == '(') )
	  st.pop();
	else
	  able = false;
      } // end if c == ')'
    } // end for
    if( not st.empty() ){
      if( able )
	++ idx;
      able = false;
    }
    if( able )
      cout << "YES\n";
    else
      cout << "NO " << idx << '\n';
    // cerr << "--------------------------------------------------" << endl;
  }
  return 0;
}
