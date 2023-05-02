#include "../include/MapInitialization.h"

void initPellets(std::map<std::string, std::shared_ptr<Pellet>> *pellets, std::map<std::string, std::shared_ptr<BigPellet>> *big_pellets)
{
    int x = 66;
    int y = 34;
    int space = 32;
    // Ligne 1 de Pellets
    pellets->insert({"Pellet 00_01", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 00_02", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 00_03", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 00_05", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 00_06", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 00_07", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 00_11", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 00_12", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 00_13", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 00_15", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 00_16", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 00_17", std::make_shared<Pellet>(x, y, true)});
    // Ligne 2
    x = 34; y = 66;
    pellets->insert({"Pellet 01_00", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 01_04", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 01_08", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 01_10", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 01_14", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 01_18", std::make_shared<Pellet>(x, y, true)});
    // Ligne 3
    x = 34; y = 98;
    big_pellets->insert({"BigPellet 02_00", std::make_shared<BigPellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 02_04", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 02_08", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 02_10", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 02_14", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    big_pellets->insert({"BigPellet 02_18", std::make_shared<BigPellet>(x, y, true)});
    // Ligne 4
    x = 34; y = 130;
    pellets->insert({"Pellet 03_00", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 03_04", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 03_08", std::make_shared<Pellet>(x, y, true)}); x+=space*2;

    pellets->insert({"Pellet 03_10", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 03_14", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 03_18", std::make_shared<Pellet>(x, y, true)});
    // Ligne 5
    x = 66; y = 162;
    pellets->insert({"Pellet 04_01", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 04_02", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 04_03", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 04_05", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 04_06", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 04_07", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 04_09", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 04_11", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 04_12", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 04_13", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 04_15", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 04_16", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 04_17", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    // Ligne 6
    x = 34; y = 194;
    pellets->insert({"Pellet 05_00", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 05_04", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 05_08", std::make_shared<Pellet>(x, y, true)}); x+=space*6;
    pellets->insert({"Pellet 05_10", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 05_14", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 05_18", std::make_shared<Pellet>(x, y, true)});
    // Ligne 7
    x = 34; y = 226;
    pellets->insert({"Pellet 06_00", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 06_04", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 06_08", std::make_shared<Pellet>(x, y, true)}); x+=space*6;
    pellets->insert({"Pellet 06_10", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 06_14", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 06_18", std::make_shared<Pellet>(x, y, true)});
    // Ligne 8
    x = 66; y = 258;
    pellets->insert({"Pellet 07_01", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 07_02", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 07_03", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 07_07", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 07_11", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 07_15", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 07_16", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 07_17", std::make_shared<Pellet>(x, y, true)});
    // Ligne 9
    x = 162; y = 290;
    pellets->insert({"Pellet 08_04", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 08_08", std::make_shared<Pellet>(x, y, false)}); x+=space*2;
    pellets->insert({"Pellet 08_10", std::make_shared<Pellet>(x, y, false)}); x+=space*4;
    pellets->insert({"Pellet 08_14", std::make_shared<Pellet>(x, y, true)});
    // Ligne 10
    x = 162; y = 322;
    pellets->insert({"Pellet 09_04", std::make_shared<Pellet>(x, y, true)}); x+=space*3;
    pellets->insert({"Pellet 09_07", std::make_shared<Pellet>(x, y, false)}); x+=space*2;
    pellets->insert({"Pellet 09_09", std::make_shared<Pellet>(x, y, false)}); x+=space*2;
    pellets->insert({"Pellet 09_11", std::make_shared<Pellet>(x, y, false)}); x+=space*3;
    pellets->insert({"Pellet 09_14", std::make_shared<Pellet>(x, y, true)});
    // Ligne 11
    x = 162; y = 354;
    pellets->insert({"Pellet 10_04", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 10_06", std::make_shared<Pellet>(x, y, false)}); x+=space*6;
    pellets->insert({"Pellet 10_12", std::make_shared<Pellet>(x, y, false)}); x+=space*2;
    pellets->insert({"Pellet 10_14", std::make_shared<Pellet>(x, y, true)});
    // Ligne 12
    x = 162; y = 386;
    pellets->insert({"Pellet 11_04", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 11_06", std::make_shared<Pellet>(x, y, false)}); x+=space*2;
    pellets->insert({"Pellet 11_08", std::make_shared<Pellet>(x, y, false)}); x+=space;
    pellets->insert({"Pellet 11_09", std::make_shared<Pellet>(x, y, false)}); x+=space;
    pellets->insert({"Pellet 11_10", std::make_shared<Pellet>(x, y, false)}); x+=space*2;
    pellets->insert({"Pellet 11_12", std::make_shared<Pellet>(x, y, false)}); x+=space*2;
    pellets->insert({"Pellet 11_14", std::make_shared<Pellet>(x, y, true)});
    // Ligne 13
    x = 2; y = 418;
    pellets->insert({"Pellet 12_left", std::make_shared<Pellet>(x, y, false)}); x+=space;
    pellets->insert({"Pellet 12_00", std::make_shared<Pellet>(x, y, false)}); x+=space;
    pellets->insert({"Pellet 12_01", std::make_shared<Pellet>(x, y, false)}); x+=space;
    pellets->insert({"Pellet 12_02", std::make_shared<Pellet>(x, y, false)}); x+=space;
    pellets->insert({"Pellet 12_03", std::make_shared<Pellet>(x, y, false)}); x+=space*2;
    // x = 194; y = 418;
    pellets->insert({"Pellet 12_05", std::make_shared<Pellet>(x, y, false)}); x+=space*3;
    pellets->insert({"Pellet 12_07", std::make_shared<Pellet>(x, y, false)}); x+=space;
    pellets->insert({"Pellet 12_08", std::make_shared<Pellet>(x, y, false)}); x+=space;
    pellets->insert({"Pellet 12_09", std::make_shared<Pellet>(x, y, false)}); x+=space*3;
    pellets->insert({"Pellet 12_13", std::make_shared<Pellet>(x, y, false)}); x+=space*2;
    pellets->insert({"Pellet 12_15", std::make_shared<Pellet>(x, y, false)}); x+=space;
    pellets->insert({"Pellet 12_16", std::make_shared<Pellet>(x, y, false)}); x+=space;
    pellets->insert({"Pellet 12_17", std::make_shared<Pellet>(x, y, false)}); x+=space;
    pellets->insert({"Pellet 12_18", std::make_shared<Pellet>(x, y, false)}); x+=space;
    pellets->insert({"Pellet 12_right", std::make_shared<Pellet>(x, y, false)});
    // Ligne 14
    x = 162; y = 450;
    pellets->insert({"Pellet 13_04", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 13_06", std::make_shared<Pellet>(x, y, false)}); x+=space*6;
    pellets->insert({"Pellet 13_12", std::make_shared<Pellet>(x, y, false)}); x+=space*2;
    pellets->insert({"Pellet 13_14", std::make_shared<Pellet>(x, y, true)});
    // Ligne 15
    x = 162; y = 482;
    pellets->insert({"Pellet 14_04", std::make_shared<Pellet>(x, y, true)}); x+=space*3;
    pellets->insert({"Pellet 14_07", std::make_shared<Pellet>(x, y, false)}); x+=space;
    pellets->insert({"Pellet 14_08", std::make_shared<Pellet>(x, y, false)}); x+=space;
    pellets->insert({"Pellet 14_09", std::make_shared<Pellet>(x, y, false)}); x+=space;
    pellets->insert({"Pellet 14_10", std::make_shared<Pellet>(x, y, false)}); x+=space;
    pellets->insert({"Pellet 14_11", std::make_shared<Pellet>(x, y, false)}); x+=space*3;
    pellets->insert({"Pellet 14_14", std::make_shared<Pellet>(x, y, true)});
    // Ligne 16
    x = 162; y = 514;
    pellets->insert({"Pellet 15_04", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 15_06", std::make_shared<Pellet>(x, y, false)}); x+=space*6;
    pellets->insert({"Pellet 15_12", std::make_shared<Pellet>(x, y, false)}); x+=space*2;
    pellets->insert({"Pellet 15_14", std::make_shared<Pellet>(x, y, true)});
    // Ligne 17
    x = 162; y = 546;
    pellets->insert({"Pellet 16_04", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 16_06", std::make_shared<Pellet>(x, y, false)}); x+=space*6;
    pellets->insert({"Pellet 16_12", std::make_shared<Pellet>(x, y, false)}); x+=space*2;
    pellets->insert({"Pellet 16_14", std::make_shared<Pellet>(x, y, true)});
    // Ligne 18
    x = 66; y = 578;
    pellets->insert({"Pellet 17_01", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 17_02", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 17_03", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 17_05", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 17_07", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 17_11", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 17_13", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 17_15", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 17_16", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 17_17", std::make_shared<Pellet>(x, y, true)});
    // Ligne 19
    x = 34; y = 610;
    pellets->insert({"Pellet 18_00", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 18_04", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 18_08", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 18_10", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 18_14", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 18_18", std::make_shared<Pellet>(x, y, true)});
    // Ligne 20
    x = 66; y = 642;
    pellets->insert({"Pellet 19_01", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 19_05", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 19_07", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 19_09", std::make_shared<Pellet>(x, y, false)}); x+=space*2;
    pellets->insert({"Pellet 19_11", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 19_13", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 19_17", std::make_shared<Pellet>(x, y, true)});
    // Ligne 21
    x = 98; y = 674;
    pellets->insert({"Pellet 20_02", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 20_04", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 20_06", std::make_shared<Pellet>(x, y, true)}); x+=space*6;
    pellets->insert({"Pellet 20_12", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 20_14", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 20_16", std::make_shared<Pellet>(x, y, true)});
    // Ligne 22
    x = 98; y = 706;
    pellets->insert({"Pellet 21_02", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 21_04", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 21_06", std::make_shared<Pellet>(x, y, true)}); x+=space*6;
    pellets->insert({"Pellet 21_12", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 21_14", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 21_16", std::make_shared<Pellet>(x, y, true)});
    // Ligne 23
    x = 66; y = 738;
    pellets->insert({"Pellet 22_01", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 22_07", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 22_09", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 22_11", std::make_shared<Pellet>(x, y, true)}); x+=space*4;
    pellets->insert({"Pellet 22_15", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 22_17", std::make_shared<Pellet>(x, y, true)});
    // Ligne 24
    x = 34; y = 770;
    pellets->insert({"Pellet 23_00", std::make_shared<Pellet>(x, y, true)}); x+=space*8;
    pellets->insert({"Pellet 23_08", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 23_10", std::make_shared<Pellet>(x, y, true)}); x+=space*8;
    pellets->insert({"Pellet 23_18", std::make_shared<Pellet>(x, y, true)});
    // Ligne 25
    x = 66; y = 802;
    pellets->insert({"Pellet 24_01", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 24_02", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 24_03", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 24_04", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 24_05", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 24_06", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 24_07", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 24_09", std::make_shared<Pellet>(x, y, true)}); x+=space*2;
    pellets->insert({"Pellet 24_11", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 24_12", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 24_13", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 24_14", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 24_15", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 24_16", std::make_shared<Pellet>(x, y, true)}); x+=space;
    pellets->insert({"Pellet 24_17", std::make_shared<Pellet>(x, y, true)});
}

void initIntersections(std::map<std::string, std::shared_ptr<Intersection<Pellet>>> *intersections, std::map<std::string, std::shared_ptr<Intersection<BigPellet>>> *intersections_big)
{
    int x = 34, y = 34;
    int space = 128;
    // Première ligne d'intersections
    intersections->insert({"Intersection 00_00", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, false, false)}); x += space;
    intersections->insert({"Intersection 00_04", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, true, false)}); x += space;
    intersections->insert({"Intersection 00_08", std::make_shared<Intersection<Pellet>>(x, y, true, false, true, true, false)}); x += space/2;
    // On se décale pour passer à la partie droite
    // x = 354;
    intersections->insert({"Intersection 00_10", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, false, false)}); x += space;
    intersections->insert({"Intersection 00_14", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, true, false)}); x += space;
    intersections->insert({"Intersection 00_18", std::make_shared<Intersection<Pellet>>(x, y, true, false, true, true, false)});

    // Deuxième ligne
    x = 34; y = 162;
    intersections->insert({"Intersection 04_00", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, false, true)}); x += space;
    intersections->insert({"Intersection 04_04", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, true, true)}); x += space/2;
    intersections->insert({"Intersection 04_06", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, true, false)}); x += space/2;
    intersections->insert({"Intersection 04_08", std::make_shared<Intersection<Pellet>>(x, y, true, true, false, true, true)}); x += space/2;
    // x = 354;
    intersections->insert({"Intersection 04_10", std::make_shared<Intersection<Pellet>>(x, y, true, true, false, true, true)}); x += space/2;
    intersections->insert({"Intersection 04_12", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, true, false)}); x += space/2;
    intersections->insert({"Intersection 04_14", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, true, true)}); x += space;
    intersections->insert({"Intersection 04_18", std::make_shared<Intersection<Pellet>>(x, y, true, false, true, true, true)});

    x = 34; y = 258;
    intersections->insert({"Intersection 07_00", std::make_shared<Intersection<Pellet>>(x, y, true, true, false, false, true)}); x += space;
    intersections->insert({"Intersection 07_04", std::make_shared<Intersection<Pellet>>(x, y, true, false, true, true, true)}); x += space/2;
    intersections->insert({"Intersection 07_06", std::make_shared<Intersection<Pellet>>(x, y, true, true, false, false, true)}); x += space/2;
    intersections->insert({"Intersection 07_08", std::make_shared<Intersection<Pellet>>(x, y, true, false, true, true, false)}); x += space/2;
    intersections->insert({"Intersection 07_10", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, false, false)}); x += space/2;
    intersections->insert({"Intersection 07_12", std::make_shared<Intersection<Pellet>>(x, y, true, false, false, true, true)}); x += space/2;
    intersections->insert({"Intersection 07_14", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, false, true)}); x += space;
    intersections->insert({"Intersection 07_18", std::make_shared<Intersection<Pellet>>(x, y, true, false, false, true, true)});

    x = 226; y = 322;
    intersections->insert({"Intersection 09_06", std::make_shared<Intersection<Pellet>>(x, y, false, true, true, false, false)}); x += space/2;
    intersections->insert({"Intersection 09_08", std::make_shared<Intersection<Pellet>>(x, y, false, true, false, true, true)}); x += space/2;
    intersections->insert({"Intersection 09_10", std::make_shared<Intersection<Pellet>>(x, y, false, true, false, true, true)}); x += space/2;
    intersections->insert({"Intersection 09_12", std::make_shared<Intersection<Pellet>>(x, y, false, false, true, true, false)});

    x = 162; y = 418;
    intersections->insert({"Intersection 12_04", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, true, true)});x += space/2;
    intersections->insert({"Intersection 12_06", std::make_shared<Intersection<Pellet>>(x, y, false, false, true, true, true)});x += space/2*3;
    intersections->insert({"Intersection 12_12", std::make_shared<Intersection<Pellet>>(x, y, false, true, true, false, true)});x += space/2;
    intersections->insert({"Intersection 12_14", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, true, true)});

    x = 226; y = 482;
    intersections->insert({"Intersection 14_06", std::make_shared<Intersection<Pellet>>(x, y, false, true, true, false, true)});x += space/2*3;
    intersections->insert({"Intersection 14_14", std::make_shared<Intersection<Pellet>>(x, y, false, false, true, true, true)});

    x = 34; y = 578;
    intersections->insert({"Intersection 17_00", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, false, false)}); x += space;
    intersections->insert({"Intersection 17_04", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, true, true)}); x += space/2;
    intersections->insert({"Intersection 17_06", std::make_shared<Intersection<Pellet>>(x, y, true, true, false, true, true)}); x += space/2;
    intersections->insert({"Intersection 17_08", std::make_shared<Intersection<Pellet>>(x, y, true, false, true, true, false)}); x += space/2;
    intersections->insert({"Intersection 17_10", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, false, false)}); x += space/2;
    intersections->insert({"Intersection 17_12", std::make_shared<Intersection<Pellet>>(x, y, true, true, false, true, true)}); x += space/2;
    intersections->insert({"Intersection 17_14", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, true, true)}); x += space;
    intersections->insert({"Intersection 17_18", std::make_shared<Intersection<Pellet>>(x, y, true, false, true, true, false)});

    x = 34; y = 642;
    intersections_big->insert({"BigIntersection 19_00", std::make_shared<Intersection<BigPellet>>(x, y, true, true, false, false, true)}); x += space/2;
    intersections->insert({"Intersection 19_02", std::make_shared<Intersection<Pellet>>(x, y, true, false, true, true, false)}); x += space/2;
    intersections->insert({"Intersection 19_04", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, false, true)}); x += space/2;
    intersections->insert({"Intersection 19_06", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, true, false)}); x += space/2;
    intersections->insert({"Intersection 19_08", std::make_shared<Intersection<Pellet>>(x, y, true, true, false, true, true)}); x += space/2;
    intersections->insert({"Intersection 19_10", std::make_shared<Intersection<Pellet>>(x, y, true, true, false, true, true)}); x += space/2;
    intersections->insert({"Intersection 19_12", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, true, false)}); x += space/2;
    intersections->insert({"Intersection 19_14", std::make_shared<Intersection<Pellet>>(x, y, true, false, true, true, true)}); x += space/2;
    intersections->insert({"Intersection 19_16", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, false, false)}); x += space/2;
    intersections_big->insert({"BigIntersection 19_18", std::make_shared<Intersection<BigPellet>>(x, y, true, false, false, true, true)});

    x = 34; y = 738;
    intersections->insert({"Intersection 22_00", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, false, false)}); x += space/2;
    intersections->insert({"Intersection 22_02", std::make_shared<Intersection<Pellet>>(x, y, true, true, false, true, true)}); x += space/2;
    intersections->insert({"Intersection 22_04", std::make_shared<Intersection<Pellet>>(x, y, true, false, false, true, true)}); x += space/2;
    intersections->insert({"Intersection 22_06", std::make_shared<Intersection<Pellet>>(x, y, true, true, false, false, true)}); x += space/2;
    intersections->insert({"Intersection 22_08", std::make_shared<Intersection<Pellet>>(x, y, true, false, true, true, false)}); x += space/2;
    intersections->insert({"Intersection 22_10", std::make_shared<Intersection<Pellet>>(x, y, true, true, true, false, false)}); x += space/2;
    intersections->insert({"Intersection 22_12", std::make_shared<Intersection<Pellet>>(x, y, true, false, false, true, true)}); x += space/2;
    intersections->insert({"Intersection 22_14", std::make_shared<Intersection<Pellet>>(x, y, true, true, false, false, true)}); x += space/2;
    intersections->insert({"Intersection 22_16", std::make_shared<Intersection<Pellet>>(x, y, true, true, false, true, true)}); x += space/2;
    intersections->insert({"Intersection 22_18", std::make_shared<Intersection<Pellet>>(x, y, true, false, true, true, false)});

    x = 34; y = 802;
    intersections->insert({"Intersection 24_00", std::make_shared<Intersection<Pellet>>(x, y, true, true, false, false, true)}); x += space/2*4;
    intersections->insert({"Intersection 24_08", std::make_shared<Intersection<Pellet>>(x, y, true, true, false, true, true)}); x += space/2;
    intersections->insert({"Intersection 24_10", std::make_shared<Intersection<Pellet>>(x, y, true, true, false, true, true)}); x += space/2*4;
    intersections->insert({"Intersection 24_18", std::make_shared<Intersection<Pellet>>(x, y, true, false, false, true, true)});
}
