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
        int cities;
        int roads;
        int knights;
        bool hasLongestRoad;
        bool hasLargestArmy;
        bool playerTurn;
        int playerNumber;
        string playerColor;
        static int playerCounter;

    public:
        Player() = default;
        Player(string name);    //constructor
        ~Player();              //destructor
        bool playedDevCard = false;

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
        void setResource(string resource, int amount) { resources[resource] = amount; }

        void settlemenet_resources();
        void road_resources();
        void devCard_resources();

        void addDevCard(string card);
        map<string, int> getDevCards() { return developmentCards; }
        void printDevCards();
        
        string toIcon(string resource);
        string getRobbed();
        int getKnights() { return knights; }

        void addKnight() { knights++; }
        void addSettlement() { settlements++; }
        void addCity() { settlements--; cities++; }

        bool getHasLongestRoad() { return hasLongestRoad; }
        void setLongestRoad(bool b) { hasLongestRoad = b; }
        bool getHasLargestArmy() { return hasLargestArmy; }

        void setLargestArmy(bool b) { hasLargestArmy = b; }
        int getSettlements() { return settlements; }
        int getCities() { return cities; }

        bool tradeBank();
        

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