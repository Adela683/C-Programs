#include <stdio.h>
#include <stdlib.h>

// Function to read input values
void read(int *n, int *m, int g[100][100], int l[100][100], int c[100][100])
{
    // Read dimensions of the grid
	scanf("%d %d", n, m);

    // Read restrictions for each row
	for (int i = 0; i < *n; i++) {
		scanf("%d", &l[i][0]);//Number of restrictions for each row
		int k = l[i][0];
		for (int j = 1; j <= k; j++)
			scanf("%d", &l[i][j]);// Read each restriction
	}

    // Read restrictions for each column
	for (int i = 0; i < *m; i++) {
		scanf("%d", &c[i][0]);  // Number of restrictions for each column
		int k = c[i][0];
		for (int j = 1; j <= k; j++)
			scanf("%d", &c[i][j]);// Read each restriction
	}

    // Read the grid
	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *m; j++)
			scanf("%d", &g[i][j]);// Read each cell of the grid
	}
}

// Function to check restrictions for each row
int check_lines(int restrictions[100][100], int grid[100][100], int n, int m)
{
	int current = 0;//Counts the number of consecutive 1.
	int groups = 0;/*Counts the total number of groups of
					consecutive 1's on a line.*/
	int ok = 0;
	int r;

	for (int i = 0; i < n; i++) {
		for (int k = 1; k <= restrictions[i][0]; k++) {
			r = restrictions[i][k];
			current = 0;
			groups = 0;
			ok = 0;
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1)
					current++;
				if ((grid[i][j] == 0 || j == m - 1) && current > 0) {
					groups++;
					if (current == r)
						ok = 1;
					current = 0;
				}
			}

			if (!(ok == 1 && groups == restrictions[i][0]))
				return -1;// Return -1 if restrictions are not satisfied
		}
	}
	return 1;//Return 1 if all restrictions are satisfied
}

// Function to check restrictions for each column
int check_columns(int restrictions[100][100], int grid[100][100], int n, int m)
{
	int current = 0;
	int groups = 0;
	int ok = 0;
	int r;
	for (int j = 0; j < m; j++) {
		for (int k = 1; k <= restrictions[j][0]; k++) {
			r = restrictions[j][k];
			current = 0;
			groups = 0;
			ok = 0;
			for (int i = 0; i < n; i++) {
				if (grid[i][j] == 1)
					current++;
				if ((grid[i][j] == 0 || i == n - 1) && current > 0) {
					groups++;
					if (current == r)
						ok = 1;
					current = 0;
				}
			}

			if (!(ok == 1 && groups == restrictions[j][0]))
				return -1;// Return -1 if restrictions are not satisfied
		}
	}
	return 1;//Return 1 if all restrictions are satisfied
}

int main(void)
{
	int T;//The number of puzzles to be checked;
	int N = 0;//The number of lines
	int M = 0;//The number of columns
	int grid[100][100];// The grid to be verified
	int grid_l[100][100], grid_c[100][100];// Restrictions for rows and columns
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		read(&N, &M, grid, grid_l, grid_c);

		// Check restrictions for rows and columns
		if (check_columns(grid_c, grid, N, M) == 1 &&
			check_lines(grid_l, grid, N, M) == 1)
			printf("Corect\n");
			// If both row and column restrictions are satisfied
		else
			printf("Eroare\n");
			//If any restriction is not satisfied
	}

	return 0;
}
