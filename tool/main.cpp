#include <functional>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "../Players/Player.h"
#include "../Cards/Card.h"
#include "../Mtmchkin.h"
#include "../Cards/Vampire.h"
#include "../Cards/Barfight.h"
#include "../Cards/Dragon.h"
#include "../Cards/Fairy.h"
#include "../Cards/Goblin.h"
#include "../Cards/Merchant.h"
#include "../Cards/Pitfall.h"
#include "../Cards/Treasure.h"
#include "../Players/Rogue.h"
#include "../Players/Wizard.h"
#include "../Players/Fighter.h"
#include "../Exception.h"
#include <algorithm>
#include <sstream>
#include <random>
#include <cstdio>
#include <fstream>
#include <cstring>

using std::unique_ptr;
using std::cout;
using std::cerr;
using std::string;
using std::fstream;
using std::istringstream;
using std::vector;

const string DECK_PATH = "../deck.txt";
const int MAX_ROUNDS = 100;

void runGame()
{
    Mtmchkin game("../deck.txt");
    while(!game.isGameOver() && game.getNumberOfRounds() < MAX_ROUNDS)
    {
        game.playRound();
        game.printLeaderBoard();
    }  
}

/* ---------------------------------------------------------------------------------------------- */
// --------------------------------       Main function          ------------------------------

int main()
{
    try
    {
        runGame();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    } 

    return 0;
}