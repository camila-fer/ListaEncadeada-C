//Projeto Lista Encadeada  Data: 06/12/2020
//Nome: Camila Fernandes da Silva
#include <stdio.h>
#include <stdlib.h>

//Estrutura NO
typedef struct No{
	int valor;
	struct No *proximo; // ponteiro para um pr�ximo elemento
}No;

//Criar a lista
typedef struct{
	No *inicio; // ponteiro do No para inicio
	int tam; // tamanho da lista, quantos elementos eu tenho
}Lista;

// Inserir no inicio da lista
void inserirInicio(Lista *lista, int valor){
	//crio um novo n�
	No *novo = (No*)malloc(sizeof(No)); // aloca��o dinamica na mem�ria
	// guardar valor
	novo->valor = valor; // vai receber um novo valor
	novo->proximo = lista->inicio; // o novo valor vai apontar para um pr�ximo da lista
	lista->inicio = novo;
	lista->tam++; // incrementa mais um
}

// Inserir no final da lista
void inserirFim(Lista *lista, int valor){
	// Crio novo no
	No *no, *novo = (No*)malloc(sizeof(No)); // aloca��o na mem�ria
	novo->valor = valor;
	novo->proximo = NULL;
	
	if(lista->inicio == NULL){
		lista->inicio = novo;
	}else{ // Caso j� tenha algum valor
		no = lista->inicio;
		while(no->proximo != NULL)
			no = no->proximo;
		no->proximo = novo;
	}
	lista->tam++;
}

// Inser��o Ordenada (meio da lista)
void inserirOrd(Lista *lista, int valor){

   	No *atual = lista->inicio;
    No *anterior = NULL;
    No *no, *novo = (No*)malloc(sizeof(No)); // aloca��o na mem�ria
    novo->valor = valor; // vai receber um novo valor

	//crio as variaveis
	//pos vai receber o tamanho da lista
	int pos = lista->tam, count;

	//verifica se o indice � igual a zero
	if(pos == 0){
		//caso seja insiro no inicio da lista
		inserirInicio(lista, valor);
	}
	//se n�o for zero recupero o N� do indice desejado
  	else{
		//pergunto a posi��o desejada e armazeno  	
		printf("\nEm qual posicao de 1 ate %d deseja inserir o novo valor: \n", pos);
		scanf("%d", &pos);
     
     	//Procura posi��o para inserir
   		for(count = 1 ; count < pos ; count++){
     		anterior = atual;
     		atual = atual->proximo; 
   		}
   		
   		//Insere no meio ou no fim da lista
   		anterior->proximo = novo;
   		novo->proximo = atual;
   		lista->tam++; //incrementa mais um
  	}
   
}

// Remover elemento da lista
void remover(Lista *lista, int valor){
	No *inicio = lista->inicio;
	// Rerencia para o No
	No *noARemover = NULL;
	
	// Preciso percorrer a lista e verifica se a lista est� vazia
	if(inicio != NULL && lista->inicio->valor == valor){
		noARemover = lista->inicio; // c�pia do elemento
		lista->inicio = noARemover->proximo; // Vou alterar o inicio e apontar para o primeiro
	}else{
		// Percorro a lista para saber quem vou remover
		/*
			(inicio != NULL && inicio->proximo) Se inicio for diferente de nulo vai para o proximo,
			(inicio->proximo != NULL && inicio->proximo->valor == valor)
			se proximo for diferente de nulo verifica se o proximo valor � igual o valor que quero
		*/
		while(inicio != NULL && inicio->proximo != NULL && inicio->proximo->valor != valor){
			inicio = inicio->proximo;
		}
		if(inicio != NULL && inicio->proximo != NULL){
			//faz a remo��o
			noARemover = inicio->proximo;
			inicio->proximo = noARemover->proximo;
		}
	}
	//Verifico se � diferente de NULL
	if(noARemover){
		free(noARemover); // vou remover a regi�o de mem�ria
		lista->tam--; //vou decrementar a lista, pois foi removido o elemento
	}
}

//Imprimir a lista
void imprimir(Lista *lista){
	
	No *inicio = lista->inicio;
	
	//Primeiro verifico se a lista est� vazia
	if(inicio == NULL){ //caso seja igual a nulo
		printf("\nLista vazia!\n\n"); //mostro msg
	return;
	}
	
	printf("\nTamanho da lista: %d\n", lista->tam); //mostra o tamanho da lista
	printf("\nLista:");
	while(inicio != NULL){ //se inicio for diferente de nulo mostra a lista
		printf("%5d", inicio->valor);
		inicio = inicio->proximo;
	}
	printf("\n        "); //espe�o entre os valores
	
	//para que mostre a ordem dos elementos/posi��o em que est�o na lista
 	int count;
 	for(count=0 ; count < lista->tam ; count++)
  		printf("  ^  ");
 		printf("\nOrdem:");
 	for(count=0 ; count < lista->tam ; count++)
  		printf("%5d", count+1);
   
 	printf("\n\n");	
}

//Fun��o principal do programa
void main(){
	
	//Criando minha lista
	Lista lista;
	int opcao, valor;
	
	//Setar a lista
	lista.inicio = NULL; // o inicio da lista � nulo
	lista.tam = 0; // tamanho inicial � zero
	
	do{
		printf("1 - Inserir no inicio\n2 - Imprimir\n3 - Inserir no fim\n4 - Remover\n5 - Insere ordenado (no meio)\n6 - Sair\n");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				printf("Digite um valor a ser inserido: ");
				scanf("%d", &valor);
				inserirInicio(&lista, valor);
				break;
			case 2:
				imprimir(&lista);
				break;
			case 3:
				printf("Digite um valor a ser inserido: ");
				scanf("%d", &valor);
				inserirFim(&lista, valor);
				break;
			case 4:
				printf("Digite o valor que deseja remover: ");
				scanf("%d", &valor);
				remover(&lista, valor);
				printf("\nValor %d removido\n\n", valor);
				break;
			case 5:
				printf("Digite um valor a ser inserido: ");
				scanf("%d", &valor);
				inserirOrd(&lista, valor);
				break;
			case 6:
				printf("\nFinalizando...\n");
				break;
			default:
				printf("\nOpcao invalida!\n\n");
		}
	}while(opcao != 6);
}
