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
void generateMap(){
    srand(time(0));
    for(auto &mapTile : mapa){
        for(int i=0;i<16;i++){
            mapTile[i].walkable = false;
        }
    }
    mapa[0][0].walkable = true;
    for(int i=0;i<16;i++){
        for(int g=0;g<16;g++){
           if(mapa[i][g].walkable == true){
                if(mapa[i-1][g].walkable != true && i > 0){
                    mapa[i-1][g].walkable = rand() % 2;
                }
                if(mapa[i+1][g].walkable != true && i < 16){
                    mapa[i+1][g].walkable = rand() % 2;
                }
                if(mapa[i][g-1].walkable != true && g > 0){
                    mapa[i][g-1].walkable = rand() % 2;
                }
                if(mapa[i][g+1].walkable != true && g < 16){
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
    cout << "'y' to draw again, 'n' to exit";
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
    if(tileCount < 20 || tileCount == 256){
        return false;
    }else{
        return true;
    }
}
int main()
{
    int fail = 0;
    while(true){
        if(tet == "n"){
        return 0;
        }else{
            generateMap();
            if(checkMap() == true){
                fail = 0;
                drawMap();
            }else{
                fail++;
                cout << "Failed attempts to generate map: ";
                cout << fail;
                cout << endl;
            }
        }
    }
}