#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

bool cmp( char l, char r ){
  if( l >= 'a' and l <= 'z' and r >= 'a' and r <= 'z' ) return l < r;
  if( l >= 'A' and l <= 'Z' and r >= 'A' and r <= 'Z' ) return l < r;
  if( l >= 'a' and l <= 'z' ){
    return (l-('a'-'A')) < r;
  }
  else{
    return l <= (r-('a' - 'A'));
  }

}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    string s, t;
    cin >> s;
    sort(s.begin(), s.end(), cmp);
    do{ cout << s << endl;}
    while(next_permutation(s.begin(), s.end(), cmp));
  }
  return 0;
}
