#include "../include/GameManager.h"
#include <iostream>

#include <SDL.h>

    // // intersections
    // SDL_Rect intersection00 = {206, 9, 12, 12};
    // SDL_Rect intersection01 = {214, 9, 12, 12};
    // SDL_Rect intersection02 = {222, 9, 12, 12};
    // SDL_Rect intersection03 = {230, 9, 12, 12};
    // SDL_Rect intersection04 = {238, 9, 12, 12};
    // SDL_Rect intersection05 = {254, 9, 12, 12};
    // SDL_Rect intersection06 = {262, 9, 12, 12};
    // SDL_Rect intersection07 = {270, 9, 12, 12};

    // SDL_Rect intersection10 = {206, 17, 12, 12};
    // SDL_Rect intersection14 = {238, 17, 12, 12};
    // SDL_Rect intersection17 = {270, 17, 12, 12};

    // SDL_Rect intersection20 = {206, 25, 12, 12};
    // SDL_Rect intersection24 = {238, 25, 12, 12};
    // SDL_Rect intersection27 = {270, 25, 12, 12};

    // SDL_Rect intersection30 = {206, 33, 12, 12};
    // SDL_Rect intersection34 = {238, 33, 12, 12};
    // SDL_Rect intersection37 = {270, 33, 12, 12};

    // SDL_Rect intersection40 = {206, 41, 12, 12};
    // SDL_Rect intersection41 = {214, 41, 12, 12};
    // SDL_Rect intersection42 = {222, 41, 12, 12};
    // SDL_Rect intersection43 = {230, 41, 12, 12};
    // SDL_Rect intersection44 = {238, 41, 12, 12};
    // SDL_Rect intersection45 = {254, 41, 12, 12};
    // SDL_Rect intersection46 = {262, 41, 12, 12};
    // SDL_Rect intersection47 = {270, 41, 12, 12};

GameManager::GameManager()
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
    // count pour l'instant non utilisé
    count = 0;
    src_bg = {200, 3, 168, 216}; // x,y, w,h (0,0) en haut a gauche
    bg = {4, 4, 672, 864};       // ici scale x4


    zones.insert({"Zone 1", new Zone{{206, 9, 12, 12}, "Zone 1", 0, 0}});
    zones.insert({"Zone 2", new Zone{{206, 9, 12, 12}, "Zone 2", 0, 0}});
    zones.insert({"Zone 3", new Zone{{206, 9, 12, 12}, "Zone 3", 0, 0}});
    zones.insert({"Zone 4", new Zone{{206, 9, 12, 12}, "Zone 4", 0, 0}});
    zones.insert({"Zone 5", new Zone{{206, 9, 12, 12}, "Zone 5", 0, 0}});


    pellets.insert({"Pellet 00_01", new Pellet{{206, 9, 12, 12}, "Pellet 00_01", 66, 34, {64, 32, 32, 32}}});
    pellets.insert({"Pellet 00_02", new Pellet{{206, 9, 12, 12}, "Pellet 00_02", 98, 34, {96, 32, 32, 32}}});
    pellets.insert({"Pellet 00_03", new Pellet{{206, 9, 12, 12}, "Pellet 00_03", 130, 34, {128, 32, 32, 32}}});

    
    pellets.insert({"Pellet 01_00", new Pellet{{206, 9, 12, 12}, "Pellet 01_00", 34, 66, {200, 9, 12, 12}}});
    pellets.insert({"Pellet 02_00", new Pellet{{206, 9, 12, 12}, "Pellet 02_00", 34, 98, {200, 9, 12, 12}}});
    pellets.insert({"Pellet 03_00", new Pellet{{206, 9, 12, 12}, "Pellet 03_00", 34, 130, {200, 9, 12, 12}}});

    // big_pellets.insert({"BiPellet 1", new BigPellet{{206, 9, 12, 12}, "BigPellet 1", {200, 9, 12, 12}}});

    intersections.insert({"Intersection 00_00", new Intersection{{206, 9, 12, 12}, "Intersection 00_00", 34, 34, {32, 32, 32, 32}, true, true, false, false}});
    intersections.insert({"Intersection 00_04", new Intersection{{214, 9, 12, 12}, "Intersection 00_04", 162, 34, {160, 32, 32, 32}, true, true, true, false}});
    intersections.insert({"Intersection 00_08", new Intersection{{222, 9, 12, 12}, "Intersection 00_08", 290, 34, {1, 1, 1, 11}, false, true, true, false}});
    intersections.insert({"Intersection 04_00", new Intersection{{230, 9, 12, 12}, "Intersection 04_00", 34, 162, {1, 1, 1, 11}, true, true, false, true}});
    // intersections.insert({"Intersection 08_00", new Intersection{{230, 9, 12, 12}, "Intersection 08_00", 34, 290, {1, 1, 1, 11}, true, true, true, true}});
    intersections.insert({"Intersection 04_04", new Intersection{{230, 9, 12, 12}, "Intersection 04_04", 162, 162, {1, 1, 1, 11}, true, true, true, true}});
    intersections.insert({"Intersection 04_08", new Intersection{{230, 9, 12, 12}, "Intersection 04_08", 290, 162, {1, 1, 1, 11}, true, false, true, true}});

}


GameManager::~GameManager()
{

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
        // std::cout<<"key : "<<it->first<<" with data : "<<it->second.first<<", "<<it->second.second<<"\n";
        if(it->second->x == x && it->second->y == y)
        {
            std::cout<<it->first<<std::endl;
        }
    }
}

void GameManager::checkForPellet(int x, int y)
{
    for (auto it = pellets.begin(); it != pellets.end(); ++it) {
        // std::cout<<"key : "<<it->first<<" with data : "<<it->second.first<<", "<<it->second.second<<"\n";
        if(it->second->x == x && it->second->y == y)
        {
            std::cout<<it->first<<std::endl;
            it->second->setGotThrew(false);
        }
    }
}

void GameManager::checkForIntersection(int x, int y)
{
    for (auto it = intersections.begin(); it != intersections.end(); ++it) {
        // std::cout<<"key : "<<it->first<<" with data : "<<it->second.first<<", "<<it->second.second<<"\n";
        if(it->second->x == x && it->second->y == y)
        {
            std::cout<<it->first<<std::endl;
            // update le is_passed et mettre à jour le fond
            // prendre en compte les orientations possibles et 
            // mettre cette orientation en place (jsp comment encore)
        }
    }
}

void GameManager::updatePellets()
{
    for (auto it = pellets.begin(); it != pellets.end(); ++it) {
        if(!it->second->getGotThrew())
        {
            SDL_Rect init = {376, 10, 10, 10};
            // SDL_Rect test = it->second->getPassed();
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
