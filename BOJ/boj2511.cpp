#include<stdio.h>
#include<algorithm>

int a[10];
int b[10];
int scrA, scrB;
char win = 'D';

int main() {
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 10; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < 10; i++) {
        if (a[i] > b[i]) {
            scrA += 3;
            win = 'A';
        }

        else if (a[i] < b[i]) {
            scrB += 3;
            win = 'B';
        }

        else {
            scrA += 1;
            scrB += 1;
        }

    }

    if (scrA > scrB) {
        win = 'A';
    }
    else if (scrA < scrB) {
        win = 'B';
    }

    printf("%d %d\n", scrA, scrB);
    printf("%c", win);
}