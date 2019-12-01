#include <bits/stdc++.h>

using namespace std;
using namespace chrono;
constexpr auto gest = chrono::hours(280 * 24);

int months[] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for( int i = 1; i <= t; ++i ){
    string sign, s;
    cin >> s;
    int tmp = s[4];
    s[4] = '\0';
    int days = atoi(s.c_str() + 2);
    s[4] = tmp;
    tmp = s[2];
    s[2] = '\0';
    int month = atoi(s.c_str());
    s[2] = tmp;
    int year = atoi(s.c_str() + 4) - 1970;
    time_point<system_clock, duration<long long>>
      cur_date( chrono::days(;
    
    cout << "i: " <<  i << "\nd: " << days << "\nm: " << month << "\ny: " << year << "\ns: " << sign << endl;
  }
  // cout << "gest = " << gest.count() << endl;
  return 0;
}
