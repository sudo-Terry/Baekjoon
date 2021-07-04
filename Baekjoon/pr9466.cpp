#include <iostream>
#include <cstring>
#define MAX 100000

using namespace std;
int node[MAX+1];
bool visited[MAX + 1];
bool visiting[MAX + 1];
int num = 0;
int t, n;

//�˰���
//visited[] �� node[]�� �����ϰ� node[n]���� n��° �л��� ������ �л��� �ε����� ����ִ�
//visited���� ���� node�� ���Ͽ� ���� �켱 Ž���� �ϰ�, ���� �� ����� ó�� ����� ��� ��ȣ�� ���� ��� Ž���� ����� ���� num�� ����Ѵ�
//��� node�� visited �ɶ����� �̸� �ݺ��� �� num��  ����Ѵ�.(���̿켱Ž��)

void dfs(int nodenum) {
	visiting[nodenum] = true;
	if (!visiting[node[nodenum]]) //�л��� ������ �ٸ� �л��� ���Ͽ� ���ȣ���� �ݺ�
		dfs(node[nodenum]);
	else if (!visited[node[nodenum]]) { //����Ŭ�� �߻����� ��� �̹� �湮�� ���� ��尡 �ƴ� ��� ����Ŭ�� �ش��ϴ� ���� �����ȴ�
		for (int i = node[nodenum]; i != nodenum; i = node[i])//����Ŭ�� �ش��ϴ� ��� �� ���� 
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