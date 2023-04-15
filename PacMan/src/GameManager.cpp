#include "../include/GameManager.h"
#include <iostream>

#include <SDL.h>

GameManager::GameManager()
: count(0)
, src_bg({200, 3, 168, 216})
, bg({4, 4, 672, 864})
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

    zones.insert({"Zone 1", new Zone{{206, 9, 12, 12}, 0, 0}});
    zones.insert({"Zone 2", new Zone{{206, 9, 12, 12}, 0, 0}});
    zones.insert({"Zone 3", new Zone{{206, 9, 12, 12}, 0, 0}});
    zones.insert({"Zone 4", new Zone{{206, 9, 12, 12}, 0, 0}});
    zones.insert({"Zone 5", new Zone{{206, 9, 12, 12}, 0, 0}});

    // big_pellets.insert({"BiPellet 1", new BigPellet{{206, 9, 12, 12}, "BigPellet 1", {200, 9, 12, 12}}});
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

    // Première ligne de Pellets
    pellets.insert({"Pellet 00_01", new Pellet{{206, 9, 12, 12}, x, y, {y, 32, 32, 32}}}); x+=space;
    pellets.insert({"Pellet 00_02", new Pellet{{206, 9, 12, 12}, x, y, {y, 32, 32, 32}}}); x+=space;
    pellets.insert({"Pellet 00_03", new Pellet{{206, 9, 12, 12}, x, y, {y, 32, 32, 32}}}); x+=space*2;

    pellets.insert({"Pellet 00_05", new Pellet{{206, 9, 12, 12}, x, y, {32, 32, 32, 32}}}); x+=space;
    pellets.insert({"Pellet 00_06", new Pellet{{206, 9, 12, 12}, x, y, {32, 32, 32, 32}}}); x+=space;
    pellets.insert({"Pellet 00_07", new Pellet{{206, 9, 12, 12}, x, y, {32, 32, 32, 32}}}); x+=space*4;

    pellets.insert({"Pellet 00_11", new Pellet{{206, 9, 12, 12}, x, y, {32, 32, 32, 32}}}); x+=space;
    pellets.insert({"Pellet 00_12", new Pellet{{206, 9, 12, 12}, x, y, {32, 32, 32, 32}}}); x+=space;
    pellets.insert({"Pellet 00_13", new Pellet{{206, 9, 12, 12}, x, y, {32, 32, 32, 32}}}); x+=space*2;

    pellets.insert({"Pellet 00_15", new Pellet{{206, 9, 12, 12}, x, y, {32, 32, 32, 32}}}); x+=space;
    pellets.insert({"Pellet 00_16", new Pellet{{206, 9, 12, 12}, x, y, {32, 32, 32, 32}}}); x+=space;
    pellets.insert({"Pellet 00_17", new Pellet{{206, 9, 12, 12}, x, y, {32, 32, 32, 32}}}); x+=space*2;

    // Il faut encore rajouter les pellets verticals qu'il manque (comme 1,0 2,0 3,0 etc...)

    // Deuxième ligne de Pellets
    x = 34; y = 162;

    pellets.insert({"Pellet 04_01", new Pellet{{206, 9, 12, 12}, x, y, {64, 32, 32, 32}}}); x+=space;
    pellets.insert({"Pellet 04_02", new Pellet{{206, 9, 12, 12}, x, y, {96, 32, 32, 32}}}); x+=space;
    pellets.insert({"Pellet 04_03", new Pellet{{206, 9, 12, 12}, x, y, {128, 32, 32, 32}}}); x+=space*2;

    pellets.insert({"Pellet 04_05", new Pellet{{206, 9, 12, 12}, x, y, {128, 32, 32, 32}}}); x+=space;
    pellets.insert({"Pellet 04_06", new Pellet{{206, 9, 12, 12}, x, y, {128, 32, 32, 32}}}); x+=space;
    pellets.insert({"Pellet 04_07", new Pellet{{206, 9, 12, 12}, x, y, {128, 32, 32, 32}}}); x+=space*4;

    pellets.insert({"Pellet 04_11", new Pellet{{206, 9, 12, 12}, x, y, {128, 32, 32, 32}}}); x+=space;
    pellets.insert({"Pellet 04_12", new Pellet{{206, 9, 12, 12}, x, y, {128, 32, 32, 32}}}); x+=space;
    pellets.insert({"Pellet 04_13", new Pellet{{206, 9, 12, 12}, x, y, {128, 32, 32, 32}}}); x+=space*2;

    pellets.insert({"Pellet 04_15", new Pellet{{206, 9, 12, 12}, x, y, {128, 32, 32, 32}}}); x+=space;
    pellets.insert({"Pellet 04_16", new Pellet{{206, 9, 12, 12}, x, y, {128, 32, 32, 32}}}); x+=space;
    pellets.insert({"Pellet 04_17", new Pellet{{206, 9, 12, 12}, x, y, {128, 32, 32, 32}}}); x+=space*2;
    
}

