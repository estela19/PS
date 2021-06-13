#include<stdio.h>
#include<algorithm>

int* num = new int[10];
int index;


int main() {
    for (int i = 0; i < 9; i++) {
        scanf("%d", &num[i]);
    }

    int* maxnum = std::max_element(num, num + 9);

    for (int i = 0; i < 10; i++) {
        if (*maxnum == num[i]) {
            index = i;
            break;
        }
    }

    printf("%d\n%d", *maxnum, index + 1);
}