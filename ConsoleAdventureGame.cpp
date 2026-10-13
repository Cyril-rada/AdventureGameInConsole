#include <iostream>
#include <string>
#include <conio.h>

/*
PLAN :
    
    
    
    - before moving check with a while loop if the hero isn't going off-course or
    in a wall/water
    
    - check if player is dead by checking if he still is on the map
    
    - make enemies unable to "eat" the exit block E
    - if E is inexistant mark the game a won
    - use #include to make all the levels and make sure to add a way to wipe
    the previous level at the start of the new one

    ? how to let the enemies know they can go down?

    
*/

struct MC
{
    char nom;
    int posX;
    int posY;
};

int main()
{
    bool isNotGameOver = false;
    const int maxMapX = 10;
    const int maxMapY = 20;
    MC H{ 'H', 0, 0 };
    char direction = ' ';

    char Map[maxMapX * maxMapY] = {'.','.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
                                   '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
                                   '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
                                   '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
                                   '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
                                   '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
                                   '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
                                   '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
                                   '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
                                   '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
    char* pMap = Map;

    while (!isNotGameOver) {

        system("cls");
        for (int x = 0; x < maxMapX; x++) {
            for (int y = 0; y < maxMapY; y++) {
                if (x + (y * maxMapX) == H.posX + (H.posY * maxMapX)) {
                    std::cout << H.nom << ' ';
                }
                else
                    std::cout << pMap[x + (y * maxMapX)] << ' ';
            }
            std::cout << '\n';
        }

        while (direction != 'z' && direction != 'Z' && direction != 'q' && direction != 'Q' && direction != 's' && direction != 'S' && direction != 'd' && direction != 'D') {
            direction = _getch();
        }

        if (direction == 'z' || direction == 'Z') {
            H.posX--;
        }
        else if (direction == 's' || direction == 'S') {
            H.posX++;
        }
        else if (direction == 'q' || direction == 'Q')
        {
            H.posY--;
        }
        else if (direction == 'd' || direction == 'D')
        {
            H.posY++;
        }

        H.posX = (H.posX + maxMapX) % maxMapX;
        H.posY = (H.posY + maxMapY) % maxMapY;

        direction = ' ';
        std::cout << "\n\n\n";
    }
}