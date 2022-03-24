#include <iostream>
#include <string>
#include <vector>
using namespace std;

int cnt = 0;

void DFS(vector<int>& numbers, int depth, int end, int sum, int target)
{
    if (depth == end)
    {
        if (sum == target)
            cnt++;

        return;
    }

    DFS(numbers, depth + 1, numbers.size(), sum + numbers[depth], target);
    DFS(numbers, depth + 1, numbers.size(), sum - numbers[depth], target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    DFS(numbers, 0, numbers.size(), 0, target);

    answer = cnt;
    return answer;
}

int main(void)
{
    int target = 4;
    vector<int> num = { 4, 1, 2, 1 };

    solution(num, target);

    return 0;
};