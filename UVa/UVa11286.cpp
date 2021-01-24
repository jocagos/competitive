#include <cstdio>
#include <unordered_map>
#include <algorithm>

using namespace std;
constexpr int MAXC = 5;

int main(){
  int n {}, tmp {};
  int courses[MAXC] {};
  long long key {};
  while( scanf("%d", &n), n ){
    unordered_map<long long, int> popularity;
    for( int i = 0; i < n; ++i ){
      key = 0LL;
      for( int j = 0; j < MAXC; ++j )
	scanf("%d", &courses[j]);
      sort(courses, courses + MAXC);
      for( int course : courses ){
	key *= 1000;
	key += course;
      }
      popularity[key] ++;
    }
    int m = 0, frosh = 0;
    for( auto& x : popularity ) if( x.second > m ) m = x.second;
    for( auto& x : popularity ) if( x.second == m ) frosh += x.second;
    printf("%d\n", frosh);
  }
  return 0;
}
