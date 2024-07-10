
/*
Autor(a): Ana Carolina Fuentes
Objetivo do código -> Comparar o tempo de execução de diferentes algoritmos de ordenação 
*/
#include <stdio.h>
#include <stdlib.h>

#ifdef _linux_
#include <sys/time.h>
#include <time.h>
#elif _WIN32
#include <sys/time.h>
#endif

#define TAM 100000
#define OPCAO 2 // 0-> ordenado, 1-> aleatório, 2-> inverso(decrescente)


void bubbleSort(int *, int);
void bubbleSortMelhorado(int *, int);
void bubbleSortPlus(int *, int);
void insertionSort(int *, int);
void selectionSort(int *, int);
void merge(int *,int *,int ,int *,int);
void mergeSort(int *,int);
void mensagem(double);
void imprimeVetor(int *, int);
int * alocaVetor(int);
void swap(int *, int *);
void quickSort(int *, int, int);
int partition(int *, int, int);
int pesquisaBinaria (int *, int, int, int);
int pesquisaSequencial (int *, int, int);

double time_diff (struct timeval *, struct timeval *);


int main()
{   
    int * vetor1 = alocaVetor(TAM);
    int * vetor2 = alocaVetor(TAM);
    int * vetor3 = alocaVetor(TAM);
    int * vetor4 = alocaVetor(TAM);
    int * vetor5 = alocaVetor(TAM);
    int * vetor6 = alocaVetor(TAM);
    int * vetor7 = alocaVetor(TAM);
    int * vetor8 = alocaVetor(TAM);

    if((vetor1 == NULL || vetor2 == NULL || vetor3 == NULL || vetor4 == NULL || vetor5 == NULL || vetor6 == NULL || vetor7 == NULL))
    {
        printf("Nao foi possivel alocar o(s) vetor(s).\n");
        return -1;
    }

    struct timeval start;
    struct timeval stop;
    double tempo_decorrido;
    //srand = (time(NULL));

    for(int i = 0; i < TAM; i++)
    {
        if(OPCAO == 0)
        {
            *(vetor1 + i) = i;
            *(vetor2 + i) = i;
            *(vetor3 + i) = i;
            *(vetor4 + i) = i;
            *(vetor6 + i) = i;
            *(vetor7 + i) = i;
            *(vetor8 + i) = i;
        } 
        else if(OPCAO == 2)
        {
            *(vetor1 + i) = TAM - i;
            *(vetor2 + i) = TAM - i;
            *(vetor3 + i) = TAM - i;
            *(vetor4 + i) = TAM - i;
            *(vetor6 + i) = TAM - i;
            *(vetor7 + i) = TAM - i;
            *(vetor8 + i) = TAM - i;

        }
    }

    //Teste Bubble Sort

    printf("\n------------BUBBLE SORT----------\n");

    imprimeVetor(vetor1, TAM);
    gettimeofday(&start, NULL);
    bubbleSort(vetor1, TAM);
    gettimeofday(&stop, NULL);
    tempo_decorrido = time_diff(&start, &stop);
    mensagem(tempo_decorrido);
    imprimeVetor(vetor1, TAM);

    printf("------------------------------------\n");

    printf("\n------------BUBBLE SORT VERSAO 1----------\n");
    imprimeVetor(vetor2, TAM);
    gettimeofday(&start, NULL);
    bubbleSortMelhorado(vetor2, TAM);
    gettimeofday(&stop, NULL);
    tempo_decorrido = time_diff(&start, &stop);
    mensagem(tempo_decorrido);
    imprimeVetor(vetor2, TAM);

    printf("------------------------------------\n");

    printf("\n------------BUBBLE SORT VERSAO 2----------\n");
    imprimeVetor(vetor3, TAM);
    gettimeofday(&start, NULL);
    bubbleSortPlus(vetor3, TAM);
    gettimeofday(&stop, NULL);
    tempo_decorrido = time_diff(&start, &stop);
    mensagem(tempo_decorrido);
    imprimeVetor(vetor3, TAM);

    printf("------------------------------------\n");

    printf("\n------------INSERTION SORT----------\n");
    imprimeVetor(vetor4, TAM);
    gettimeofday(&start, NULL);
    insertionSort(vetor4, TAM);
    gettimeofday(&stop, NULL);
    tempo_decorrido = time_diff(&start, &stop);
    mensagem(tempo_decorrido);
    imprimeVetor(vetor4, TAM);

    printf("------------------------------------\n");

    printf("\n------------MERGE SORT----------\n");
    imprimeVetor(vetor6, TAM);
    gettimeofday(&start, NULL);
    mergeSort(vetor6, TAM);
    gettimeofday(&stop, NULL);
    tempo_decorrido = time_diff(&start, &stop);
    mensagem(tempo_decorrido);
    imprimeVetor(vetor6, TAM);

    printf("------------------------------------\n");
    printf("\n------------QUICK SORT----------\n");
    imprimeVetor(vetor7, TAM);
    gettimeofday(&start, NULL);
    quickSort(vetor7, 0, TAM - 1);
    gettimeofday(&stop, NULL);
    tempo_decorrido = time_diff(&start, &stop);
    mensagem(tempo_decorrido);
    imprimeVetor(vetor7, TAM);

    printf("------------------------------------\n");

    printf("\n--------------Teste de Pesquisa------------------\n");
    printf("\n-----------------Binaria--------------------\n");
    gettimeofday(&start, NULL);
    if(OPCAO == 2)
        {
            quickSort(vetor8, 0, TAM - 1);
            pesquisaBinaria(vetor8, 0, TAM - 1, TAM);
        }
    gettimeofday(&stop, NULL);
    tempo_decorrido = time_diff(&start, &stop);
    mensagem(tempo_decorrido);
    printf("\n-----------------Sequencial--------------------\n");
    gettimeofday(&start, NULL);
    pesquisaSequencial(vetor8, TAM, 1);
    gettimeofday(&stop, NULL);
    tempo_decorrido = time_diff(&start, &stop);
    mensagem(tempo_decorrido);


    

}

