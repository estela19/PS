#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int T, N;
std::vector<int> v;


int main() {
    std::cin >> T;

    while (T--) {
        std::string str;
        bool eflag = false;

        std::cin >> str;
        std::cin >> N;

        char buff;
        int tmp;
        for (int i = 0; i < N; i++) {
            std::cin >> buff >> tmp;
            v.push_back(tmp);
        }
        std::cin >> buff;

        int size = str.size();
        for (int i = 0; i < size; i++) {
            if (str[i] == 'R') std::reverse(v.begin(), v.end());
            else if (str[i] == 'D') {
                if (v.empty()) {
                    eflag = true;
                    break;
                }
                v.erase(v.begin());
            }
        }

        if (eflag) std::cout << "error\n";
        else if (v.empty()) {
            std::cout << "[]\n";
        }
        else {
            std::cout << "[";
            std::for_each(v.begin(), v.end() - 1, [](int n) {std::cout << n << ","; });
            std::cout << *(v.end() - 1) << "]\n";
        }

        v.clear();
        eflag = false;
    }
}