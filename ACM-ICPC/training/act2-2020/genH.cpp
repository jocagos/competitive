#include <iostream>

using namespace std;
constexpr int MAXN = 1000010;
long long int vals[MAXN] {};
long long int diffs[MAXN] {};

void gen(){
  vals[0] = 0;
  vals[1] = 2;
  diffs[0] = 0;
  diffs[1] = vals[1] - vals[0];
  for( int i = 2; i < MAXN; ++ i ){
    vals[i] = vals[i - 1] + i * 2 + i - 1;
    diffs[i] = vals[i] - vals[i - 1];
  }
}

int main(){
  gen();
  for( int i = 0; i < 100; ++ i )
    cout << i << ": " << vals[i] << " " << diffs[i] << endl;
  return 0;
}
