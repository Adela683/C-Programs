#include <stdio.h>
#include <stdlib.h>

void operatia1(int table[401][401], int N, int X, int op1[401])
{
	int i, j;
	int ok;
	for (i = 1; i <= N * N; i++) {
		ok = 1;
		for (j = 0; j < N * N; j++)
			if (table[X - 1][j] == i)
				ok = 0;
		op1[i] = ok;
	}
}

void operatia2(int table[401][401], int N, int X, int op2[401])
{
	int i, j;
	int ok;
	for (i = 1; i <= N * N; i++) {
		ok = 1;
		for (j = 0; j < N * N; j++) {
			if (table[j][X - 1] == i)
				ok = 0;
		}
		op2[i] = ok;
	}
}

void operatia3(int table[401][401], int N, int Z, int op3[401])
{
	int i, j, l;
	int ok;
	for (l = 1; l <= N * N; l++) {
		ok = 1;
		for (i = ((Z - 1) / N) * N; i < ((Z - 1) / N) * N + N; i++) {
			for (j = ((Z - 1) % N) * N; j < ((Z - 1) % N) * N + N; j++) {
				if (table[i][j] == l)
					ok = 0;
			}
		}
		op3[l] = ok;
	}
}

int operatia4(int table[401][401], int N, int X, int Y, int op4[401])
{
	int op1[401], op2[401], op3[401];
	int Z = ((X - 1) / N) * N + (Y - 1) / N;
	int i;

	int op4_restriction = 1;

	if (table[X - 1][Y - 1] != 0)
		op4_restriction = 0;

	operatia1(table, N, X, op1);
	operatia2(table, N, Y, op2);
	operatia3(table, N, Z + 1, op3);

	for (i = 1; i <= N * N; i++) {
		if (op1[i] == 1 && op2[i] == 1 && op3[i] == 1)
			op4[i] = 1;
		else
			op4[i] = 0;
	}

	return op4_restriction;
}

void operatia5(int table[401][401], int X, int Y, int C,
			   int *elemente, int N, int *tabla_valida)
{
	if (table[X - 1][Y - 1] == 0) {
		(*elemente)++;

		int op4[401];
		operatia4(table, N, X, Y, op4);
		if (op4[C] == 0)
			*tabla_valida = 0;

		table[X - 1][Y - 1] = C;
	}
}

void operatia6(int elemente, int tabla_valida, int N)
{
	if (tabla_valida == 0) {
		printf("%d\n", 1);
	} else {
		if (elemente < N * N * N * N)
			printf("%d\n", 0);
		else
			printf("%d\n", 2);
	}
}

int main(void)
{
	int i, j;
	int N, M;
	int table[401][401];
	int elemente = 0;
	int tabla_valida = 1;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N * N; i++) {
		for (j = 0; j < N * N; j++) {
			scanf("%d", &table[i][j]);
			if (table[i][j] != 0)
				elemente++;
		}
	}

	int operatie;
	int C, X, Y, Z;
	int op1[401], op2[401], op3[401], op4[401];

	for (i = 0; i < M; i++) {
		scanf("%d", &operatie);

		if (operatie == 1) {
			scanf("%d", &X);
			operatia1(table, N, X, op1);

			for (j = 1; j <= N * N; j++)
				printf("%d ", op1[j]);
			printf("\n");
		} else if (operatie == 2) {
			scanf("%d", &X);
			operatia2(table, N, X, op2);

			for (j = 1; j <= N * N; j++)
				printf("%d ", op2[j]);
			printf("\n");
		} else if (operatie == 3) {
			scanf("%d", &Z);
			operatia3(table, N, Z, op3);

			for (j = 1; j <= N * N; j++)
				printf("%d ", op3[j]);
			printf("\n");
		} else if (operatie == 4) {
			scanf("%d %d", &X, &Y);
			int return_value = operatia4(table, N, X, Y, op4);

			if (return_value == 0) {
				for (j = 1; j <= N * N; j++)
					printf("%d ", 0);
				printf("\n");
			} else {
				for (j = 1; j <= N * N; j++)
					printf("%d ", op4[j]);
				printf("\n");
			}
		} else if (operatie == 5) {
			scanf("%d %d %d", &X, &Y, &C);
			operatia5(table, X, Y, C, &elemente, N, &tabla_valida);
		} else if (operatie == 6) {
			operatia6(elemente, tabla_valida, N);
		}
	}
}
