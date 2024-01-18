#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int data;
	struct no *proximo;
}No;

typedef struct{
	No *inicio;
	int tam;
}Lista;

void criar__lista(Lista *lista){
	lista->inicio = NULL;
	lista->tam = 0;
}

void inserir__no__inicio__lista(Lista *lista, int value){
	No *novo = malloc(sizeof(No));
	
	if(novo){
		novo->data = value;
		novo->proximo = lista->inicio;
		lista->inicio = novo;
	}else{
		printf("Alocacao de memoria mal sucedida");
	}
}

void inserir__no__meio__lista(Lista *lista, int value, int antecessor){
	No *aux, *novo = malloc(sizeof(No));
	
	if(novo){
		novo->data = value;
		
		if(lista->inicio == NULL){
			novo->proximo = NULL;
			lista->inicio = novo;
		}else{
			aux = lista->inicio;
			while(aux->data != antecessor && aux->proximo != NULL)	
				aux = aux->proximo;
			novo->proximo = aux->proximo;
			aux->proximo = novo;
		}
	}else{
		printf("Alocacao de memoria mal sucedida");
	}

}

void inserir__no__final__lista(Lista *lista, int value){
	No *aux, *novo = malloc(sizeof(No));
	
	if(novo){
		novo->data = value;
		novo->proximo = NULL;
		
		if(lista->inicio == NULL){
			lista->inicio = novo;
		}else{
			aux = lista->inicio;
			while(aux->proximo)
				aux = aux->proximo;
			aux->proximo = novo;
		}
		
	}else{
		printf("Alocacao de memoria mal sucedida");		
	}
}

void imprimir(Lista *lista) {
    No *aux;

    if (lista->inicio) {
        aux = lista->inicio;
        while (aux) {
            printf("%d ", aux->data);
            aux = aux->proximo;
        }
        printf("\n");
    } else {
        printf("Lista Vazia\n");
    }
}


int main(){
	
	int opcao, valor, anterior;
	
	Lista lista;
	
	criar__lista(&lista);
	
	do{
		printf("Entre com a operacao\n\t1-Inserir Inicio\n\t2-Inserir Meio\n\t3-Inserir Final\n\t4-Mostrar Lista");
		scanf("%d", &opcao);
		
	        switch (opcao) {
            case 1:
                printf("Entre com o valor para inserir no inicio: ");
                scanf("%d", &valor);
				inserir__no__inicio__lista(&lista,valor);
                break;
            case 2:
                printf("Entre com o valor para inserir no Meio: ");
                scanf("%d%d", &valor, &anterior);
				inserir__no__meio__lista(&lista, valor, anterior);
                break;
            case 3:
                printf("Entre com o valor para inserir no Meio: ");
                scanf("%d", &valor);
                inserir__no__final__lista(&lista, valor);           
                break;
            case 4:
				imprimir(&lista);
                break;
        }
	
		
		
		
	}while(opcao!=0);
	
	
	
	return 0;	

}