#include<iostream>
#include<list>

std::list<char> str;
std::string input;
int N;

int main() {

    std::cin >> input;
    for (int i = 0; i < input.size(); i++) {
        str.push_back(input[i]);
    }

    str.insert(str.begin(), '0');

    auto index = --str.end();
    auto first_idx = str.begin();

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::string tmp;
        auto last_idx = --str.end();
        std::cin >> tmp;

        if (tmp == "L" && index != first_idx) --index;
        else if (tmp == "D" && index != last_idx) ++index;
        else if (tmp == "B" && index != first_idx) {
            str.erase(index--);
        }
        else if (tmp == "P") {
            char newchar;
            std::cin >> newchar;
            if (index != last_idx) {
                str.insert(++index, newchar);
                index--;
            }

            else {
                str.push_back(newchar);
                index++;
            }
        }
    }

    str.erase(str.begin());

    for (auto& i : str) std::cout << i;

    return 0;
}