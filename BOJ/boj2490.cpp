#include<stdio.h>

int result;
char yutresult(int result);

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            int tmp;
            scanf("%d", &tmp);
            result += tmp;
        }
        printf("%c\n", yutresult(result));
        result = 0;
    }
}

char yutresult(int result) {
    switch (result) {
    case 3:
        return 'A';
        
    case 2:
        return 'B';

    case 1:
        return 'C';

    case 0:
        return 'D';

    case 4:
        return 'E';
    }
}