int pivotamento(double **A, int linhaInicial, int col, int n){
	int i, max;
	
	max = fabs(A[linhaInicial][col]);
	int linhaMax = linhaInicial;
	
	for(i=linhaInicial; i<n; i++){
		if(fabs(A[i][col]) >= max){
			max = fabs(A[i][col]);
			linhaMax = i;
		}
	}
	
	return linhaMax;
}

void trocaLinha(double **A, int l1, int l2, int n){
	double *aux;
	
	if(l1 != l2){
		for(int i=0; i<=n; i++){
			aux = A[l1];
			A[l1] = A[l2];
			A[l2] = aux;
		}
	}
}

void guardaLinha(double *A, double *copy, int n){
	for(int j=0; j<=n; j++)
		copy[j] = A[j];
}

void divideLinha(double *A, double pivo, int n){
	for(int coluna=0; coluna<=n; coluna++){
		A[coluna] = A[coluna] / pivo;
	}
}

void multiplicaLinha(double *A, double pivo, int n){
	for(int coluna=0; coluna<=n; coluna++){
		A[coluna] *= pivo;
	}
}

void subtraiLinha(double *A, double *B, int n){
	for(int coluna=0; coluna<=n; coluna++){
		A[coluna] -= B[coluna];
	}
}

void imprime(double **A, int n){
	int i, j;
	printf("\n");
	for(i=0; i<n; i++){
		for(j=0; j<=n; j++){	
			if(j != n)
				printf("%.1lf\t", A[i][j]);
			else
				printf("\t| %.8lf\n", A[i][j]);
		}
	}
	printf("\n");
}

void carregaN(int *n, char input[]){
	
	FILE *arq = fopen(input, "r");
	if(arq == NULL)
		printf("Erro ao carregar o arquivo!\n");
	else{ 
		rewind(arq);
		fscanf(arq, "%d", n);
	}
	
	fclose(arq);
}

void carregaMatriz(double **A, int n, char input[]){

	FILE *arq = fopen(input, "r");
	if(arq == NULL)
		printf("Erro ao carregar o arquivo!\n");
	else{ 
		rewind(arq);
		
		fscanf(arq, "%d\n", &n);
		
		int i, j;
				
		for(i=0; i<n; i++){
			A[i] = (double*)malloc(sizeof(double)*(n+1));
			
			for(j=0; j<=n; j++){
				if(j != n){
					fscanf(arq, "%lf", &A[i][j]);
				}
				else{
					fscanf(arq, "%lf", &A[i][j]);
				}
			}
		}
	}
	
	fclose(arq);
}
