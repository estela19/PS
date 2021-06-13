#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>

int N;
int sol;
int a[30];
char prev;
bool flag = false;
std::string str;

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> str;

        for (int j = 0; j < str.size(); j++) {
            if (a[str[j] - 'a'] != 0 && prev != str[j]) {
                flag = true;
                break;
            }
            a[str[j] - 'a']++;
            prev = str[j];
        }

        if (!flag) {
            sol++;
        }

        memset(a, 0, sizeof(a));
        flag = false;
        prev = '!';
    }

    std::cout << sol;
}