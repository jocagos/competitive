#include <iostream>
#include <vector>

using namespace std;

struct card{
  int val;
  char suit;

  card() : val(0), suit('0') {};
  card( int v, char s ) : val(v), suit(s) {};
};

typedef struct card Card;

int main(){
  int cards[13] = {3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 4, 5, 4};
  int n;
  scanf("%d", &n);
  vector<Card> v(n);
  int idx = 2;
  
  return 0;
}
