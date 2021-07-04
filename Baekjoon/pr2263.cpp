#include <iostream>
#define MAX 100000
using namespace std;

//알고리즘 >> 포스트오더에서는 무조건 마지막 수가 루트이므로 트리의 루트를 알 수 있다.
//인오더 식에서는 루트숫자를 기준으로 왼쪽의 모든 숫자들이 왼쪽 서브트리(그룹 left), 오른쪽의 모든 숫자들이 오른쪽 서브트리의 노드번호이다(그룹 right)
//포스트 오더식은 즉 (그룹left 노드번호들의 나열) + (그룹right 노드번호들의 나열) + 루트 와 같이 이해할 수 있다.
//오른쪽 서브트리, 즉, 그룹 right의 노드번호 나열의 마지막 숫자도 결국 오른쪽 서브트리의 루트노드임을 알 수 있다.
//이로 인해 다시 그룹을 나눠 루트를 계속 유추하다보면 그래프의 형태를 알 수 있고 그룹의 노드들이 2개 이하 남았을 경우 그래프의 리프들의 형태를 결정할 수 있다

int n;
int inorder[MAX + 1];
int postorder[MAX + 1];
int preorder[MAX + 1];
int index[MAX + 1];

void solve(int begin1, int end1, int begin2, int end2) {
	if (begin1 > end1 || begin2 > end2)
		return;
	int root = postorder[end2]; //포스트 오더의 마지막 수는 항상 트리의 루트
	cout << root << " "; //프리오더의 첫수는 항상 트리의 루트
	int rootindex = index[root];
	int temp = rootindex - begin1;
	solve(begin1, rootindex - 1, begin2, begin2 + temp - 1); //왼쪽 그룹
	solve(rootindex+1, end1, begin2 + temp, end2 - 1); //오른쪽 그룹
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> inorder[i];
	for (int i = 0; i < n; i++)
		cin >> postorder[i];
	for (int i = 0; i < n; i++)
		index[inorder[i]] = i;

	solve(0, n - 1, 0, n - 1);
	return 0;
}