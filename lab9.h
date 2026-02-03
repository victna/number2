#ifndef LAB9
#define LAB9
void initializeImage(int image[5][5]);
int drawPixel(int image[5][5], int row, int col);
void invertImage(int image[5][5]);
int flipRow(int image[5][5], int row);
int flipColumn(int image[5][5], int col);
void clearImage(int image[5][5]);
void displayImage(int image[5][5]);
void rotateRight(int image[5][5]);
#endif
