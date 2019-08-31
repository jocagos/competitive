/* UVa 11661 - Burger Time? */
#include <stdio.h>

int main( void ){
    int l = -1, i, d, min = 0;
    char f, c;
    while( l != 0 ){
        scanf("%d", &l);
        if( l != 0 ) scanf(" ");
        d = 0;
        f = '.';
        min = l;
        if( !l ) break;
        for( i = 0; i < l; ++i ){
            scanf("%c", &c);
            if( c == 'z' || c == 'Z' ){
                min = 0;
                if( i+1 != l ) scanf("%*s");
                break;
            }
            if( c == 'R' ){
                if( f == 'D' )
                    if( d < min )
                        min = d;
                    d = 1;
                    f = 'R';
                    continue;
            }
            if( c == 'D' ){
                if( f == 'R' )
                    if( d < min )
                        min = d;
                d = 1;
                f = 'D';
                continue;
            }
            d++;
        }
        printf("%d\n", min);
    }
    return 0;
}