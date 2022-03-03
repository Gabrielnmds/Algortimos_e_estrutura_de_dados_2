#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int Type;
typedef struct Node* node;
typedef struct binary_tree* tree;

// Define como os elementos serao armazenados na arvore
struct Node {
	Type key;
	struct Node* esq;
	struct Node* dir;
};

// Define uma arvore binaria
struct binary_tree {
	node raiz; // Ponteiro para raiz
	int height; // Altura da arvore
};

tree new_tree(){
	tree t = malloc(sizeof(tree));
	t->height = 1;
	t->raiz = malloc(sizeof(node));
	t->raiz = NULL;
	return t;
}

bool ehFolha(node n) {
	if(n->esq == NULL && n->dir == NULL)
		return true;
	else
		return false;
}

void manutencao(tree t, node n) {
	Type aux;
	if(!ehFolha(n)){
		// Testa se esq eh maior que n, consertando caso seja
		if(n->esq->key > n->key){
			aux = n->esq->key;
			n->esq->key = n->key;
			n->key = aux;
		}
		// Testa se n eh maior que dir, consertando caso seja
		else if(n->key > n->dir->key){
			aux = n->dir->key;
			n->dir->key = n->key;
			n->key = aux;
			// Testa novamente se esq eh maior que n, consertando caso a nova chave de n seja menor
			if(n->esq->key > n->key){
				aux = n->esq->key;
				n->esq->key = n->key;
				n->key = aux;
			}
		}
		manutencao(t, n->esq);
		manutencao(t, n->dir);
	}
	else 
		return;
}

bool tree_search(Type k, node n) {
	if(k == n->key)
		return true;//k = n->key;
	else if(k != n->key && ehFolha(n))
		return false;//printf("\nRegistro nao presente na arvore!"); 
	else if(k < n->key) 
		tree_search(k, n->esq);
	else
		tree_search(k, n->dir);
}



void insert(tree t, Type k, node n) {
	if(tree_search(k, t->raiz))
		printf("\nRegistro ja presente na arvore!");
	else{
		if(ehFolha(n)){
			node new = malloc(sizeof(node));
			new->key = k;
			new->esq = NULL;
			new->dir = NULL;
			if(k < n->key)
				n->esq = new;
			else 
				n->dir = new;
			t->height++;
		}
		else if(n == NULL){
			node new = malloc(sizeof(node));
			n = new;
			n->key = k;
			n->esq = NULL;
			n->dir = NULL;
		}
		else if(k > n->esq->key && k < n->key){
			node new = malloc(sizeof(node));
			new->key = k;
			new->dir = NULL;
			new->esq = n->esq;
			n->esq = new;
		}
		else if(k < n->dir->key && k > n->key){
			node new = malloc(sizeof(node));
			new->key = k;
			new->esq = NULL;
			new->dir = n->dir;
			n->dir = new;
		}
		else{
			if(k < n->key)
				insert(t, k, n->esq);
			else if(k > n->key)
				insert(t, k, n->dir);
		}
	}
}

void pesquisa_sequencial(Type v[], Type k, int n){
	int found;
	for(int i=0;i<n;i++){
		if(k == v[i]){
			found = 1;
			break;
		}
		else
			found = 0;
	}
	if(!found)
		printf("\nRegistro inexistente!");
	else
		printf("\nElemento no indice %d do vetor", v[i]);
}

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

void binary_search(Type v[], Type k, int m, int n){
	insertion(v, m, n);	
	if(m > n)
		printf("\nElemento inexistente!");
	if(k == v[n/2])
		printf("\nElemento no indice %d do vetor", v[n/2]);
	else if(k < v[n/2])
		binary_search(v, k, 0, n/2);
	else if(k > v[n/2])
		binary_search(v, k, (n/2)+1, n);
}