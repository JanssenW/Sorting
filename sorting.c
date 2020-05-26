#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h> 

#define CLEAR "clear"

int passei = 0;

unsigned long long current_timestamanhop() {
    struct timeval tv;
    unsigned long long tim;
    gettimeofday(&tv, NULL);
    tim = 1000000 * tv.tv_sec + tv.tv_usec;
    return tim;
}

void imprimirArray(int *array, int tamanho) {


    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
}

int *criarArray(int tamanho) {
    int *array = (int *) malloc(sizeof(int) * tamanho);
    for (int i = 0; i < tamanho; i++) {
        array[i] = i + 1;
    }
    return array;
}

int *desorganizar(int *array, int tamanho) {
    time_t tim;
    srand((unsigned) time(&tim));
    for (int i = 0; i < tamanho; i++) {
        int rand_pos = (int)(((double)rand()/RAND_MAX) * tamanho);
        int t = array[rand_pos];
        array[rand_pos] = array[i];
        array[i] = t;
    }
    return array;
}



void insertionSort(int *x, int tamanho) {
    //implementar e medir/imprimir o tempo total de execucao em microssegundos

    //int x[] = *array;
    passei = 1;
    int n = tamanho;
    int i, k, aux;

for (k = 1; k < n; k++) {

    aux = x[k];

    for (i = k - 1; i >= 0 && aux < x[i]; i--) {

        x[i + 1] = x[i];

    }

        x[i + 1] = aux;

    }



}

void bubblesort(int *x, int tamanho) {

    passei = 1;
    int i, j, aux;

        for(j = tamanho - 1; j > 0; j--) {

            for(i = 0; i < j; i++) {

                if(x[i] > x[i + 1]) {

                    aux = x[i];
                    x[i] = x[i + 1];
                    x[i + 1] = aux;
                }
            }
    }
}



void quickSort(int *x, int p, int u) {

    //p -> indice na Primeira posição do array
    //u -> indice na Ultima posição do array
    passei = 1;
    int i, j, pivo, aux;
    
    i = p;
    j = u;

    pivo = x[(i + j)/2];

        do{

            while(x[i] < pivo && i < u) i++;

            while(x[j] > pivo && j > p) j--;

                if(i <= j){

                    aux = x[i];
                    x[i] = x[j];
                    x[j] = aux;
                    i++;
                    j--;
                }

        } while(i <= j);

            if(p < j) quickSort(x, p, j);
            if(i < u) quickSort(x, i, u);
}



void shellSort(int *x, int tamanho) {
    //implementar e medir/imprimir o tempo total de execucao em microssegundos

    //int x[] = array;
    passei = 1;
    int n = tamanho;

    int gap, j, k, aux;

    for(gap = n / 2; gap >= 1; gap = gap / 2) {

        for(j = gap; j < n; j++) {

        aux = x[j];

        for(k = j - gap; k >= 0 && aux < x[k]; k-=gap) {

                x[k + gap] = x[k];

            }

        x[k + gap] = aux;

      }
    }


}


void imprimeMenu() {
    printf("================================================================\n");
    printf("|     Tempo de execucao de diferentes metodos de ordenacao     |\n");
    printf("================================================================\n");
    printf("| Operacoes:                                                   |\n");
    printf("| 1) Insertion Sort                                            |\n");
    printf("| 2) Shell Sort                                                |\n");
    printf("| 3) Bobble Sort                                               |\n");
    printf("| 4) Quick Sort                                                |\n");
    printf("| 5) Imprimir array original                                   |\n");
    printf("| 6) Imprimir array ordenado                                   |\n");
    printf("| 7) Novo vetor                                                |\n");
    printf("| 9) Sair                                                      |\n");
    printf("+--------------------------------------------------------------+\n");
    printf("  Pressione a opcao desejada ");
}


int main() {
    int *original, *ordenado, tamanho;
    int ok = 1;
    int tam;
    

     char opcao = '0';
    //pedir e ler o valor de tamanho, e substituir a atribuicao abaixo
    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &tam);

    //criando o array original
    original = desorganizar(criarArray(tam), tam);
    //alocando memoria para o array ordenado
    
    //copiar semopre o original para o ordenado, antes de chamar cada metodo de ordenacao
   
    //exemplo de medicao de tempo, em microssegundos
    unsigned long long t1, t2;
    /*
    t1 = current_timestamanhop();
    imprimirArray(original, tamanho);
    t2 = current_timestamanhop();
    printf("\nDuracao em microssegundos: %lld\n", t2 - t1);
    getchar();
    */
    //imprimindo o menu. Colocar dentro de um la�o de while e chamar as funcoes, controlar encerramento com switch


    while(ok) {
        system(CLEAR);
        imprimeMenu();
        opcao = getchar();
        switch(opcao) {
            case '1':   printf("\nOrdenar com Insertion Sort: ");
                        ordenado = (int *) malloc(sizeof(int) * tam);
                        memcpy(ordenado, original, sizeof(int) * tam);
                        t1 = current_timestamanhop();
                        insertionSort(ordenado, tam);
                        t2 = current_timestamanhop();
                        printf("\nDuracao em microssegundos: %lld\n", t2 - t1);
                        
						getchar();
						getchar();
						break;
            case '2': 	printf("\nOrdenar com Shell Sort: ");
                        ordenado = (int *) malloc(sizeof(int) * tam);
                         memcpy(ordenado, original, sizeof(int) * tam);
                        t1 = current_timestamanhop();
                        shellSort(ordenado, tam);
                        t2 = current_timestamanhop();
                        printf("\nDuracao em microssegundos: %lld\n", t2 - t1);

						getchar();
						getchar();
						break;


            case '3': 	printf("\nOrdenar com Bubble Sort: ");
                        ordenado = (int *) malloc(sizeof(int) * tam);
                         memcpy(ordenado, original, sizeof(int) * tam);
                        t1 = current_timestamanhop();
                        bubblesort(ordenado, tam);
                        t2 = current_timestamanhop();
                        printf("\nDuracao em microssegundos: %lld\n", t2 - t1);

						getchar();
						getchar();
						break;


            case '4': 	printf("\nOrdenar com Quick Sort: ");
                        ordenado = (int *) malloc(sizeof(int) * tam);
                         memcpy(ordenado, original, sizeof(int) * tam);
                        t1 = current_timestamanhop();
                        quickSort(ordenado, 0, tam - 1);
                        t2 = current_timestamanhop();
                        printf("\nDuracao em microssegundos: %lld\n", t2 - t1);

						getchar();
						getchar();
						break;





            case '5': 	imprimirArray(original, tam);
						getchar();
						getchar();
						break;
            case '6': 	if (passei)

                        imprimirArray(ordenado, tam);

                        else printf("Nenhum vetor ordenado");

                        

						getchar();
						getchar();
						break;
            case '7':   passei = 0;
                        printf("\nDigite o tamanho do vetor: ");   
                        scanf("%d", &tam);
                        original = desorganizar(criarArray(tam), tam);
                        getchar();
						getchar();
                        break;

            case '9': 	ok = 0;
						break;
            default: 	printf("\nOpcao invalida!\n");
						getchar();
						getchar();
						break;
        }
    }
    printf("\n");
    return (EXIT_SUCCESS);
}

