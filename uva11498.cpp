#include <stdio.h>

int main()
{
  int K = 1, N, M, X, Y;
  char ans1[] = "divisa";
  char ya1 = 'N';
  char ya2 = 'S';
  char xa1 = 'E';
  char xa2 = 'W';
  do{
    scanf("%d", &K);
    if( K == 0 )
      break;
    scanf("%d %d", &N, &M);
    while(K--){
      scanf("%d %d", &X, &Y);
      if( X == N or Y == M )
	printf("divisa\n");
      else{
	if( X > N and Y > M )
	  printf("NE\n");
	else if( X > N and Y < M )
	  printf("SE\n");
	else if( X < N and Y > M )
	  printf("NO\n");
	else if( X < N and Y < M )
	  printf("SO\n");
      }
    }
  }while(true);
  return 0;
}
  
