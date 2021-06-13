#include<iostream>
#include<algorithm>

int A, B, C;
long long sol;

long long func(int B);

int main(){
    std::cin >> A >> B >> C;

    std::cout << func(B);
}

long long func(int B){
    if(B == 0) return 1;
    else if(B == 1) return A % C;
    else if (B % 2 == 0){
        return ((func(B/2)%C) * (func(B/2)%C) * 1LL) % C;
    }
    else if (B % 2 == 1){
        return ((func(B/2)%C) * (func(B/2)%C) * A * 1LL) % C;
    }
}