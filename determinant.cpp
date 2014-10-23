// MATRIX DETERMINANS

#include <vector>
#include <cstdio>
#include "determinant.h"

using namespace std;


void oszlopcsere(vector<vector<double> > &A, int f, int t) {
	printf("Oszlopcsere %d es %d kozt.\n", f, t);
	int n = A[0].size();
	double temp;
	for (int i = 0; i < n; i++) {
		temp = A[i][f];
		A[i][f] = A[i][t];
		A[i][t] = temp;
	}
}

int maxindex(const vector<vector<double> > &A, int sor) {
	int n = A.size();
	double max = A[sor][0];
	int maxindex = 0;
	for (int i = 1; i < n; i++) {
		if (abs(max) < abs(A[sor][i])) {
			max = A[sor][i];
			maxindex = i;
		}
	}
	printf("A maximalis index a %d sorban a %d oszlop.\n", sor, maxindex);
	return maxindex;
}

void sorkivonas(vector<vector<double> > &A, int mibol, int mit, double hanyszor) {
	printf("Sorkivonas %d sorbol %lf*%d sort.\n", mibol, hanyszor, mit);
	int n = A[0].size();
	for (int i = 0; i < n; i++) {
		A[mibol][i] -= hanyszor * A[mit][i];
	}
}

double det(vector<vector<double> > &A) {
	double det = 1;
	int i = 0;
	const int n = A.size();
	while (i < n - 1) {
		int temp = maxindex(A, i);
		det *= A[i][temp];
		if (det == 0)
			break;
		if (temp != i) {
			det *= -1;
			oszlopcsere(A, temp, i);
		}
		for (int j = i + 1; j < n; j++) {
			sorkivonas(A, j, i, A[j][i] / A[i][i]);
		}
		i++;
		matrixkiir(A);
	}
	det *= A[n - 1][n - 1];
	return det;
}

void matrixkiir(const vector<vector<double> > &A) {
	const int n = A.size();
	const int m = A[0].size();
	printf("A:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%1lf ", A[i][j]);
		}
		printf("\n");
	}
}
