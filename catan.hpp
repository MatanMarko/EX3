// Matan Markovits 322318080
// Matanmarkovits@gmail.com

#pragma once
#include <iostream>
#include <vector>
#include "player.hpp"
#include "board.hpp"
#include <random>
using namespace std;

namespace ariel
{
    class Catan
    {
    private:
        vector<Player*> players;
        Board board;
        unsigned int turn = 0;
        vector<string> devCards;

    public:
        Catan(Player p1, Player p2, Player p3);     //constructor
        ~Catan();                                   //destructor

        int chooseStartingPlayer();
        Board getBoard();
        Player& getPlayer(int playerNumber);
        
        bool placeSettlement(Player& p);
        bool placeRoad(Player& p);
        bool buildCity(Player& p);

        int checkForWinner();
        void printPoints();
        void addPoints(int playerNumber, int points);

        void shuffleDeck();
        void rollDice();
        void useDevelopmentCard(int playerNumber, string card);

        void printResources(int playerNumber);
        void resourceDistribution(int dice);
        void firstDistribution(int vertex, Player& player);

        void printBoard();
        void buyDevelopmentCard(Player& p);
        bool useDevelopmentCard(Player& p, string card);

        void endTurn();
        
    };
} // namespace ariel