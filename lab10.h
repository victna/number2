#ifndef LAB10
#define LAB10
#define SIZE 5 /* symbolic constant for map size */
void initializeMap(int map[SIZE][SIZE]);
void displayMap(int map[SIZE][SIZE], int playerX, int playerY);
int move(int *x, int *y, char direction);
int checkTreasure(int x, int y);
/* Honors only */
int leaveTrace(int map[SIZE][SIZE], int x, int y);
#endif