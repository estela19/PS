#include<iostream>
#include<algorithm>

int N, cnt;
int build[80001];


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> build[i];
    }

    for(int i = 0; i < N; i++){
        int j = i + 1;

        while(j < N && build[i] > build[j]){
            cnt++;
            j++;
        }
    }

    std::cout << cnt;
}