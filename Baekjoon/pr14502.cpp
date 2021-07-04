#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 8
#define BLANK 0
#define WALL 1
#define VIRUS 2
using namespace std;

int n, m;
int dx[] = { 0, 1, 0, -1 };//중앙 북 동 남 서
int dy[] = { 1, 0, -1, 0 };
int area[MAX][MAX];
int temparea[MAX][MAX];
vector<pair<int, int>> indexOfBlank;
vector<pair<int, int>> indexOfVirus;
bool visited[MAX][MAX];
int maxBlank = 0;
int tempx1, tempx2, tempx3, tempy1, tempy2, tempy3;

//알고리즘 >> 브루트포스 알고리즘
//비어있는 칸중 임의의 3개를 골라 변화가 없을때까지 바이러스를 퍼트리고 빈칸의 수가 max보다 크면 max를 갱신한다

void spreadVirus() {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	for (int i = 0; i < indexOfVirus.size(); i++) {
		q.push(make_pair(indexOfVirus[i].first, indexOfVirus[i].second)); // i, j
		visited[indexOfVirus[i].first][indexOfVirus[i].second] = true;
	}
	while (!q.empty()) {
		int cury = q.front().first, curx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextx = curx + dx[i], nexty = cury + dy[i];
			if (!visited[nexty][nextx]) { //아직 방문하지 않은 칸만 검사한다
				if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n) {//전체 영역 범위를 벗어나지 않는 경우에만
					if (temparea[nexty][nextx] == BLANK) {//빈공간일 경우
						temparea[nexty][nextx] = VIRUS;//바이러스 퍼짐
						q.push(make_pair(nexty, nextx));//퍼진 곳에서 다시 바이러스 퍼트림
						visited[nexty][nextx] = true;//해당 좌표 방문완료
					}
				}
			}
		}
	}
}

void solve() {
	for (int i = 0; i < indexOfBlank.size() - 2; i++) { //임의의 3개의 칸을 골라 벽을 설치
		for (int j = i + 1; j < indexOfBlank.size() - 1; j++) {
			for (int k = j + 1; k < indexOfBlank.size(); k++) {
				memcpy(temparea, area, sizeof(area));
				temparea[indexOfBlank[i].first][indexOfBlank[i].second] = WALL;
				temparea[indexOfBlank[j].first][indexOfBlank[j].second] = WALL;
				temparea[indexOfBlank[k].first][indexOfBlank[k].second] = WALL;
				spreadVirus(); //바이러스를 퍼트리고 max값이 크면 갱신
				int count = 0;
				for (int i = 0; i < n; i++) { //바이러스 다 퍼트린 뒤 빈칸의 수 확인
					for (int j = 0; j < m; j++) {
						if (temparea[i][j] == BLANK)
							count++;
					}
				}
				if (count > maxBlank) //빈칸 수가 최대이면 갱신
					maxBlank = count;
			}
		}
	}
}

int main() {
	int temp;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			if (temp == WALL)
				area[i][j] = WALL;
			else if (temp == VIRUS) {
				area[i][j] = VIRUS;
				indexOfVirus.push_back(make_pair(i, j));
			}
			else {
				indexOfBlank.push_back(make_pair(i, j));
			}
		}
	}
	solve();
	cout << maxBlank;
	return 0;
}