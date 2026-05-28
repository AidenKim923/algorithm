#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <array>

using namespace std;

int solution(vector<string> board)
{
    const int n = (int)board.size();
    const int m = (int)board[0].size();

    // 우 하 좌 상
    constexpr array<int, 4> dr = { 0,  0, 1, -1};
    constexpr array<int, 4> dc = { 1, -1, 0,  0};

    int sr = 0, sc = 0, er = 0, ec = 0;

    for (int r = 0; r < n; ++r)
        for (int c = 0; c < m; ++c)
        {
            if (board[r][c] == 'R') { sr = r; sc = c; }
            else if (board[r][c] == 'G') { er = r; ec = c; }
        }

    vector<int> dist(n * m, -1);

    const auto enc = [&](int r, int c) { return (r * m) + c; };

    queue<int> que;
    dist[enc(sr, sc)] = 0;
    que.push(enc(sr, sc));

    const int goal = enc(er, ec);

    while (!que.empty())
    {
        const int cur  = que.front(); que.pop();
        const int cr   = cur / m;
        const int cc   = cur % m;
        const int cost = dist[cur];

        if (cur == goal) return cost;

        for (int d = 0; d < 4; ++d)
        {
            int tr = cr, tc = cc;
            while (((tr + dr[d]) >= 0) && ((tr + dr[d]) < n) &&
                ((tc + dc[d]) >= 0) && ((tc + dc[d]) < m) &&
                (board[tr + dr[d]][tc + dc[d]] != 'D'))
            {
                tr += dr[d];
                tc += dc[d];
            }

            const int next = enc(tr, tc);
            if (dist[next] != -1) continue;

            dist[next] = cost + 1;
            que.push(next);
        }
    }
    return -1;
}
