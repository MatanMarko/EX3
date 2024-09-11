// Matan Markovits 322318080
// Matanmarkovits@gmail.com

#include "catan.hpp"
namespace ariel
{
    Catan::Catan(Player& p1, Player& p2, Player& p3){
        this->board = Board();
        this->players = {&p1, &p2, &p3};
        devCards.insert(devCards.end(), 14, "Knight");
        devCards.insert(devCards.end(), 5, "Victory point");
        devCards.insert(devCards.end(), 2, "Road building");
        devCards.insert(devCards.end(), 2, "Year of plenty");
        devCards.insert(devCards.end(), 2, "Monopoly");
        //shuffle the deck:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(devCards.begin(), devCards.end(), std::default_random_engine(seed)); // Replace 'shuffle' with 'std::shuffle'
    }
    Catan::~Catan(){}  //destructor

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Catan::chooseStartingPlayer() {
    // Return a random number between 1 and 3
    srand(static_cast<unsigned int>(time(0)));
    int startPlayer = (rand() % 3);
    cout << "Starting player is: " << startPlayer << endl;
    this->turn = startPlayer;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Board Catan::getBoard(){
        return this->board;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Player& Catan::getPlayer(int playerNumber){     // Return a reference to the player by the player number
        return *players[playerNumber-1];
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool Catan::placeSettlement(Player& p){     // Place a settlement on the board
        if(*players[turn] != p){
            cout << "Wait your turn " << p.getName() << endl;
            cout << "Now it's " << players[turn]->getName() << endl;
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
            if (spot == -1){ 
                cout << "You decided not to build the settlement" << endl;
                return false; }
            if(spot >= 0 && spot <= 53){
                if(board.getSpot(spot).get_owner() == ""){
                    vector<unsigned int> neighbors = board.getSpot(spot).getNeighbors();
                    for(unsigned int i=0; i<neighbors.size(); i++){
                        if(board.getSpot(neighbors[i]).get_owner() != ""){
                            cout << "Can't place a settelment next to another settlement or city" << endl;
                            available = false;
                            break; // breaks from 'for' loop only
                        }
                    }
                    if(available) { break; }    // breaks from 'while' loop
                } else{ cout << "There's already a settlement" << endl;}
            } else { cout << "You are out of bounds (0-53)" << endl; }
        }
        p.settlemenet_resources();      // Remove the resources from the player
        board.setOwner(spot, p.getColor());     // Set the owner of the spot to the player's color
        board.getSpot(spot).changeType("Settlement");       // Change the spot's type to settlement
        p.addPoints(1);     // Add a point to the player
        p.addSettlement();  // Add a settlement to the player
        
        if(p.getSettlements() == 2 && p.getCities() == 0){    // If the player has placed two settlements, distribute resources
            firstDistribution(spot, p);
        }

        return true;    // Return true if the settlement was placed successfully
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
            if (cin.fail()){    //check if the input isn't int type
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number" << endl;
                continue;
            }
            if (src == -1){ 
                cout << "You decided not to build the road" << endl;
                return false; }
            cin >> dst;
            if (cin.fail()){        // Check if the input isn't an integer
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number" << endl;
                continue;
            }
            if (src == -1){
                cout << "You decided not to build the road" << endl;
                return false; }
    
            if(src < 0 || src > 53 || dst < 0 || dst > 53){
                cout << "No such spot" << endl;
                continue;
            }
            if(!board.getSpot(src).adj_spot(board.getSpot(dst))){
                cout << "There's no road between " << src << " and " << dst << endl;
                continue;
            }
            if(!board.getSpot(src).adj_spot(board.getSpot(dst))){
                cout << "There's no road between " << src << " and " << dst << endl;
                continue;
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
            try {
                Edge* edge = board.getEdge(src, dst);  // Find the edge between the two spots
                edge->setOwner(p.getColor());  // Set the road's owner to the player's color
            }   catch (std::invalid_argument& e) {
                    cout << e.what() << endl;
                    continue;
                }
            p.road_resources();     // Remove the resources from the player

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
        p.addRoad();    // Add a road to the player
        return true;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Catan::endTurn()
    {
        turn = (turn + 1) % 3;
        players[turn]->playedDevCard = false;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool Catan::checkForWinner(){
        //check if there is a player with the most roads and if he has more than 5 roads
        int mostRoads = 0;
        int mostRoadsPlayer = 0;
        for (unsigned int i=0; i<players.size(); i++){
            if (players[i]->getRoadsNum() > mostRoads){
                mostRoads = players[i]->getRoadsNum();
                mostRoadsPlayer = i;
            }
        }
        if (mostRoads >= 5){
            if (players[mostRoadsPlayer]->getHasLongestRoad() == false){
                for (unsigned int i=0; i<players.size(); i++){
                    if (players[i]->getHasLongestRoad() == true){
                        players[i]->setLongestRoad(false);
                        players[i]->addPoints(-2);
                    }
                }
                players[mostRoadsPlayer]->setLongestRoad(true);
                players[mostRoadsPlayer]->addPoints(2);
                cout << "!!!!!!!!! " << players[mostRoadsPlayer]->getName() << " has the longest road !!!!!!!!" << endl;
            }
            
        }

        //check if there is a player with the most knights and if he has more than 2 knights
        int mostKnights = 0;
        int mostKnightsPlayer = 0;
        for (unsigned int i=0; i<players.size(); i++){
            if (players[i]->getKnights() > mostKnights){
                mostKnights = players[i]->getKnights();
                mostKnightsPlayer = i;
            }
        }
        if (mostKnights >= 3){
            if (players[mostKnightsPlayer]->getHasLargestArmy() == false){
                for (unsigned int i=0; i<players.size(); i++){
                    if (players[i]->getHasLargestArmy() == true){
                        players[i]->setLargestArmy(false);
                        players[i]->addPoints(-2);
                    }
                }
                players[mostKnightsPlayer]->setLargestArmy(true);
                players[mostKnightsPlayer]->addPoints(2);
                cout << "!!!!!!!!! " << players[mostKnightsPlayer]->getName() << " has the largest army !!!!!!!!" << endl;
            }
        }

        for (unsigned int i=0; i<players.size(); i++){      // Check if any player has 10 points
            if (players[i]->getPoints() >= 10){
                cout << players[i]->getName() << " has won the game!" << endl;
                return true;
            }
        }
        return false;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Catan::printPoints(){
        for (unsigned int i=0; i<players.size(); i++){
            cout << players[i]->getName() << " has " << players[i]->getPoints() << " points." << endl;
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int Catan::rollDice(){
        // Return a random number between 1 and 6 twice to keep the dice statistics
        srand(static_cast<unsigned int>(time(0)));
        int dice1 = (rand() % 6) + 1;
        int dice2 = (rand() % 6) + 1;
        int sum = dice1 + dice2;
        if (sum != 7) {resourceDistribution(sum);}
        cout << getPlayer(turn + 1).getName()<< " has rolled " << sum << endl;
        return sum;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Catan::printResources(Player& p){
        cout << p.getName() << " has:\n" << endl;
        p.printResources();
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Catan::resourceDistribution(int dice){
        // Distribute resources to the players based on the dice roll
        for(unsigned int i=0; i<54; i++){
            string spotResouce = board.getSpot(i).dice_hit(dice);
            if(spotResouce!="none"){
                for(unsigned int j=0; j<3; j++){
                    if(board.getSpot(i).get_owner() == getPlayer(j + 1).getColor()){
                        if(spotResouce == "Lumber"){ getPlayer(j + 1).addResource("Lumber"); }
                        if(spotResouce == "Brick"){ getPlayer(j + 1).addResource("Brick"); }
                        if(spotResouce == "Wool"){ getPlayer(j + 1).addResource("Wool"); }
                        if(spotResouce == "Ore"){ getPlayer(j + 1).addResource("Ore"); }
                        if(spotResouce == "Grain"){ getPlayer(j + 1).addResource("Grain"); }
                    }
                }
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Catan::printBoard(){
        board.printBoard();
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Catan::addPoints(Player& p, int points){
        p.addPoints(points);
        if (checkForWinner() != 0) {
            this->turn = 4; // End the game
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Catan::buyDevelopmentCard(Player& p){
        if(*players[turn] != p){
            cout << "Wait your turn " << p.getName() << endl;
            cout << "It's your turn " << players[turn]->getName() << endl;
            return;
        }

        if (devCards.size() == 0){
            cout << "No more development cards" << endl;
            return;
        }

        if(p.getResource("Ore") < 1 || p.getResource("Wool") < 1 || p.getResource("Grain") < 1){
            cout << "Not enough resources" << endl;
            return;
        }
        p.devCard_resources();
        string card = devCards.back();
        devCards.pop_back();
        cout << "You got " << card << endl;
        p.addDevCard(card);
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool Catan::useDevelopmentCard(Player& p){

        if(*players[turn] != p){
            cout << "Wait your turn " << p.getName() << ", you can only play development cards in your turn" << endl;
            cout << "It's your turn " << players[turn]->getName() << endl;
            return false;
        }

        p.printDevCards();
        cout << "\nChoose a card to play:" << endl;
        cout << "1 = Knight, 2 = Victory point, 3 = Road building, 4 = Year of plenty, 5 = Monopoly, (or 0 to cancel)" << endl;
        int card;
        cin >> card;
        if (card == 0){
            cout << "You decided not to play a card" << endl;
            return false;
        }
        if (card < 1 || card > 5){
            cout << "No such card\n" << endl;
            return false;
        }

        string cardKey;
        switch(card) {
            case 1: cardKey = "Knight"; break;
            case 2: cardKey = "Victory point"; break;
            case 3: cardKey = "Road building"; break;
            case 4: cardKey = "Year of plenty"; break;
            case 5: cardKey = "Monopoly"; break;
        }

        // Check if the player has the card
        if (p.getDevCards()[cardKey] == 0){
            cout << "You don't have that card" << endl;
            return false;
        }

        // Victory point card
        if (card == 2){
            p.addPoints(1);
            p.getDevCards()["victory point"]--;
            cout << "You have used a victory point card, you got 1 point" << endl;
            return true;
        }
        // Check if the player has already played a dev card, only victory point can be played more than once
        if (p.playedDevCard == false){
            // Knight card
            if (card == 1){
                p.getDevCards()["Knight"]--;
                cout << "You have used a knight card, choose another player to get random resouce from him" << endl;
                int playerNumber;
                cin >> playerNumber;
                if (playerNumber < 1 || playerNumber > 3){
                    cout << "No such player" << endl;
                    return false;
                }
                if (playerNumber == p.getNumber()){
                    cout << "You can't choose yourself" << endl;
                    return false;
                }
                string resource = getPlayer(playerNumber).getRobbed();
                p.addResource(resource);
                p.playedDevCard = true;
                p.addKnight();
                return true;
            }

            // Road building card
            if (card == 3){
                p.getDevCards()["Road building"]--;
                cout << "You have used a road building card, place two roads" << endl;
                placeRoad(p);
                placeRoad(p);
                p.playedDevCard = true;
                return true;
            }

            // Year of plenty card
            if (card == 4){
                cout << "You have used a year of plenty card, choose two resources:" << endl;
                cout << "Lumber, Brick, Wool, Ore, Grain" << endl;
                string resource1, resource2;
                cin >> resource1 >> resource2;
                if(resource1 != "Lumber" && resource1 != "Brick" && resource1 != "Wool" && resource1 != "Ore" && resource1 != "Grain"){
                    cout << "No such resource / Wrong typing" << endl;
                    return false;
                }
                p.getDevCards()["Year of plenty"]--;
                p.addResource(resource1);
                p.addResource(resource2);
                p.playedDevCard = true;
                return true;
            }

            //Monopoly card
            if (card == 5){
                cout << "You have used a monopoly card, choose a resource to take from all players:" << endl;
                cout << "Lumber, Brick, Wool, Ore, Grain" << endl;
                string resource;
                cin >> resource;
                if(resource != "Lumber" && resource != "Brick" && resource != "Wool" && resource != "Ore" && resource != "Grain"){
                    cout << "No such resource / Wrong typing" << endl;
                    return false;
                }
                for (unsigned int i=0; i<players.size(); i++){
                    if (players[i]->getColor() != p.getColor()){
                        p.setResource(resource, p.getResource(resource) + (*players[i]).getResource(resource));
                        players[i]->setResource(resource, 0);
                    }
                }
                p.getDevCards()["Monopoly"]--;
                p.playedDevCard = true;
                return true;
            }
        }
        return false;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool Catan::buildCity(Player& p){
        if(*players[turn] != p){
            cout << "Wait your turn " << p.getName() << endl;
            cout << "It's your turn " << players[turn]->getName() << endl;
            return false;
        }

        if(p.getResource("Ore") < 3 || p.getResource("Grain") < 2){
            cout<< "not enough resources" << endl;
            return false;
        }
        if (p.getCities() == 4){
            cout << "You can't build more than 4 cities" << endl;
            return false;
        }

        unsigned int spot;
        while(true){
            cin >> spot;
            if (spot == -1){
                cout << "You decided not to build the city" << endl;
                return false;
            }
            if(spot >= 0 && spot <= 53){
                if(board.getSpot(spot).get_owner() == p.getColor()){
                    board.getSpot(spot).changeType("City");
                    p.setResource("Ore", p.getResource("Ore") - 3);
                    p.setResource("Grain", p.getResource("Grain") - 2);
                    p.addPoints(1);
                    p.addCity();
                    return true;
                } else{ cout << "You don't own this spot" << endl;}
            } else { cout << "You are out of bounds (0-53)" << endl; }
        }
        return false;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Catan::rob(Player* p) {
    cout << "Choose a player to rob" << endl;
    int playerNumber;

        while (true) {
            if (!(cin >> playerNumber)) {
                // If the input is not an integer, clear the error flag and ignore the input
                cout << "Invalid input. Please enter a valid player number (1-3)." << endl;
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
                continue;
            }

            if (playerNumber < 1 || playerNumber > 3) {
                cout << "No such player" << endl;
                continue;
            }

            if (playerNumber == p->getNumber()) {
                cout << "You can't choose yourself" << endl;
                continue;
            }

            string resource = getPlayer(playerNumber).getRobbed(); // Rob the chosen player
            p->addResource(resource);   // Add the resource to the player who rolled the dice
            break;
        }
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Catan::tradePlayer(Player& p){     // Trade resources with another player
    if(*players[turn] != p){
        cout << "Wait your turn " << p.getName() << endl;
        cout << "It's your turn " << players[turn]->getName() << endl;
        return;
    }

    cout << "Choose a player to trade with" << endl;
    int playerNumber;
        if (!(cin >> playerNumber)) {
            // If the input is not an integer, clear the error flag and ignore the input
            cout << "Invalid input. Please enter a valid player number (1-3)." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
            return;
        }

        if (playerNumber < 1 || playerNumber > 3) {
            cout << "No such player" << endl;
            return;
        }

        if (playerNumber == p.getNumber()) {
            cout << "You can't choose yourself" << endl;
            return;
        }

        cout << "Choose a resource to give" << endl;
        string resource1;
        cin >> resource1;

        if (resource1 != "Lumber" && resource1 != "Brick" && resource1 != "Wool" && resource1 != "Ore" && resource1 != "Grain") {
            cout << "No such resource" << endl;
            return;
        }

        cout << "Choose a resource to get" << endl;
        string resource2;
        cin >> resource2;

        if (resource2 != "Lumber" && resource2 != "Brick" && resource2 != "Wool" && resource2 != "Ore" && resource2 != "Grain") {
            cout << "No such resource" << endl;
            return;
        }

        cout << "How many " << resource1 << " do you want to give?" << endl;
        int amount1;
        cin >> amount1;

        if (amount1 < 0 || amount1 > p.getResource(resource1)) {
            cout << "Invalid amount" << endl;
            return;
        }

        cout << "How many " << resource2 << " do you want to get?" << endl;
        int amount2;
        cin >> amount2;
        if (amount2 < 0) {
            cout << "Invalid amount" << endl;
            return;
        }

        if (amount1 == 0 && amount2 == 0) {
            cout << "You can't trade nothing" << endl;
            return;
        }

        if (getPlayer(playerNumber).getResource(resource2) < amount2) {
            cout << "The other player doesn't have enough resources" << endl;
            return;
        }
        cout << getPlayer(playerNumber).getName() << ", do you agree to get " << amount2 << " " << resource2 << " for " << amount1 << " " << resource1 << "?" << endl;
        cout << "1 = Yes, 0 = No" << endl;
        int answer;
        cin >> answer;
        if (answer != 1 && answer != 0) {
            cout << "Invalid input" << endl;
            return;
        }
        if (answer == 0) {
            cout << "Trade canceled" << endl;
            return;
        }

        cout << "Trade accepted" << endl;

        p.setResource(resource1, p.getResource(resource1) - amount1);
        p.setResource(resource2, p.getResource(resource2) + amount2);
        getPlayer(playerNumber).setResource(resource1, getPlayer(playerNumber).getResource(resource1) + amount1);
        getPlayer(playerNumber).setResource(resource2, getPlayer(playerNumber).getResource(resource2) - amount2);
        return;  
    
    }


    
} // namespace ariel;