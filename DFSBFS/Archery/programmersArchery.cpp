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

int diff = 0;
vector<int> vAnswer = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
bool isHitLowScore(vector<int> cmp)
{
    for (int i = 10; i >= 0; i--)
    {
        if (vAnswer[i] > cmp[i])
            return false;
        else if (vAnswer[i] < cmp[i])
            return true;
    }
}

void solve(vector<int>& apc, vector<int>& ryn, int idx, int arrow)
{
    if (idx == 11 || arrow == 0)
    {
        ryn[10] += arrow;
        int sumApc = 0;
        int sumRyn = 0;
        for (int i = 0; i < 11; i++)
        {
            if (apc[i] != 0 && apc[i] >= ryn[i])
            {
                sumApc += (10 - i);
            }
            else if (apc[i] < ryn[i])
            {
                sumRyn += (10 - i);
            }
        }

        if (diff < sumRyn - sumApc)
        {
            diff = sumRyn - sumApc;
            vAnswer = ryn;
        }
        else if (diff == sumRyn - sumApc)
        {
            if (isHitLowScore(ryn))
            {
                diff = sumRyn - sumApc;
                vAnswer = ryn;
            }
        }

        ryn[10] = 0;
        return;
    }

    if (apc[idx] < arrow)
    {
        ryn[idx] = apc[idx] + 1;
        arrow -= ryn[idx];
        solve(apc, ryn, idx + 1, arrow);
        arrow += ryn[idx];
        ryn[idx] = 0;
    }

    solve(apc, ryn, idx + 1, arrow);

}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> ryan(11, 0);

    solve(info, ryan, 0, n);

    vector<int> noCase = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    if (vAnswer == noCase)
        answer.push_back(-1);
    else
        answer = vAnswer;

    return answer;
}

int main()
{
    vector<int> v = { 0,0,1,2,0,1,1,1,1,1,1 };

    solution(9, v);

    return 0;
}