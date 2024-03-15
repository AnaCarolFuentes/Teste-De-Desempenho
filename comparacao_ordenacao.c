
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

#define TAM 10
#define OPCAO 2 // 0-> ordenado, 1-> aleatório, 2-> inverso(decrescente)


void bubbleSort(int *, int);
void bubbleSortMelhorado(int *, int);
void bubbleSortPlus(int *, int);
void insertionSort(int *, int);
void selectionSort(int *, int);
void mensagem(double);
void imprimeVetor(int *, int);
int * alocaVetor(int);

double time_diff (struct timeval *, struct timeval *);


int main()
{   
    int * vetor1 = alocaVetor(TAM);
    int * vetor2 = alocaVetor(TAM);
    int * vetor3 = alocaVetor(TAM);
    int * vetor4 = alocaVetor(TAM);
    int * vetor5 = alocaVetor(TAM);
    int * vetor6 = alocaVetor(TAM);

    if((vetor1 == NULL && vetor2 != NULL && vetor3 != NULL && vetor4 != NULL && vetor5 != NULL && vetor6 != NULL))
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
        } 
        else if(OPCAO == 2)
        {
            *(vetor1 + i) = TAM - i;
            *(vetor2 + i) = TAM - i;
            *(vetor3 + i) = TAM - i;
            *(vetor4 + i) = TAM - i;

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

void bubbleSort(int * vetor, int size)
{
    int swap;

    for(int i = 1; i <= size; i++)
    {
        for(int j = 0; j < size; j++)
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
    int i;
    int j;
    int swap; 

    for(i = 1; i < size - 1; i++) 
    {
        for(j = size; j >= i; j--)
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
        for(j = 0; j < TAM; j++)
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
    for(int i = 1; i < size; i++)
    {
        eleito = vetor[i];
        j = i - 1;
        
        while(j >= 0 && vetor[j] > eleito)
        {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j+1] = eleito;
    } //corrigir e perguntar Simon
}




