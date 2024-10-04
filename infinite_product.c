#include <math.h>
#include <stdio.h>

long long convert(long long x)
{
	long long ultima_cifra, putere = 1, y = 0;
	while (x) {
		ultima_cifra = x % 10;
		y = ultima_cifra * putere + y;
		putere = putere * 8;
		x = x / 10;
	}
	return y;
}

int main(void)
{
	double norma = 0, norma_b = 0;
	long long n, i, a, b, max1, max2, max1_b, max2_b;
	unsigned long long produs = 0;
	scanf("%lld", &n);
	max1 = -1;
	max2 = -1;
	max2_b = -1;
	max1_b = -1;
	for (i = 0; i < n; i++) {
		scanf("%lld %lld", &a, &b);
		produs += (unsigned long long)convert(a) * convert(b);
		a = convert(a);
		b = convert(b);
		norma += (double)(pow(a, 2));
		norma_b += (double)(pow(b, 2));

		// daca a este mai mare decat primul maxim
		if (a > max1) {
			max2 = max1;
			max1 = a;
		} else if (a > max2 && a != max1) {
			max2 = a;
		}
		if (b > max1_b) {
			max2_b = max1_b;
			max1_b = b;
		} else if (b > max2_b && b != max1_b) {
			max2_b = b;
		}
	}
	printf("%lld\n", produs);
	printf("%lld %lld\n", max2, max2_b);
	printf("%.7F %.7F\n", sqrt(norma), sqrt(norma_b));

	return 0;
}
