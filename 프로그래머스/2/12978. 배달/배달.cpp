#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int INF = 987654321;

int solution(int N, vector<vector<int> > road, int K) {
    vector<vector<pair<int, int>>> graph(N + 1);

    for (const auto& r : road)
    {
        int from = r[0], to = r[1], cost = r[2];
        graph[from].push_back({ to,   cost });
        graph[to].push_back(  { from, cost });
    }

    // 최단 거리 배열
    vector<int> dist(N + 1, INF);
    dist[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, 1 });

    while (!pq.empty())
    {
        auto [time, cur] = pq.top();
        pq.pop();

        if (dist[cur] < time) continue;

        for (auto [next, cost] : graph[cur])
        {
            int nextTime = time + cost;
            if (dist[next] > nextTime)
            {
                dist[next] = nextTime;
                pq.push({ nextTime, next });
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (dist[i] <= K) ++answer;
    }
    
    return answer;
}
