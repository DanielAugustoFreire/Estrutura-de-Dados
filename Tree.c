#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct treeNode{
	struct treeNode *LeftPtr;
	int data;
	struct treeNode *RightPtr;
};
typedef struct treeNode TREENODE;
typedef TREENODE *TREE__NODE__PTR;

void InsertNode(TREE__NODE__PTR *TreePtr, int value){
	
	if(*TreePtr == NULL){
		*TreePtr = malloc(sizeof(TREENODE));
		
		if(*TreePtr != NULL){
			(*TreePtr)->data = value;
			(*TreePtr)->LeftPtr = NULL;
			(*TreePtr)->RightPtr = NULL;
		}
		else{
			printf ("%d nao inserido. Nao existe memoria disponivel. \n",value);
		}
	}
	else{
		if(value < (*TreePtr)->data)
			InsertNode(&((*TreePtr)->LeftPtr), value);
		else{
			if(value > (*TreePtr)->data)
				InsertNode(&((*TreePtr)->RightPtr), value);
			else
				printf("Dup");
		}
	}
}
void preOrder(TREE__NODE__PTR TreePtr){
	if(TreePtr != NULL){
		printf("%3d", TreePtr->data);
		preOrder(TreePtr->LeftPtr);
		preOrder(TreePtr->RightPtr);
	}
}

void inOrder(TREE__NODE__PTR TreePtr){
	if(TreePtr != NULL){
		inOrder(TreePtr->LeftPtr);
		printf("%3d", TreePtr->data);
		inOrder(TreePtr->RightPtr);
	}
}

void postOrder(TREE__NODE__PTR TreePtr){
	if(TreePtr != NULL){
		postOrder(TreePtr->LeftPtr);
		postOrder(TreePtr->RightPtr);
		printf("%3d", TreePtr->data);
	}
}

int main(){
	int i, valor;
	TREE__NODE__PTR No_Principal = NULL;
	srand(time(NULL));
	for(i = 0; i <= 10; i++){
		valor = rand() % 100;
		printf("%3d", valor);
		InsertNode(&No_Principal, valor);
	}
	printf(" \n\nO percurso com preOrder e:\n"); 
	preOrder(No_Principal); 

	printf("\n\nO percurso com inOrder e:\n");
	inOrder(No_Principal); 
	
	printf("\n\nO percurso com postorder e:\n"); 
	postOrder(No_Principal);
	
	return 0;
}
