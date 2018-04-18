#include <iostream>
#include <cstring>
using namespace std;
// This solution takes about 0.14s/1.000s, it can be improved A LOT
int main(){
  int t;
  int vals[260];
  scanf("%d ", &t);
  while(t--){
    memset(vals, 0, sizeof vals);
    int k, v, sum = 0;
    char c;
    string line, lines {};
    scanf("%d ", &k);
    for( int i = 0; i < k; ++i ){
      scanf("%c %d ", &c, &v);
      vals[c+128] = v;
    }
    scanf("%d ", &k);
    for( int i = 0; i < k; ++i ){
      getline(cin, line);
      lines += line;
    }
    for( int i = 0; i < lines.size(); ++i ) sum += vals[lines[i]+128];
    printf("%d.%02d$\n", sum / 100, sum % 100);
  }
  return 0;
}
