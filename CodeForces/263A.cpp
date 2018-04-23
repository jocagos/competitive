#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int x = 0, y = 0;
    for( int i = 1, tmp = 0; i < 6; ++i){
        for( int j = 1; j < 6; ++j){
            scanf("%d", &tmp);
            if( tmp ){
                x = i;
                y = j;
                goto end;
            }
        }
    }
    end:
    printf("%d\n", abs(x-3)+abs(y-3));
    return 0;
}