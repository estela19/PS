#include<iostream>
#include<algorithm>
#include<string.h>
#include<set>
#include<string>

std::string A, B;
int a[25], b[25];
int N;
bool flag = false;

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> A >> B;

        int size = A.size();
        for (int j = 0; j < size; j++) {
            a[A[j] - 'a']++;
        }

        size = B.size();
        for (int j = 0; j < size; j++) {
            b[B[j] - 'a']++;
        }

        for (int j = 0; j < 25; j++) {
            if (a[j] != b[j]) {
                flag = true;
                break;
            }
        }

        if (flag) std::cout << "Impossible\n";
        else std::cout << "Possible\n";

        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        flag = false;
    }
}