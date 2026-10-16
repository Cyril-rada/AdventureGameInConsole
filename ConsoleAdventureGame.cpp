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

void afficher_map(int map_size_x, int map_size_y, MC H, const std::vector<ENEMY>&Monstres, int* p) {
        for (int j = 0; j < map_size_y; j++) {
            for (int i = 0; i < map_size_x; i++) {
                int index = i + (j * map_size_x);

                if (i == H.posX && j == H.posY) {
                    std::cout << H.nom << ' ';
                }
                else {
                    bool monstre_affiche = false;

                    for (const ENEMY& monstre : Monstres) {
                        if (i == monstre.posX && j == monstre.posY) {
                            std::cout << monstre.nom << ' ';
                            monstre_affiche = true;
                            break;
                        }
                    }

                    if (!monstre_affiche) {
                        
                        switch (p[index]) {
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
                }
            }
            std::cout << '\n';
        }
    }
int main()
{
    std::cout << "changement a la con, comme demande";
    bool isGameOver = false;
    const int maxMapX = 20;
    const int maxMapY = 10;
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

        
        afficher_map(20, 10, H, Enemies, pMap);

            std::cout << '\n' << H.HP << '/' << maxHP;
            while (direction != 'z' && direction != 'Z' && direction != 'q' && direction != 'Q' && direction != 's' && direction != 'S' && direction != 'd' && direction != 'D') {
                direction = _getch();
            }

            int newCoordX = H.posX;
            int newCoordY = H.posY;

            if (direction == 'z' || direction == 'Z') {
                newCoordY--;
            }
            else if (direction == 's' || direction == 'S') {
                newCoordY++;
            }
            else if (direction == 'q' || direction == 'Q') {
                newCoordX--;
            }
            else if (direction == 'd' || direction == 'D') {
                newCoordX++;
            }

            newCoordX = (newCoordX + maxMapX) % maxMapX;
            newCoordY = (newCoordY + maxMapY) % maxMapY;

            int endCoords = pMap[newCoordX * maxMapY + newCoordY];
            
            if (endCoords != HILL && endCoords != LAKE) {
                H.posX = newCoordX;
                H.posY = newCoordY;
            }
            for (int T{}; T < Enemies.size(); T++) {
                bool onEnemy = (H.posX == Enemies[T].posX && H.posY == Enemies[T].posY);
                if (onEnemy)
                    H.HP--;
            }
            if (H.HP <= 0)
                isGameOver = true;

            direction = ' ';
            std::cout << "\n\n\n";
            system("cls");
        }

    if (isGameOver == true)
            std::cout << "\n\nGUEYMME AUVEURE\n\n";
    }
