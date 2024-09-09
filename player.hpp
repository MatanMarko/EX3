// Matan Markovits 322318080
// Matanmarkovits@gmail.com

#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include <map>
#include "board.hpp"
using namespace std;

namespace ariel
{
    //int ariel::Player::playerCounter = 0;
    class Player
    {
    private:
        string name;
        int points;
        map<string, int> resources;
        map<string, int> developmentCards;
        int settlements;
        int roads;
        bool hasLongestRoad;
        bool hasLargestArmy;
        bool hasUsedDevelopmentCard;
        bool playerTurn;
        int playerNumber;
        string playerColor;
        static int playerCounter;

    public:
        Player() = default;
        Player(string name);    //constructor
        ~Player();              //destructor

        int getPoints();
        string getName();
        bool tradePlayers(int player1, int player2, string resource1, string resource2, int amount1, int amount2);
        bool tradeBank(string resource1, string resource2, int amount1, int amount2); 
        void printResources();
        string getColor() { return playerColor; }
        void addResource(string resource);
        void addPoints(int points);
        int getNumber();
        int getRoadsNum() { return roads; }
        void addRoad() { roads++; }
        int getResource(string resource);
        void settlemenet_resources();
        void road_resources();

        //operator overloading:
        bool operator==(const Player &p) const
        {
            return this->playerNumber == p.playerNumber;
        }
        bool operator!=(const Player &p) const
        {
            return !(*this == p);
        }

    };
} // namespace ariel