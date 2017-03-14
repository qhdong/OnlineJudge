#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

//#define ONLINE_JUDGE
using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    const string POKER = "345678910JQKA2";
    const string KING_1 = "joker JOKER";
    const string KING_2 = "JOKER joker";
    
    string cards;
    while (getline(cin, cards)) {
        
        // two kings, the largets one
        if (cards.find(KING_1) != string::npos) {
            cout << KING_1 << endl;
            continue;
        }
        if (cards.find(KING_2) != string::npos) {
            cout << KING_2 << endl;
            continue;
        }
        
        auto pos = cards.find('-');
        string playerA = cards.substr(0, pos);
        string playerB = cards.substr(pos + 1);
        int numA = 1 + count(playerA.begin(), playerA.end(), ' ');
        int numB = 1 + count(playerB.begin(), playerB.end(), ' ');
        
        if (numA == numB) {
            auto firstA = playerA.substr(0, playerA.find(' '));
            auto firstB = playerB.substr(0, playerB.find(' '));
            if (POKER.find(firstA) > POKER.find(firstB)) {
                cout << playerA << endl;
            } else {
                cout << playerB << endl;
            }
        } else {
            if (numA == 4) {
                cout << playerA << endl;
            } else if (numB == 4) {
                cout << playerB << endl;
            } else {
                cout << "ERROR" << endl;
            }
        }
        
    }
    
    #ifdef ONLINE_JUDGE
    fclose(stdin);
    #endif
    
    return 0;
}
