#include<iostream>
#include<algorithm>
#include<cmath>

long long N;

int main(){
    std::cin >> N;

    long long sol = ceil(sqrt(N));

    std::cout << sol;
}