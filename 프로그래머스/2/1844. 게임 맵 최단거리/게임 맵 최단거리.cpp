#include <vector>
#include <queue>

using namespace std;

struct Position
{
    int r, c;
};

int solution(vector<vector<int>> maps)
{
    int n = (int)maps.size();
    int m = (int)maps[0].size();

    vector<vector<int>> dist(n, vector<int>(m, -1)); // -1 = 미방문
    dist[0][0] = 1;

    int dr[4] = { 0, 0, 1, -1 }; // 동, 서, 남, 북
    int dc[4] = { 1, -1, 0, 0 };

    queue<Position> q;
    q.push({ 0, 0 });

    while (!q.empty())
    {
        Position cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nr = cur.r + dr[dir];
            int nc = cur.c + dc[dir];

            if ((nr < 0) || (nr >= n) || (nc < 0) || (nc >= m))
                continue;
            if (maps[nr][nc] == 0)
                continue;
            if (dist[nr][nc] != -1)
                continue;

            dist[nr][nc] = dist[cur.r][cur.c] + 1;
            q.push({ nr, nc });
        }
    }

    return dist[n - 1][m - 1];
}
