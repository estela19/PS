#include<iostream>
#include<algorithm>

int N, X;

int main(){
    std::cin >> N >> X;

    for(int i = 0; i < N; i ++){
        int tmp;
        std::cin >> tmp;

        if(tmp < X){
            std::cout << tmp << " ";
        }
    }

    return 0;

}