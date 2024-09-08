//placeSettelemnt
//placeRoad
//rollDice
//endTurn
//trade
//buyDevelopmentCard
//useDevelopmentCard
//printPoints
//printsResources

#include "player.hpp"

namespace ariel
{
    Player::Player(string name){
        this->name = name;
        this->points = 0;
        this->resources = {{"wood", 0}, {"brick", 0}, {"ore", 0}, {"wheat", 0}, {"wool", 0}};
        this->developmentCards = {{"bonus points", 0}, {"knight", 0}, {"road building", 0}, {"year of plenty", 0}, {"monopoly", 0}};
        this->settlements = 0;
        this->roads = 0;
        this->hasLongestRoad = false;
        this->hasLargestArmy = false;
        this->hasUsedDevelopmentCard = false;
        this->playerTurn = false;
        this->playerNumber = ++playerCounter;
        this->playerColor = playerNumber == 1 ? "Red" : playerNumber == 2 ? "Blue" : "Green";
    }

    bool placeSettlement(int vertex, Board &board){
        return Catan.placeSettlement(vertex, board, this->playerNumber);
    }
}
