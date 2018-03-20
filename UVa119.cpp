#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  bool first = false;
  while(scanf("%d", &n) != EOF){
    if( first ) cout << endl;
    else first = true;
    int m, f;
    vector<string> names;
    map<string, int> p;
    string s;
    for( int i = 0; i < n; ++i ){
      cin >> s;
      p.insert({s, 0});
      names.push_back(s);
    }
    for( int i = 0; i < n; ++i ){
      cin >> s;
      cin >> m;
      cin >> f;
      if( f != 0 ) p[s] -= m / f * f;
      for( int j = 0; j < f; ++j ){
        cin >> s;
        p[s] += m / f;
      }
    }
    for( int i = 0; i < names.size(); ++i ) cout << names[i] << " " << p[names[i]] << endl;
    
  }
  
  return 0;
}
