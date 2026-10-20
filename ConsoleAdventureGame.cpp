#include <iostream>
#include <conio.h>
#include <vector>
#include <fstream>
#include <string>


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

bool level_loader(const std::string& filename, int* mapArray, int maxMapX, int maxMapY, MC& hero, std::vector<ENEMY>& enemies) {
    std::ifstream file(filename);


    if (!file.is_open()) {
        return false;
    }

    enemies.clear();
    bool heroTrouve = false;

    hero.posX = 0;
    hero.posY = 0;



    int EN{};

    char tile;

    for (int y = 0; y < maxMapY; ++y) {
        for (int x = 0; x < maxMapX; ++x) {


            if (file >> tile) {
                int index = x + (y * maxMapX);


                switch (tile) {
                case '.': mapArray[index] = GROUND; break;
                case 'M': mapArray[index] = HILL; break;
                case '~': mapArray[index] = LAKE; break;
                case 'E': mapArray[index] = EXIT; break;
                case 'H':
                    hero.posX = x;
                    hero.posY = y;
                    mapArray[index] = GROUND;
                    heroTrouve = true;
                    break;
                case 'X':
                    enemies.push_back({ 'X', x, y });
                    mapArray[index] = GROUND;
                    break;
                default:  mapArray[index] = GROUND; break;
                }
            }
        }
    }

    file.close();

    return true;
}

void show_map(int map_size_x, int map_size_y, MC H, const std::vector<ENEMY>& Monstres, int* p) {
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
                    case GROUND: std::cout << '.' << ' '; break;
                    case HILL:   std::cout << 'M' << ' '; break;
                    case LAKE:   std::cout << '~' << ' '; break;
                    case EXIT:   std::cout << 'E' << ' '; break;
                    }
                }
            }
        }
        std::cout << '\n';
    }
}
int main()
{
    std::cout << "changement a la con, comme demande\n";
    bool isGameOver = false;
    bool isGameWon = false;
    const int maxMapX = 20;
    const int maxMapY = 10;
    MC H{ 'H', 0, 0, 3 };
    char direction = ' ';

    std::vector<ENEMY> Enemies;


    int Map[maxMapX * maxMapY] = { 0 };

    int* pMap = Map;

    int maxHP = H.HP;

    int currentLevel = 1;

    std::string levelFileName = "level" + std::to_string(currentLevel) + ".txt";
    if (!level_loader(levelFileName, pMap, maxMapX, maxMapY, H, Enemies)) {
        std::cout << "Erreur: Impossible de charger le fichier " << levelFileName << "\n";
        std::cout << "Avez-vous cree les fichiers level1.txt, level2.txt, etc. ?\n";
        return 1;
    }

    while (!isGameOver && !isGameWon) {


        show_map(20, 10, H, Enemies, pMap);
        std::cout << "\nHP: " << H.HP << '/' << maxHP << " | Niveau: " << currentLevel << "\n";

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

        int endCoords = pMap[newCoordX + (newCoordY * maxMapX)];

        if (endCoords == EXIT) {
            currentLevel++;
            std::string nextLevelFileName = "level" + std::to_string(currentLevel) + ".txt";

            system("cls");

            if (!level_loader(nextLevelFileName, pMap, maxMapX, maxMapY, H, Enemies)) {
                isGameWon = true;
            }
            direction = ' ';
            continue;
        }

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

        int enemyDir = rand() % 5;;

        for (int ED{}; ED < Enemies.size(); ED++) {

            int enemyCoordX = Enemies[ED].posX;
            int enemyCoordY = Enemies[ED].posY;

            if (enemyDir == 1) {
                enemyCoordY--;
            }
            else if (enemyDir == 2) {
                enemyCoordY++;
            }
            else if (enemyDir == 3) {
                enemyCoordX--;
            }
            else if (enemyDir == 4) {
                enemyCoordX++;
            }

            enemyCoordX = (enemyCoordX + maxMapX) % maxMapX;
            enemyCoordY = (enemyCoordY + maxMapY) % maxMapY;

            int enemyCoords = pMap[enemyCoordX + (enemyCoordY * maxMapX)];

            if (enemyCoords != HILL && enemyCoords != LAKE && enemyCoords != EXIT) {
                Enemies[ED].posX = enemyCoordX;
                Enemies[ED].posY = enemyCoordY;
            }
            enemyDir = rand() % 5;
        }


        direction = ' ';
        system("cls");
    }

    if (isGameOver)
        std::cout << "\n\nGAME OVER\n\n";
    else if (isGameWon) {
        std::cout << "\n\nCONGRATULATIONS, my little cattywampus cucumber!\n\n"; // reférence à TADC épisode 7
    }
}