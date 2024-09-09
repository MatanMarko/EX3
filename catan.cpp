// Matan Markovits 322318080
// Matanmarkovits@gmail.com

#include "catan.hpp"

namespace ariel
{
    Catan::Catan(Player p1, Player p2, Player p3){
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        vector<Player> players = {this->p1, this->p2, this->p3};
        this->board = Board();
        this->turn = 1;
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

    bool Catan::placeSettlement_test(int vertex, int playerNumber){
        if (this->turn != playerNumber) {                   // Check if it's the player's turn
            cout << "It's not your turn." << endl;
            return false;
        }
        if (vertex < 0 || vertex > 53) {                    // Check if the vertex number is valid
            cout << "Invalid vertex number." << endl;
            return false;
        }
        if (board.getSpot(vertex).get_owner() != "none") {      // Check if the spot is already taken
            cout << "This spot is already taken." << endl;
            return false;
        }
        if(getPlayer(playerNumber).getPoints() < 2){        // Check check if it's the first two turns of the game (so he can place a settlement without a road)
            return placeSettlement_startGame(vertex, playerNumber);
        }
        else{
            // Check if the player has a road connected to the spot
            // Check if the spot is connected to the player's settlement
            // Check if the spot is not connected to another settlement
            // Check if the spot is not connected to another road
            // Check if the spot is not connected to another spot of the player
        }
        return true; ///////// change
    }


    bool Catan::placeSettlement_startGame(int vertex, int playerNumber){
        if (board.getSpot(vertex).get_owner() != "none") {      // Check if the spot is already taken
            cout << "This spot is already taken." << endl;
            return false;
        }
        board.getSpot(vertex).set_owner(getPlayer(playerNumber).getName()); 
        getPlayer(playerNumber).addPoints(1);

        if(getPlayer(playerNumber).getPoints() == 2){      // If it's the second settlement, distribute resources
            firstDistribution(vertex, getPlayer(playerNumber));
        }
        return true;
    }

    bool Catan::placeRoad_test(int src, int dest, Player& p){
        if (this->turn != p.getNumber()) {                   // Check if it's the player's turn
            cout << "It's not your turn." << endl;
            return false;
        }
        if (src < 0 || src > 71 || dest < 0 || dest > 71) {                    // Check if the vertex number is valid
            cout << "Invalid vertex number." << endl;
            return false;
        }
        if (board.getSpot(src).adj_spot(board.getSpot(dest)) == false) {      // Check if the two spots are adjacent
            cout << "These spots are not connected." << endl;
            return false;
        }
        if (p.getPoints() <=2 && p.getRoadsNum()<=2){                       // check if its one of the two starter roads
            return placeRoad_startGame(src, dest, p);
        }
        return true; ///////// change
    }

    bool Catan::placeRoad_startGame(int src, int dest, Player& p){
        if (board.getSpot(src).get_owner() == p.getName() || board.getSpot(dest).get_owner() == p.getName()) {      // Check if one of the spots is connected to the player
            if(board.getEdge(src, dest)->getOwner() == "none"){
                board.getEdge(src, dest)->setOwner(p.getName());
                p.addRoad();
                return true;
            }
            else{
                cout << "This road is already taken." << endl;
                return false;
            }
        }
        return true ; ///////// change
    }

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

    void Catan::firstDistribution(int vertex, Player& player){
        // Distribute resources to the player based on the second settlement
        vector<string> resources = board.getSpot(vertex).get_adj_resources();
        for(unsigned int i=0; i<resources.size(); i++){
            if(resources[i] == "Lumber"){ player.addResource("Lumber"); }
            if(resources[i] == "Brick"){ player.addResource("Brick"); }
            if(resources[i] == "Wool"){ player.addResource("Wool"); }
            if(resources[i] == "Ore"){ player.addResource("Ore"); }
            if(resources[i] == "Grain"){ player.addResource("Grain"); }
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