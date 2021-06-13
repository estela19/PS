#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>

int N;
int totalN;
double sum;

double GPAtoNum(std::string gpa);

int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::string str;
        std::cin >> str;
        std::cin >> str;
        int many = std::stoi(str);

        std::cin >> str;
        double tmp = GPAtoNum(str);

        sum += tmp * many;
        totalN += many;
    }
    double sol = sum / (totalN *10);
    printf("%.2lf", sol + 0.00001);
}

double GPAtoNum(std::string gpa)
{
    double result = 0;

    if (gpa[1] == '+')
    {
        result = 3;
    }
    else if (gpa[1] == '0')
    {
        result = 0;
    }
    else if (gpa[1] == '-')
    {
        result = -(3);
    }


    if (gpa[0] == 'A')
    {
        result += 40;
    }
    else if (gpa[0] == 'B')
    {
        result += 30;
    }
    else if (gpa[0] == 'C')
    {
        result += 20;
    }
    else if (gpa[0] == 'D')
    {
        result += 10;
    }

    return result;
}