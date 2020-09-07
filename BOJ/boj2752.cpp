#include<stdio.h>
#include<algorithm>

int num[3];

int main() {
    scanf("%d %d %d", &num[0], &num[1], &num[2]);
    std::sort(num, num + 3);
    printf("%d %d %d", num[0], num[1], num[2]);
}