double time_diff (struct timeval * start, struct timeval * stop)
{
    double tempoDecorrido = (stop->tv_sec - start->tv_sec) + 1.0e-6 * (stop->tv_usec - start->tv_usec);//tv_sec (membro da struct timeval que representa o numero inteiro de segundos percorrido). tv_usec (restante do tempo representado em microssegundo)
    return tempoDecorrido; 
}

void mensagem(double tempo)
{
    printf("Tempo decorrido: %lf s\n", tempo);
}

void imprimeVetor(int * vetor, int size)
{
    printf("Vetor: ");

    for(int i = 0; i < 10; i++)
    {
        printf("%d - ", *(vetor + i));
    }
    printf("\n");

}

int * alocaVetor(int size)
{
    int * vetor = (int*) malloc(size*sizeof(int));

    return vetor;
}

void bubbleSort(int * vetor, int size) //n
{
    int swap;

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - 1; j++)
        {
            if(vetor[j] > vetor[j+1])
            {
                swap = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = swap;
            }
        }
    }
}

void bubbleSortMelhorado(int * vetor, int size) //n² 
{
    int swap; 

    for(int i = 0; i < size; i++) 
    {
        for( int j = size - 1; j >= i; j--)
        {
            if(vetor[j] < vetor[j-1])
            {
                swap = vetor[j-1];
                vetor[j-1] = vetor[j];
                vetor[j] = swap;
            }
        }
    }
}

void bubbleSortPlus(int * vetor, int size) //n²
{
    int troca = 1; 
    int swap;
    int j;
    int i = 1;

     while (i <= TAM && troca == 1)
    {
        troca = 0;
        for(j = 0; j < TAM - 1; j++)
        {
            
            if(vetor[j] > vetor[j+1])
            {
                troca = 1;
                swap = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = swap;
            }  
        }   
            i++;
    }

}

void insertionSort(int * vetor, int size) //compara sempre à esquerda do elemento
{
    int eleito, j;
    for(int i = 1; i <= size - 1; i++)
    {
        eleito = vetor[i];
        j = i - 1;
        
        while(j >= 0 && vetor[j] > eleito)
        {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j+1] = eleito;
    } 
}

void merge(int * A,int * L, int leftCount, int * R,int rightCount) {
	int i , j, k;
	
	i = 0; j = 0; k =0;

	while(i < leftCount && j < rightCount) {
		if(L[i] < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

void mergeSort(int * A,int n) {
	int mid, i, *L, *R;
	if(n < 2) return; 

	mid = n/2; 

	L = (int*) malloc (mid*sizeof(int));
	R = (int*) malloc ((n- mid)*sizeof(int));

	for(i = 0;i<mid;i++) L[i] = A[i];
	for(i = mid;i<n;i++) R[i-mid] = A[i];

	mergeSort(L,mid); 
	mergeSort(R,n-mid); 
	merge(A,L,mid,R,n-mid); 
    free(L);
    free(R);
}

void swap (int  * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int * vet, int low, int high)
{
    int pivot = vet[high];
    int i = (low - 1);

    for(int j = low; j <= high - 1; j++)
    {
        if(vet[j] <= pivot)
        {
            i++;
            swap(&vet[i], &vet[j]);
        }
    }
    swap(&vet[i + 1], &vet[high]);
    return (i + 1);
}

void quickSort (int * vet, int low, int high)
{
    int pi;
    if(low < high)
    {
        pi = partition(vet, low, high);

        quickSort (vet, low, pi - 1);
        quickSort (vet, pi + 1, high);
    }

}

int pesquisaBinaria (int * vet, int l, int r, int key)
{
    int mid;
    while (l >= r)
    {
        mid = l + (r - l)/2;
        if(vet[mid] == key)
            return mid;
        if(vet[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;

}
int pesquisaSequencial (int * vet, int tam, int key)
{
    for(int i = 0; i < tam; i++)
    {
        if(vet[i] == key)
            return i;
    }
    return -1;
}



