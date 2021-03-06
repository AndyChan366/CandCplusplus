#include <iostream>
#define N 5
using namespace std;
int maze[N][N] = {
    { 0, 1, 1, 0, 0 },
    { 0, 0, 1, 0, 1 },
    { 0, 0, 1, 0, 0 },
    { 1, 1, 0, 0, 1 },
    { 0, 0, 1, 0, 0 }
};
int visited[N + 1] = { 0, };
void DFS(int start)
{
    visited[start] = 1;
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i] && maze[start - 1][i - 1] == 1)
            DFS(i);
    }
    cout << start << " ";
}
int main()
{
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == 1)
            continue;
        DFS(i);
    }
    return 0;
}
