#include <stdio.h>
#define MAX_DEGREE 200

struct polynomial {
    int degree;
    int coef[MAX_DEGREE + 1];
};

struct polynomial multiply(struct polynomial a, struct polynomial b) {
    struct polynomial result;
    result.degree = a.degree + b.degree;

    for (int i = 0; i <= result.degree; i++) {
        result.coef[i] = 0;
    }

    for (int i = 0; i <= a.degree; i++) {
        for (int j = 0; j <= b.degree; j++) {
            result.coef[i + j] += a.coef[i] * b.coef[j];
        }
    }

    return result;
}

void print(struct polynomial p) {
    int isFirstTerm = 1;

    for (int i = p.degree; i >= 0; i--) {
        if (p.coef[i] != 0) {
            if (!isFirstTerm) {
                printf(" + ");
            }
            else {
                isFirstTerm = 0;
            }
            printf("%dx^%d", p.coef[i], i);
        }
    }
    printf("\n");
}

int main(void) {
    struct polynomial a = { 2, {1, 2, 3} };
    struct polynomial b = { 3, {1, 2} };
    struct polynomial c;

    printf("a(x) = ");
    print(a);

    printf("b(x) = ");
    print(b);

    c = multiply(a, b);

    printf("---------------------------------\n");
    printf("c(x) = ");
    print(c);

    return 0;
}
