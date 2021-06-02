#include<iostream>
#include<algorithm>

long long sum;
std::string input;
int num[10];

int main() {
    std::cin >> input;

    int i = 0;
    while (input[i] != NULL) {
        int target = input[i] - '0';
        num[target]++;
        sum += target;
        i++;
    }


    if (num[0] == 0 || sum % 3 != 0) {
        std::cout << -1;
    }

    else {
        for (int i = 9; i >= 0; i--) {
            while (num[i] != 0) {
                std::cout << i;
                num[i]--;
            }
        }
    }
}