#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

int main(){
  int n;
  string s;
  scanf("%d", &n);
  cin >> s;
  map<string, int> two_grams;
  for( int i = 0; i < n-1; ++i ) two_grams[s.substr(i, 2)]++;
  pair<string, int> max_idx = *two_grams.begin();
  for( auto x : two_grams ) if( max_idx.second < x.second ) max_idx = x;
  cout << max_idx.first << endl;
  return 0;
}
