
#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"

using namespace std;
using namespace ariel;

int main()
{
    unsigned int choice;
    int dice;
    string name1,name2,name3;
    cout << "Welcome to Catan!\n Insert your names" << endl;
    cout <<"Player 1 (You're red):" << endl;
    cin >> name1;
    cout <<"Player 2 (You're yellow):" << endl;
    cin >> name2;
    cout <<"Player 3 (You're blue):" << endl;
    cin >> name3;
    Player p1(name1);
    Player p2(name2);
    Player p3(name3);
    Catan catan(p1, p2, p3);
    vector<Player*> players = {&p1, &p2, &p3};
    // Starting of the game. Every player places two settlements and two roads.
    //catan.chooseStartingPlayer();   // should print the name of the starting player
    for(unsigned int i=0; i<=2; i++){
        catan.printBoard();
        cout <<"Place the 1st Settelment " << players[i]->getName() << endl;
        catan.placeSettlement(*players[i]);
        catan.printBoard();
        cout <<"Place the 1st road " << players[i]->getName() << endl;
        catan.placeRoad(*players[i]);
        catan.endTurn();
    }
    catan.endTurn();
    for(unsigned int j=3; j>0; j--){
        unsigned int i = j-1;
        catan.endTurn();
        catan.printBoard();
        cout <<"Place the 2nd Settelment " << players[i]->getName() << endl;
        catan.placeSettlement(*players[i]);
        catan.printBoard();
        cout <<"Place the 2st road " << players[i]->getName() << endl;
        catan.placeRoad(*players[i]);
        catan.endTurn();
    }
    catan.printBoard();
    while(!catan.checkForWinner()){
        cout << "It's " << players[catan.getTurn()]->getName() <<"'s turn"<< endl;
        dice = catan.rollDice();
        if (dice == 7){
            cout << "\n!!!!! Robber was rolled !!!!!" << endl;
            catan.rob(players[catan.getTurn()]);
        }
        choice = 10;
        while(choice != 9 && !catan.checkForWinner()){
            cout << "===========================" << endl;
            players[catan.getTurn()]->printResources();
            cout << "--------------------" << endl;
            players[catan.getTurn()]->printDevCards();
            cout << "===========================" << endl;
            cout << "Choose your move:" << endl;
            cout << "1 - Build settlement" << endl;
            cout << "2 - Build road" << endl;
            cout << "3 - Upgrade to city" << endl;
            cout << "4 - Trade with player" << endl;
            cout << "5 - Trade with bank" << endl;
            cout << "6 - Buy development card" << endl;
            cout << "7 - Use development card" << endl;
            cout << "9 - End turn" << endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Where do you want to build it? (-1 to cancel)" << endl;
                    catan.placeSettlement(*players[catan.getTurn()]);
                    break;
                case 2:
                    cout << "Where do you want to build it? (-1 to cancel)" << endl;
                    catan.placeRoad(*players[catan.getTurn()]);
                    break;
                case 3:
                    cout << "Choose settlement to upgrade. (-1 to cancel)" << endl;
                    catan.buildCity(*players[catan.getTurn()]);
                    break;
                case 4:
                    catan.tradePlayer(*players[catan.getTurn()]);
                    break;
                case 5:
                    players[catan.getTurn()]->tradeBank();
                    break;
                case 6:
                    catan.buyDevelopmentCard(*players[catan.getTurn()]);
                    break;
                case 7:
                    catan.useDevelopmentCard(*players[catan.getTurn()]);
                    break;
                case 9:
                    catan.endTurn();
                    break;
                case 0:
                    cout << "Exiting game." << endl;
                    return 0; // Exit the game loop and end the program
                default:
                    cout << "Invalid choice. Please choose a valid option." << endl;
                    break;
            }
            catan.printBoard();
        }
    }
    cout << "====================\n" << players[catan.getTurn()]->getName() << " Won!!!\n" <<"====================\n" << endl;
    return 0;
}
