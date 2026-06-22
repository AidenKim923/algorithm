#include <string>
#include <vector>

using namespace std;

int dfs(int current, int parent, const vector<vector<int>>& adj, int n, int& min_diff)
{
    int subtree_size = 1;

    for (int next : adj[current])
    {
        if (next != parent)
        {
            subtree_size += dfs(next, current, adj, n, min_diff);
        }
    }

    min_diff = min(min_diff, abs(n - 2 * subtree_size));

    return subtree_size;
}
int solution(int n, vector<vector<int>> wires)
{
    // 인접 리스트 생성
    vector<vector<int>> adj(n + 1);

    for (const auto& wire : wires)
    {
        adj[wire[0]].push_back(wire[1]);
        adj[wire[1]].push_back(wire[0]);
    }

    // 최댓값으로 초기화
    int min_diff = n;

    // 1번 노드를 임의의 루트로 설정하여 DFS 시작
    dfs(1, 0, adj, n, min_diff);

    return min_diff;
}
