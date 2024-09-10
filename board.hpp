// Matan Markovits 322318080
// Matanmarkovits@gmail.com

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
            int source;
            int destination;

        public:
            Edge(Spot &spot1, Spot &spot2){
                this->source = spot1.get_id();
                this->destination = spot2.get_id();
                this->owner = "";
                }
            ~Edge();
            string getOwner(){return owner;}
            void setOwner(string new_owner) {this->owner = new_owner;}
            string getColor(){return color;}
            void setColor(string new_color){color = new_color;}
            int getNumber(){return number;}
            int getSource(){return source;}
            int getDestination(){return destination;}
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
            Spot& getSpot(unsigned int spotNum){return spots[spotNum];}   
            Edge* getEdge(int src, int dest);    
            string print_road(Edge &edge, string preview);     
    };
}