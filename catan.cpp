// Matan Markovits 322318080
// Matanmarkovits@gmail.com

#include "catan.hpp"

namespace ariel
{
    Catan::Catan(Player p1, Player p2, Player p3){
        // this->p1 = p1;
        // this->p2 = p2;
        // this->p3 = p3;
        //vector<Player> players = {this->p1, this->p2, this->p3};
        this->board = Board();
        //this->turn = 1;
        this->players = {&p1, &p2, &p3};
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
        return *players[playerNumber-1];
    }

    // Player& Catan::getPlayer(int playerNumber){
    //     if (playerNumber == 1) {return this->p1;}
    //     else if (playerNumber == 2) {return this->p2;}
    //     else if (playerNumber == 3) {return this->p3;}
    //     else {throw invalid_argument("Invalid player number");}
    // }

    bool Catan::placeSettlement(Player& p){
        if(*players[turn] != p){
            cout << "Wait your turn " << p.getName() << endl;
            cout << "It's your turn " << players[turn]->getName() << endl;
            return false;
        }
        if(p.getResource("Lumber") < 1 || p.getResource("Brick") < 1 || p.getResource("Grain") < 1 || p.getResource("Wool") < 1){
            cout<< "not enough resources" << endl;
            return false;
        }
        unsigned int spot;
        while(true){
            bool available = true;
            cin >> spot;
            if(spot >= 0 && spot <= 53){
                if(board.getSpot(spot).get_owner() == ""){
                    vector<unsigned int> neighbors = board.getSpot(spot).getNeighbors();
                    for(unsigned int i=0; i<neighbors.size(); i++){
                        if(board.getSpot(neighbors[i]).get_owner() != ""){
                            cout << "Can't place a settelment next to another settlement or city" << endl;
                            available = false;
                            break; // breaks from for loop only
                        }
                    }
                    if(available) { break; }
                } else{ cout << "There's already a settlement" << endl;}
            } else { cout << "You are out of bounds (1-54)" << endl; }
        }
        p.settlemenet_resources();
        board.setOwner(spot, p.getColor());
        p.addPoints(1);
        return true;
    }

    // bool Catan::placeSettlement_test(int vertex, int playerNumber){
    //     if (this->turn != playerNumber) {                   // Check if it's the player's turn
    //         cout << "It's not your turn." << endl;
    //         return false;
    //     }
    //     if (vertex < 0 || vertex > 53) {                    // Check if the vertex number is valid
    //         cout << "Invalid vertex number." << endl;
    //         return false;
    //     }
    //     if (board.getSpot(vertex).get_owner() != "none") {      // Check if the spot is already taken
    //         cout << "This spot is already taken." << endl;
    //         return false;
    //     }
    //     if(getPlayer(playerNumber).getPoints() < 2){        // Check check if it's the first two turns of the game (so he can place a settlement without a road)
    //         return placeSettlement_startGame(vertex, playerNumber);
    //     }
    //     else{
    //         // Check if the player has a road connected to the spot
    //         // Check if the spot is connected to the player's settlement
    //         // Check if the spot is not connected to another settlement
    //         // Check if the spot is not connected to another road
    //         // Check if the spot is not connected to another spot of the player
    //     }
    //     return true; ///////// change
    // }


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


