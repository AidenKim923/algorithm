#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Position
{
    int r, c;
};

const int dr[4] = { 0, 0, 1, -1 };   // 동, 서, 남, 북
const int dc[4] = { 1, -1, 0, 0 };

vector<vector<int>> BFS(const vector<string>& maps, int n, int m, int sr, int sc)
{
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[sr][sc] = 0;

    queue<Position> q;
    q.push({ sr, sc });

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
            if (maps[nr][nc] == 'X')
                continue;
            if (dist[nr][nc] != -1)
                continue;

            dist[nr][nc] = dist[cur.r][cur.c] + 1;
            q.push({ nr, nc });
        }
    }

    return dist;
}

int solution(vector<string> maps)
{
    int n = (int)maps.size();
    int m = (int)maps[0].size();

    Position start{}, lever{}, exitPos{};

    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            if (maps[r][c] == 'S') start = { r, c };
            else if (maps[r][c] == 'L') lever = { r, c };
            else if (maps[r][c] == 'E') exitPos = { r, c };
        }
    }

    // 1단계: 시작점 -> 레버
    vector<vector<int>> distFromStart = BFS(maps, n, m, start.r, start.c);
    int toLever = distFromStart[lever.r][lever.c];

    if (toLever == -1) return -1;

    // 2단계: 레버 -> 출구
    vector<vector<int>> distFromLever = BFS(maps, n, m, lever.r, lever.c);
    int toExit = distFromLever[exitPos.r][exitPos.c];

    if (toExit == -1) return -1;

    return toLever + toExit;
}
