#include "spot.hpp"

namespace ariel {

    Spot::Spot() {}
    Spot::~Spot() {}

    const std::string DEFAULT = "\033[0m";

    void Spot::setSpot(vector<string> resources, vector<unsigned int> numbers, vector<unsigned int> neighbors) {
        this->resources = resources;
        this->numbers = numbers;
        this->neighbors = neighbors;
        vector<string> available_roads(neighbors.size(), "");
        this->roads = available_roads;
    }

    // string Spot::get_resource(unsigned int i) {
    //     return this->resources[i];
    // }

    string Spot::get_resource(unsigned int i) {
        if (this->resources[i] == "Ore") { return "🪨" + to_string(numbers[i]); }
        else if (this->resources[i] == "Wool") { return "🐑" + to_string(numbers[i]); }
        else if (this->resources[i] == "Lumber") { return "🪵" + to_string(numbers[i]); }
        else if (this->resources[i] == "Grain") { return "🌾" + to_string(numbers[i]); }
        else if (this->resources[i] == "Brick") { return "🧱" + to_string(numbers[i]); }
        else if (this->resources[i] == "Deseert") { return "\033[0;33mDESERT\033[0m"; }
        else { return " "; }
    }

    void Spot::set_owner(string new_owner) {
        this->owner = new_owner;
    }

    string Spot::get_owner() {
        return this->owner;
    }

    void Spot::set_id(unsigned int new_id) {
        this->id = new_id;
    }

    std::ostream& operator<<(std::ostream& os, Spot& spot) {
        string spaces = "    ";
        if(spot.id < 10){ spaces = "     "; }
        os << spot.owner << "("<<to_string(spot.id)<<")" << DEFAULT << spaces;
        return os;
    }

}