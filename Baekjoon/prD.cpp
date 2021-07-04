#include <iostream>
#include <cstring>
#include <string>
#define MAX 300010
using namespace std;
typedef long long ll;

bool isRight[MAX];
ll bfs1[MAX], bfs2[MAX];
ll tc, n, ans = 0;

int main() {
	cin >> tc;
	while (tc--) {
		memset(isRight, false, sizeof(isRight));
		memset(bfs1, 0, sizeof(bfs1)); memset(bfs2, 0, sizeof(bfs2));
		cin >> n;
		string str; 
		cin >> str;
		for (ll i = 0; i < n; i++) {
			if (str.at(i) == 'R') 
				isRight[i] = true;
			else
				isRight[i] = false;
		}
		for (ll i = 1; i <= n; i++) { //������ ����
			ll temp = 0;
			if (!isRight[i - 1]) {  //�������
				temp++;
				if (i - 2 >= 0 && isRight[i - 2]) { //���κ� �ƴϸ� �ǳ��̵��ϸ鼭 ���Ѵ�
					temp++;
					temp += bfs1[i - 2]; 
				}
			}
			bfs1[i] = temp;
		}
		for (ll i = n - 1; i >= 0; i--) { //���� ����
			ll temp = 0;
			if (isRight[i]) { 
				temp++;
				if (i + 1 < n && !isRight[i + 1]) {
					temp++;
					temp += bfs2[i + 2];
				}
			}
			bfs2[i] = temp;
		}
		for (ll i = 0; i <= n; i++) {
			cout << bfs1[i] + bfs2[i] + 1 << " ";//�������̵� + �����̵� + �ڱ��ڽ�
		}cout << '\n';
	}
	return 0;
}