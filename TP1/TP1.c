#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion(int V[], int m, int n){ 
	int aux;
	for(int j=m;j<n;j++){
		aux = V[j];
		int i = j - 1;
		while(i>=0 && aux<V[i]){
			V[i+1] = V[i];
			i--;
		}
		V[i+1] = aux;
	}
}

int partition(int V[], int m, int n){
	int p = V[n];
	int i = m - 1;
	int aux;
	for(int j=m;j<n;j++){
		if(V[j] <= p){
			i = i + 1;
			aux = V[j];
			V[j] = V[i];
			V[i] = aux;
		}
	}
	aux = V[i + 1];
	V[i + 1] = V[n];
	return i + 1;
}

void mySort(int V[], int m, int n){ //m < n
	if(m < n){
		int q;
		q = partition(V, m, n);
		insertion(V, m, q - 1);
		insertion(V, q + 1, n);	
	}
}

void heapsort(int V[], int n) {
	int i = n / 2, pai, filho, t;
	for (;;){
		if(i > 0){ 
			i--;
            t = V[i];
        } 
	    else{
		    n--;
            if (n == 0)
				break;
            t = V[n];
            V[n] = V[0];
        }
    pai = i;
    filho = i * 2 + 1;
    while (filho < n) {
        if((filho + 1 < n)  &&  (V[filho + 1] > V[filho]))
			filho++;
			if (V[filho] > t) {
				V[pai] = V[filho];
				pai = filho;
				filho = pai * 2 + 1;
            } 
			else{
				break;
            }
        }
		V[pai] = t;
    }
}

void quicksort(int V[], int m, int n){
	if(m < n){
		int q;
		q = partition(V, m, n);
		quicksort(V, m, q - 1);
		quicksort(V, q + 1, n);	
	}
}