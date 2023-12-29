#include "raylib.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <process.h>
#include <stdio.h>

int main(){
    int x=10,y=0,z=0,d=50;
    int dirX, dirY;
    InitWindow(800, 800, "first window");
    
    SetTargetFPS(30);
    int posX=400, posY=400;
    
    while(!WindowShouldClose()){
        srand(_getpid());
        int randVal = rand() % 800;
        
        dirX = ((randVal / 200) > 2 )? 1 : -1 ; 
        if (randVal / 200 == 3 || randVal / 200 == 1) dirY = -1;
        else dirY = 1;
        printf("dirX: %d  +  dirY: %d\n", dirX, dirY);
        BeginDrawing();
            
            Color c = {x, y, z, d};

            DrawPixel(posX+=dirX, posY+=dirY, WHITE);
            
            
        
        EndDrawing();
    }
    CloseWindow();
    return 0;
}