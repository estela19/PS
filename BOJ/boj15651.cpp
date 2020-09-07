#include<stdio.h>
#include<algorithm>
#include<math.h>

int N, M;

int main() {
    scanf("%d %d", &N, &M);

    int cnt = pow(N, M);

    for (int i = 0; i < cnt; i++) {
        for (int j = M; j >= 1; j--) {
            int tmp = pow(N, j - 1);
            printf("%d ", ((i / tmp) % N) + 1);
        }
        printf("\n");
    }

}