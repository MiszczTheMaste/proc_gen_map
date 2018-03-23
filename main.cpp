#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Tile{
    public:
    bool walkable;
};
Tile mapa[16][16];

string tet;
/*void generateMap(){
    srand(time(0));
    for(auto &mapTile : mapa){
        for(int i=0;i<16;i++){
            mapTile[i].walkable = false;
        }
    }
    mapa[1][1].walkable = true;
    for(int i=1;i<15;i++){
        for(int g=1;g<15;g++){
           if(mapa[i][g].walkable == true){
                if(mapa[i-1][g].walkable != true && i > 1){
                    mapa[i-1][g].walkable = rand() % 2;
                }
                if(mapa[i+1][g].walkable != true && i < 15){
                    mapa[i+1][g].walkable = rand() % 2;
                }
                if(mapa[i][g-1].walkable != true && g > 1){
                    mapa[i][g-1].walkable = rand() % 2;
                }
                if(mapa[i][g+1].walkable != true && g < 15){
                    mapa[i][g+1].walkable = rand() % 2;
                }
           }

        }
    }
}
*/
void generateMap(){
    srand(time(0));
    for(auto &mapTile : mapa){
        for(int i=0;i<16;i++){
            mapTile[i].walkable = false;
        }
    }
    int param1 = rand() % 14 + 1;
    int param2 = rand() % 14 + 1;
    mapa[param1][param2].walkable = true;
    if(mapa[param1-1][param2].walkable != true && param1 > 1){
        mapa[param1-1][param2].walkable = rand() % 2;
    }
    if(mapa[param1+1][param2].walkable != true && param1 < 15){
        mapa[param1+1][param2].walkable = rand() % 2;
    }
    if(mapa[param1][param2-1].walkable != true && param2 > 1){
        mapa[param1][param2-1].walkable = rand() % 2;
    }
    if(mapa[param1][param2+1].walkable != true && param2 < 15){
        mapa[param1][param2+1].walkable = rand() % 2;
    }

     for(int i=1;i<15;i++){
        for(int g=1;g<15;g++){
           if(mapa[i][g].walkable == true){
                if(mapa[i-1][g].walkable != true && i > 1){
                    mapa[i-1][g].walkable = rand() % 2;
                }
                if(mapa[i+1][g].walkable != true && i < 14){
                    mapa[i+1][g].walkable = rand() % 2;
                }
                if(mapa[i][g-1].walkable != true && g > 1){
                    mapa[i][g-1].walkable = rand() % 2;
                }
                if(mapa[i][g+1].walkable != true && g < 14){
                    mapa[i][g+1].walkable = rand() % 2;
                }
           }

        }
    }
    for(int i=15;i<1;i--){
        for(int g=15;g>1;g--){
           if(mapa[i][g].walkable == true){
                if(mapa[i-1][g].walkable != true && i > 1){
                    mapa[i-1][g].walkable = rand() % 2;
                }
                if(mapa[i+1][g].walkable != true && i < 14){
                    mapa[i+1][g].walkable = rand() % 2;
                }
                if(mapa[i][g-1].walkable != true && g > 1){
                    mapa[i][g-1].walkable = rand() % 2;
                }
                if(mapa[i][g+1].walkable != true && g < 14){
                    mapa[i][g+1].walkable = rand() % 2;
                }
           }

        }
    }
}
void drawMap(){
    for(auto &mapTile : mapa){
        for(int i=0;i<16;i++){
            if(mapTile[i].walkable == true){
                cout << "+";
            }else{
                cout << "/";
            }
        }
        cout << endl;
    }
    cout << "'y' to draw again, 'g' to draw again and gets number of failed attempts, 'n' to exit";
    cout << endl;
    cin >> tet;
}

bool checkMap(){
    int tileCount = 0;
    for(int i=0;i<16;i++){
        for(int g=0;g<16;g++){
           if(mapa[i][g].walkable == true){
                tileCount++;
           }
        }
    }
    if(tileCount < 40 || tileCount > 200){
        return false;
    }else{
        return true;
    }
}
int main()
{
    int fail = 0;
    cout << "'y' to draw again, 'g' to draw again and gets number of failed attempts, 'n' to exit";
    cout << endl;
    cin >> tet;
    while(true){
        if(tet == "n"){
        return 0;
        }else{
            generateMap();
            if(checkMap() == true){
                fail = 0;
                drawMap();
            }else if(tet == "g"){
                fail++;
                cout << "Failed attempts to generate map: ";
                cout << fail;
                cout << endl;
            }
        }
    }
}
