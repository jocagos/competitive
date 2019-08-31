#include <iostream>
#include <cstring>

using namespace std;

int main(){
  int t, n, i, a[101], p;
  scanf("%d ", &t);
  for( i = 0; i < 100; ++i ) a[i] = 0;
  while(t--){
    scanf("%d ", &n);
    string s;
    p = 0; i = 1;
    while(n--){
      getline(cin, s);
      if( strncmp(s.c_str(), "LEFT", 4) == 0 ) a[i] = -1;
      else if( strncmp(s.c_str(), "RIGHT", 5) == 0 ) a[i] = 1;
      else if( strncmp(s.c_str(), "SAME AS", 7) == 0 )
	a[i] = a[stoi(s.substr(8))];
      p += a[i++];
    }
    printf("%d\n", p);
  }
  return 0;
}
