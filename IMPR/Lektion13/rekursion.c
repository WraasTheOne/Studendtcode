#include <stdio.h>


#define W 5
#define H 5

int blob_count(int grid[][H], int x, int y);
int rekursion(int grid[][H], int x, int y);

int main(void)
{
    int grid[W][H] = {
        {1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 1, 1},
    };
    for(int x = 0; x < W; x++){
        for(int y = 0; y < H; y++){
            printf("%d\n", blob_count(grid, x, y));
        }
    }
    

    return 0;
}

int blob_count(int grid[][H], int x, int y)
{
    if(grid[x][y] == 1){
        return rekursion(grid, x, y);
    }else{
        return 0;
    }

}

int rekursion(int grid[][H], int x, int y){
    int counter = 0;
    if(grid[x+1][y] == 1){
        x += 1;
        grid[x+1][y] = 0;
        counter += rekursion(grid,x,y);
    }
    if(grid[x][y+1] == 1){
        y += 1;
        counter += rekursion(grid,x,y);
        grid[x][y+1] = 0;
    }
    if(grid[x-1][y] == 1){
        x -= 1;
        counter += rekursion(grid,x,y);
        grid[x-1][y] = 0;
    }
    if(grid[x][y-1] == 1){
        y -= 1;
        counter += rekursion(grid,x,y);
        grid[x][y-1] = 0;
    }
    
    return counter;
}