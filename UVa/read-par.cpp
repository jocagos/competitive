#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
  int a;
  cin >> a;
  cout << "A was " << a << endl;
  scanf("(%d)", &a);
  printf("Now a is (%d)\n", a);
  return 0;
}
