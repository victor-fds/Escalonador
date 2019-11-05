#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"matrizes.h"

int main(){
	int n;
	printf("Preparado para ler 'n' do arquivo\n");
	system("pause");
	
	char file[] = "input/input (12).txt";
	
	carregaN(&n, file);
	
	double **A = (double**)malloc(sizeof(double)*n);
	
	carregaMatriz(A, n, file);
	
	int i, j;
	
	
	imprime(A, n);
	printf("\n\n");
	
	for(i=0; i<n; i++){
		
		int linhaMax;
		
		linhaMax = pivotamento(A, i, i, n);		
		trocaLinha(A, linhaMax, i, n);
		
		double pivo = A[i][i];
		double aux[n+1];
		
		divideLinha(A[i], pivo, n);
		guardaLinha(A[i], aux, n);
		
		for(j=0; j<n; j++){
			if(i != j){
				multiplicaLinha(A[i], A[j][i], n);
				subtraiLinha(A[j], A[i], n);
				guardaLinha(aux, A[i], n);
			}
		}
	}
	
	imprime(A, n);	
}
