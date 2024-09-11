// Matan Markovits 322318080
// Matanmarkovits@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
#include "spot.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <map>
#include <random>
#include <chrono>

using namespace std;
using namespace ariel;

//test case of the constructor
TEST_CASE("constructor"){
    Player p1("PlayerOne");
    Player p2("PlayerTwo");
    Player p3("PlayerThree");
    Catan catan(p1, p2, p3);
    CHECK(catan.getPlayer(1).getName() == "PlayerOne");
    CHECK(catan.getPlayer(2).getName() == "PlayerTwo");
    CHECK(catan.getPlayer(3).getName() == "PlayerThree");
}

//test case of the placeSettlement function
TEST_CASE("placeSettlement"){
    Player p1("PlayerOne");
    Player p2("PlayerTwo");
    Player p3("PlayerThree");
    Catan catan(p1, p2, p3);
    catan.placeSettlement(p1);
    CHECK(p1.getSettlements() == 1);
    CHECK(p1.getResource("Lumber") == 3);
    CHECK(p1.getResource("Brick") == 3);
    CHECK(p1.getResource("Grain") == 1);
    CHECK(p1.getResource("Wool") == 1);
    CHECK(catan.getBoard().getSpot(0).get_owner() == p1.getColor());
    CHECK(catan.getBoard().getSpot(0).get_type() == "Settlement");
}

//test case of the placeRoad function
TEST_CASE("placeRoad"){
    Player p1("PlayerOne");
    Player p2("PlayerTwo");
    Player p3("PlayerThree");
    Catan catan(p1, p2, p3);
    catan.placeSettlement(p1);
    catan.placeRoad(p1);
    CHECK(p1.getRoadsNum() == 1);
    CHECK(p1.getResource("Lumber") == 2);
    CHECK(p1.getResource("Brick") == 2);
    CHECK(catan.getBoard().getSpot(0).getRoadOwner(0) == p1.getColor());
}

//test case of the buildCity function
TEST_CASE("buildCity"){
    Player p1("PlayerOne");
    Player p2("PlayerTwo");
    Player p3("PlayerThree");
    Catan catan(p1, p2, p3);
    catan.placeSettlement(p1);
    catan.placeRoad(p1);
    catan.placeSettlement(p1);
    catan.placeRoad(p1);
    catan.buildCity(p1);
    CHECK(p1.getCities() == 1);
    CHECK(p1.getResource("Ore") == 0);
    CHECK(p1.getResource("Grain") == 0);
    CHECK(catan.getBoard().getSpot(0).get_type() == "City");
}

//test case of the checkForWinner function
TEST_CASE("checkForWinner"){
    Player p1("PlayerOne");
    Player p2("PlayerTwo");
    Player p3("PlayerThree");
    Catan catan(p1, p2, p3);
    catan.addPoints(p1, 10);
    CHECK(catan.checkForWinner() == true);
}

//test case of the rollDice function
TEST_CASE("rollDice"){
    Player p1("PlayerOne");
    Player p2("PlayerTwo");
    Player p3("PlayerThree");
    Catan catan(p1, p2, p3);
    CHECK(catan.rollDice() >= 2);
    CHECK(catan.rollDice() <= 12);
}

//test case of the resourceDistribution function
TEST_CASE("resourceDistribution"){
    Player p1("PlayerOne");
    Player p2("PlayerTwo");
    Player p3("PlayerThree");
    Catan catan(p1, p2, p3);
    catan.placeSettlement(p1);
    catan.placeRoad(p1);
    catan.placeSettlement(p1);
    catan.placeRoad(p1);
    catan.resourceDistribution(6);
    CHECK(p1.getResource("Lumber") == 3);
    CHECK(p1.getResource("Brick") == 3);
    CHECK(p1.getResource("Wool") == 3);
    CHECK(p1.getResource("Ore") == 3);
    CHECK(p1.getResource("Grain") == 3);
}

//test case of the endTurn function
TEST_CASE("endTurn"){
    Player p1("PlayerOne");
    Player p2("PlayerTwo");
    Player p3("PlayerThree");
    Catan catan(p1, p2, p3);
    catan.endTurn();
    CHECK(catan.getTurn() == 1);
}

//test case of the rob function
TEST_CASE("rob"){
    Player p1("PlayerOne");
    Player p2("PlayerTwo");
    Player p3("PlayerThree");
    Catan catan(p1, p2, p3);
    catan.rob(&p1);
}

//test case of the tradePlayer function
TEST_CASE("tradePlayer"){
    Player p1("PlayerOne");
    Player p2("PlayerTwo");
    Player p3("PlayerThree");
    Catan catan(p1, p2, p3);
    catan.tradePlayer(p1);
}

