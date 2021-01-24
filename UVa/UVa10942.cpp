#include <iostream>
#include <iomanip>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

// offset of 1 zero so we can access it directly with the month
int months_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool is_leap( int year ){
  if( year % 400 == 0 )
    return true;
  else if( year % 100 == 0 )
    return false;
  else if( year % 4 == 0 )
    return true;
  else
    return false;
}

bool is_valid( int day, int month, int year ){
  if( month < 1 or month > 12 )
    return false;
  bool leap = is_leap( year );
  if( day < 1 or day > months_days[month] + ( leap and month == 2 ? 1 : 0 ) )
    return false;
  return true;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  int c {};
  int vals[3] {};
  cin >> tc;
  while( tc -- ){
    cin >> c;
    for( int i = 0; i < 3; ++ i )
      cin >> vals[i];
    sort( vals, vals + 3 );
    c = (c % 4) * 100;
    // sorted as YYYY, MM, DD
    vector<tuple<int, int, int>> dates;
    do{
      if( is_valid( vals[0], vals[1], vals[2] + c ) ){
	dates.emplace_back( vals[2] + c, vals[1], vals[0] );
      }
    } while( next_permutation( vals, vals + 3 ) );
    if( (int)dates.size() > 0 ){
      sort( dates.begin(), dates.end() );
      int y, m, d;
      tie( y, m, d ) = dates[0];
      if( y >= 100 )
	y %= 100;
      cout << setw( 2 ) << setfill( '0' ) << y << " "
	   << setw( 2 ) << setfill( '0' ) << m << " "
	   << setw( 2 ) << setfill( '0' ) << d << "\n";
    }
    else
      cout << "-1\n";
  }
  return 0;
}
