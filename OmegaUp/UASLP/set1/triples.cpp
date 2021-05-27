#include <iostream>

using namespace std;
constexpr int MAXN = 50050;
int vals[MAXN] {}, triples[MAXN] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, idx {};
  cin >> n;
  for( int i = 0; i < n; ++ i ){
    cin >> vals[i];
    if( vals[i] % 3 == 0 )
      triples[idx ++] = i + 1;
  }
  if( idx ){
    cout << idx << '\n';
    for( int i = 0; i < idx; ++ i )
      cout << triples[i] << (i + 1 == idx ? "\n" : " ");
  }
  else
    cout << "No hay triples.\n";
  return 0;
}
