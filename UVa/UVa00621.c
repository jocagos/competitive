#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    char s[1024];
    scanf("%d", &n);
    while(n--){
        scanf("%s", s);
        int l = strlen(s);
        if( !strcmp(s, "1") || !strcmp(s, "4") || !strcmp(s, "78") ) printf("+\n");
        else if( s[l-1] == '5' && s[l-2] == '3' ) printf("-\n");
        else if( s[0] == '9' && s[l-1] == '4' ) printf("*\n");
        else if( s[0] == '1' && s[1] == '9' && s[2] == '0' ) printf("?\n");
        else printf("?\n");
    }
    return 0;
}