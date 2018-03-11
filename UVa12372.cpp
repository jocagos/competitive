#include <iostream>
#define inRange(a, b, x) (((a) <= (x)) && ((x) <= (b)))
#define optimize_ios() ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main(){
    int T, L, W, H;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i){
        scanf("%d %d %d", &L, &W, &H);
        printf("Case %d: %s\n", i+1, ( inRange(0, 20, L) && inRange(0, 20, W) && inRange(0, 20, H) ? "good" : "bad" ) );
    }
    return 0;
}