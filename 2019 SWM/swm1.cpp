#include<iostream>
#include<vector>

int N;
std::vector<int> v;

int main()
{
    std::cin >> N;

    while (N != 0)
    {
        if (N % 2 == 0)
        {
            v.push_back(1);
            N -= 2;
        }

        else
        {
            v.push_back(7);
            N -= 3;
        }
    }

    for (auto& i : v)
    {
        std::cout << i;
    }
}