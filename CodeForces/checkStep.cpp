#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
  set<int> values;
  srand(time(NULL));
  int v;
  while( values.size() < 50 ){
    int r = rand() % 985 + 1;
    values.insert(r);
  }
  for( auto x : values ) cout << x << " ";
  cout << endl;
  return 0;
}
