//ChooseStartingPlayer
//getBoard
//printWinner

#include "catan.hpp"

namespace ariel
{
    Catan::Catan(Player p1, Player p2, Player p3)
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->board = Board();
    }

    void Catan::ChooseStartingPlayer()
    {
        
    }

    Board Catan::getBoard()
    {
        return this->board;
    }

    void Catan::printWinner()
    {
        if (p1.getPoints() >= 10)
        {
            cout << p1.getName() << " is the winner!" << endl;
        }
        else if (p2.getPoints() >= 10)
        {
            cout << p2.getName() << " is the winner!" << endl;
        }
        else if (p3.getPoints() >= 10)
        {
            cout << p3.getName() << " is the winner!" << endl;
        }
        else
        {
            cout << "None of the players reached 10 points." << endl;
        }
    }

    bool Catan::placeSettlement(int vertex, Board &board, string name)
    {
        return board.placeSettlement(vertex, name);
    }
} // namespace ariel