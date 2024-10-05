//praticando métodos de ordenação de dados e busca binária.

/*
  nome: BuscaBinaria.c
  autor: Giovanni Rafael Serafim
  data: 05/6/2024
  descrição: informa a posição do elemento que o usuario pedir de um vetor ordenado por insertion sort.
*/

#include <stdio.h>
#include <stdlib.h>
void buscabinaria(int *, int, int); //prototipando a função da busca binaria

void InsertionSort (int*, int);//prototipando a função do insertionSort

int main()
{
	int tam;
	printf("informe o tamanho do vetor: ");
	scanf("%d", &tam);
	
	int *vet = (int*) malloc(tam * sizeof(int)); //aloçação dinâmica

	if (vet == NULL) {
        printf("Erro na alocação de memoria\n");
        return 1; // Encerra o programa com erro
         }
	
    for(int i=0;i<tam;i++)
    {
    	printf("digite a posicao %d do vetor: ", i+1);
    	scanf("%d", &vet[i]);
	}
    
    printf("vetor atual: ");
    
		for (int i=0; i<tam; i++) //printando o vetor
	{
		printf("%d|", vet[i]);
	}
	
	InsertionSort(vet, tam);

	printf("\nvetor ordenado pelo insertionSort: ");
	
		for (int i=0; i<tam; i++) //printando o vetor
	{
		printf("%d|", vet[i]);
	}
	buscabinaria( vet,  0,  tam-1); //chamando a função
}

void InsertionSort(int *lista, int tamanho) 
{
int i,j,aux;
  for(i=0; i<tamanho-1; i++) {
    if(lista[i]>lista[i+1]) { 
      aux=lista[i+1];
      lista[i+1]=lista[i]; lista[i]=aux;
      j=i-1;
       while(j>=0){
         if(aux<lista[j]){
            lista[j+1]=lista[j]; lista[j]=aux;
        }else{
         break;
          }
       j=j-1;
         }//fim do while
     }
   } //fim do for
}//fim do insertion sort

void buscabinaria (int *v, int ini, int fim)
{
	int elem;//elemento pedido pelo usuario
	int meio;
	int achou = 0;//variavel para caso o elemento não seja achado
	
	printf("\ndigite o elemento desejado: ");
	scanf("%d", &elem);
	
	while (ini<=fim) //enquanto o vetor existir
	{
		meio = (ini+fim)/2;
		
		if (elem == v[meio])
		{
			achou = 1;
			break;
		}
		
		else if(elem < v[meio])//se menor, cortar a metade maior do vetor
		{
			fim = meio - 1;
		}
		else//se maior, cortar a metade menor do vetor
		{
			ini = meio + 1;
		}		
	}
	
	if(achou == 1)
	{
		printf("o %d esta na posicao %d", elem, meio+1);
	}
	else
	{
		printf("o %d nao existe nesse vetor", elem);
	}
}//fim da busca binaria