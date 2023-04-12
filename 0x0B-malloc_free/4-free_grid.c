#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * free_grid - frees a 2 dimensional grid previously created by your alloc_grid
 * @grid: 2dimensional grid
 * @height:height of the grid
 * return: 0
 */
void free_grid(int **grid, int height)
{
	int n;

	for (n = 0; n < height; n++)
	{
		free(grid[n]);
	}

	free(grid);

}
