#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool matrix[20001][20001];
bool isVisited[20001];
int dist[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    queue<int> q;

    for (int i = 0; i < edge.size(); i++)
    {
        matrix[edge[i][0]][edge[i][1]] = true;
        matrix[edge[i][1]][edge[i][0]] = true;
    }

    q.push(1);
    isVisited[1] = true;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        for (int i = 1; i <= n; i++)
        {
            if (matrix[temp][i] == true && !isVisited[i])
            {
                q.push(i);
                isVisited[i] = true;
                dist[i] = dist[temp] + 1;
            }
        }
    }

    int largest = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] > largest)
            largest = dist[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == largest)
            answer++;
    }

    return answer;
}

int main(void)
{
    vector<vector<int>> edge = { {3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2} };
    solution(6, edge);
    return 0;
};