#include <iostream>

using namespace std;

int getDamage( string s ){
  int power = 1, damage = 0;
  for( int i = 0; i < s.length(); ++i ){
    if( s[i] == 'C' ) power <<= 1;
    if( s[i] == 'S' ) damage += power;
  }
  return damage;
}

int main(){
  int t;
  scanf("%d ", &t);
  for( int i = 1; i <= t; ++i ){
    printf("Case #%d: ", i);
    string s;
    int d;
    scanf("%d ", &d);
    cin >> s;
    int minDamage(0), actualDamage(0), currentDamage(1);
    for( int j = 0; j < s.length(); ++j ){
      if( s[j] == 'C' ) currentDamage <<= 1;
      if( s[j] == 'S' ){
	actualDamage += currentDamage;
	minDamage++;
      }
    }
    if( minDamage > d ){
      printf("IMPOSSIBLE\n");
      continue;
    }
    if( currentDamage < d ){
      printf("0\n");
      continue;
    }
    if( s.length() == 2 ){
      s = to_string(s[1]) + to_string(s[0]);
      if( getDamage(s) > d ){
	printf("IMPOSSIBLE\n");
	continue;
      }
      else{
	printf("1\n");
	continue;
      }
    }
  }
  return 0;
}
