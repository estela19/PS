#include<iostream>
#include<algorithm>
#include<deque>
#include<string>

std::deque<char> s;
int index;

int main(int argc, char* argv[]) {
    std::string str;
    std::cin >> str;

    while (str.find('-') == std::string::npos) {
        int size = str.size();
        for (int i = 0; i < size; i++) {
            if (str[i] == '{') {
                s.push_back('{');
            }

            else {
                if (!s.empty() && s.back() == '{') {
                    s.pop_back();
                }
                else {
                    s.push_back('}');
                }
            }
        }

        int cnt = 0;
        size = s.size();
        for (int i = 0; i < size; i += 2) {
            if (s[i] == '}') {
                cnt++;
            }

            if (s[i + 1] == '{') {
                cnt++;
            }
        }


        std::cout << ++index << ". " << cnt << "\n";

        s.clear();

        std::cin >> str;
    }

    return 0;
}