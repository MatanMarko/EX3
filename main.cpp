#include "board.hpp"
#include "catan.hpp"
#include "player.hpp"
#include <iostream>
using namespace std;
using namespace ariel;

// int main() {
//     ariel::Board board;
//     ariel::Player p1("Matan");
//     ariel::Player p2("Yael");
//     ariel::Player p3("Shir");
//     ariel::Catan catan(p1, p2, p3);
//     board.printBoard();
//     catan.placeSettlement_startGame(0, 1);
//     board.printBoard();
//     catan.placeSettlement_startGame(1, 2);
//     board.printBoard();
//     catan.placeRoad_startGame(0, 4, p1);
//     board.printBoard();
//     catan.placeRoad_startGame(1, 4, p2);
//     board.printBoard();
//     return 0;
// }

int main() {
    ariel::Board board;
    ariel::Player p1("Matan");
    ariel::Player p2("Yael");
    ariel::Player p3("Shir");
    vector<Player*> players = {&p1, &p2, &p3};
    ariel::Catan catan(p1, p2, p3);
    Spot spot;

    for(unsigned int i=0; i<=2; i++){
        catan.printBoard();
        cout <<"Place the 1st Settelment " << players[i]->getName() << endl;
        catan.placeSettlement(*players[i]);
        catan.printBoard();
        cout <<"Place the 1st road " << players[i]->getName() << endl;
        catan.placeRoad(*players[i]);
        catan.endTurn();
    }
}