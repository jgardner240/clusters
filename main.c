#include <stdio.h>
#include "main.h"

unsigned int searchNeighbors(int row, int col)
{
	unsigned int count = 1; // There's always one bad pixel (the center) when this function is called
	int rowMin, rowMax, colMin, colMax;

	// Make sure we don't try to search outside the array boundaries
	rowMin = (row > 0) ? (row - 1) : 0;
	colMin = (col > 0) ? (col - 1) : 0;
	rowMax = (row < (SENSOR_HEIGHT - 1)) ? (row + 1) : (SENSOR_HEIGHT - 1);
	colMax = (col < (SENSOR_WIDTH - 1)) ? (col + 1) : (SENSOR_WIDTH - 1);

	// Mark the center searched, so we don't double count.
	array[row][col] = SEARCHED;

	for (int x = rowMin; x <= rowMax; x++) {
		for (int y = colMin; y <= colMax; y++) {
			if (array[x][y] == 0) {
				count += searchNeighbors(x,y);
			}
		}
	}
	return count;
}

int main(void)
{
    unsigned int count = 0;
    unsigned int currentClusterCount = 0;

	for (int row=0; row<SENSOR_HEIGHT; row++) {
		for (int col=0; col<SENSOR_WIDTH; col++) {
			if (array[row][col] == 0) {
				count += searchNeighbors(row,col);
				if (count>1)
					printf("Cluster %d, count %d\n", currentClusterCount++, count);
				count = 0;
			}
		}
	}

	return 0;
}

