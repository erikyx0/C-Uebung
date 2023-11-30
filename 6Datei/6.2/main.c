#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

double getratio(double Xval[], double Yval[], int ValAmount, double *minmaxvalues);
int drawing(double Xval[], double Yval[], int ValAmount, double *minmaxvalues);

int main(int argc, char **argv){
    FILE *file;
    double xValues[100];
    double yValues[100];
    int step=0;

    file = fopen("test.csv", "r");
    
    if (file == NULL){
        printf("Error openimg the file\n");
        return 1;
    }
    do{
        fscanf(file, "%lf, %lf", &xValues[step], &yValues[step]);
        step++; 
    }while(!feof(file));

    fclose(file);

    //get ratio
    double *minmaxData;
    minmaxData = malloc(sizeof(double)*2); //maxX, maxY, minX, minY
    getratio(xValues, yValues, step, minmaxData);
    for (int i=0; i<2; i++){
           printf("Data: %lf\n", minmaxData[i]);
    }
    
    //drawing stuff
    double *lineValues;
    lineValues = malloc(sizeof(int)*2);
    drawing(xValues, yValues, step, minmaxData);
    
    return 0;
}

int drawing(double Xval[], double Yval[], int ValAmount, double *minmaxvalues){
    InitWindow(1000,700,"graph plotting");
    Color linecolor = {100, 100, 100, 255}; 
    double xPos, yPos;
    int offset = 50;

    double Xgetmaxtoratio = 900 / minmaxvalues[0];
    double Ygetmaxtoratio = 600 / minmaxvalues[1];

    while (!WindowShouldClose()){

        BeginDrawing();

            DrawLine(50, GetScreenHeight()-50, GetScreenWidth()-50, GetScreenHeight()-50, BLACK);
            DrawLine(50, GetScreenHeight()-50, 50, 50, linecolor);


            ClearBackground(RAYWHITE);
            DrawText("Graph plotter: ", 420, 20, 20, LIGHTGRAY);
            for (int i=0; i<ValAmount; i++){
                xPos = (Xval[i] * Xgetmaxtoratio) + offset;
                yPos = GetScreenHeight() - (Yval[i] * Ygetmaxtoratio) - offset;
                
                DrawCircle(xPos, yPos, 2, BLACK);
               
                char drawValueX[10]; char drawValueY[10];
                snprintf(drawValueX, sizeof(drawValueX), "%.2lf", Xval[i]);
                snprintf(drawValueY, sizeof(drawValueX), "%.2lf", Yval[i]);
                DrawText(drawValueX, xPos, GetScreenHeight()-45, 5, GRAY);
                DrawText(drawValueY, 20, yPos, 5, GRAY);
            }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

double getratio(double Xval[], double Yval[], int ValAmount, double *minmaxvalues){
    double maxX=0, minX=0, maxY, minY;
    for (int i=0; i<ValAmount; i++){
        minmaxvalues[0] = maxX = (Xval[i] > maxX) ? Xval[i] : maxX;
        minmaxvalues[1] = maxY = (Yval[i] > maxY) ? Yval[i] : maxY;
        //minX = (Xval[i] < Xval[i+1]) ? Xval[i] : Xval[i+1];
        //minY = (Yval[i] < Yval[i+1]) ? Yval[i] : Yval[i+1];
    }
    
    return 0;
}






