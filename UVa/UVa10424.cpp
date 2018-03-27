#include <iostream>
#include <cctype>

using namespace std;

int main(){
  string s1, s2;
  while( getline(cin, s1)){
    getline(cin, s2);
    int l = 0, r = 0;
    for( int i = 0; i < s1.length(); ++i ){
      if( isupper(s1[i]) ) l += s1[i]-'A'+1;
      else if( islower(s1[i])) l += s1[i]-'a'+1;
    }
    for( int i = 0; i < s2.length(); ++i ){
      if( isupper(s2[i]) ) r += s2[i]-'A'+1;
      else if( islower(s2[i])) r += s2[i]-'a'+1;
    }
    if( l % 9 ) l %= 9;
    else l = 9;
    if( r % 9 ) r %= 9;
    else r = 9;
    if( l >= r ) printf("%.2f %%\n", r * 100.0 / l);
    else printf("%.2f %%\n", l * 100.0 / r);
  }
  return 0;
}
