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
        vector<DevCard> deck;

    public:
        Catan(Player p1, Player p2, Player p3);
        void ChooseStartingPlayer();
        Board getBoard();
        Player& getPlayer(int playerNumber);
        void printWinner();
        bool placeSettlement(int vertex, string playerNumber);
        bool placeRoad(int src, int dest, string playerNumber);
    };
} // namespace ariel