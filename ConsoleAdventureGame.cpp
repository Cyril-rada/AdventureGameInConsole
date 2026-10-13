#include <iostream>
#include <string>

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

        for (int i = 0; i < maxMapX; i++) {
            for (int j = 0; j < maxMapY; j++) {
                if (i + (j * maxMapY) == H.posX + (H.posY * maxMapY)) {
                    std::cout << H.nom << ' ';
                }
                else
                    std::cout << pMap[i + (j * maxMapY)] << ' ';
            }
            std::cout << '\n';
        }

        while (direction != 'z' && direction != 'q' && direction != 's' && direction != 'd') {
            std::cin >> direction;
        }
    
        if (direction == 'z') {
            H.posX--;
        }
        else if (direction == 's') {
            H.posX++;
        }
        else if (direction == 'q')
        {
            H.posY--;
        }
        else if (direction == 'd')
        {
            H.posY++;
        }
    
        H.posX = (H.posX + maxMapX) % maxMapX;
        H.posY = (H.posY + maxMapY) % maxMapY;

        direction = ' ';
    }    
}