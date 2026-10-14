#include <iostream>
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
    ENEMY E1{ 'X', 9, 11 };
    ENEMY E2{ 'X', 9, 12 };
    ENEMY E3{ 'X', 9, 13 };
    ENEMY E4{ 'X', 9, 14 };
    ENEMY E5{ 'X', 6, 7 };



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
        

                for (int x = 0; x < maxMapX; x++) {
            for (int y = 0; y < maxMapY; y++) {
                if (x == H.posX && y == H.posY) {
                    std::cout << H.nom << ' ';
                }
                else if (x == E1.posX && y == E1.posY) {
                    std::cout << E1.nom << ' ';
                }
                else if (x == E2.posX && y == E2.posY) {
                    std::cout << E2.nom << ' ';
                }
                else if (x == E3.posX && y == E3.posY) {
                    std::cout << E3.nom << ' ';
                }
                else if (x == E4.posX && y == E4.posY) {
                    std::cout << E4.nom << ' ';
                }
                else if (x == E5.posX && y == E5.posY) {
                    std::cout << E5.nom << ' ';
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

        bool onEnemy =
            (H.posX == E1.posX && H.posY == E1.posY) ||
            (H.posX == E2.posX && H.posY == E2.posY) ||
            (H.posX == E3.posX && H.posY == E3.posY) ||
            (H.posX == E4.posX && H.posY == E4.posY) ||
            (H.posX == E5.posX && H.posY == E5.posY);

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