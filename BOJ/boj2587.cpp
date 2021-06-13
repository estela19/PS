#include<stdio.h>
#include<algorithm>

int sum;
int N;
int mean;
int inp[6];

int main() {
    for (int i = 0; i < 5; i++) {
        scanf("%d", &inp[i]);
        sum += inp[i];
    }

    std::sort(inp, inp + 5);
    printf("%d\n%d", sum / 5, inp[2]);

}