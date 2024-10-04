#include <stdio.h>
#include <stdlib.h>

void fractie_ireductibila(int numarator, int numitor)
{
	int nr1 = numarator, nr2 = numitor;
	while (nr2 != nr1) {
		if (nr1 > nr2)
			nr1 = nr1 - nr2;
		else
			nr2 = nr2 - nr1;
	}
	printf("%d/%d\n", numarator / nr1, numitor / nr1);
}

void ordonare(int letter_freq[123], int poz[123], int k)
{
	int i, aux, j;
	// for (i = 97; i < 123; i++)
	// {
	//     if (letter_freq[poz[i]] < letter_freq[poz[i + 1]])
	//     {
	//         aux = poz[i];
	//         poz[i] = poz[i + 1];
	//         poz[i + 1] = aux;
	//     }
	//     else if (letter_freq[poz[i]] == letter_freq[poz[i + 1]])
	//     {
	//         if (poz[i] < poz[i + 1])
	//         {
	//             aux = poz[i];
	//             poz[i] = poz[i + 1];
	//             poz[i + 1] = aux;
	//         }
	//     }
	// }
	int aux_freq[123];
	for (i = 97; i < 123; ++i) {
		aux_freq[i] = letter_freq[i];
		poz[i] = i;
	}

	int swapped;
	for (i = 97; i < 122; ++i) {
		swapped = 0;
		for (j = 97; j < 122 + 97 - i; ++j) {
			if (aux_freq[j] < aux_freq[j + 1]) {
				aux = aux_freq[j];
				aux_freq[j] = aux_freq[j + 1];
				aux_freq[j + 1] = aux;

				aux = poz[j];
				poz[j] = poz[j + 1];
				poz[j + 1] = aux;

				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}

	for (i = 0; i < k - 1; ++i)
		printf("%c ", (char)poz[i + 97]);
	printf("%c\n", (char)poz[i + 97]);
}

int main(void)
{
	int i, letter_freq[123], alert_count = 0, distinct = 0;
	int total = 0, poz[123], k;
	char buf[4];

	for (i = 97; i < 123; i++) {
		// poz[i] = i;
		letter_freq[i] = 0;
	}

	while (1) {
		scanf("%s", buf);

		if (buf[0] >= 'a' && buf[0] <= 'z') {
			if (letter_freq[(int)buf[0]] == 0)
				distinct++;
			letter_freq[(int)buf[0]]++;

			alert_count++;
			total++;
		} else if (buf[0] == 'Q') {
			scanf("%s", buf);
			printf("%c %d\n", buf[0], letter_freq[(int)buf[0]]);
		} else if (buf[0] == 'T') {
			scanf("%d", &k);
			ordonare(letter_freq, poz, k);

			// for (i = 0; i < k; i++)
			//     printf("%c", (char)poz[i]);
			// printf("\n");
		} else if (buf[0] == 'E') {
			scanf("%s", buf);
			total = total - letter_freq[(int)buf[0]];
			// distinct--;
			letter_freq[(int)buf[0]] = 0;
		} else {
			return 0;
		}

		if (distinct >= 2 && total >= 5) {
			for (i = 97; i < 123; i++) {
				if ((letter_freq[i] >= (total / 2) + (total % 2)) &&
					alert_count >= 5) {
					printf("%c ", (char)i);
					fractie_ireductibila(letter_freq[i], total);
					alert_count = 0;
				}
			}
		}
	}
	return 0;
}
