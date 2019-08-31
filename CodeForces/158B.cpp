#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int v[5] = {0, 0, 0, 0, 0};
    for( int i = 0, t; i < n; ++i ){ scanf("%d", &t); v[t]++; }
    int ans {};
    ans += v[4] + v[3];
    if( v[1] > v[3] ) v[1] -= v[3];
    else v[1] = 0;
    if( v[2] % 2 == 0 ) ans += v[2] / 2;
    else ans += v[2] / 2 + 1, v[1] -= 2;
    if( v[1] > 0 )
        if( v[1] % 4 == 0 ) ans += v[1] / 4;
        else ans += v[1] / 4 + 1;
    printf("%d\n", ans);
    return 0;
}