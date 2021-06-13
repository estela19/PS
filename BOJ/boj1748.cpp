#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>

int N;
long long sol;
std::string str;

int main() {
    std::cin >> str;

    int len = str.size();
    N = std::stoi(str);


    for (int j = 1; j <= len - 1; j++) {
        sol += 9 * pow(10, j - 1) * j;
    }

    sol += (N - (pow(10, len - 1) - 1)) * len;

    std::cout << sol;

   
}