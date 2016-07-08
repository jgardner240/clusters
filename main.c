#include <stdio.h>

#define SENSOR_WIDTH  20
#define SENSOR_HEIGHT 20

#define SEARCHED	-1
typedef union
{
	short pixel[SENSOR_HEIGHT * SENSOR_WIDTH];
	short cell[SENSOR_HEIGHT][SENSOR_WIDTH];
} FRAME_BUFFER_T, *FRAME_BUFFER_PTR_T;

short array[SENSOR_HEIGHT][SENSOR_WIDTH] = {
		{1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,1,1},
		{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

int searchNeighbors(int row, int col)
{
	int count = 1;
	int rowMin, rowMax, colMin, colMax;

	rowMin = (row > 0) ? (row - 1) : 0;
	colMin = (col > 0) ? (col - 1) : 0;
	rowMax = (row < (SENSOR_HEIGHT - 1)) ? (row + 1) : (SENSOR_HEIGHT - 1);
	colMax = (col < (SENSOR_WIDTH - 1)) ? (col + 1) : (SENSOR_WIDTH - 1);

	array[row][col] = SEARCHED;

	for (int x = rowMin; x <= rowMax; x++) {
		for (int y = colMin; y <= colMax; y++) {
			if (array[x][y] == 0) {
				count += searchNeighbors(x,y);
			}
			else
				array[x][y] = SEARCHED;
		}
	}
	return count;
}

int main(void)
{
	int i, count;
	int currentClusterCount = 0;
	printf("Hello World!\n");
	count = 0;
	for (int row=0; row<SENSOR_HEIGHT; row++) {
		for (int col=0; col<SENSOR_WIDTH; col++) {
			if (array[row][col] == 0) {
				count += searchNeighbors(row,col);
				printf("Cluster %d, count %d\n", currentClusterCount++, count);
				count = 0;
			}
		}
	}

	return 0;
}

