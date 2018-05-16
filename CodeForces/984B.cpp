#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    vector<vector<char>> mat(m);
    for( int i = 0; i < m; ++ i ) mat[i].resize(n);
    for( int i = 0; i < m; ++ i ){
        for( int j = 0; j < n; ++ j ) scanf("%c", &mat[i][j] );
        scanf("\n");
    }
    bool valid = true;
    int count = 0;
    for( int i = 0; i < m and valid; ++ i ){
        for( int j = 0; j < n and valid; ++ j ){
            if( i == 0 ){
                
            }
        }
    }
    return 0;
}