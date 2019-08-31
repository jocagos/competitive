#include <bits/stdc++.h>

using namespace std;

class romans{
public:
  int i, v, x, l, c;

  romans() : i{}, v{}, x{}, l{}, c{} {};
  romans( int _i, int _v, int _x, int _l, int _c ) : i{_i}, v{_v}, x{_x}, l{_l}, c{_c} {};
  romans operator+( romans right ){
    return romans( this->i + right.i, this->v + right.v, this->x + right.x, this->l + right.l, this->c + right.c );
  };
  void operator=( romans right ){
    this->i = right.i;
    this->v = right.v;
    this->x = right.x;
    this->l = right.l;
    this->c = right.c;
  }
};
map<int, romans> ans {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  for( int n = 1; n <= 100; ++ n ){
    int p = n % 10;
    int i {}, v {}, x {}, l {}, c {};
    if( p == 4 ){
      i = 1;
      v = 1;
    }
    else if( p == 9 ){
      i = 1;
      x = 1;
    }
    else if( 1 <= p and p <= 3 )
      i = p;
    else if( p == 5 ) v = 1;
    else if( 6 <= p and p <= 8 ) v = 1, i = p - 5;
    p = n / 10;
    if( p == 4 ){
      x += 1;
      l += 1;
    }
    else if( p == 9 ){
      x += 1;
      c += 1;
    }
    else if( 1 <= p and p <= 3 )
      x += p;
    else if( 6 <= p and p <= 8 ){
      x += p - 5;
      l += 1;
    }
    else if( p == 5 ) l ++;
    else if( p == 10 ) c ++;
    romans s = romans( i, v, x, l, c );
    if( n > 1 ){
      ans[n] = s + ans[n - 1];
    }
    else ans[n] = s;
    cerr << "N is " << n << endl;
    cerr << "S is ( " << s.i << ", " << s.v << ", " << s.x << ", " << s.l << ", " << s.c << " )" << endl;
    cerr << "i: " << i << "\tans[n].i: " << ans[n].i << "\nv: " << v << "\tans[n].v: " << ans[n].v << "\nx: " << x << "\tans[n].x: " << ans[n].x << "\nl: " << l << "\tans[n].l: " << ans[n].l << "\nc: " << c << "\tans[n].c: " << ans[n].c << endl;
    cerr << "=============================================" << endl;
  }
  while( cin >> n, n ){
    cout << n << ": " << ans[n].i << " i, " << ans[n].v << " v, " << ans[n].x << " x, " << ans[n].l << " l, " << ans[n].c << " c\n";
  }
  return 0;
}
