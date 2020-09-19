#include<iostream>
#include<algorithm>

int a[1001];
int N, K;
int cnt;
int num;
bool flag = false;

int main() {
    std::cin >> N >> K;

    std::fill(a + 1, a + N + 1, 1);

    int prim = 2;
    while(true){
        while (a[prim] != 1) {
            prim++;
        }
   
        for (int i = 1; i * prim <= N; i++) {
            if (a[prim * i] != 0) {
                a[prim * i] = 0;
                cnt++;
                num = prim * i;
                if (cnt == K) {
                    flag = true;
                    break;
                }
            }
        }

        if (flag) break;
    }
    std::cout << num;
}