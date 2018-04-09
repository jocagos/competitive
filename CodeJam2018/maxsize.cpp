#include <cstdlib>
#include <cstdio>
using namespace std;

int main(){
  int * arr = new int[1 << 30];
  printf("Done! allocated space for %ld elements! Space used is %ld bytes \n", 1L << 30, (1L << 30)*sizeof(int) );
  return 0;
}
