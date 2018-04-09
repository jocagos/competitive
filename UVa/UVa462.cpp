#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

struct Card { char rank, suit; };

int main()
{
    string line;
    
    // the order S-H-D-C happens to be the chars in descending order
    // so we pass a custom comparator (a lambda function) for the map 
    map<char, int, bool(*)(char, char)> suitCount([](char l, char r) { return l > r; });
    
    while (getline(cin, line)) {
        Card card;
        vector<Card> cards;
        set<char> stoppedSuits; 
        int points = 0; // <- does not include points from rule 5,6,7
        int rule567points = 0;
        
        suitCount['S'] = 0;
        suitCount['H'] = 0;
        suitCount['D'] = 0;
        suitCount['C'] = 0;
        
        istringstream iss(line);
        
        while (iss >> card.rank >> card.suit) {
            suitCount[card.suit]++;
            cards.push_back(card);
        }
        
        for (auto &c : cards) {
            switch (c.rank) {
                case 'A': 
                    points += 4; 
                    stoppedSuits.insert(c.suit);
                    break;
                case 'K': 
                    points += 3;
                    if (suitCount[c.suit] >  1) stoppedSuits.insert(c.suit);
                    if (suitCount[c.suit] <= 1) points--;
                    break;
                case 'Q': 
                    points += 2;
                    if (suitCount[c.suit] >  2) stoppedSuits.insert(c.suit);
                    if (suitCount[c.suit] <= 2) points--;
                    break;
                case 'J': 
                    points += 1;
                    if (suitCount[c.suit] <= 3) points--; 
                    break;
            } 
        }
        for (auto &kv : suitCount) {
            switch (kv.second) {
                case 2: rule567points += 1; break;
                case 1: rule567points += 2; break;
                case 0: rule567points += 2; break;
            }
        }
        
        int totalPoints = points + rule567points;
        
        if (totalPoints < 14) {
            cout << "PASS" << endl;
        } else if (points >= 16 && stoppedSuits.size() == 4) {
            cout << "BID NO-TRUMP" << endl;
        } else if (totalPoints >= 14) {
            int highest = 0;
            char suit;
            // get highest suit count, in the order S-H-D-C:
            for (auto &kv : suitCount) {
                if (kv.second > highest) {
                    highest = kv.second;
                    suit = kv.first;
                }
            }
                
            cout << "BID " << suit << endl;
        }
    }
    return 0;
}