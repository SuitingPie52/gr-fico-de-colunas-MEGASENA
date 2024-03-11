// INFORMACOES IMPORTANTES:
// 
// NUMERO 0 NAO PODE SER JOGADO, POR ISSO NAO FOI UTILIZADO NOS ARRAYS
// SE VC QUISER 20 IDX NO GRAFICO, BOTAR 21 JA QUE O 0 FOI DESCONSIDERADO

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cstdio>

int i = 0, j = 0, temp = 0;
const int TAMANHO = 61;
int mapa[TAMANHO];
time_t t;

int copyArray(int l[TAMANHO], int l2[TAMANHO]) { // cria a copia de uma array
	
	for (i = 0; i < TAMANHO; i++) {
		
		l2[i] = l[i];
		
	}
	
	return l2[TAMANHO];
	
}

int valueDescendingSort(int l[TAMANHO]) { // vai ordenar os valores de idx 1 a 60 de forma decrescente
	
	for(i = 1; i < TAMANHO - 1; i++) {
	
		for(j = i + 1; j < TAMANHO; j++) {
	
			if (l[j] > l[i]) {
			
				temp = l[i];
				l[i] = l[j];
				l[j] = temp;
			
			}
		}                                            
		                                  
	}
	
	return l[TAMANHO];
	
	
} 

int maxMapValue(int l[TAMANHO]) { 
	
	int maxValue = 0;
	
	for(i = 1; i < TAMANHO - 1; i++) {
	
		if (l[i] > maxValue) {
			
			maxValue = l[i];
			
		}                                
		                                  
	}
	
	return maxValue;
	
	
} 


void printTableMostSorted(int mapa[TAMANHO]) {
		
	int valueSorted[TAMANHO];
	copyArray(mapa, valueSorted);
	valueDescendingSort(valueSorted);
	int printed = 1;
	int comp, temp;
	
	j = 1;
	comp = valueSorted[j];
	int rank = 1; 
	
	printf("Most sorted numbers (min: 5)\n------------------------\n| Pos. | Idx. | Value. |\n------------------------\n");
	
	while (printed < 6) {
		
		// printar todos os idx e valores dos maiores valores
		for (i = 1; i < TAMANHO; i++) {
			
			if (comp == mapa[i]) {
				
				printf("| %4d | %4d | %6d |\n", rank, i, mapa[i]);
				printed++;
				
			}
			
		}
	
		rank++;
	
		// mudar valor dos n�meros que ser�o printados
		temp = valueSorted[j];
		while (temp == comp) {
			
			j++;
			comp = valueSorted[j]; 
			
		}
		
	}
	
	printf("------------------------\n\n");
	
}

void printTableLessSorted(int mapa[TAMANHO]) {
	
	int valueSorted[TAMANHO];
	copyArray(mapa, valueSorted);
	valueDescendingSort(valueSorted);
	int printed = 1;
	int comp, temp;
	
	j = TAMANHO - 1;
	comp = valueSorted[j];
	int rank = 1; 
	
	printf("Less sorted numbers (min: 5)\n------------------------\n| Pos. | Idx. | Value. |\n------------------------\n");
	
	while (printed < 6) {
		
		// printar todos os idx e valores dos maiores valores
		for (i = 1; i < TAMANHO; i++) {
			
			if (comp == mapa[i]) {
				
				printf("| %4d | %4d | %6d |\n", rank, i, mapa[i]);
				printed++;
				
			}
			
		}
	
		rank++;
	
		// mudar valor dos n�meros que ser�o printados
		temp = valueSorted[j];
		while (temp == comp) {
			
			j--;
			comp = valueSorted[j]; 
			
		}
		
	}
	
	printf("------------------------\n\n");
	
}

void printGraph (int mapa[TAMANHO]) { // vai receber um array que representa cada número e sua frequência
									// Ex: mapa[5] armazena o int 10, quer dizer que 5 aparece 10 xs
	
	int maxValue = maxMapValue(mapa);
	
	// imprime colunas 

	// BOTAR TITULO/LEGENDA NO GRAFICO
	printf("-------------------------------------\n|Frequency Graph: Most Sorted Number|\n-------------------------------------\n");
	
	
	for (i = maxValue; i > 0; i--) {
		
		printf("%2d  |", i);
		
		for (j = 1; j < TAMANHO; j++) {
			
			if (mapa[j] >= i) {
				
				printf("  %c%c", 219, 219);
				
			} else {
				
				printf("    ");
				
			}
			
		}
		
		printf("\n");
		
	}
	
	
	// imprimir linha horizintal
	printf("--------");
	for (i = 1; i < TAMANHO; i++) {
		
		printf("----");
		
	}
	
	// imrprime idx (números sorteados)
	
	printf("\n    |");
	
	for (i = 1; i < TAMANHO; i++) {
		
		printf("  %2d", i);
		
	} 
	
	printf("\n\n");
	
	printTableMostSorted(mapa);
	printTableLessSorted(mapa);
	
}

int main(){
	
	// definindo valores aleatorios para um array
	
	srand((unsigned) time(&t));

	for (i = 1; i < TAMANHO; i++) {
	
		mapa[i] = (rand() % 21);
	
	}
        	
	for (i = 0; i < TAMANHO; i++) {
	
		printf("%d\n", mapa[i]);
	
	}  
	

	
	printf("-----------------------------\n");
	
	printGraph(mapa);
	
}
