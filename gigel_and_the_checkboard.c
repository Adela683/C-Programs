#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, n, a[1001][1001];
	unsigned long long d;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	int aux;

	i = 0;
	j = 0;
	while (a[i][j] != 0) {
		// daca suma indicilor i si j este para casuta este alba
		//,daca nu este neagra
		if ((i + j) % 2 == 0) {
			aux = a[i][j];
			a[i][j] = 0;
			j = j + aux;
			d = d + abs(aux);
		} else {
			aux = a[i][j];
			a[i][j] = 0;
			i = i + aux;
			d = d + abs(aux);
		}
		while (j >= n)
			j = j - n;
		while (j < 0)
			j = j + n;
		while (i >= n)
			i = i - n;
		while (i < 0)
			i = i + n;
	}
	printf("%llu\n", d);
	printf("%d ", n - i);

	if (j < 26) {
		printf("%c\n", (char)(j + 'A'));
	} else if (j >= 26 && j <= 701) {
		printf("%c", (char)((j / 26) - 1 + 'A'));
		printf("%c\n", (char)((j % 26) + 'A'));
	}
	// else
	// {
	//     printf("%c", 'A');
	//     printf("%c", (char)((j / 26) - 27 + 'A'));
	//     printf("%c\n", (char)((j % 26) + 'A'));
	// }
	return 0;
}
