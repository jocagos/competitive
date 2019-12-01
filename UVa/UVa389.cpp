#include <bits/stdc++.h>

using namespace std;
string line {};
string base;
char ans[8] {};
long long max_power {}, n {};
int mp[256] {}, pm[18] {};
int pows[100] {};

bool convert( int from, int to ){
  n = 0;
  int po = 1;
  for( unsigned i = base.length() - 1; 0 <= i and i <= base.length(); -- i ){
    n += mp[(int)base[i]] * po;
    po *= from;
  }
  max_power = 0;
  pows[max_power] = 1;
  while( pows[max_power] < n ){
    max_power ++;
    pows[max_power] = pows[max_power - 1] * to;
  }
  if( n == 0 ){
    ans[0] = '0';
    ans[1] = '\0';
    return true;
  }
  if( max_power > 7 )
    return false;
  else{
    for( int i = 0; i < max_power; ++ i ){
      ans[i] = pm[n / pows[max_power - (i + 1)]];
      n %= pows[max_power - (i + 1)];
    }
    ans[max_power] = '\0';
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for( int i = '0'; i <= '9'; ++ i )
    mp[i] = i - '0';
  for( int i = 'A'; i <= 'F'; ++ i )
    mp[i] = 10 + (i - 'A');
  for( int i = 0; i <= 16; ++ i ){
    if( i < 10 )
      pm[i] = i + '0';
    else
      pm[i] = 'A' + (i - 10);
  }
  string line {};
  while( getline( cin, line ) ){
    istringstream iss( line );
    int from {}, to {};
    iss >> base >> from >> to;
    if( convert( from, to ) ){
      cout << setw( 7 ) << ans << '\n';
    }
    else
      cout << setw(7) << "ERROR" << setw(1 ) << '\n';
  }
  return 0;
}
