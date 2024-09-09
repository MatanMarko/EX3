// Matan Markovits 322318080
// Matanmarkovits@gmail.com

#include "player.hpp"
#include "catan.hpp"

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

    void Player::addResource(string resource){
        this->resources[resource]++;
    }

    void Player::addPoints(int points){
        this->points += points;
    }
}
