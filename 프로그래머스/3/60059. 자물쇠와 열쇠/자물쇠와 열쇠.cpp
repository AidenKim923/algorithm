#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void rotateMatrix(vector<vector<int>>& key)
{
	reverse(key.begin(), key.end());
	for (int i = 0; key.size() > i; ++i)
	{
		for (int j = i + 1; key.size() > j; ++j)
		{
			swap(key[i][j], key[j][i]);
		}
	}
}

bool checkOpen(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& key, vector<vector<int>>& lock)
{
	int M = key.size();
	int N = lock.size();

	// key값 적용
	for (int i = x; (x + M) > i; ++i)
	{
		for (int j = y; (y + M) > j; ++j)
		{
			matrix[i][j] += key[i - x][j - y];
		}
	}
	// check lock
	for (int i = N; (matrix.size() - N) > i; ++i)
	{
		for (int j = N; (matrix.size() - N) > j; ++j)
		{
			if (matrix[i][j] != 1)
			{
				return false;
			}
		}
	}
	return true;
}

void toOrigin(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& key)
{
	int M = key.size();
	for (int i = x; (x + M) > i; ++i)
	{
		for (int j = y; (y + M) > j; ++j)
		{
			matrix[i][j] -= key[i - x][j - y];
		}
	}
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
	bool answer = false;
	int M = key.size();
	int N = lock.size();

	vector<vector<int>> matrix(3 * N, vector<int>(3 * N));

	for (int i = N; (matrix.size() - N) > i; ++i)
	{
		for (int j = N; (matrix.size() - N) > j; ++j)
		{
			matrix[i][j] = lock[i - N][j - N];
		}
	}
	for (int k = 0; 4 > k; ++k)
	{
		for (int i = 0; (matrix.size() - M) > i; ++i)
		{
			for (int j = 0; (matrix.size() - M) > j; ++j)
			{
				if (checkOpen(i, j, matrix, key, lock))
				{
					return true;
				}
				else
				{
					toOrigin(matrix, i, j, key);
				}
			}
		}
		rotateMatrix(key);
	}
	return answer;
}

int main() {
	vector<vector<int>> key = { {0, 0, 0}, {1, 0, 0}, {0, 1, 1} };
	vector<vector<int>> lock = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };

	bool result = solution(key, lock);

	cout << boolalpha << "Result: " << result << endl;

	return 0;
}