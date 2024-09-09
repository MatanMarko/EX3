// Matan Markovits 322318080
// Matanmarkovits@gmail.com

#pragma once
#include <iostream>
#include <vector>
#include "player.hpp"
#include "board.hpp"
using namespace std;

namespace ariel
{
    class Catan
    {
    private:
        Player p1;
        Player p2;
        Player p3;
        Board board;
        int turn;
        //vector<DevCard> deck;

    public:
        Catan(Player p1, Player p2, Player p3);     //constructor
        ~Catan();                                   //destructor

        int chooseStartingPlayer();
        Board getBoard();
        Player& getPlayer(int playerNumber);
        
        bool placeSettlement(int vertex, string playerNumber);
        bool placeRoad(int src, int dest, string playerNumber);

        void endTurn();
        int checkForWinner();
        void printPoints();

        void buyDevelopmentCard(int playerNumber);

        void shuffleDeck();

        void rollDice();
        void useDevelopmentCard(int playerNumber, string card);

        void printResources(int playerNumber);
        void resourceDistribution(int dice);
        void printBoard();
        void addPoints(int playerNumber, int points);
    };
} // namespace ariel