#include <stdio.h>
#include <stdlib.h>
int a[20][20];
int conditie(int i, int j, int a[20][20]) {
	if (i >= 0 && i < 10 && j >= 0 && j < 10)
		return 1;
	else return 0;
}
void incrementare(int i, int j, int a[20][20]) {
	if (conditie(i, j, a) && a[i][j] != -1) {
		++a[i][j];
	}
}
void Vecini(int i, int j, int a[20][20]) {
	int n, m;
	a[i][j] = -1;


	for (m = -1; m <= 1; m++) {

		for (n = -1; n <= 1; n++) {
			incrementare(i + m, j + n, a);
		}
	}
}

int main() {
	int i, j, n, nr = 0, b, c;
	printf("Introduceti numarul de bombe:\n");
	scanf("%d", &n);
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++)
			a[i][j] = 0;
	}
	while (nr < n) {
		b = rand() % 10;
		c = rand() % 10;
		if (a[b][c] == 0) {
			nr++;
			a[b][c] = -1;
		}
	}
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			if (a[i][j] == -1)
				Vecini(i, j, a);

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++)
			if (a[i][j] == -1)
				printf("* ");
			else
				printf("%d ", a[i][j]);
		printf("\n");

	}
	return 0;
	system("pause");

}