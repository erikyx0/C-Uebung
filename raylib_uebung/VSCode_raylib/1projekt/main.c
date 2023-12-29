#include "raylib.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <process.h>
#include <stdio.h>

int main(){
    int a=255, b=255, c=255, d=0;
    int dirX, dirY;
    InitWindow(800, 800, "first window");
    
    SetTargetFPS(40);
    int posX=400, posY=400;
    
    while(!WindowShouldClose()){

        srand(time(NULL) * _getpid());
        int randVal = rand() % 800;
        //printf("rand: %d\n", randVal);

        dirX = ((randVal / 200) > 2 )? 1 : -1 ; 

        if (randVal / 200 == 3 || randVal / 200 == 1){
            dirY = -1;
            a = 150, b = 225, c = 150, d = 255;
        }
        else {
            dirY = 1;
            a = 100, b = 100, c = 255, d = 255;
           
        }

        //printf("dirX: %d  +  dirY: %d\n", dirX, dirY);
        BeginDrawing();
        if (posX >= 0 && posX <= 800 && posY >= 0 && posY <= 800){

            Color colo = {a, b, c, d};
            DrawPixel(posX+=dirX, posY+=dirY, colo);

        }else{
            if (posX < 0){
                posX = 800;

            }else if (posX > 800){
                posX = 0;
            }else if (posY < 0){
                posY = 800;
            }else{
                posY = 0;
            }
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}