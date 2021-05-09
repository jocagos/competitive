#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
constexpr double EPS = 1e-6, pi = acos(-1);

int main(){
  int p {}, a {}, b {}, c {}, d {}, n {};
  while( scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n) == 6 ){
    double diff {}, ma {-1e30};
    double per_a {}, per_c {};
    double vals_sin_an[400] {}, vals_sin_cn[400] {}, vals_cos_an[400] {}, vals_cos_cn[400] {}, vals_alpha[400] {}, vals_gamma[400] {};
    per_a = fmod( a, 2 * pi );
    per_c = fmod( c, 2 * pi );
    bool keep_a {true}, keep_c {true};
    int times_a {1}, times_c {1};
    for( int i = 1; i <= 360; ++ i ){
      vals_alpha[i] = vals_alpha[i - 1] + per_a;
      vals_gamma[i] = vals_gamma[i - 1] + per_c;
      if( vals_alpha[i] >= 2 * pi )
	vals_alpha[i] -= 2 * pi;
      if( keep_a and i != 1 and (fabs(vals_alpha[i] - vals_alpha[1]) < EPS)  )
	keep_a = false;
      if( keep_a ) ++ times_a;
      if( keep_c and i != 1 and (fabs(vals_gamma[i] - vals_gamma[1]) < EPS)  )
	keep_c = false;
      if( keep_c ) ++ times_c;
    }
    fprintf( stderr, "per_a = %.6lf\nper_c = %.6lf\ntimes_a = %d\ntimes_c = %d\n", per_a, per_c, times_a, times_c );
    // something after this causes an issue
    // need to re-do the period thing for sine and cosine
    // also consider non-discrete periods/continuous periods
    times_a = min( times_a, 360 );
    times_c = min( times_c, 360 );
    for( int i = 1; i <= times_a; ++ i ){
      vals_sin_an[i] = sin( vals_alpha[i] );
      vals_cos_an[i] = cos( vals_alpha[i] );
    }
    for( int i = 1; i <= times_c; ++ i ){
      vals_sin_cn[i] = sin( vals_gamma[i] );
      vals_cos_cn[i] = cos( vals_gamma[i] );
    }
    double sin_b = sin( b ), cos_b = cos( b ), sin_d = sin( d ), cos_d = cos( d );
    for( int i = 1; i <= n; ++ i ){
      double val = p *
	(vals_sin_an[n % times_a] * cos_b
	 + vals_cos_an[n % times_a] * sin_b
	 + vals_cos_cn[n % times_c] * cos_d
	 - vals_sin_cn[n % times_c] * sin_d + 2);
      diff = max( diff, ma - val );
      ma = max( ma, val );
    }
    printf("%.6lf\n", diff);
  }
  return 0;
}
