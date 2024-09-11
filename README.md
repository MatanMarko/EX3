# **Catan Board Game Implementation in C++**

## **Project Overview**
This project is a C++ implementation of the popular board game *Catan*. It replicates key features of the original game, including resource gathering, trading, and building. Players compete to gather resources, build settlements, roads, and cities, and accumulate development cards in their quest to reach 10 victory points and win the game. The game is designed for three players and incorporates game mechanics such as the robber, longest road, and largest army.

## **Features**
- **Players**: Up to three players can play, each represented by a unique color (Red, Yellow, Blue).
- **Resource Management**: Players gather resources based on dice rolls, and spend them to build roads, settlements, cities, and buy development cards.
- **Development Cards**: Players can purchase and use development cards, including Knights, Victory Points, Road Building, Monopoly, and Year of Plenty.
- **Trading**: Players can trade resources with each other or the bank.
- **Robber**: Rolling a 7 activates the robber, allowing a player to steal resources from others.
- **Victory Conditions**: The game ends when a player reaches 10 points by building cities, settlements, or using development cards.

## **Gameplay Flow**
1. **Setup**: 
   - The game starts by prompting players to input their names. Each player is assigned a color.
   - Players place two settlements and two roads at the beginning of the game in a turn-based fashion.

2. **Turns**:
   - Each turn starts with a dice roll to distribute resources based on the settlements and cities on the board.
   - Players take actions during their turn, such as building, trading, or using development cards.
   - Players can also roll a 7, which triggers the robber, allowing the active player to steal resources from another player.
   
3. **Winning**:
   - A player wins the game once they reach 10 points. Points are accumulated by building settlements (1 point), cities (2 points), or using Victory Point development cards.

## **Classes & Code Structure**

### **Player Class (`player.cpp`)**
Handles individual player attributes, including:
- Resources: Players start with a predefined number of resources (Lumber, Brick, Ore, Grain, and Wool).
- Development Cards: Stores the number of development cards a player has and handles their effects.
- Points: Tracks victory points and conditions for Longest Road and Largest Army.
- Trading: Supports resource trading between players and with the bank.
- Resource management: Methods to add, subtract, and print resources.

### **Catan Class (`catan.cpp`)**
This is the game engine that manages the state of the board and player interactions, including:
- **Dice Rolls**: Simulates the roll of two dice and distributes resources based on the roll.
- **Building**: Methods for placing settlements, roads, and upgrading settlements to cities.
- **Development Cards**: Allows players to buy and play development cards.
- **End Turn & Win Conditions**: Ends the current player's turn and checks for a winner.

### **Spot Class (`spot.cpp`)**
Represents individual spots on the board where players can build settlements and roads. This class handles:
- **Resource Distribution**: Each spot produces resources based on dice rolls.
- **Ownership**: Tracks which player owns a settlement or city on the spot.
- **Adjacency**: Determines if two spots are adjacent, which is essential for building roads.

## **Compilation and Execution**

### **Prerequisites**
- Ensure you have a C++ compiler (e.g., g++) installed.
- The game uses standard libraries, so no external dependencies are required.

### **Compilation**
Use the following command to compile the game:
```bash
g++ -o catan demo.cpp catan.cpp player.cpp spot.cpp -std=c++11
```

### **Running the Game**
After compiling, run the executable:
```bash
./catan
```

### **Game Input**
The game is interactive, and players will need to input their actions at various points, including:
- Selecting where to place settlements and roads.
- Choosing resources to trade.
- Rolling dice to generate resources.

## **How to Play**
1. At the start, each player inputs their name.
2. Players take turns placing their initial settlements and roads.
3. On each player's turn:
   - Roll the dice to gather resources.
   - Choose actions such as building, trading, or playing development cards.
   - End the turn when done.
4. The game continues until one player reaches 10 victory points.

## **Future Enhancements**
- **AI Opponents**: Implement AI players to enable single-player mode.
- **GUI**: Add a graphical user interface to enhance the player experience.
- **Networked Multiplayer**: Allow players to connect over a network and play remotely.

## **Author**
- Matan Markovits
- Email: matanmarkovits@gmail.com

This README covers all the major aspects of the project, from the setup to gameplay instructions. Let me know if you'd like to adjust any section or add further details!
