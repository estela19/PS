#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

int N;

struct INFO
{
    std::string name;
    int Y, M, D;
};

INFO info[100];

bool cmp(INFO f, INFO s);

int main()
{
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> info[i].name >> info[i].D >> info[i].M >> info[i].Y;
    }
    std::sort(info, info + N, cmp);
    std::cout << info[N - 1].name << '\n';
    std::cout << info[0].name;
}

bool cmp(INFO f, INFO s)
{
    if (f.Y != s.Y) return f.Y < s.Y;
    if (f.M != s.M) return f.M < s.M;
    if (f.D != s.D) return f.D < s.D;
}