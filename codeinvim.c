#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int cmpfunc(const void *a, const void *b)
{
	return (*(int *)b - *(int *)a);
}

// Function to calculate the total score
int score_calculation(int a[], int b[], int n)
{
	int product = 0;
	for (int i = 0; i < n; i++)
		product += a[i] * b[i];

	return product;
}

// Function to calculate the increase for each subject
void growth_of_matter(int a[], int b[], int n, int growth[])
{
	for (int i = 0; i < n; i++) {
		if (a[i] < 10)
			growth[i] = b[i] * (10 - a[i]);
		else
			growth[i] = 0;
	}
}

int main(void)
{
	int n;
	int c[100], x[100], pmin;
	int m = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d ", &x[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	scanf("%d", &pmin);

	int growth[100];
	growth_of_matter(x, c, n, growth);

	// Sort the increase array in descending order
	qsort(growth, n, sizeof(int), cmpfunc);

	// Calculate the initial total score
	int current_score = score_calculation(x, c, n);

	// Iterate until the total score is greater than or equal
	//to the required minimum
	while (current_score < pmin) {
		// Check if all subjects have been used and the score is
		//still below the minimum
		if (m == n) {
			printf("-1\n");
			return 0;
		}

		// Increase the total score by the current subject's increase
		current_score += growth[m];
		m++;
	}

	// Print the minimum number of additional subjects needed
	printf("%d\n", m);

	return 0;
}
