#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include <map>
#include "board.hpp"
using namespace std;

namespace ariel
{
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
        Player(string name);
        bool placeSettelemnt(int vertex, Board &board);
    };
} // namespace ariel