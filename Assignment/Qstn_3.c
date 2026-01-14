#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {

        for (int s = 1; s <= n - i; s++) {
            printf(" ");
        }

        for (int star = 1; star <= 2*i - 1; star++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
