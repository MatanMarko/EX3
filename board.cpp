// Matan Markovits 322318080
// Matanmarkovits@gmail.com

#include "board.hpp"

namespace ariel {

    Board::Board() {
        spots = {Spot(),Spot(),Spot(),
             Spot(),Spot(),Spot(),Spot(),
             Spot(),Spot(),Spot(),Spot(),
          Spot(),Spot(),Spot(),Spot(),Spot(),
          Spot(),Spot(),Spot(),Spot(),Spot(),
       Spot(),Spot(),Spot(),Spot(),Spot(),Spot(),
       Spot(),Spot(),Spot(),Spot(),Spot(),Spot(),
          Spot(),Spot(),Spot(),Spot(),Spot(),
          Spot(),Spot(),Spot(),Spot(),Spot(),
             Spot(),Spot(),Spot(),Spot(),
             Spot(),Spot(),Spot(),Spot(),
                 Spot(),Spot(),Spot()};


        vector<unsigned int> numbers =    {10, 2, 9,
                                         12, 6, 4, 10,
                                        9, 11, 0, 3, 8, 
                                          8, 3, 4, 5,
                                           5, 6, 11};

        vector<string> resources =         {"Ore", "Wool", "Lumber",
                                        "Grain", "Brick", "Wool", "Brick",
                                    "Grain", "Lumber", "Desert", "Lumber", "Ore",
                                         "Lumber", "Ore", "Grain", "Wool",
                                             "Brick", "Grain", "Wool"};


        spots[0].setSpot({"Ore"}, {10}, {3,4}, 0);
        spots[1].setSpot({"Wool"}, {2}, {4,5}, 1);
        spots[2].setSpot({"Lumber"}, {9}, {5,6}, 2);
        spots[3].setSpot({"Ore"}, {10}, {0,7}, 3);
        spots[4].setSpot({"Ore", "Wool"}, {10, 2}, {0,1,8}, 4);
        spots[5].setSpot({"Wool", "Lumber"}, {2, 9}, {1,2,9}, 5);
        spots[6].setSpot({"Lumber"}, {9}, {2,10}, 6);
        spots[7].setSpot({"Grain", "Ore"}, {12, 10}, {3,11,12}, 7);
        spots[8].setSpot({"Brick", "Ore", "Wool"}, {6, 10, 2}, {4,12,13}, 8);
        spots[9].setSpot({"Wool", "Wool", "Lumber"}, {4, 2, 9}, {5,13,14}, 9);
        spots[10].setSpot({"Brick", "Lumber"}, {10,9}, {6,14,15}, 10);
        spots[11].setSpot({"Grain"}, {12}, {7,16}, 11);
        spots[12].setSpot({"Ore", "Grain", "Brick"}, {10, 12, 6}, {7,8,17}, 12);
        spots[13].setSpot({"Wool", "Brick", "Wool"}, {2, 6, 4}, {8,9,18}, 13);
        spots[14].setSpot({"Lumber", "Wool", "Brick"}, {9, 4, 10}, {9,10,19}, 14);
        spots[15].setSpot({"Brick"}, {10}, {10,20}, 15);
        spots[16].setSpot({"Grain", "Grain"}, {9, 12}, {11,21,22}, 16);
        spots[17].setSpot({"Lumber", "Grain", "Brick"}, {11, 12, 6}, {12,22,23}, 17);
        spots[18].setSpot({"Desert", "Brick", "Wool"}, {0, 6, 4}, {13,23,24}, 18);
        spots[19].setSpot({"Lumber", "Wool", "Brick"}, {3, 4, 10}, {14,24,25}, 19);
        spots[20].setSpot({"Ore", "Brick"}, {8, 10}, {15,25,26}, 20);
        spots[21].setSpot({"Grain"}, {9}, {16,27}, 21);
        spots[22].setSpot({"Grain", "Grain", "Lumber"}, {12, 9, 11}, {16,17,28}, 22);
        spots[23].setSpot({"Brick", "Lumber", "Desert"}, {6, 11, 0}, {17,18,29}, 23);
        spots[24].setSpot({"Lumber", "Wool", "Desert"}, {3, 4, 0}, {18,19,30}, 24);
        spots[25].setSpot({"Lumber", "Brick", "Ore"}, {3, 10, 8}, {19,20,31}, 25);
        spots[26].setSpot({"Ore"}, {8}, {20,32}, 26);
        spots[27].setSpot({"Grain"}, {9}, {21,33}, 27);
        spots[28].setSpot({"Lumber", "Grain", "Lumber"}, {8, 9, 11}, {22,33,34}, 28);
        spots[29].setSpot({"Ore", "Lumber", "Desert"}, {3, 11, 0}, {23,34,35}, 29);
        spots[30].setSpot({"Grain", "Lumber", "Desert"}, {4, 3, 0}, {24,35,36}, 30);
        spots[31].setSpot({"Wool", "Lumber", "Ore"}, {5, 3, 8}, {25,36,37}, 31);
        spots[32].setSpot({"Ore"}, {8}, {26,37}, 32);
        spots[33].setSpot({"Lumber", "Grain"}, {8, 9}, {27,28,38}, 33);
        spots[34].setSpot({"Ore", "Lumber", "Lumber"}, {3, 8, 11}, {28,29,39}, 34);
        spots[35].setSpot({"Grain", "Ore", "Desert"}, {4, 3, 0}, {29,30,40}, 35);
        spots[36].setSpot({"Lumber", "Wool", "Grain"}, {3, 4, 5}, {30,31,41}, 36);
        spots[37].setSpot({"Ore", "Wool"}, {8, 5}, {31,32,42}, 37);
        spots[38].setSpot({"Lumber"}, {8}, {33,43}, 38);
        spots[39].setSpot({"Brick", "Lumber", "Ore"}, {5, 8, 3}, {34,43,44}, 39);
        spots[40].setSpot({"Grain", "Ore", "Grain"}, {6, 3, 4}, {35,44,45}, 40);
        spots[41].setSpot({"Wool", "Grain", "Wool"}, {11, 4, 5}, {36,45,46}, 41);
        spots[42].setSpot({"Wool"}, {5}, {37,46}, 42);
        spots[43].setSpot({"Lumber", "Brick"}, {8, 5}, {38,39,47}, 43);
        spots[44].setSpot({"Brick", "Grain", "Ore"}, {5, 6, 3}, {39,40,48}, 44);
        spots[45].setSpot({"Grain", "Grain", "Wool"}, {4, 6, 11}, {40,41,49}, 45);
        spots[46].setSpot({"Wool", "Wool"}, {5, 11}, {41,42,50}, 46);
        spots[47].setSpot({"Brick"}, {5}, {43,51}, 47);
        spots[48].setSpot({"Brick", "Grain"}, {5, 6}, {44,51,52}, 48);
        spots[49].setSpot({"Grain", "Wool"}, {6, 11}, {45,52,53}, 49);
        spots[50].setSpot({"Wool"}, {11}, {46,53}, 50);
        spots[51].setSpot({"Brick"}, {5}, {47,48}, 51);
        spots[52].setSpot({"Grain"}, {6}, {48,49}, 52);
        spots[53].setSpot({"Wool"}, {11}, {49,50}, 53);



        edges = {Edge(spots[0], spots[3]), Edge(spots[0], spots[4]), Edge(spots[4], spots[1]), Edge(spots[1], spots[5]), Edge(spots[5], spots[2]), Edge(spots[2], spots[6]),
            Edge(spots[3], spots[7]), Edge(spots[4], spots[8]), Edge(spots[5], spots[9]), Edge(spots[6], spots[10]),
            Edge(spots[11], spots[7]), Edge(spots[7], spots[12]), Edge(spots[12], spots[8]), Edge(spots[8], spots[13]), Edge(spots[9], spots[13]), Edge(spots[9], spots[14]), Edge(spots[10], spots[14]), Edge(spots[10], spots[15]),
            Edge(spots[11], spots[16]), Edge(spots[12], spots[17]), Edge(spots[13], spots[18]), Edge(spots[14], spots[19]), Edge(spots[15], spots[20]),
            Edge(spots[16], spots[21]), Edge(spots[16], spots[22]), Edge(spots[17], spots[22]), Edge(spots[17], spots[23]), Edge(spots[18], spots[23]), Edge(spots[18], spots[24]), Edge(spots[19], spots[24]), Edge(spots[19], spots[25]), Edge(spots[20], spots[25]), Edge(spots[20], spots[26]),
            Edge(spots[21], spots[27]), Edge(spots[22], spots[28]), Edge(spots[23], spots[29]), Edge(spots[24], spots[30]), Edge(spots[25], spots[31]), Edge(spots[26], spots[32]),
            Edge(spots[27], spots[33]), Edge(spots[28], spots[33]), Edge(spots[28], spots[34]), Edge(spots[29], spots[34]), Edge(spots[29], spots[35]), Edge(spots[30], spots[35]), Edge(spots[30], spots[36]), Edge(spots[31], spots[36]), Edge(spots[31], spots[37]), Edge(spots[32], spots[37]),
            Edge(spots[33], spots[38]), Edge(spots[34], spots[39]), Edge(spots[35], spots[40]), Edge(spots[36], spots[41]), Edge(spots[37], spots[42]),
            Edge(spots[38], spots[43]), Edge(spots[39], spots[43]), Edge(spots[39], spots[44]), Edge(spots[40], spots[44]), Edge(spots[40], spots[45]), Edge(spots[41], spots[45]), Edge(spots[41], spots[46]), Edge(spots[42], spots[46]),
            Edge(spots[43], spots[47]), Edge(spots[44], spots[48]), Edge(spots[45], spots[49]), Edge(spots[46], spots[50]),
            Edge(spots[47], spots[51]), Edge(spots[51], spots[48]), Edge(spots[48], spots[52]), Edge(spots[52], spots[49]), Edge(spots[49], spots[53]), Edge(spots[53], spots[50])};

    }

