#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

int main(){
  int t;
  scanf("%d ", &t);
  map<string, int> haab {
    {"pop", 0}, {"no", 20}, {"zip", 40}, {"zotz", 60}, {"tzec", 80}, {"xul", 100}, {"yoxkin", 120}, {"mol", 140}, {"chen", 160}, {"yax", 180}, {"zac", 200}, {"ceh", 220}, {"mac", 240}, {"kankin", 260}, {"muan", 280}, {"pax", 300}, {"koyab", 320}, {"cumhu", 340}, {"uayet", 360}
  };
  // akbal, kan, chicchan, cimi, manik, lamat, muluk, ok, chuen, eb, ben, ix, mem, cib, caban, eznab, canac, ahau
  string tzolkin[20] { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
  cout << t << endl;
  while(t--){
    string line;
    getline(cin, line);
    istringstream iss(line);
    int days = 0;
    string s;
    iss >> s;
    days += stoi(s);
    iss >> s;
    days += haab[s];
    iss >> s;
    days += stoi(s) * 365;
    cout << days % 13 + 1 << " " << tzolkin[days%20] << " " << days / 260 << endl;
  }
  return 0;
}
