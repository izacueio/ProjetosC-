#include <stdio.h>
#include <string.h>
int main() {
    int n, m, qtd, p, i;
    double total, valores[900];
    char str[51], comida[900][51];
    scanf("%d", &n);
    while (n--) {
        total = 0;
        scanf("%d", &m);
        for (i = 0; i < m; i++) {
            scanf("%s %lf", comida[i], &valores[i]);
        }
        scanf("%d", &p);
        while (p--) {
            scanf("%s %d", str, &qtd);
            for (i = 0; i < m; i++) {
                if (!strcmp(str, comida[i])) {
                    total += qtd * valores[i];
                }
            }
        }
        printf("R$ %.2lf\n", total);
        memset(comida, 0, sizeof(comida));
        memset(valores, 0, sizeof(valores));
    }
    return 0;
}