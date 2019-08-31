#include <iostream>
#include <cstdio>

using namespace std;

int months[] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main(){
  int t;
  scanf("%d ", &t);
  for( int i = 1; i <= t; ++i ){
    string s, sign;
    cin >> s;
    int days = stoi(s.substr(2, 2)),
      month = stoi(s.substr(0, 2)),
      year = stoi(s.substr(4)),
      gest = 280;
    bool leap = ( year % 400 == 0 || year % 100 != 0 && year % 4 == 0 ? true : false );
    if( leap ) months[1] = 29;
    else months[i] = 28;
    
    printf("%d %d/%d/%d %s\n", i, days, month, year, sign);
  }
  return 0;
}
