#include <iostream>
#include <cstring>
#define MAX 100000

using namespace std;
int node[MAX+1];
bool visited[MAX + 1];
bool visiting[MAX + 1];
int num = 0;
int t, n;

//알고리즘
//visited[] 과 node[]를 선언하고 node[n]에는 n번째 학생이 선택한 학생의 인덱스가 들어있다
//visited하지 않은 node에 대하여 깊이 우선 탐색을 하고, 만약 그 결과가 처음 출발한 노드 번호와 같을 경우 탐색한 노드의 수를 num에 기록한다
//모든 node가 visited 될때까지 이를 반복한 뒤 num을  출력한다.(깊이우선탐색)

void dfs(int nodenum) {
	visiting[nodenum] = true;
	if (!visiting[node[nodenum]]) //학생이 선택한 다른 학생에 대하여 재귀호출을 반복
		dfs(node[nodenum]);
	else if (!visited[node[nodenum]]) { //사이클이 발생했을 경우 이미 방문이 끝난 노드가 아닐 경우 사이클에 해당하는 팀이 생성된다
		for (int i = node[nodenum]; i != nodenum; i = node[i])//사이클에 해당하는 노드 수 세기 
			num++;
		num++;
	}
	visited[nodenum] = true;
}

int main() {
	cin >> t;
	while (t--)
	{
		memset(visited, false, sizeof(visited));
		memset(visiting, false, sizeof(visiting));
		num = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> node[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i])
				dfs(i);
		}
		cout << n - num << endl;
	}
	return 0;
}