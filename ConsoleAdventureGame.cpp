#include <iostream>
#include <conio.h>
#include <vector>

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

enum Obstacles
{
    GROUND = 1,
    HILL,
    LAKE,
    EXIT
};

struct MC
{
    char nom;
    int posX;
    int posY;
    int HP;
};

struct ENEMY
{
    char nom;
    int posX;
    int posY;
};

int main()
{
    bool isGameOver = false;
    const int maxMapX = 10;
    const int maxMapY = 20;
    MC H{ 'H', 0, 0, 3 };
    char direction = ' ';

    std::vector<ENEMY> Enemies{
        { 'X', 9, 11 },
        { 'X', 9, 12 },
        { 'X', 9, 13 },
        { 'X', 9, 14 },
        { 'X', 6, 7 }
    };

    int Map[maxMapX * maxMapY] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                   1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                   1, 1, 2, 2, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                   1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1,
                                   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    int* pMap = Map;

    int maxHP = H.HP;


    while (!isGameOver) {

        for (int E = 0; E < Enemies.size(); E++) {
            for (int y = 0; y < maxMapY; y++) {
                for (int x = 0; x < maxMapX; x++) {
                    if (x == H.posX && y == H.posY) {
                        std::cout << H.nom << ' ';
                    }
                    else if (x == Enemies[E].posX && y == Enemies[E].posY) {
                        std::cout << Enemies[E].nom << ' ';
                    }
                    else
                        switch (pMap[x * maxMapY + y]) {
                        case 1:
                            std::cout << '.' << ' ';
                            break;
                        case 2:
                            std::cout << 'M' << ' ';
                            break;
                        case 3:
                            std::cout << '~' << ' ';
                            break;
                        case 4:
                            std::cout << 'E' << ' ';
                            break;
                        }
                }
                std::cout << '\n';
            }

            std::cout << '\n' << H.HP << '/' << maxHP;
            while (direction != 'z' && direction != 'Z' && direction != 'q' && direction != 'Q' && direction != 's' && direction != 'S' && direction != 'd' && direction != 'D') {
                direction = _getch();
            }

            int newCoordX = H.posX;
            int newCoordY = H.posY;

            if (direction == 'z' || direction == 'Z') {
                newCoordX--;
            }
            else if (direction == 's' || direction == 'S') {
                newCoordX++;
            }
            else if (direction == 'q' || direction == 'Q') {
                newCoordY--;
            }
            else if (direction == 'd' || direction == 'D') {
                newCoordY++;
            }

            newCoordX = (newCoordX + maxMapX) % maxMapX;
            newCoordY = (newCoordY + maxMapY) % maxMapY;

            int endCoords = pMap[newCoordX * maxMapY + newCoordY];

            if (endCoords != HILL && endCoords != LAKE) {
                H.posX = newCoordX;
                H.posY = newCoordY;
            }

            bool onEnemy = (H.posX == Enemies[E].posX && H.posY == Enemies[E].posY);

            if (onEnemy)
                H.HP--;

            if (H.HP <= 0)
                isGameOver = true;

            direction = ' ';
            std::cout << "\n\n\n";
            system("cls");
        }

        if (isGameOver == true)
            std::cout << "\n\nGUEYMME AUVEURE\n\n";
    }
}