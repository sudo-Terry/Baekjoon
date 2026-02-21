#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 20

int N;
int matrix[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> queens;
int counter = 0;
int ans = 0;

void set_queen_path(int col, int row, bool disable){
	// 퀸을 놓을때는 matrix -1, 뺄때는 matrix +1
	int num = disable ? -1 : 1;

	matrix[col][row] += num;

	for(int j = 1; j <= N; j++){
		if(j == row) continue;
		matrix[col][j] += num;
	}

	for(int i = 1; i <= N; i++){
		if(i == col) continue;
		matrix[i][row] += num;
	}

	//대각
	for(int i = col + 1, j = row + 1; i <= N && j <= N; i++, j++)
		matrix[i][j] += num;

	for(int i = col - 1, j = row - 1; i >= 1 && j >= 1; i--, j--)
		matrix[i][j] += num;

	for(int i = col + 1, j = row - 1; i <= N && j >= 1; i++, j--)
		matrix[i][j] += num;

	for(int i = col - 1, j = row + 1; i >= 1 && j <= N; i--, j++)
		matrix[i][j] += num;
}

void backtrack(int col) {
	if(col > N) {
		ans++;
		return;
	}

	for(int row = 1; row <= N; row++){
		if(matrix[col][row] == 1){
			set_queen_path(col, row, true);
			backtrack(col + 1);
			set_queen_path(col, row, false);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

	cin >> N;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			matrix[i][j] = 1;

	backtrack(1);

	cout << ans;

	return 0;
}