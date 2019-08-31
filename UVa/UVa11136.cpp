#include <iostream>
#include <set>

using namespace std;

int main(){
  int n;
  while( scanf("%d", &n), n ){
    multiset<int> hoax;
    long long sum = 0;
    for( int i = 0, tmp; i < n; ++i ){
      cin >> tmp;
      for( int j = 0, t; j < tmp; ++j ){
	cin >> t;
	hoax.insert(t);
      }
      auto h = --hoax.end();
      auto l = hoax.begin();
      sum += *h-*l;
      hoax.erase(l);
      hoax.erase(h);
    }
    cout << sum << endl;
  }
  return 0;
}
