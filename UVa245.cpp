#include <bits/stdc++.h>

using namespace std;

int main(){
  char c, buf[100];
  int idx {};
  deque<string> ds;
  set<string> ss;
  bool is_num = false;
  while( (c = getchar()) != '0' ){
    if( isdigit( c ) ){
      is_num = true;
      buf[idx ++] = c;
    }
    else if( isalpha( c ) ){
      is_num = false;
      buf[idx ++] = c;
    }
    else{
      if( is_num ){
	string s = buf;
	int n = stoi( s );
	cout << ds[n - 1];
      }
      else if( idx != 0 ){
	string s = buf;
	if( ss.find( s ) != ss.end() ){
	  ss.emplace( s );
	  ds.emplace_front( s );
	}
	cout << s;
      }
      cout << c;
      is_num = false;
    }
  }
  return 0;
}
