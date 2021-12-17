#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int SW = 1000;
    const int SH = 500;

    InitWindow(SW, SH, "RayShot | John Lins");
    
    int limit = 10;
    int used = 0;
    
    Vector2 *boxPositions = malloc(limit * sizeof(Vector2));
    
    
    float value = 0;
    
    SetTargetFPS(60);
    while (!WindowShouldClose())    
    {
        value += 0.1;
        BeginDrawing();

            ClearBackground(RED);
            
            if(IsMouseButtonDown(0)){
                boxPositions[used] = GetMousePosition();
                used++;
            }
            
            for(int i = 0; i < used; i++){
                DrawRectangle(boxPositions[i].x, boxPositions[i].y, 20, 20, BLUE);
                
                
            }
                     

      
        EndDrawing();
        
        
    }
    TakeScreenshot("image.png"); 
    CloseWindow();     

    return 0;
}