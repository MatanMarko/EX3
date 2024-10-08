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
        this->developmentCards = {{"Victory point", 0}, {"Knight", 0}, {"Road building", 0}, {"Year of plenty", 0}, {"Monopoly", 0}};
        this->settlements = 0;
        this->cities = 0;
        this->roads = 0;
        this->hasLongestRoad = false;
        this->hasLargestArmy = false;
        this->playedDevCard = false;
        this->playerTurn = false;
        this->playerNumber = ++playerCounter;
        this->playerColor = playerNumber == 1 ? "\033[0;31m" : playerNumber == 2 ? "\033[0;33m" : "\033[0;34m";
        this->knights = 0;
    }
    
    Player::~Player(){}  //destructor

    //////////////////////////////////////////////////////////////////////////

    int Player::getPoints(){
        return this->points;
    }

    //////////////////////////////////////////////////////////////////////////

    string Player::getName(){
        return this->name;
    }

    //////////////////////////////////////////////////////////////////////////

    void Player::printResources(){
        cout << this->name << " has:\n" << endl;
        for (auto const &resource : this->resources){
            cout << resource.first << " " << toIcon(resource.first) << ": " << resource.second << endl;
        }
    }

    //////////////////////////////////////////////////////////////////////////

    int Player::getResource(string resource){
        return this->resources[resource];
    }

    //////////////////////////////////////////////////////////////////////////

    void Player::addResource(string resource){
        this->resources[resource]++;
    }

    //////////////////////////////////////////////////////////////////////////

    void Player::addPoints(int points){
        this->points += points;
    }

    //////////////////////////////////////////////////////////////////////////

    int Player::getNumber(){
        return this->playerNumber;
    }

    //////////////////////////////////////////////////////////////////////////

    void Player::settlemenet_resources(){
        this->resources["Lumber"]--;
        this->resources["Brick"]--;
        this->resources["Grain"]--;
        this->resources["Wool"]--;
    }

    //////////////////////////////////////////////////////////////////////////

    void Player::road_resources(){
        this->resources["Lumber"]--;
        this->resources["Brick"]--;
    }

    //////////////////////////////////////////////////////////////////////////

    void Player::devCard_resources(){
        this->resources["Ore"]--;
        this->resources["Wool"]--;
        this->resources["Grain"]--;
    }

    //////////////////////////////////////////////////////////////////////////

    void Player::addDevCard(string card){
        this->developmentCards[card]++;
        if (card == "Knight"){
            this->knights++;
        }
    }

    //////////////////////////////////////////////////////////////////////////

    void Player::printDevCards(){
        bool empty = true;
        cout << "Development cards " << this->name << " has:" << endl;
        for (auto const &devCard : this->developmentCards){
            if (devCard.second > 0){ 
                cout << devCard.first << ": " << devCard.second << endl;
                empty = false;
            }
        }
        if (empty){
            cout << "none" << endl;
        }
        cout << "" << endl;
    }

    //////////////////////////////////////////////////////////////////////////

    string Player::toIcon(string resource){
        if (resource == "Lumber"){ return "🌲"; }
        if (resource == "Brick"){ return "🧱"; }
        if (resource == "Ore"){ return "⛏️"; }
        if (resource == "Grain"){ return "🌾"; }
        if (resource == "Wool"){ return "🐑"; }
        return "";
    }

    //////////////////////////////////////////////////////////////////////////

    string Player::getRobbed(){
        srand(static_cast<unsigned int>(time(0)));
        int availableResources = 0;
        for (auto const &resource : this->resources){
            if (resource.second > 0){
                availableResources++;
            }
        }
        if (availableResources == 0){
            cout << name << " have no resources" << endl;
            return "";
        }
        int robbedResource = (rand() % availableResources);
        int i = 0;
        for (auto &resource : this->resources){
            if (resource.second > 0){
                if (i == robbedResource){
                    resource.second--;
                    cout << name << " has been robbed of " << resource.first << endl;
                    return resource.first;
                }
                i++;
            }
        }
        return "";
    }

    //////////////////////////////////////////////////////////////////////////

    bool Player::tradeBank(){
        string resource1, resource2;
        cout << "Choose a resource to give:" << endl;
        cin >> resource1;
        if (resource1 != "Lumber" && resource1 != "Brick" && resource1 != "Ore" && resource1 != "Grain" && resource1 != "Wool"){
            cout << "Invalid resource" << endl;
            return false;
        }
        cout << "Choose a resource to get:" << endl;
        cin >> resource2;
        if (resource2 != "Lumber" && resource2 != "Brick" && resource2 != "Ore" && resource2 != "Grain" && resource2 != "Wool"){
            cout << "Invalid resource" << endl;
            return false;
        }
        if (resource1 == resource2){
            cout << "You can't trade the same resource" << endl;
            return false;
        }
        if (this->resources[resource1] < 4){
            cout << "You don't enough " << resource1 << endl;
            return false;
        }
        this->resources[resource1] -= 4;
        this->resources[resource2]++;
        return true;
    }

} // namespace ariel
