#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEXT_SIZE 1000

// Estrutura para armazenar o mapa de frequência
struct FrequencyMapResult {
    char pattern[MAX_TEXT_SIZE];
    int count;
};

// Função para criar um mapa de frequência para k-mers em uma sequência de DNA
struct FrequencyMapResult *FrequencyMap(char Text[], int k, int *resultSize) {
    struct FrequencyMapResult *freqMap = NULL;

    *resultSize = 0;
    for (int i = 0; i <= strlen(Text) - k; i++) {
        char currentPattern[MAX_TEXT_SIZE];
        strncpy(currentPattern, &Text[i], k);
        currentPattern[k] = '\0';

        int isNewPattern = 1;
        for (int j = 0; j < *resultSize; j++) {
            if (strcmp(freqMap[j].pattern, currentPattern) == 0) {
                isNewPattern = 0;
                freqMap[j].count++;
                break;
            }
        }

        if (isNewPattern) {
            freqMap = realloc(freqMap, (*resultSize + 1) * sizeof(struct FrequencyMapResult));
            if (freqMap == NULL) {
                printf("Erro de alocação de memória.\n");
                exit(EXIT_FAILURE);
            }

            strncpy(freqMap[*resultSize].pattern, currentPattern, k);
            freqMap[*resultSize].pattern[k] = '\0';
            freqMap[*resultSize].count = 1;
            (*resultSize)++;
        }
    }

    return freqMap;
}

int main() {
    char Text[MAX_TEXT_SIZE];
    int k;

    // Solicitando que o usuário insira o texto
    printf("Digite o texto: ");
    fgets(Text, MAX_TEXT_SIZE, stdin);
    Text[strcspn(Text, "\n")] = '\0';  // Remover o caractere de nova linha inserido pelo fgets

    // Solicitando que o usuário insira o valor de k
    printf("Digite o valor de k: ");
    scanf("%d", &k);

    int resultSize;
    struct FrequencyMapResult *result = FrequencyMap(Text, k, &resultSize);

    // Imprimindo o resultado
    printf("Mapa de Frequência:\n");
    for (int i = 0; i < resultSize; i++) {
        printf("%s: %d vezes\n", result[i].pattern, result[i].count);
    }

    free(result);

    return 0;
}
