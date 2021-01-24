#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

struct Date{
  int day, month, year;
  string str;
  Date( int yy = 0, int mm = 0, int dd = 0, string s = "" ) : day(dd), month(mm), year(yy), str(s) {}
};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  cin >> n;
  vector<Date> dates( n );
  for( int i = 0; i < n; ++ i )
    cin >> dates[i].str >> dates[i].day >> dates[i].month >> dates[i].year;
  sort( dates.begin(), dates.end(),
	[]( Date& lhs, Date& rhs ) -> bool {
	  if( lhs.year != rhs.year )
	    return lhs.year > rhs.year;
	  else if( lhs.month != rhs.month )
	    return lhs.month > rhs.month;
	  else if( lhs.day != rhs.day )
	    return lhs.day > rhs.day;
	  else
	    return lhs.str > rhs.str;
	});
  cout << dates[0].str << '\n' << dates.back().str << '\n';
  return 0;
}
