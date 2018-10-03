#include <iostream>

int main(){
    std::string s;
    bool f = true;
    while(getline(std::cin, s) ){
        for( auto i = 0; i < s.length(); ++i ){
            if( s.at(i) == '\"' && f ) std::cout << "``", f = false;
            else if( s.at(i) == '\"' ) std::cout << "\'\'", f = true;
            else std::cout << s.at(i);
        }
    std::cout.flush();
    }
    return 0;
}