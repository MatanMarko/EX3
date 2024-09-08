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
        unsigned int id;
        
    public:
        Spot();
        ~Spot();
        void setSpot(vector<string> type, vector<unsigned int> num, vector<unsigned int> neighbors);
        friend std::ostream& operator<<(std::ostream& os, Spot& spot);    //operator overloading for printing
        void set_owner(string new_owner);
        string get_owner();
        void set_id(unsigned int new_id);
        friend std::ostream& operator<<(std::ostream& os, const Spot& spot);

        string get_resource(unsigned int i);
    };
}