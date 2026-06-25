#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    // 인접 리스트 생성
    vector<vector<int>> graph(n + 1);
    for (const auto& e : edge)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    // 거리 배열 대신 방문 여부만 체크하는 배열 사용 (메모리 및 속도 이점)
    vector<char> visited(n + 1, 0);
    queue<int> q;

    q.push(1);
    visited[1] = 1;

    int answer = 0;

    // BFS 탐색
    while (!q.empty())
    {
        // 현재 레벨에 있는 노드의 개수
        int q_size = q.size();

        answer = q_size;

        for (int i = 0; i < q_size; ++i)
        {
            int curr = q.front();
            q.pop();

            for (int next : graph[curr])
            {
                if (!visited[next])
                {
                    visited[next] = 1;
                    q.push(next);
                }
            }
        }
    }

    return answer;
}
