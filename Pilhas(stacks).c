#include <stdio.h>
#include <stdlib.h>

typedef struct NoPilha {
    int data;
    struct NoPilha* proximoPtr;
} NO__PILHA;

typedef NO__PILHA* NO__PILHA__PTR;

void push(NO__PILHA__PTR*, int value);
int pop(NO__PILHA__PTR*);
int isEmpty(NO__PILHA__PTR);
void printar__no(NO__PILHA__PTR);

int main(){
	int opcao, valor;
	
	NO__PILHA__PTR pilha = NULL;
	
	do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Verificar se a pilha esta vazia\n");
        printf("4. Imprimir a pilha\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido na pilha: ");
                scanf("%d", &valor);
                push(&pilha, valor);
                break;
			case 2:
			    if (!isEmpty(pilha)) {
			        printf("Elemento removido: %d\n", pop(&pilha));
			    } else {
			        printf("A pilha esta vazia.\n");
			    }
			    break;
			case 3:
			    if (isEmpty(pilha)) {
			        printf("A pilha esta vazia.\n");
			    } else {
			        printf("A pilha nao esta vazia.\n");
			    }
			    break;
			case 4:
				printar__no(pilha);
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

void push(NO__PILHA__PTR *TopPtr, int value){
	NO__PILHA__PTR NewPtr;
	NewPtr = malloc(sizeof(NO__PILHA));
	if(NewPtr){
		NewPtr->data = value;
		NewPtr->proximoPtr = *TopPtr;
		*TopPtr=NewPtr;
	}else{
		printf( "%d nao foi inserido. Nao existe memória disponivel.\n" , value);
	}
}

int pop(NO__PILHA__PTR *TopPtr){
	NO__PILHA__PTR TempPtr;
	int ValorPop;
	TempPtr = *TopPtr;
	ValorPop = (*TopPtr)->data;
	*TopPtr = (*TopPtr)->proximoPtr;
	free(TempPtr);
	return ValorPop;
}

int isEmpty(NO__PILHA__PTR TopPtr){
	if(TopPtr == NULL)
		return 1;
	else 
		return 0;
}

void printar__no(NO__PILHA__PTR TopPtr){
	if(TopPtr == NULL){
		printf("Stack Vazia");
	}
	else{
		while(TopPtr != NULL){
			printf("%d", TopPtr->data);
			TopPtr = TopPtr->proximoPtr;
		}
	}
}







