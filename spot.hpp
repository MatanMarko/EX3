// Matan Markovits 322318080
// Matanmarkovits@gmail.com

#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace ariel {
    class Spot {
    private:
        vector<string> resources;
        vector<unsigned int> numbers;
        vector<unsigned int> neighbors;
        vector<string> roads;
        string owner = "";
        string type = "";
        unsigned int id;
        
    public:
        Spot();
        ~Spot();

        string get_type(){return type;}
        void setSpot(vector<string> type, vector<unsigned int> num, vector<unsigned int> neighbors, unsigned int id);
        void set_owner(string new_owner);

        string get_owner();
        void set_id(unsigned int new_id);
        unsigned int get_id(){return id;}
        
        friend std::ostream& operator<<(std::ostream& os, const Spot& spot);
        string dice_hit(unsigned int dice);
        bool adj_spot(Spot &spot);
        
        string get_resource(unsigned int i);
        vector<string> get_adj_resources(){return resources;}
        vector<unsigned int> getNeighbors(){ return neighbors; }

        vector<string> getRoads(){ return roads; }
        void setRoadOwner(string color, unsigned int i){ this->roads[i] = color; };
        string getRoadOwner(unsigned int i){ return roads[i]; };

        void changeType(string newType){ this->type = newType; }

        //operator overloading:
        bool operator==(Spot &s) {return this->id == s.id;}
        friend std::ostream& operator<<(std::ostream& os, Spot& spot);    //operator overloading for printing
    };
}