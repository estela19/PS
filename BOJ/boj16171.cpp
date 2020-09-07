#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>

std::vector<char> v;
char input[101];
std::string target;

int main() {
    scanf("%s", input);
    std::cin >> target;

    int len = strlen(input);
    for (int i = 0; i < len; i++)
    {
        if (input[i]<'0' || input[i] >'9')
        {
            v.push_back(input[i]);
        }
    }
    std::string str(v.begin(), v.end());

    if (str.find(target) != -1)
    {
        std::cout << "1";
    }
    else
    {
        std::cout << "0";
    }
}