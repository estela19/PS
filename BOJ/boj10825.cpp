#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<tuple>
#include<algorithm>

int N;

int main()
{
    std::cin >> N;
    std::set<std::tuple<int, int, int, std::string>> s;
    for (int i = 0; i < N; i++)
    {
        int k, e, m;
        std::string name;
        std::cin >> name >> k >> e >> m;
        s.insert({ -k, e, -m, name });
    }

    for (auto& k : s)
    {
        std::cout << std::get<3>(k) << '\n';
    }
    

}