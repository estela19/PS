#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

int N;
std::vector<std::string> inp;
std::vector<int> length;
std::vector<int> sum;

bool cmp(std::string f, std::string s);

int main()
{
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        inp.push_back(tmp);
    }
    std::sort(inp.begin(), inp.end(), cmp);

    for (auto& i : inp)
    {
        std::cout << i << '\n';
    }

}

bool cmp(std::string f, std::string s)
{
    if (f.length() != s.length()) return f.length() < s.length();
    else
    {
        const char* ftmp = f.c_str();
        int i = 0;
        int fsum = 0;
        while (ftmp[i] != '\0')
        {
            if (ftmp[i] >= '0' && ftmp[i] <= '9')
            {
                fsum += ftmp[i] - '0';
            }
            i++;
        }

        const char* stmp = s.c_str();
        int j = 0;
        int ssum = 0;
        while (stmp[j] != '\0')
        {
            if (stmp[j] >= '0' && stmp[j] <= '9')
            {
                ssum += stmp[j] - '0';
            }
            j++;
        }
        
        if (fsum != ssum) return fsum < ssum;
    }

    return f < s;
    /*
    int i = 0;
    while (true)
    {
        if (f[i] == s[i]) i++;
        else if (f[i] > s[i]) return f[i] > s[i];
        else return f[i] < s[i];
    }
    */
}
