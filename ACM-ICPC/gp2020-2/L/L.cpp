#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 21;

int main(){
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);
  int L {}, C {};
  scanf("%d %d\n", &L, &C);
  int S = min(15, max(L, C));
  char ** grid = new char*[L];
  for( int i = 0; i < L; ++ i )
    grid[i] = new char[C + 1];
  for( int i = 0; i < L; ++ i )
    scanf("%s\n", grid[i]);
  int N {};
  scanf("%d\n", &N);
  char ** words = new char*[N];
  for( int i = 0; i < N; ++ i )
    words[i] = new char[S + 1];
  for( int i = 0; i < N; ++ i )
    scanf("%s\n", words[i]);

  vector<vector<bitset<MAXN>>> words_used( MAXN, vector<bitset<MAXN>>( MAXN, bitset<MAXN>() ) );
  
  // for( int i = 0; i < L; ++ i )
  //   printf("%s\n", grid[i]);
  // for( int i = 0; i < N; ++ i )
  //   printf("%s\n", words[i]);
  for( int i = 0; i < MAXN; ++ i )
    delete[] grid[i];
  delete[] grid;
  for( int i = 0; i < N; ++ i )
    delete[] words[i];
  delete[] words;
  return 0;
}
