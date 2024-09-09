// Matan Markovits 322318080
// Matanmarkovits@gmail.com

#include "player.hpp"
#include "catan.hpp"

namespace ariel
{
    int Player::playerCounter = 0;

    Player::Player(string name){    //constructor
        this->name = name;
        this->points = 0;
        this->resources = {{"Lumber", 4}, {"Brick", 4}, {"Ore", 0}, {"Grain", 2}, {"Wool", 2}};
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
    Player::~Player(){}  //destructor

    int Player::getPoints(){
        return this->points;
    }

    string Player::getName(){
        return this->name;
    }

    void Player::printResources(){
        cout << "Player " << this->name << " has:" << endl;
        for (auto const &resource : this->resources){
            cout << resource.first << ": " << resource.second << endl;
        }
    }

    string Player::getColor(){
        return this->playerColor;
    }

    int Player::getResource(string resource){
        return this->resources[resource];
    }

    void Player::addResource(string resource){
        this->resources[resource]++;
    }

    void Player::addPoints(int points){
        this->points += points;
    }

    int Player::getNumber(){
        return this->playerNumber;
    }

    void Player::settlemenet_resources(){
        this->resources["wood"]--;
        this->resources["brick"]--;
        this->resources["wheat"]--;
        this->resources["wool"]--;
    }

    void Player::road_resources(){
        this->resources["wood"]--;
        this->resources["brick"]--;
    }
}
