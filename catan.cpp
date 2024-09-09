// Matan Markovits 322318080
// Matanmarkovits@gmail.com

#include "catan.hpp"

namespace ariel
{
    Catan::Catan(Player p1, Player p2, Player p3){
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->board = Board();
        this->turn = chooseStartingPlayer();
    }
    Catan::~Catan(){}  //destructor

    int chooseStartingPlayer() {
    // Return a random number between 1 and 3
    srand(static_cast<unsigned int>(time(0)));
    int startPlayer = (rand() % 3) + 1;
    cout << "Starting player is: " << startPlayer << endl;
    return startPlayer;
    }

    Board Catan::getBoard(){
        return this->board;
    }

    Player& Catan::getPlayer(int playerNumber){
        if (playerNumber == 1) {return this->p1;}
        else if (playerNumber == 2) {return this->p2;}
        else if (playerNumber == 3) {return this->p3;}
        else {throw invalid_argument("Invalid player number");}
    }

    /////////////////////////////////////////////////////////////////////
    // bool placeSettlement(int vertex, string playerNumber);
    // bool placeRoad(int src, int dest, string playerNumber);
    //////////////////////////////////////////////////////////////////////

    void Catan::endTurn(){
        this->turn = (this->turn + 1) % 3;
        cout << "\nIt's " << getPlayer(this->turn).getName() << "'s turn." << endl;
    }

    int Catan::checkForWinner(){
        if (p1.getPoints() >= 10) {
            cout << p1.getName() << " won the game" << endl;
            return 1;
        }
        else if (p2.getPoints() >= 10) {
            cout << p2.getName() << " won the game" << endl;
            return 2;
        }
        else if (p3.getPoints() >= 10) {
            cout << p3.getName() << " won the game" << endl;
            return 3;
        }
        else {return 0;}
    }

    void Catan::printPoints(){
        cout << p1.getName() << " has " << p1.getPoints() << " points." << endl;
        cout << p2.getName() << " has " << p2.getPoints() << " points." << endl;
        cout << p3.getName() << " has " << p3.getPoints() << " points." << endl;
    }

    /////////////////////////////////////////////////////////////////////
    // void buyDevelopmentCard(int playerNumber);

    //void useDevelopmentCard(int playerNumber, string card){
    //////////////////////////////////////////////////////////////////////

    void Catan::shuffleDeck(){
        // Shuffle the deck of development cards
    }

    void Catan::rollDice(){
        // Return a random number between 1 and 6 twice to keep the dice statistics
        srand(static_cast<unsigned int>(time(0)));
        int dice1 = (rand() % 6) + 1;
        int dice2 = (rand() % 6) + 1;
        int sum = dice1 + dice2;
        cout << "Dice roll: " << sum << endl;
        resourceDistribution(sum);
        cout << getPlayer(this->turn).getName()<< " has rolled " << sum << endl;
    }

    void Catan::printResources(int playerNumber){
        if (playerNumber == 1) {p1.printResources();}
        else if (playerNumber == 2) {p2.printResources();}
        else if (playerNumber == 3) {p3.printResources();}
        else {throw invalid_argument("Invalid player number");}
    }

    void Catan::resourceDistribution(int dice){
        // Distribute resources to the players based on the dice roll
        for(unsigned int i=0; i<=53; i++){
            string spotResouce = board.getSpot(i).dice_hit(dice);
            if(spotResouce!="none"){
                for(unsigned int j=0; j<3; j++){
                    if(board.getSpot(i).get_owner() == getPlayer(j).getName()){
                        if(spotResouce == "Lumber"){ getPlayer(j).addResource("Lumber"); }
                        if(spotResouce == "Brick"){ getPlayer(j).addResource("Brick"); }
                        if(spotResouce == "Wool"){ getPlayer(j).addResource("Wool"); }
                        if(spotResouce == "Ore"){ getPlayer(j).addResource("Ore"); }
                        if(spotResouce == "Grain"){ getPlayer(j).addResource("Grain"); }
                    }
                }
            }
        }
    }

    void Catan::printBoard(){
        board.printBoard();
    }

    void Catan::addPoints(int playerNumber, int points){
        if (playerNumber == 1) {p1.addPoints(points);}
        else if (playerNumber == 2) {p2.addPoints(points);}
        else if (playerNumber == 3) {p3.addPoints(points);}
        else {throw invalid_argument("Invalid player number");}

        if (checkForWinner() != 0) {
            this->turn = 0;
        }
    }

    

    
} // namespace ariel