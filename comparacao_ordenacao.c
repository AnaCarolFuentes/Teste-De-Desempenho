#include <stdio.h>
#include <stdlib.h>

#ifdef _linux_
#include <sys/time.h>
#include <time.h>
#elif _WIN64_
#include <sys/time.h>
#endif


#define TAM 10000
#define OPCAO 0 // 0-> ordenado, 1-> aleatório, 2-> inverso(decrescente)
/*
Autor(a): Ana Carolina Fuentes
Objetivo do código -> Comparar o tempo de execução de diferentes algoritmos de ordenação 
*/

void bubbleSort(int *, int);
void bubbleSortMelhorado(int *, int);
void bubbleSortPlus(int *, int);
void insertionSort(int *, int);
void selectionSort(int *, int);

double time_diff (struct timeval *, struct timeval *);


int main()
{   
    int vetor1[TAM];
    int vetor2[TAM];
    int vetor3[TAM];
    struct timeval start;
    struct timeval stop;
    double tempo_decorrido = 0.0;
    //srand = (time(NULL));

    gettimeofday(&start, NULL);

        for(int i=0; i<10; i++)
        {
            vetor1[i] = i;
        }

    gettimeofday(&stop, NULL);

    printf("Tempo decorrido: %lf", time_diff(&start, &stop));

}

double time_diff (struct timeval * start, struct timeval * stop)
{
    return (stop->tv_sec - start->tv_sec) + 1000000 * (stop->tv_usec - start->tv_usec); //tv_sec (membro da struct timeval que representa o numero inteiro de segundos percorrido). tv_usec (restante do tempo representado em microssegundo)
}
