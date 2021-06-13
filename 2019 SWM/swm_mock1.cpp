#include<iostream>
#include<vector>
#include<algorithm>

int N, K;


int main()
{
    std::cin >> N >> K;
    std::cout << N / (K - 1);
}