void GameManager::initIntersections()
{
    int x = 34, y = 34;
    int space = 128;
    // Première ligne d'intersections
    intersections.insert({"Intersection 00_00", new Intersection{{206, 9, 12, 12}, x, y, {32, 32, 32, 32}, true, true, false, false}}); x += space;
    intersections.insert({"Intersection 00_04", new Intersection{{214, 9, 12, 12}, x, y, {160, 32, 32, 32}, true, true, true, false}}); x += space;
    intersections.insert({"Intersection 00_08", new Intersection{{222, 9, 12, 12}, x, y, {1, 1, 1, 11}, false, true, true, false}});
    // On se décale pour passer à la partie droite
    x = 354;
    intersections.insert({"Intersection 00_10", new Intersection{{222, 9, 12, 12}, x, y, {1, 1, 1, 11}, true, true, false, false}}); x += space;
    intersections.insert({"Intersection 00_14", new Intersection{{214, 9, 12, 12}, x, y, {160, 32, 32, 32}, true, true, true, false}}); x += space;
    intersections.insert({"Intersection 00_18", new Intersection{{222, 9, 12, 12}, x, y, {1, 1, 1, 11}, false, true, true, false}});

    // Deuxième ligne
    x = 34; y = 162;
    intersections.insert({"Intersection 04_00", new Intersection{{206, 9, 12, 12}, x, y, {32, 32, 32, 32}, true, true, false, false}}); x += space;
    intersections.insert({"Intersection 04_04", new Intersection{{214, 9, 12, 12}, x, y, {160, 32, 32, 32}, true, true, true, false}}); x += space;
    intersections.insert({"Intersection 04_08", new Intersection{{222, 9, 12, 12}, x, y, {1, 1, 1, 11}, false, true, true, false}});
    x = 354;
    intersections.insert({"Intersection 04_10", new Intersection{{222, 9, 12, 12}, x, y, {1, 1, 1, 11}, true, true, false, false}}); x += space;
    intersections.insert({"Intersection 04_14", new Intersection{{214, 9, 12, 12}, x, y, {160, 32, 32, 32}, true, true, true, false}}); x += space;
    intersections.insert({"Intersection 04_18", new Intersection{{222, 9, 12, 12}, x, y, {1, 1, 1, 11}, false, true, true, false}});
}

// faire une méthode pour la détection comme ici,
// mais ensuite appeler une méthode qui met à jour les valeurs
// parce que pour l'intersections par exemple,
// on va mettre à jour + is_passed en false + donenr orientations
// et pour Pellet on va aussi mettre à jour + is_passed 
// -> donc on aura des répétitions de code

void GameManager::checkForZone(int x, int y)
{
    for (auto it = zones.begin(); it != zones.end(); ++it) {
        if(it->second->x == x && it->second->y == y)
        {
            std::cout<<it->first<<std::endl;
        }
    }
}

void GameManager::checkForPellet(int x, int y)
{
    for (auto it = pellets.begin(); it != pellets.end(); ++it) {
        if(it->second->x == x && it->second->y == y)
        {
            std::cout<<it->first<<std::endl;
            it->second->setGotThrew(false);
        }
    }
}

bool GameManager::checkForIntersection(int x, int y)
{
    bool isIntersection = false;
    for (auto it = intersections.begin(); it != intersections.end(); ++it) {
        if(it->second->x == x && it->second->y == y)
        {
            std::cout<<it->first<<std::endl;
            isIntersection = !isIntersection;
            // update le is_passed et mettre à jour le fond
            // prendre en compte les orientations possibles et 
            // mettre cette orientation en place (jsp comment encore)
        }
    }
    return isIntersection;
}

void GameManager::updatePellets()
{
    for (auto it = pellets.begin(); it != pellets.end(); ++it) {
        if(!it->second->getGotThrew())
        {
            SDL_Rect init = {376, 10, 10, 10};
            setColorAndBlitScaled(false, &init, it->second->getPassed());
        }
    }
}

void GameManager::updateInterface(SDL_Rect* ghost_rect, SDL_Rect ghost_rect_in)
{
    setColorAndBlitScaled(false, &src_bg, &bg);
    
    // met la toute première intersection à jour en mettant son
    // fond noir de droite

    // mise à jour d'une case (par exemple les cases : case_01, 10 et 20)
    SDL_Rect init = {376, 10, 10, 10}; // où on trouve le rectagle noir
    // SDL_Rect case_00 = {32, 32, 32, 32}; // la position de la première case
    SDL_Rect case_01 = {64, 32, 32, 32}; // la position de la case 01
    SDL_Rect case_10 = {32, 64, 32, 32};
    SDL_Rect case_20 = {32, 96, 32, 32};
    // setColorAndBlitScaled(false, &init, &case_20);
    // setColorAndBlitScaled(false, &init, &case_10);


    // IL FAUT QUE LES setColorAndBlitScaled SOIT DANS CETTE FONCTION
    // POUR QUE CA SE METTE A JOUR SINON CA MARCHE PAS
    count = (count + 1) % (512);
    if(0 <= count and count <= 250)
        setColorAndBlitScaled(false, &init, &case_20);

    // // ici on change entre les 2 sprites sources pour une jolie animation.
    // SDL_Rect ghost_in2 = *ghost_in;
    // if ((count / 4) % 2)
    //     ghost_in2.x += 17;
    
    updatePellets();

    SDL_Rect ghost_in2 = ghost_rect_in;
    setColorAndBlitScaled(true, &ghost_in2, ghost_rect);

    SDL_UpdateWindowSurface(pWindow);

    // LIMITE A 60 FPS
    SDL_Delay(16); // SDL_Delay(16); de base
    // utiliser SDL_GetTicks64() pour plus de precisions

}
