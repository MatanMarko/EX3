// #include "board.hpp"
// #include "catan.hpp"
// #include "player.hpp"
// #include "spot.hpp"

// #include <vector>
// #include <iostream>

// using namespace std;
// using namespace ariel;

// int main() {
//     ariel::Board board;
//     ariel::Player p1("Matan");
//     ariel::Player p2("Yael");
//     ariel::Player p3("Shir");
//     ariel::Catan catan(p1, p2, p3);
//     Spot spot;

//     catan.printBoard();                 // the first turn of player 1
//     cout <<  p1.getName() << ", place your first Settelment " << endl;
//     catan.placeSettlement(p1);
//     catan.printBoard();
//     cout <<  p1.getName() << ", place your first road (source spot and destination spot) " << endl;
//     catan.placeRoad(p1);
//     catan.endTurn();

//     catan.printBoard();                 // the first turn of player 2
//     cout <<  p2.getName() << ", place your first Settelment " << endl;
//     p2.printResources();
//     catan.placeSettlement(p2);
//     p2.printResources();
//     catan.printBoard();
//     cout <<  p2.getName() << ", place your first road (source spot and destination spot) " << endl;
//     catan.placeRoad(p2);
//     p2.printResources();
//     catan.printBoard();
//     catan.endTurn();

//     catan.printBoard();                 // the first turn of player 3
//     cout <<  p3.getName() << ", place your first Settelment " << endl;
//     catan.placeSettlement(p3);
//     cout <<  p3.getName() << ", place your first road (source spot and destination spot) " << endl;
//     catan.placeRoad(p3);
//     catan.printBoard();
//     catan.endTurn();    //pass the turn to player 1
//     catan.endTurn();    //pass the turn to player 2
//     catan.endTurn();    //pass the turn to player 3

//     catan.printBoard();                 // the second turn of player 3
//     cout <<  p3.getName() << ", place your second Settelment " << endl;
//     catan.placeSettlement(p3);
//     cout <<  p3.getName() << ", place your second road (source spot and destination spot) " << endl;
//     catan.placeRoad(p3);
//     catan.endTurn();    //pass the turn to player 1
//     catan.endTurn();    //pass the turn to player 2

//     catan.printBoard();                 // the second turn of player 2
//     cout <<  p2.getName() << ", place your second Settelment " << endl;
//     catan.placeSettlement(p2);
//     cout <<  p2.getName() << ", place your second road (source spot and destination spot) " << endl;
//     catan.placeRoad(p2);
//     catan.endTurn();    //pass the turn to player 3
//     catan.endTurn();    //pass the turn to player 1

//     catan.printBoard();                 // the second turn of player 1
//     cout <<  p1.getName() << ", place your second Settelment " << endl;
//     catan.placeSettlement(p1);
//     cout <<  p1.getName() << ", place your second road (source spot and destination spot) " << endl;
//     catan.placeRoad(p1);
//     catan.endTurn();    //pass the turn to player 2

//     p2.addResource("Ore");
//     p2.addResource("Ore");
//     p2.addResource("Ore");
//     p2.addResource("Grain");
//     p2.addResource("Grain");
//     catan.printBoard();
//     p2.printResources();
//     cout << "" << endl;
//     cout << "where do you want to place the city?" << endl;
//     catan.buildCity(p2);
//     catan.printBoard();
//     p2.printResources();
//     cout << "" << endl;
//     p2.addResource("Ore");
//     p2.addResource("Grain");
//     p2.addResource("Wool");
//     p2.printResources();
//     catan.buyDevelopmentCard(p2);
//     cout << "" << endl;
//     catan.useDevelopmentCard(p2);
//     cout << "" << endl;
//     catan.printResources(p2);
// }