#include <iostream>
#include <vector>

using namespace std;

class Interval{
public:
  int l, r;
  string name;

  Interval( int _l = 0, int _r = 0, string _name = "" ) : l(_l), r(_r), name(_name) {};
  
};

int main(){
  int t;
  scanf("%d", &t);
  
  while( t-- ){
    int d, q, nquery;
    scanf("%d ", &d);
    string s;
    int l, r;
    vector<Interval> inters(d);
    for( int i = 0; i < d; ++i ) cin >> inters[i].name >> inters[i].l >> inters[i].r;
    scanf("%d", &q);
    while( q-- ){
      int count = 0, index = 0;
      index = 0;
      scanf("%d", &nquery);
      for( int i = 0; i < inters.size(); ++i ){
	if( count > 1 ) break;
	if( inters[i].l <= nquery and nquery <= inters[i].r ) count++, index = i;
      }
      if( count == 1 ) cout << inters[index].name << endl;
      else cout << "UNDETERMINED" << endl;
    }
    if( t ) cout << endl;
  }
  return 0;
}
