#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <list>
#include <sstream>
#include <cstdlib>
#include <math.h>
using namespace std;

#pragma warning (disable : 4996)
string sampleString = "0123456789ABCDEF";

string Modify(int num, int conversionNum)
{
    string temp = "";

    if (num < conversionNum)
    {
        temp += sampleString[num];
        return temp;
    }
    while (num > 0)
    {
        temp += sampleString[num % conversionNum];
        num /= conversionNum;
    }
    string conversionString = "";
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        conversionString += temp[i];
    }
    return conversionString;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    string numString = "";

    //���ؾ��� ���ڿ� �����
    for (int i = 0; i < m * t; i++)
    {
        //0���� ������ȯ �� string �߰�
        numString += Modify(i, n);
    }

    //Ʃ�갡 ���ؾ��� ����
    for (int i = p - 1; i < t * m; i += m)
    {
        answer += numString[i];
    }

    return answer;
}

int main()
{

    solution(16, 16, 2, 1);
    return 0;
}