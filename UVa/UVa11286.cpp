#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
  int n;
  while( scanf("%d", &n), n ){
    vector<int> courses(5);
    string key {};
    map<string, int> popularity;
    for( int i = 0, tmp; i < n; ++i ){
      courses.clear();
      key.clear();
      for( int j = 0; j < 5; ++j ){
	scanf("%d", &tmp);
	courses.push_back(tmp);
      }
      sort(courses.begin(), courses.end());
      for( auto& x : courses ) key += to_string(x);
      popularity[key]++;
    }
    int m = 0, frosh = 0;
    for( auto& x : popularity ) if( x.second > m ) m = x.second;
    for( auto& x : popularity ) if( x.second == m ) frosh += x.second;
    cout << frosh << endl;
  }
  return 0;
}
