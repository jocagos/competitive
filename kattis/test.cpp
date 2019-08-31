#include <iostream>

using namespace std;

typedef pair<int, int> point;
typedef pair<point, int> iii;

int main(){
  point p(1, 2);
  iii q(p, 3);
  cout << "p(" << p.first << ", " << p.second << endl;
  cout << "q((" << q.first.first << ", " << q.first.second << "), " << q.second << ")" << endl;
  return 0;
}
