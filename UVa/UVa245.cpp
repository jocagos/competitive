/*
 * Possible speed up by changing the indexes of the words only
 * then looking for the nth key in linear time.
 * Right now: linear time times the extract and put at the front
 * so up to quadratic time
 */

#include <bits/stdc++.h>

using namespace std;

int main(){
  char c, buf[100];
  int idx {};
  deque<string> ds;
  set<string> ss;
  bool is_num = false;
  while( (c = getchar()) != EOF ){
    // cerr << "Read >" << c << "<" << endl;
    if( isdigit( c ) ){
      if( not is_num and c == '0' ) break;
      // cerr << "Digit" << endl;
      is_num = true;
      buf[idx ++] = c;
    }
    else if( isalpha( c ) ){
      // cerr << "Alpha" << endl;
      is_num = false;
      buf[idx ++] = c;
    }
    else{
      if( is_num ){
	buf[idx] = '\0';
	idx = 0;
	string s = buf;
	int n = stoi( s );
	s = ds[n - 1];
	// cerr << "s is now >" << s << "<" << endl;
	// cerr << "Index is " << n << endl;
	// cerr << "ds[" << n - 1 << "] = >" << ds[n - 1] << "<" << endl;
	ds.erase( ds.begin() + n - 1 );
	ds.emplace_front( s );
	// cerr << "Read " << s << " as " << n << endl;
	// cerr << "Current size of deque is " << ds.size() << endl;
	cout << s;
      }
      else if( not isalnum( c ) ){
	buf[idx] = '\0';
	idx = 0;
	string s = buf;
	// cerr << "C is >" << c << "<" << endl;
	// cerr << "s is >" << s << "<" << endl;
	if( s != "" and ss.find( s ) == ss.end() ){
	  ss.emplace( s );
	  ds.emplace_front( s );
	}
	else if( s != "" ){
	  auto it = find( begin( ds ), end( ds ), s );
	  ds.erase( it );
	  ds.emplace_front( s );
	}
	// cerr << "DEQUE IS:\n" << endl;
	// for( auto word : ds ) cerr << ">" << word << "< ";
	// cerr << endl;
	cout << s;
      }
      cout << c;
      is_num = false;
    }
  }
  return 0;
}
