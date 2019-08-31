#include <bits/stdc++.h>

using namespace std;

int main(){
  for( int i = 0; i < 1/*000000*/; ++ i ){
    string cmd("./nd << \"");
    cmd += to_string(i);
    cmd += "\" >> solutions.txt";
    system(cmd.c_str());
  }
  return 0;
}
