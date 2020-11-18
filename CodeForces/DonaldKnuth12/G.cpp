#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void bucket_sort( string & str ){
  int buckets[10] {};
  for( char c : str )
    ++ buckets[c - '0'];
  int curr = 9;
  for( int i = 0; i < str.length(); ++ i ){
    if( buckets[curr] ){
      str[i] = curr + '0';
      buckets[curr] --;
    }
    else{
      curr --;
      i --;
    }
  }
}

int main(){
  int n {};
  cin >> n;
  vector<string> vs( n );
  for( int i = 0; i < n; ++ i )
    cin >> vs[i];
  for( auto& str : vs ){
    // sort each str
    bucket_sort( str );
  }
  sort( vs.begin(), vs.end(), [&]( string lhs, string rhs ) -> bool {
	       // sort by length
	       if( lhs.length() != rhs.length() )
		 return lhs.length() < rhs.length();
	       else{
		 // sort by ASCII, descending
		 for( int i = 0; i < lhs.length(); ++ i ){
		   if( lhs[i] != rhs[i] )
		     return lhs[i] > rhs[i];
		 }
	       }
	       return false;
	     } );
  for( auto& s : vs )
    cout << s;
  cout << endl;
  return 0;
}
