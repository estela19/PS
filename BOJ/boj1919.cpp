#include<iostream>
#include<algorithm>
#include<string>

int a[26], b[26];
int cnt;

int main(){
    std::string first;
    std::string second;

    std::cin >> first;
    std::cin >> second;

    int size = first.size();
    for(int i = 0; i < size; i++){
        a[first[i] - 'a']++;
    }

    size = second.size();
    for(int i = 0; i < size; i++){
        b[second[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++){
        cnt += std::abs(a[i] - b[i]);
    }

    std::cout << cnt;

    return 0;
}