#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* SkewArray(char* Genome) {
    int n = strlen(Genome);
    int* skew = (int*)malloc((n + 1) * sizeof(int));
    if (skew == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }

    int current_skew = 0;
    skew[0] = 0;

    for (int i = 0; i < n; i++) {
        if (Genome[i] == 'C') {
            current_skew--;
        } else if (Genome[i] == 'G') {
            current_skew++;
        }
        skew[i + 1] = current_skew;
    }

    return skew;
}

int main() {
    char Genome[] = "GAGCCACCGCGATA";
    int* skew_values = SkewArray(Genome);

    int n = strlen(Genome) + 1;
    for (int i = 0; i < n; i++) {
        printf("%d ", skew_values[i]);
    }
    printf("\n");

    free(skew_values); // Liberar a memória alocada
    return 0;
}
