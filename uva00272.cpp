#include <iostream>

int main(){
    std::string s;
    std::cin >> s;
    for( auto i = 0; i < s.length(); ++i ){
        if( s.at(i) == '\"' && i % 2 ) s.at(i) = '`';
        else if( s.at(i) == '\"' && !(i % 2) ) s.at(i) = '\'';
    }
    std::cout << s;
    return 0;
}