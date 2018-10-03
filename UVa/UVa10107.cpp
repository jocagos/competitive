#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  vector<long long> v;
  long long t;
  while( scanf("%lld ", &t) != EOF ){
    v.push_back(t);
    if( v.size() % 2 ){
      nth_element(v.begin(),v.begin()+(v.size()-1)/2, v.end());
      cout << v[v.size()/2] << endl;
    }
    else{
      long long ans = 0;
      nth_element(v.begin(), v.begin()+(v.size()-1)/2, v.end());
      ans += v[(v.size()-1)/2];
      nth_element(v.begin(), v.begin()+(v.size()-1)/2+1, v.end());
      ans += v[(v.size()-1)/2+1];
      cout << ans/2 << endl;
    }
  }
  return 0;
}
