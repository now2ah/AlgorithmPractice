#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    long long shortTime = 0;
    sort(times.begin(), times.end());
    long long longTime = (long long)times[times.size() - 1] * n;

    long long start = shortTime;
    long long end = longTime;
    long long mid = (start + end) / 2;

    while (end >= start)
    {
        long long mid = (start + end) / 2;
        long long people = 0;

        for (int i = 0; i < times.size(); i++)
        {
            people += mid / times[i];
        }

        if (people < n)
        {
            start = mid + 1;
        }
        else
        {
            answer = mid;
            end = mid - 1;
        }
    }

    return answer;
}

int main(void)
{
    int n = 7;
    vector<int> times = { 7, 10 };

    solution(n, times);

	return 0;
};