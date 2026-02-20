#define SIZE 5
#define TREASURE_X 2
#define TREASURE_Y 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "lab10.h"
void initializeMap(int map[SIZE][SIZE]){
    //srand(time(NULL));
    int PLAYER_X = rand() % SIZE;
    int PLAYER_Y = rand() % SIZE;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            map[i][j] = 0;
            if((i==TREASURE_X && j==TREASURE_Y)||(i==PLAYER_X && j==PLAYER_Y)){
                if(i==TREASURE_X){map[i][j] = 9;} // Treasure
                else{map[i][j] = 8;} // Player
            }
        }
    }
}
int checkTreasure(int x, int y){
    return (x == TREASURE_X && y == TREASURE_Y);
}
void printMap(const int *map){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            switch(map[i * SIZE + j]){
                case 1:// Discovered
                    printf("[%d] ", map[i * SIZE + j]);
                    break;
                case 9:// Treasure
                    printf("[0] ");
                    break;
                case 8:// Player
                    printf("[P] ");
                    break;
                default:
                    printf("[%d] ", map[i * SIZE + j]);
                    break;
            }
        }
        printf("\n");
    }
}
int move(int *x, int *y, char direction){
    switch(direction){
        case 'U':
        case 'u':
            if(*x > 0){(*x)--;if(checkTreasure(*x,*y)){printf("\nCongratulations! You found the treasure!");} return 1;}
            break;
        case 'D':
        case 'd':
            if(*x < SIZE - 1){(*x)++;if(checkTreasure(*x,*y)){printf("\nCongratulations! You found the treasure!");} return 1;}
            break;
        case 'L':
        case 'l':
            if(*y > 0){(*y)--;if(checkTreasure(*x,*y)){printf("\nCongratulations! You found the treasure!");} return 1;}
            break;
        case 'R':
        case 'r':
            if(*y < SIZE - 1){(*y)++;if(checkTreasure(*x,*y)){printf("\nCongratulations! You found the treasure!");} return 1;}
            break;
        default:
            return 0;
    }
    return 0;
}
int leaveTrace(int map[SIZE][SIZE], int x, int y){
    if(map[x][y] != 1){ // Discovered
        map[x][y] = 1; // Mark as discovered
        printf("New Area Unlocked!\n");
        return 1;
    }
    return 0;
}