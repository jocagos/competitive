#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  while( cin >> n ){
    if( n == -1 ) break;
    int spd, hrs, miles = 0, sumHrs = 0;
    while( n-- ){
      cin >> spd >> hrs;
      miles += spd * (hrs - sumHrs);
      sumHrs = hrs;
    }
    cout << miles << " miles" << endl;
  }
  return 0;
}
