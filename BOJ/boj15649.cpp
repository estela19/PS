#include<stdio.h>
#include<algorithm>
#include<vector>

int N, M;
std::vector<int> v;

int main() {
    v.resize(10);
    std::fill(v.begin(), v.end(), 1);
    
    scanf("%d %d", &N, &M);
    
    for (int i = 1; i <= N; i++) {
        for (int j = M; j >= 1; j--) {
            printf("%d ", v[i]);
        }
    }

    for (auto& i : v) {
        printf("%d\n", i);
    }
}