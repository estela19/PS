#include<iostream>
#include<deque>
#include<string>

int N, num;
std::string str;
std::deque<int> dq;


int main() {
    std::cin >> N;
    
    while (N--) {
        std::cin >> str;

        if (str == "push_back") {
            std::cin >> num;
            dq.push_back(num);
        }
        else if (str == "push_front") {
            std::cin >> num;
            dq.push_front(num);
        }
        else if (str == "pop_front") {
            if(dq.empty()) std::cout << "-1\n";
            else {
                std::cout << dq.front() <<"\n";
                dq.pop_front();
            }
        }
        else if (str == "pop_back") {
            if(dq.empty()) std::cout << "-1\n";
            else {
                std::cout << dq.back() << "\n";
                dq.pop_back();
            }    
        }
        else if (str == "size") {
            std::cout << dq.size() << "\n";
        }
        else if (str == "empty") {
            if (dq.empty()) std::cout << "1\n";
            else std::cout << "0\n";
        }
        else if (str == "front") {
            if (dq.empty()) std::cout << "-1\n";
            else {
                std::cout << dq.front() << "\n";
            }
        }
        else if (str == "back") {
            if (dq.empty()) std::cout << "-1\n";
            else {
                std::cout << dq.back() << "\n";
            }
        }
    }
}