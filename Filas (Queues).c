#include <stdio.h>
#include <stdlib.h>

struct fila{
	int data;
	struct fila *proximo;
};

typedef struct fila FILA;
typedef FILA *FILA__PTR;

void enqueue(FILA__PTR *Fim_Da_Fila, FILA__PTR *Inicio_Da_Fila, int value){
	FILA__PTR Novo_Ptr;
	Novo_Ptr = malloc(sizeof(FILA));
	
	if(Novo_Ptr){
		Novo_Ptr->data = value;
		Novo_Ptr->proximo = NULL;
		if(*Inicio_Da_Fila == NULL)
		{
			*Inicio_Da_Fila = Novo_Ptr;
			*Fim_Da_Fila = Novo_Ptr;
		}else{
			(*Fim_Da_Fila)->proximo = Novo_Ptr;
			*Fim_Da_Fila = Novo_Ptr;	
		}
	}else{
			printf( "%d nao inserido. Nao existe memoria disponivel.\n", value);
	}
}

int dequeue(FILA__PTR *Fim_Da_Fila, FILA__PTR *Inicio_Da_Fila){
	FILA__PTR Temporario;
	int value;

	if(*Inicio_Da_Fila == NULL){
		printf("Fila Vazia\n");
		return -1;
	}
	
	value = (*Inicio_Da_Fila)->data;
	Temporario = *Inicio_Da_Fila;
	*Inicio_Da_Fila = (*Inicio_Da_Fila)->proximo;
	if(*Inicio_Da_Fila == NULL){
		*Fim_Da_Fila = NULL;
	}
	free(Temporario);
	return value;
}

int printQueue(FILA__PTR Ponteiro_Atual){
	if(Ponteiro_Atual== NULL){
		printf("A Fila Esta Vazia");
	}else{
		printf("FILA: \n\n");
		
		while(Ponteiro_Atual != NULL){
			printf("%d ", Ponteiro_Atual->data);
			Ponteiro_Atual = Ponteiro_Atual->proximo;
		}
		printf("NULL \n\n");
	}
	
}

int main() {
    FILA__PTR Inicio_Da_Fila = NULL;
    FILA__PTR Fim_Da_Fila = NULL;

    int opcao, valor;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Imprimir Fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido na fila: ");
                scanf("%d", &valor);
                enqueue(&Fim_Da_Fila, &Inicio_Da_Fila, valor);
                system("cls");
                break;
            case 2:
                valor = dequeue(&Fim_Da_Fila, &Inicio_Da_Fila);
                if (valor != -1) {
                    printf("\nElemento removido: %d\n\n", valor);
                }
                system("pause");
                system("cls");
                break;
            case 3:
            	system("cls");
                printQueue(Inicio_Da_Fila);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}