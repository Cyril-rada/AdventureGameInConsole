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
    int maxHP;
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



    while (!isGameOver) {


        for (int x = 0; x < maxMapX; x++) {
            for (int y = 0; y < maxMapY; y++) {
                if (x + (y * maxMapX) == H.posX + (H.posY * maxMapX)) {
                    std::cout << H.nom << ' ';
                }
                else if (x + (y * maxMapX) == E1.posX + (E1.posY * maxMapX)) {
                    std::cout << E1.nom << ' ';
                }
                else if (x + (y * maxMapX) == E2.posX + (E2.posY * maxMapX)) {
                    std::cout << E2.nom << ' ';
                }
                else if (x + (y * maxMapX) == E3.posX + (E3.posY * maxMapX)) {
                    std::cout << E3.nom << ' ';
                }
                else if (x + (y * maxMapX) == E4.posX + (E4.posY * maxMapX)) {
                    std::cout << E1.nom << ' ';
                }
                else if (x + (y * maxMapX) == E5.posX + (E5.posY * maxMapX)) {
                    std::cout << E5.nom << ' ';
                }
                else
                    switch (pMap[x + (y * maxMapX)]) {
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
        std::cout << '\n' << H.maxHP;
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
        system("cls");
    }
}