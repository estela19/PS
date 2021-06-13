#include<iostream>
#include<list>
#include<string>
#include<algorithm>

int N;

int main() {
    std::cin >> N;

    while (N--) {
        std::string tmp;
        std::cin >> tmp;
        std::list<char>pw;

        int size = tmp.size();

        auto cur = pw.begin();
        for (int i = 0; i < size; i++) {
            if (tmp[i] == '<') {
                if(cur != pw.begin()) --cur;
            }

            else if (tmp[i] == '>') {
                if(cur != pw.end()) ++cur;
            }
            
            else if (tmp[i] == '-') {
                if(cur != pw.begin()) cur = pw.erase(--cur);
            }

            else {
                if (cur == pw.end()) pw.push_back(tmp[i]);
                else pw.insert(cur, tmp[i]);
            }

        }

        for (auto& i : pw) std::cout << i;
        std::cout << '\n';
    }
}