    Board::~Board() {}  //destructor
    Edge::~Edge() {}  //destructor

    string Board::print_road(Edge &edge, string preview) 
    {
        return edge.getOwner() == "" ? preview : edge.getOwner() + preview + "\033[0m";
    }

    Edge* Board::getEdge(unsigned int src, unsigned int dest) {
    // Loop through the edges to find the one that connects the two spots
    for (Edge &edge : edges) {
        // Check if the edge connects the two spots src and dest
        if ((edge.getSource() == src && edge.getDestination() == dest) ||
            (edge.getSource() == dest && edge.getDestination() == src)) {
                return &edge;
        }
    }
    // If no such edge is found, return nullptr or throw an exception
    throw std::invalid_argument("No edge connects the given spots.");
}
    
    void Board::printBoard(){
        cout << "\n";
        cout << "            " << spots[0] << spots[1] << spots[2] << endl;
        cout << "           "<<print_road(edges[0],"/   ")<<print_road(edges[1],"\\   ")<<print_road(edges[2], "/   ")<<print_road(edges[3], "\\   ")<<print_road(edges[4], "/   ")<<print_road(edges[5] ,"\\   ") << endl;
        cout << "        " << spots[3] << spots[4] << spots[5] << spots[6] << endl;
        cout << "         "<<print_road(edges[6] ,"|   ")<<spots[0].get_resource(0)<<print_road(edges[7] ," |  ")<<spots[1].get_resource(0)<<print_road(edges[8] ,"  |   ")<<spots[2].get_resource(0)<<print_road(edges[9] ,"  |") << endl;
        cout << "        " << spots[7] << spots[8] << spots[9] << spots[10] << endl;
        cout << "       "<<print_road(edges[10] ,"/    ")<<print_road(edges[11] ,"\\  ")<<print_road(edges[12] ,"/    ")<<print_road(edges[13] ,"\\  ")<<print_road(edges[14] ,"/    ")<<print_road(edges[15] ,"\\  ")<<print_road(edges[16] ,"/    ")<<print_road(edges[17] ,"\\  ") << endl;
        cout << "    " << spots[11] << spots[12] << spots[13] << spots[14] << spots[15] << endl;
        cout << "     "<<print_road(edges[18] ,"|  ")<<spots[7].get_resource(0)<<print_road(edges[19] ,"  |  ")<<spots[8].get_resource(0)<<print_road(edges[20] ,"  |  ")<<spots[9].get_resource(0)<<print_road(edges[21] ,"  |  ")<<spots[10].get_resource(0)<<print_road(edges[22] ," |") << endl;
        cout << "    " << spots[16] << spots[17] << spots[18] << spots[19] << spots[20] << endl;
        cout << "   "<<print_road(edges[23] ,"/    ")<<print_road(edges[24] ,"\\  ")<<print_road(edges[25] ,"/    ")<<print_road(edges[26] ,"\\  ")<<print_road(edges[27] ,"/    ")<<print_road(edges[28] ,"\\  ")<<print_road(edges[29] ,"/    ")<<print_road(edges[30] ,"\\  ")<<print_road(edges[31] ,"/    ")<<print_road(edges[32] ,"\\  ") << endl;
        cout << spots[21] << spots[22] << spots[23] << spots[24] << spots[25] << spots[26] << endl;
        cout << " "<<print_road(edges[33] ,"|   ")<<spots[16].get_resource(0)<<print_road(edges[34] ," |   ")<<spots[17].get_resource(0)<<print_road(edges[35] ," | ")<<spots[18].get_resource(0)<<print_road(edges[36] ," |  ")<<spots[19].get_resource(0)<<print_road(edges[37] ,"  |  ")<<spots[20].get_resource(0)<<print_road(edges[38] ,"   |") << endl;
        cout << spots[27] << spots[28] << spots[29] << spots[30] << spots[31] << spots[32] << endl;
        cout << "   "<<print_road(edges[39] ,"\\    ")<<print_road(edges[40] ,"/  ")<<print_road(edges[41] ,"\\    ")<<print_road(edges[42] ,"/  ")<<print_road(edges[43] ,"\\    ")<<print_road(edges[44] ,"/  ")<<print_road(edges[45] ,"\\    ")<<print_road(edges[46] ,"/  ")<<print_road(edges[47] ,"\\    ")<<print_road(edges[48] ,"/  ") << endl;
        cout << "    " << spots[33] << spots[34] << spots[35] << spots[36] << spots[37] << endl;
        cout << "     "<<print_road(edges[49] ,"|  ")<<spots[28].get_resource(0)<<print_road(edges[50] ,"   |   ")<<spots[29].get_resource(0)<<print_road(edges[51] ,"   |  ")<<spots[30].get_resource(0)<<print_road(edges[52] ," |  ")<<spots[31].get_resource(0)<<print_road(edges[53] ,"  |") << endl;
        cout << "    " << spots[38] << spots[39] << spots[40] << spots[41] << spots[42] << endl;
        cout << "       "<<print_road(edges[54] ,"\\    ")<<print_road(edges[55] ,"/  ")<<print_road(edges[56] ,"\\    ")<<print_road(edges[57] ,"/  ")<<print_road(edges[58] ,"\\    ")<<print_road(edges[59] ,"/  ")<<print_road(edges[60] ,"\\    ")<<print_road(edges[61] ,"/  ") << endl;
        cout << "        " << spots[43] << spots[44] << spots[45] << spots[46] << endl;
        cout << "         "<<print_road(edges[62] ,"|  ")<<spots[39].get_resource(0)<<print_road(edges[63] ,"  |  ")<<spots[40].get_resource(0)<<print_road(edges[64] ,"  |  ")<<spots[41].get_resource(0)<<print_road(edges[65] ,"  |") << endl;
        cout << "        " << spots[47] << spots[48] << spots[49] << spots[50] << endl;
        cout << "           "<<print_road(edges[66] ,"\\    ")<<print_road(edges[67] ,"/  ")<<print_road(edges[68] ,"\\    ")<<print_road(edges[69] ,"/  ")<<print_road(edges[70] ,"\\    ")<<print_road(edges[71] ,"/  ") << endl;
        cout << "            " << spots[51] << spots[52] << spots[53] << "\n\n--------------------------------------------------\n\n";
    }

    void Board::setOwner(unsigned int spot, string color) {
        this->spots[spot].set_owner(color);
    }
    

}