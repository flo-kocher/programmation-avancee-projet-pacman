#include "../include/GameManager.h"
#include <iostream>

#include <SDL.h>

GameManager::GameManager()
: count(0)
, src_bg({200, 3, 168, 216})
, bg({4, 4, 672, 864})
, score(0)
{
    // on fait une variable coordonnées{X, X, X, X}, qu'on va augmenter en faisant des x+=4 etc...
    // et pour a la version updaté, quand on passe sur la case, on a juste à prendre
    // la même valeur mais avec un y+= 100 par exemple (on a juste un décalage sur une coord sur le Sprite)

    // ------------>>>>>>>>>>>
    // en fait on a même pas besoin de données la valeur, il peut la calculer lui
    // même en prenant la valeur de la case de base !!!!!

    std::cout<<"Window constructor\n";
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Echec de l'initialisation de la SDL " << SDL_GetError() << std::endl;
        // exit il faut peut être faire autrement
        exit;
    }
    if((pWindow = SDL_CreateWindow("PacManGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 900, SDL_WINDOW_SHOWN)) == NULL)
        std::cerr<<"Echec de la création de la fenêtre "<<SDL_GetError()<<std::endl;
    if((win_surf = SDL_GetWindowSurface(pWindow)) == NULL)
        std::cerr<<"Echec de la récupération de la surface de la fenêtre "<<SDL_GetError()<<std::endl;
    if((plancheSprites = SDL_LoadBMP("./pacman_sprites.bmp")) == NULL)
        std::cerr<<"Echec du chargement du bmp "<<SDL_GetError()<<std::endl;

    // big_pellets.insert({"BiPellet 1", new BigPellet{"BigPellet 1", {200, 9, 12, 12}}});
    initPellets();
    initIntersections();
}


GameManager::~GameManager()
{

}

void GameManager::initPellets()
{
    int x = 66;
    int y = 34;
    int space = 32;
    // Ligne 1 de Pellets
    pellets.insert({"Pellet 00_01", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 00_02", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 00_03", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 00_05", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 00_06", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 00_07", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 00_11", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 00_12", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 00_13", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 00_15", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 00_16", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 00_17", new Pellet{x, y, true}});
    // Ligne 2
    x = 34; y = 66;
    pellets.insert({"Pellet 01_00", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 01_04", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 01_08", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 01_10", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 01_14", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 01_18", new Pellet{x, y, true}});
    // Ligne 3
    x = 34; y = 98;
    big_pellets.insert({"BigPellet 02_00", new BigPellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 02_04", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 02_08", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 02_10", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 02_14", new Pellet{x, y, true}}); x+=space*4;
    big_pellets.insert({"BigPellet 02_18", new BigPellet{x, y, true}});
    // Ligne 4
    x = 34; y = 130;
    pellets.insert({"Pellet 03_00", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 03_04", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 03_08", new Pellet{x, y, true}}); x+=space*2;

    pellets.insert({"Pellet 03_10", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 03_14", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 03_18", new Pellet{x, y, true}});
    // Ligne 5
    x = 66; y = 162;
    pellets.insert({"Pellet 04_01", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 04_02", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 04_03", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 04_05", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 04_06", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 04_07", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 04_09", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 04_11", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 04_12", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 04_13", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 04_15", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 04_16", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 04_17", new Pellet{x, y, true}}); x+=space*2;
    // Ligne 6
    x = 34; y = 194;
    pellets.insert({"Pellet 05_00", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 05_04", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 05_08", new Pellet{x, y, true}}); x+=space*6;
    pellets.insert({"Pellet 05_10", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 05_14", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 05_18", new Pellet{x, y, true}});
    // Ligne 7
    x = 34; y = 226;
    pellets.insert({"Pellet 06_00", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 06_04", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 06_08", new Pellet{x, y, true}}); x+=space*6;
    pellets.insert({"Pellet 06_10", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 06_14", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 06_18", new Pellet{x, y, true}});
    // Ligne 8
    x = 66; y = 258;
    pellets.insert({"Pellet 07_01", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 07_02", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 07_03", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 07_07", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 07_11", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 07_15", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 07_16", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 07_17", new Pellet{x, y, true}});
    // Ligne 9
    x = 162; y = 290;
    pellets.insert({"Pellet 08_04", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 08_08", new Pellet{x, y, false}}); x+=space*2;
    pellets.insert({"Pellet 08_10", new Pellet{x, y, false}}); x+=space*4;
    pellets.insert({"Pellet 08_14", new Pellet{x, y, true}});
    // Ligne 10
    x = 162; y = 322;
    pellets.insert({"Pellet 09_04", new Pellet{x, y, true}}); x+=space*3;
    pellets.insert({"Pellet 09_07", new Pellet{x, y, false}}); x+=space*2;
    pellets.insert({"Pellet 09_09", new Pellet{x, y, false}}); x+=space*2;
    pellets.insert({"Pellet 09_11", new Pellet{x, y, false}}); x+=space*3;
    pellets.insert({"Pellet 09_14", new Pellet{x, y, true}});
    // Ligne 11
    x = 162; y = 354;
    pellets.insert({"Pellet 10_04", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 10_06", new Pellet{x, y, false}}); x+=space*6;
    pellets.insert({"Pellet 10_12", new Pellet{x, y, false}}); x+=space*2;
    pellets.insert({"Pellet 10_14", new Pellet{x, y, true}});
    // Ligne 12
    x = 162; y = 386;
    pellets.insert({"Pellet 11_04", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 11_06", new Pellet{x, y, false}}); x+=space*2;
    pellets.insert({"Pellet 11_08", new Pellet{x, y, false}}); x+=space;
    pellets.insert({"Pellet 11_09", new Pellet{x, y, false}}); x+=space;
    pellets.insert({"Pellet 11_10", new Pellet{x, y, false}}); x+=space*2;
    pellets.insert({"Pellet 11_12", new Pellet{x, y, false}}); x+=space*2;
    pellets.insert({"Pellet 11_14", new Pellet{x, y, true}});
    // Ligne 13
    x = 34; y = 418;
    pellets.insert({"Pellet 12_00", new Pellet{x, y, false}}); x+=space;
    pellets.insert({"Pellet 12_01", new Pellet{x, y, false}}); x+=space;
    pellets.insert({"Pellet 12_02", new Pellet{x, y, false}}); x+=space;
    pellets.insert({"Pellet 12_03", new Pellet{x, y, false}}); x+=space*2;
    // x = 194; y = 418;
    pellets.insert({"Pellet 12_05", new Pellet{x, y, false}}); x+=space*3;
    pellets.insert({"Pellet 12_07", new Pellet{x, y, false}}); x+=space;
    pellets.insert({"Pellet 12_08", new Pellet{x, y, false}}); x+=space;
    pellets.insert({"Pellet 12_09", new Pellet{x, y, false}}); x+=space*3;
    pellets.insert({"Pellet 12_13", new Pellet{x, y, false}}); x+=space*2;
    pellets.insert({"Pellet 12_15", new Pellet{x, y, false}}); x+=space;
    pellets.insert({"Pellet 12_16", new Pellet{x, y, false}}); x+=space;
    pellets.insert({"Pellet 12_17", new Pellet{x, y, false}}); x+=space;
    pellets.insert({"Pellet 12_18", new Pellet{x, y, false}});
    // Ligne 14
    x = 162; y = 450;
    pellets.insert({"Pellet 13_04", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 13_06", new Pellet{x, y, false}}); x+=space*6;
    pellets.insert({"Pellet 13_12", new Pellet{x, y, false}}); x+=space*2;
    pellets.insert({"Pellet 13_14", new Pellet{x, y, true}});
    // Ligne 15
    x = 162; y = 482;
    pellets.insert({"Pellet 14_04", new Pellet{x, y, true}}); x+=space*3;
    pellets.insert({"Pellet 14_07", new Pellet{x, y, false}}); x+=space;
    pellets.insert({"Pellet 14_08", new Pellet{x, y, false}}); x+=space;
    pellets.insert({"Pellet 14_09", new Pellet{x, y, false}}); x+=space;
    pellets.insert({"Pellet 14_10", new Pellet{x, y, false}}); x+=space;
    pellets.insert({"Pellet 14_11", new Pellet{x, y, false}}); x+=space*3;
    pellets.insert({"Pellet 14_14", new Pellet{x, y, true}});
    // Ligne 16
    x = 162; y = 514;
    pellets.insert({"Pellet 15_04", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 15_06", new Pellet{x, y, false}}); x+=space*6;
    pellets.insert({"Pellet 15_12", new Pellet{x, y, false}}); x+=space*2;
    pellets.insert({"Pellet 15_14", new Pellet{x, y, true}});
    // Ligne 17
    x = 162; y = 546;
    pellets.insert({"Pellet 16_04", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 16_06", new Pellet{x, y, false}}); x+=space*6;
    pellets.insert({"Pellet 16_12", new Pellet{x, y, false}}); x+=space*2;
    pellets.insert({"Pellet 16_14", new Pellet{x, y, true}});
    // Ligne 18
    x = 66; y = 578;
    pellets.insert({"Pellet 17_01", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 17_02", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 17_03", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 17_05", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 17_07", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 17_11", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 17_13", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 17_15", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 17_16", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 17_17", new Pellet{x, y, true}});
    // Ligne 19
    x = 34; y = 610;
    pellets.insert({"Pellet 18_00", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 18_04", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 18_08", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 18_10", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 18_14", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 18_18", new Pellet{x, y, true}});
    // Ligne 20
    x = 66; y = 642;
    pellets.insert({"Pellet 19_01", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 19_05", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 19_07", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 19_09", new Pellet{x, y, false}}); x+=space*2;
    pellets.insert({"Pellet 19_11", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 19_13", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 19_17", new Pellet{x, y, true}});
    // Ligne 21
    x = 98; y = 674;
    pellets.insert({"Pellet 20_02", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 20_04", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 20_06", new Pellet{x, y, true}}); x+=space*6;
    pellets.insert({"Pellet 20_12", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 20_14", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 20_16", new Pellet{x, y, true}});
    // Ligne 22
    x = 98; y = 706;
    pellets.insert({"Pellet 21_02", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 21_04", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 21_06", new Pellet{x, y, true}}); x+=space*6;
    pellets.insert({"Pellet 21_12", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 21_14", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 21_16", new Pellet{x, y, true}});
    // Ligne 23
    x = 66; y = 738;
    pellets.insert({"Pellet 22_01", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 22_07", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 22_09", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 22_11", new Pellet{x, y, true}}); x+=space*4;
    pellets.insert({"Pellet 22_15", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 22_17", new Pellet{x, y, true}});
    // Ligne 24
    x = 34; y = 770;
    pellets.insert({"Pellet 23_00", new Pellet{x, y, true}}); x+=space*8;
    pellets.insert({"Pellet 23_08", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 23_10", new Pellet{x, y, true}}); x+=space*8;
    pellets.insert({"Pellet 23_18", new Pellet{x, y, true}});
    // Ligne 25
    x = 66; y = 802;
    pellets.insert({"Pellet 24_01", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 24_02", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 24_03", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 24_04", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 24_05", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 24_06", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 24_07", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 24_09", new Pellet{x, y, true}}); x+=space*2;
    pellets.insert({"Pellet 24_11", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 24_12", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 24_13", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 24_14", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 24_15", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 24_16", new Pellet{x, y, true}}); x+=space;
    pellets.insert({"Pellet 24_17", new Pellet{x, y, true}});
}

void GameManager::initIntersections()
{
    int x = 34, y = 34;
    int space = 128;
    // Première ligne d'intersections
    intersections.insert({"Intersection 00_00", new Intersection<Pellet>{x, y, true, true, true, false, false}}); x += space;
    intersections.insert({"Intersection 00_04", new Intersection<Pellet>{x, y, true, true, true, true, false}}); x += space;
    intersections.insert({"Intersection 00_08", new Intersection<Pellet>{x, y, true, false, true, true, false}}); x += space/2;
    // On se décale pour passer à la partie droite
    // x = 354;
    intersections.insert({"Intersection 00_10", new Intersection<Pellet>{x, y, true, true, true, false, false}}); x += space;
    intersections.insert({"Intersection 00_14", new Intersection<Pellet>{x, y, true, true, true, true, false}}); x += space;
    intersections.insert({"Intersection 00_18", new Intersection<Pellet>{x, y, true, false, true, true, false}});

    // Deuxième ligne
    x = 34; y = 162;
    intersections.insert({"Intersection 04_00", new Intersection<Pellet>{x, y, true, true, true, false, true}}); x += space;
    intersections.insert({"Intersection 04_04", new Intersection<Pellet>{x, y, true, true, true, true, true}}); x += space/2;
    intersections.insert({"Intersection 04_06", new Intersection<Pellet>{x, y, true, true, true, true, false}}); x += space/2;
    intersections.insert({"Intersection 04_08", new Intersection<Pellet>{x, y, true, true, false, true, true}}); x += space/2;
    // x = 354;
    intersections.insert({"Intersection 04_10", new Intersection<Pellet>{x, y, true, true, false, true, true}}); x += space/2;
    intersections.insert({"Intersection 04_12", new Intersection<Pellet>{x, y, true, true, true, true, false}}); x += space/2;
    intersections.insert({"Intersection 04_14", new Intersection<Pellet>{x, y, true, true, true, true, true}}); x += space;
    intersections.insert({"Intersection 04_18", new Intersection<Pellet>{x, y, true, false, true, true, true}});

    x = 34; y = 258;
    intersections.insert({"Intersection 07_00", new Intersection<Pellet>{x, y, true, true, false, false, true}}); x += space;
    intersections.insert({"Intersection 07_04", new Intersection<Pellet>{x, y, true, false, true, true, true}}); x += space/2;
    intersections.insert({"Intersection 07_06", new Intersection<Pellet>{x, y, true, true, false, false, true}}); x += space/2;
    intersections.insert({"Intersection 07_08", new Intersection<Pellet>{x, y, true, false, true, true, false}}); x += space/2;
    intersections.insert({"Intersection 07_10", new Intersection<Pellet>{x, y, true, true, true, false, false}}); x += space/2;
    intersections.insert({"Intersection 07_12", new Intersection<Pellet>{x, y, true, false, false, true, true}}); x += space/2;
    intersections.insert({"Intersection 07_14", new Intersection<Pellet>{x, y, true, true, true, false, true}}); x += space;
    intersections.insert({"Intersection 07_18", new Intersection<Pellet>{x, y, true, false, false, true, true}});

    x = 226; y = 322;
    intersections.insert({"Intersection 09_06", new Intersection<Pellet>{x, y, false, true, true, false, false}}); x += space/2;
    intersections.insert({"Intersection 09_08", new Intersection<Pellet>{x, y, false, true, false, true, true}}); x += space/2;
    intersections.insert({"Intersection 09_10", new Intersection<Pellet>{x, y, false, true, false, true, true}}); x += space/2;
    intersections.insert({"Intersection 09_12", new Intersection<Pellet>{x, y, false, false, true, true, false}});

    x = 162; y = 418;
    intersections.insert({"Intersection 12_04", new Intersection<Pellet>{x, y, true, true, true, true, true}});x += space/2;
    intersections.insert({"Intersection 12_06", new Intersection<Pellet>{x, y, false, false, true, true, true}});x += space/2*3;
    intersections.insert({"Intersection 12_12", new Intersection<Pellet>{x, y, false, true, true, false, true}});x += space/2;
    intersections.insert({"Intersection 12_14", new Intersection<Pellet>{x, y, true, true, true, true, true}});

    x = 226; y = 482;
    intersections.insert({"Intersection 14_06", new Intersection<Pellet>{x, y, false, true, true, false, true}});x += space/2*3;
    intersections.insert({"Intersection 14_14", new Intersection<Pellet>{x, y, false, false, true, true, true}});

    x = 34; y = 578;
    intersections.insert({"Intersection 17_00", new Intersection<Pellet>{x, y, true, true, true, false, false}}); x += space;
    intersections.insert({"Intersection 17_04", new Intersection<Pellet>{x, y, true, true, true, true, true}}); x += space/2;
    intersections.insert({"Intersection 17_06", new Intersection<Pellet>{x, y, true, true, false, true, true}}); x += space/2;
    intersections.insert({"Intersection 17_08", new Intersection<Pellet>{x, y, true, false, true, true, false}}); x += space/2;
    intersections.insert({"Intersection 17_10", new Intersection<Pellet>{x, y, true, true, true, false, false}}); x += space/2;
    intersections.insert({"Intersection 17_12", new Intersection<Pellet>{x, y, true, true, false, true, true}}); x += space/2;
    intersections.insert({"Intersection 17_14", new Intersection<Pellet>{x, y, true, true, true, true, true}}); x += space;
    intersections.insert({"Intersection 17_18", new Intersection<Pellet>{x, y, true, false, true, true, false}});

    x = 34; y = 642;
    intersections_big.insert({"BigIntersection 19_00", new Intersection<BigPellet>{x, y, true, true, false, false, true}}); x += space/2;
    intersections.insert({"Intersection 19_02", new Intersection<Pellet>{x, y, true, false, true, true, false}}); x += space/2;
    intersections.insert({"Intersection 19_04", new Intersection<Pellet>{x, y, true, true, true, false, true}}); x += space/2;
    intersections.insert({"Intersection 19_06", new Intersection<Pellet>{x, y, true, true, true, true, false}}); x += space/2;
    intersections.insert({"Intersection 19_08", new Intersection<Pellet>{x, y, true, true, false, true, true}}); x += space/2;
    intersections.insert({"Intersection 19_10", new Intersection<Pellet>{x, y, true, true, false, true, true}}); x += space/2;
    intersections.insert({"Intersection 19_12", new Intersection<Pellet>{x, y, true, true, true, true, false}}); x += space/2;
    intersections.insert({"Intersection 19_14", new Intersection<Pellet>{x, y, true, false, true, true, true}}); x += space/2;
    intersections.insert({"Intersection 19_16", new Intersection<Pellet>{x, y, true, true, true, false, false}}); x += space/2;
    intersections_big.insert({"BigIntersection 19_18", new Intersection<BigPellet>{x, y, true, false, false, true, true}});

    x = 34; y = 738;
    intersections.insert({"Intersection 22_00", new Intersection<Pellet>{x, y, true, true, true, false, false}}); x += space/2;
    intersections.insert({"Intersection 22_02", new Intersection<Pellet>{x, y, true, true, false, true, true}}); x += space/2;
    intersections.insert({"Intersection 22_04", new Intersection<Pellet>{x, y, true, false, false, true, true}}); x += space/2;
    intersections.insert({"Intersection 22_06", new Intersection<Pellet>{x, y, true, true, false, false, true}}); x += space/2;
    intersections.insert({"Intersection 22_08", new Intersection<Pellet>{x, y, true, false, true, true, false}}); x += space/2;
    intersections.insert({"Intersection 22_10", new Intersection<Pellet>{x, y, true, true, true, false, false}}); x += space/2;
    intersections.insert({"Intersection 22_12", new Intersection<Pellet>{x, y, true, false, false, true, true}}); x += space/2;
    intersections.insert({"Intersection 22_14", new Intersection<Pellet>{x, y, true, true, false, false, true}}); x += space/2;
    intersections.insert({"Intersection 22_16", new Intersection<Pellet>{x, y, true, true, false, true, true}}); x += space/2;
    intersections.insert({"Intersection 22_18", new Intersection<Pellet>{x, y, true, false, true, true, false}});

    x = 34; y = 802;
    intersections.insert({"Intersection 24_00", new Intersection<Pellet>{x, y, true, true, false, false, true}}); x += space/2*4;
    intersections.insert({"Intersection 24_08", new Intersection<Pellet>{x, y, true, true, false, true, true}}); x += space/2;
    intersections.insert({"Intersection 24_10", new Intersection<Pellet>{x, y, true, true, false, true, true}}); x += space/2*4;
    intersections.insert({"Intersection 24_18", new Intersection<Pellet>{x, y, true, false, false, true, true}});
}

bool GameManager::isGameOver()
{
    if(score == 2100)
        return true;
    return false;
}

void GameManager::checkForZone(int x, int y)
{
    for (auto it = zones.begin(); it != zones.end(); ++it) {
        if(it->second->x == x && it->second->y == y)
        {
            std::cout<<it->first<<std::endl;
        }
    }
}

template <typename T>
void GameManager::checkForPelletTemplate(int x, int y, T map)
{
    for (auto it = map.begin(); it != map.end(); ++it) {
        if(it->second->x == x && it->second->y == y)
        {
            // std::cout<<it->first<<std::endl;
            it->second->setGotThrew(false);
            if(it->second->hasPellet())
            {
                score += it->second->addPoints();
                it->second->setHasPellet();
            }
        }
    }
}

void GameManager::checkForPellet(int x, int y)
{
    checkForPelletTemplate(x, y, pellets);
    checkForPelletTemplate(x, y, big_pellets);
}

template <typename T>
int GameManager::checkForIntersectionTemplate(int x, int y, int last_pressed_key, T map)
{
    bool isIntersection = false;
    for (auto it = map.begin(); it != map.end(); ++it) {
        if(it->second->x == x && it->second->y == y)
        {
            // std::cout<<it->first<<std::endl;
            it->second->setGotThrew(false);
            if(it->second->hasPellet())
            {
                score += it->second->addPoints();
                it->second->setHasPellet();
            }
            if(last_pressed_key == 0 && it->second->canGoRight() || last_pressed_key == 1 && it->second->canGoDown()
            || last_pressed_key == 2 && it->second->canGoLeft() || last_pressed_key == 3 && it->second->canGoUp())
                return 1;
            else
                return 2;
        }
    }
    return 0;
}

int GameManager::checkForIntersection(int x, int y, int last_pressed_key)
{
    return checkForIntersectionTemplate(x, y, last_pressed_key, intersections) + checkForIntersectionTemplate(x, y, last_pressed_key, intersections_big);
}

template <typename T>
void GameManager::updatePellets(T map)
{
    for (auto it = map.begin(); it != map.end(); ++it) {
        if(!it->second->getGotThrew())
        {
            SDL_Rect init = {376, 10, 10, 10};
            setColorAndBlitScaled(false, &init, it->second->getRectangle());
        }
    }
}

template <typename T>
void GameManager::updateIntersections(T map)
{
    for (auto it = map.begin(); it != map.end(); ++it) {
        if(!it->second->getGotThrew())
        {
            SDL_Rect init = {376, 10, 10, 10};
            setColorAndBlitScaled(false, &init, it->second->getRectangle());
        }
    }
}

void GameManager::updateInterface(SDL_Rect* ghost_rect, SDL_Rect ghost_rect_in)
{
    setColorAndBlitScaled(false, &src_bg, &bg);
    std::cout<<score<<std::endl;

    SDL_Rect black_rect = {376, 10, 10, 10}; // Position d'un rectangle noir

    count = (count + 1) % (250);
    if(0 <= count and count <= 125)
    {
        setColorAndBlitScaled(false, &black_rect, intersections_big.at("BigIntersection 19_00")->getRectangle());
        setColorAndBlitScaled(false, &black_rect, intersections_big.at("BigIntersection 19_18")->getRectangle());
        setColorAndBlitScaled(false, &black_rect, big_pellets.at("BigPellet 02_00")->getRectangle());
        setColorAndBlitScaled(false, &black_rect, big_pellets.at("BigPellet 02_18")->getRectangle());
    }

    updatePellets(pellets);
    updatePellets(big_pellets);
    updateIntersections(intersections);
    updateIntersections(intersections_big);

    SDL_Rect ghost_in2 = ghost_rect_in;
    // if ((count / 8) % 2)
        // ghost_in2.x += 20;
    setColorAndBlitScaled(true, &ghost_in2, ghost_rect);

    SDL_UpdateWindowSurface(pWindow);

    // LIMITE A 60 FPS
    SDL_Delay(4); // SDL_Delay(16); de base
    // utiliser SDL_GetTicks64() pour plus de precisions

}
