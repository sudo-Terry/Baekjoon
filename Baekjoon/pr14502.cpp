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
int dx[] = { 0, 1, 0, -1 };//�߾� �� �� �� ��
int dy[] = { 1, 0, -1, 0 };
int area[MAX][MAX];
int temparea[MAX][MAX];
vector<pair<int, int>> indexOfBlank;
vector<pair<int, int>> indexOfVirus;
bool visited[MAX][MAX];
int maxBlank = 0;
int tempx1, tempx2, tempx3, tempy1, tempy2, tempy3;

//�˰��� >> ���Ʈ���� �˰���
//����ִ� ĭ�� ������ 3���� ��� ��ȭ�� ���������� ���̷����� ��Ʈ���� ��ĭ�� ���� max���� ũ�� max�� �����Ѵ�

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
			if (!visited[nexty][nextx]) { //���� �湮���� ���� ĭ�� �˻��Ѵ�
				if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n) {//��ü ���� ������ ����� �ʴ� ��쿡��
					if (temparea[nexty][nextx] == BLANK) {//������� ���
						temparea[nexty][nextx] = VIRUS;//���̷��� ����
						q.push(make_pair(nexty, nextx));//���� ������ �ٽ� ���̷��� ��Ʈ��
						visited[nexty][nextx] = true;//�ش� ��ǥ �湮�Ϸ�
					}
				}
			}
		}
	}
}

void solve() {
	for (int i = 0; i < indexOfBlank.size() - 2; i++) { //������ 3���� ĭ�� ��� ���� ��ġ
		for (int j = i + 1; j < indexOfBlank.size() - 1; j++) {
			for (int k = j + 1; k < indexOfBlank.size(); k++) {
				memcpy(temparea, area, sizeof(area));
				temparea[indexOfBlank[i].first][indexOfBlank[i].second] = WALL;
				temparea[indexOfBlank[j].first][indexOfBlank[j].second] = WALL;
				temparea[indexOfBlank[k].first][indexOfBlank[k].second] = WALL;
				spreadVirus(); //���̷����� ��Ʈ���� max���� ũ�� ����
				int count = 0;
				for (int i = 0; i < n; i++) { //���̷��� �� ��Ʈ�� �� ��ĭ�� �� Ȯ��
					for (int j = 0; j < m; j++) {
						if (temparea[i][j] == BLANK)
							count++;
					}
				}
				if (count > maxBlank) //��ĭ ���� �ִ��̸� ����
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