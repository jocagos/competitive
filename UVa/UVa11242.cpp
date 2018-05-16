#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int f, r;
  while( scanf("%d %d", &f, &r), f ){
    vector<int> front_teeth(f);
    vector<int> rear_teeth(r);
    for( int i = 0; i < f; ++ i ) scanf("%d", &front_teeth[i]);
    for( int i = 0; i < r; ++ i ) scanf("%d", &rear_teeth[i]);
    vector<double> ratios;
    for( int i = 0; i < front_teeth.size(); ++ i ){
      for( int j = 0; j < rear_teeth.size(); ++ j ){
	ratios.emplace_back(1.0 * rear_teeth[j] / front_teeth[i]);
      }
    }
    sort( ratios.begin(), ratios.end());
    double maxSpread = 0.0;
    for( int i = 0; i < ratios.size() - 1; ++i ) maxSpread = max( maxSpread, ratios[i+1] / ratios[i] );
    printf("%.2f\n", maxSpread);
  }
  return 0;
}
