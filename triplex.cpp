#include <iostream>
#include <ctime>

bool PlayGameAtDifficulty(int Difficulty)
{

    const int CodeA = rand() % (Difficulty * 2) + 1;
    const int CodeB = rand() % (Difficulty * 2) + 1;
    const int CodeC = rand() % (Difficulty * 2) + 1;
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "+ There are 3 numbers to the safe combination\n";
    std::cout << "+ The sum of the codes is: " << CodeSum << std::endl;
    std::cout << "+ The product of the codes is: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;

    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    std::cout << "You entered: " << GuessA << GuessB << GuessC << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "\nYou guessed right! The safe opens, and you take its contents. On to the next job for an even bigger score...\n";
        return true;
    } else {
        std::cout << "\nYou guessed wrong! Try again quickly before the owners return home\n";
        return false;
    }


}

void PrintIntroduction(int Difficulty)
{
    std::cout << "You are a burglar, and have broken into a home where you have discovered a level " << Difficulty << " safe.\n";
    std::cout << "Crack the safe combination to get their valuables!\n\n";
}


int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    int MaxDifficulty = 10;
    PrintIntroduction(LevelDifficulty);
    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGameAtDifficulty(LevelDifficulty);
        // PlayGameAtDifficulty(LevelDifficulty);
        std::cin.clear(); // clears errors
        std::cin.ignore(); // discards buffer
        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        

    }
    std::cout << "\nYou have stolen enough to comforatably retire to a paradise of your choosing. Until you decide to come back for more...\n";
    return 0;
}
// how to compile and run in terminal
// g++ -o triplex triplex.cpp
// ./triplex