    //////////////////////////////////////////////////////////////////////
    bool Catan::placeRoad(Player& p){
        if(*players[turn] != p){
            cout << "Wait your turn " << p.getName() << endl;
            cout << "It's your turn " << players[turn]->getName() << endl;
            return false;
        }
        if(p.getResource("Lumber") < 1 || p.getResource("Brick") < 1){
            cout<< "not enough resources" << endl;
            return false;
        }
        unsigned int src, dst;
        while(true){
            cin >> src;
            cin >> dst;
            if(src == 0 || dst == 0){ return false; }
            if(src < 0 || src > 53 || dst < 0 || dst > 53){
                cout << "No such spot" << endl;
                continue;
            }
            if(!board.getSpot(src).adj_spot(board.getSpot(dst))){
                cout << "There's no road between " << src << " and " << dst << endl;
                continue;
            // }
            // if(!board.getSpot(src).adj_spot(board.getSpot(dst))){
            //     cout << "There's no road between " << src << " and " << dst << endl;
            //     continue;
            }
            if(p.getColor() != board.getSpot(src).get_owner() && p.getColor() != board.getSpot(dst).get_owner()){

                if(board.getSpot(src).get_owner()=="" || p.getColor() != board.getSpot(src).get_owner().replace(2, 2, "0;")){

                    if (board.getSpot(dst).get_owner()=="" || p.getColor() != board.getSpot(dst).get_owner().replace(2, 2, "0;")){

                        vector<string> roads = this->board.getSpot(src).getRoads();
                        bool neighborRoad = false;

                        for(unsigned int i=0; i<roads.size(); i++){
                            if(roads[i] == p.getColor()){
                                neighborRoad = true;
                            }
                        }
                        roads = this->board.getSpot(dst).getRoads();

                        for(unsigned int i=0; i<roads.size(); i++){
                            if(roads[i] == p.getColor()){
                                neighborRoad = true;
                            }
                        }

                        if(!neighborRoad){
                            cout << "Cant place a road not connected to a settlement/road" << endl; 
                            continue;
                        }   
                    }
                }
                      
                
            }
            p.road_resources();
            vector<unsigned int> neighbors = this->board.getSpot(dst).getNeighbors();
            bool existingRoad = false;
            for(unsigned int i=0; i<neighbors.size(); i++){
                if(board.getSpot(neighbors[i]) == board.getSpot(dst)){
                    if(board.getSpot(src).getRoadOwner(i) != ""){
                        existingRoad = true;
                        break;
                    }
                    board.getSpot(src).setRoadOwner(p.getColor(), i);
                }
            }
            if(existingRoad){
                cout << "There's already a road there" << endl;
                continue;
            }
            neighbors = this->board.getSpot(dst).getNeighbors();
            for(unsigned int i=0; i<neighbors.size(); i++){
                if(board.getSpot(neighbors[i]) == board.getSpot(src)){
                    board.getSpot(dst).setRoadOwner(p.getColor(), i);
                }
            }
            break;
        }
        return true;
    }

    // bool Catan::placeRoad_test(int src, int dest, Player& p){
    //     if (this->turn != p.getNumber()) {                   // Check if it's the player's turn
    //         cout << "It's not your turn." << endl;
    //         return false;
    //     }
    //     if (src < 0 || src > 71 || dest < 0 || dest > 71) {                    // Check if the vertex number is valid
    //         cout << "Invalid vertex number." << endl;
    //         return false;
    //     }
    //     if (board.getSpot(src).adj_spot(board.getSpot(dest)) == false) {      // Check if the two spots are adjacent
    //         cout << "These spots are not connected." << endl;
    //         return false;
    //     }
    //     if (p.getPoints() <=2 && p.getRoadsNum()<=2){                       // check if its one of the two starter roads
    //         return placeRoad_startGame(src, dest, p);
    //     }
    //     return true; ///////// change
    // }

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
        for (unsigned int i=0; i<players.size(); i++){
            if (players[i]->getPoints() >= 10){
                cout << players[i]->getName() << " has won the game!" << endl;
                return i+1;
            }
        }
    }

    void Catan::printPoints(){
        for (unsigned int i=0; i<players.size(); i++){
            cout << players[i]->getName() << " has " << players[i]->getPoints() << " points." << endl;
        }
    }
    /////////////////////////////////////////////////////////////////////
    // void buyDevelopmentCard(int playerNumber);

    //void useDevelopmentCard(int playerNumber, string card){
    //////////////////////////////////////////////////////////////////////

    // void Catan::shuffleDeck(){
    //     // Shuffle the deck of development cards
    // }

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
        cout << players[playerNumber-1]->getName() << " has:" << endl;
        players[playerNumber-1]->printResources();
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
        players[playerNumber-1]->addPoints(points);
        if (checkForWinner() != 0) {
            this->turn = 0;
        }
    }

    

    
} // namespace ariel