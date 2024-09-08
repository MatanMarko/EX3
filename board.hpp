#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "spot.hpp"

using namespace std;

namespace ariel {

    class Edge {
        private:
            string owner;
            int number;
            string color;

        public:
            Edge(Spot &spot1, Spot &spot2){this->owner = "none";}
            ~Edge();
            string getOwner(){return owner;}
            void setOwner(string new_owner){owner = new_owner;}
            string getColor(){return color;}
            void setColor(string new_color){color = new_color;}
            int getNumber(){return number;}
    };

    class Board {
        private:
            vector<Spot> spots;
            vector<Edge> edges;
            
        public:
            Board();
            ~Board();
            void setOwner(unsigned int spot, string color);
            void printBoard();
            string printBoard(Edge &edge, string preview);

            
    };
}