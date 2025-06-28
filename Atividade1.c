#include <stdio.h>

// função pra mostrar o conteúdo do array
void exibirArray(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// função de busca linear
int localizarLinear(int v[], int n, int alvo) {
    for (int i = 0; i < n; i++) {
        if (v[i] == alvo) return i;
    }
    return -1;
}

// função de ordenação Bubble Sort
void ordenarBubble(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

// função de busca binaria (array deve estar ordenado)
int localizarBinaria(int v[], int n, int alvo) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (v[meio] == alvo)
            return meio;
        else if (v[meio] < alvo)
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

int main() {
    int numeros[] = {88, 42, 17, 95, 23, 56, 71, 3, 39, 64};
    int tam = 10;

    printf("Array inicial:\n");
    exibirArray(numeros, tam);

    // busca linear
    printf("\nProcurando o numero 23 com busca linear...\n");
    int posLinear = localizarLinear(numeros, tam, 23);
    if (posLinear != -1)
        printf("Numero 23 encontrado na posicao %d (linear).\n", posLinear);
    else
        printf("Numero 23 não encontrado (linear).\n");

    // ordenação com Bubble Sort
    printf("\nOrdenando com Bubble Sort...\n");
    ordenarBubble(numeros, tam);

    printf("Array ordenado:\n");
    exibirArray(numeros, tam);

    // busca binária
    printf("\nProcurando o numero 23 com busca binaria...\n");
    int posBinaria = localizarBinaria(numeros, tam, 23);
    if (posBinaria != -1)
        printf("Numero 23 encontrado na posicao %d (binaria).\n", posBinaria);
    else
        printf("Numero 23 não encontrado (binaria).\n");

    return 0;
}