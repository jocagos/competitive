#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

struct Card { char rank, suit;
  // Card& operator=( const Card& right ){
    
  // }
};
constexpr int MAXC = 60;
vector<Card> cards( MAXC );

int main()
{
  fastio;
  string line;
  // the order S-H-D-C happens to be the chars in descending order
  // so we pass a custom comparator (a lambda function) for the map 
  map<char, int, bool(*)(char, char)> suitCount([](char l, char r) { return l > r; });
  //unordered_map<char, int> suitCount { { 'S', 0 }, { 'H', 0 }, { 'D', 0 }, { 'C', 0 } } ;
  while( getline( cin, line ) ){
    Card card;
    int cardIdx = 0;
    // set<char> stoppedSuits;
    unordered_map<char, bool> stoppedSuits;
    int points = 0; // <- does not include points from rule 5,6,7
    int rule567points = 0;
        
    suitCount['S'] = 0;
    suitCount['H'] = 0;
    suitCount['D'] = 0;
    suitCount['C'] = 0;
        
    istringstream iss(line);
        
    while( iss >> card.rank >> card.suit ){
      suitCount[card.suit] ++;
      cards[cardIdx ++] = card;
    }
        
    for( int i = 0; i < cardIdx; ++ i /* auto &c : cards */ ){
      Card& c = cards[i];
      switch( c.rank ){
      case 'A': 
	points += 4;
	stoppedSuits[c.suit] = true;
	// stoppedSuits.insert( c.suit );
	break;
      case 'K': 
	points += 3;
	if( suitCount[c.suit] > 1 ) stoppedSuits[c.suit] = true;//.insert( c.suit );
	if( suitCount[c.suit] <= 1 ) points--;
	break;
      case 'Q': 
	points += 2;
	if( suitCount[c.suit] > 2 ) stoppedSuits[c.suit] = true;//.insert( c.suit );
	if( suitCount[c.suit] <= 2 ) points--;
	break;
      case 'J': 
	points += 1;
	if( suitCount[c.suit] <= 3 ) points--; 
	break;
      } 
    }
    for( auto &kv : suitCount ){
      switch( kv.second ){
      case 2: rule567points += 1; break;
      case 1: rule567points += 2; break;
      case 0: rule567points += 2; break;
      }
    }
        
    int totalPoints = points + rule567points;
        
    if( totalPoints < 14 ) cout << "PASS\n";
    else if( points >= 16 && stoppedSuits.size() == 4 ) cout << "BID NO-TRUMP\n";
    else if( totalPoints >= 14 ){
      int highest = suitCount['S'];
      char suit = 'S';
      //      vector<pair<char, int>> sco( suitCount.begin(), suitCount.end() );
      //sort( sco.begin(), sco.end(), []( pair<char, int>& left, pair<char, int>& right ){ return ( left.second != right.second ? left.second > right.second : left.first > right.first ); } );
      // // get highest suit count, in the order S-H-D-C:
      // for( auto &kv : suitCount ){
      // 	if( kv.second > highest ){
      // 	  highest = kv.second;
      // 	  suit = kv.first;
      // 	}
      // }
      
      cout << "BID " << sco[0].first << '\n';
    }
  }
  return 0;
}
