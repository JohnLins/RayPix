#include "raylib.h"
#include "raygui.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    
    int width = 60;
    int height = 40;
    
    float pixdim = 20;
    
    printf("Width, Height, Pixdim: \n");
   scanf("%d %d %f", &width, &height, &pixdim);
   //scanf("Height: %d", &height);
   //scanf("Pixdim: %f", &pixdim);
    
    
    const int SW = pixdim * width;
    const int SH = pixdim * height;
    
  //  int used = 0;
    
    Color **pixels = (Color**)malloc(height * sizeof(Color*));
    for(int i = 0; i < height; i++){ 
        pixels[i] = (Color*)malloc(width * sizeof(Color));
        for(int j = 0; j < width; j++){
            pixels[i][j] = (Color){0,0,0,0}; 
        }
    } 
    
   // Color pixels[height][width];
    /*Color **pixels = malloc((height) * sizeof(Color));
    
    for(int i = 0; i < height; i++){
        pixels[i] = malloc((width) * sizeof(Color));
    }
    */
    
    int colorSpace = 30;
    
    InitWindow(SW, SH + colorSpace, "Pix | John Lins");
    
    Color cc = (Color){0, 0, 0, 255};
   
    
    SetTargetFPS(60);
    while (!WindowShouldClose())    
    {
        if(IsKeyPressed('S')){
            //InitWindow(SW, SH, "Pix | John Lins");
                TakeScreenshot("image.png"); 
            }
            
        BeginDrawing();

            ClearBackground(WHITE);
            
            
            
            DrawText(FormatText("R: %d, G: %d, B: %d, A: %d", cc.r, cc.g, cc.b, cc.a), 2, SH + colorSpace - (20+2), 20, BLACK);
            
            DrawRectangle(SW/2, SH + colorSpace - 10, SW - 2, 10, cc);
            
            
            
            if(IsKeyDown('R')) {
                if (IsKeyDown(KEY_UP)){ cc.r++;}
                if (IsKeyDown(KEY_DOWN)){ cc.r--;}
            }
            if(IsKeyDown('G')) {
                if (IsKeyDown(KEY_UP)){ cc.g++;}
                if (IsKeyDown(KEY_DOWN)){ cc.g--;}
            }
            if(IsKeyDown('B')) {
                if (IsKeyDown(KEY_UP)){ cc.b++;}
                if (IsKeyDown(KEY_DOWN)){ cc.b--;}
            }
            if(IsKeyDown('A')) {
                if (IsKeyDown(KEY_UP)){ cc.a++;}
                if (IsKeyDown(KEY_DOWN)){ cc.a--;}
            }
            
            
            if(IsMouseButtonDown(0)){
                
                pixels[(int)(GetMousePosition().y/pixdim)][(int)(GetMousePosition().x/pixdim)] = cc;
                
               // used ++;
            } else if (IsMouseButtonDown(1)){
                pixels[(int)(GetMousePosition().y/pixdim)][(int)(GetMousePosition().x/pixdim)] = (Color){0,0,0,0};
            }
            
            
            //draw pixels
          /*  for(int i = 0; i < used; i++){
                DrawRectangleV(pixels[i], (Vector2){pixdim, pixdim}, GREEN);
            }*/
            
            if(!IsKeyPressed('S')){
               for(int i = 0; i < width; i++){
                    DrawLine(i*pixdim, 0, i*pixdim, SH, BLACK);
               }        
               
               for(int i = 0; i < height; i++){
                    DrawLine(0, i*pixdim, SW, i*pixdim, BLACK);
               }  
          }   
            
            
            for(int i = 0; i < height; i++){
                for(int j = 0; j < width; j++){
                    DrawRectangle(j * pixdim, i * pixdim, pixdim, pixdim, (Color)(pixels[i][j]));
                   
                }
            }
            
    
      
        EndDrawing();
        
        
        
    }
    
    CloseWindow();     

    return 0;
}