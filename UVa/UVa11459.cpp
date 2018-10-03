#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
  int t;
  int board[101];
  scanf("%d ", &t);
  while(t--){
    int a, b, c;
    bool stop = false;
    memset(board, 0, sizeof board);
    scanf("%d %d %d ", &a, &b, &c);
    short players[a];
    fill_n(players, a, 1);
    int bot, top;
    for( int i = 0; i < b; ++i ){
      scanf("%d %d ", &bot, &top);
      board[bot] = top;
    }
    for( int i = 0, p = 0, tmp; i < c; ++i ){
      scanf("%d ", &tmp);
      if( !stop ) players[p] += tmp;
      if( !stop and players[p] > 100 ) players[p] = 100;
      if( !stop and board[players[p]] != 0 ) players[p] = board[players[p]];
      if( players[p] == 100 ) stop = true;
      if( !stop )p++; if( !stop) p %= a;
    }
    for( int i = 0; i < a; ++i ){
      printf("Position of player %d is %d.\n", i+1, players[i]);
    }
  }
  return 0;
}
