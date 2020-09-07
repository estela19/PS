#include<stdio.h>
#include<algorithm>
#include<vector>

std::vector<int> v;
int N;

int main() {
    scanf("%d", &N);
    while (N) {
        for (int i = 0; i < N; i++) {
            int tmp;
            scanf("%d", &tmp);
            v.push_back(tmp);
        }

        for (int i1 = 0; i1 <= N - 6; i1++) {
            for (int i2 = i1 + 1; i2 <= N - 5; i2++) {
                for (int i3 = i2 + 1; i3 <= N - 4; i3++) {
                    for (int i4 = i3 + 1; i4 <= N - 3; i4++) {
                        for (int i5 = i4 + 1; i5 <= N - 2; i5++) {
                            for (int i6 = i5 + 1; i6 <= N - 1; i6++) {
                                printf("%d %d %d %d %d %d\n", v[i1], v[i2], v[i3], v[i4], v[i5], v[i6]);
                            }
                        }
                    }
                }
            }
        }
        printf("\n");
        v.clear();
        scanf("%d", &N);
    }
}