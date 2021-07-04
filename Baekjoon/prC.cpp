#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 100010
using namespace std;

typedef long long ll;
ll verNum[MAX], a[MAX], b[MAX];
ll tc = 0, n, ans = 0, len = 0;

int main() {
	cin >> tc;
	while (tc--) {
		ans = 0;
		cin >> n; //number of chains
		memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));
		memset(verNum, 0, sizeof(verNum));
		for (int i = 1; i <= n; i++) cin >> verNum[i];
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		for (int i = 2; i <= n; i++) {
			if (i == 2 || a[i] == b[i]) //������ ����
				len = 2 + (verNum[i] - 1) + abs(b[i] - a[i]);
			else {
				ll route1 = len + 2 + (verNum[i] - 1) - abs(b[i] - a[i]); //ü�ο��� ���� ���� ���
				ll route2 = 2 + (verNum[i] - 1) + abs(b[i] - a[i]); //ü�ο��� ���� ���
				len = max(route1, route2);//ū�� ����
			}
			if (len > ans) ans = len;
		}
		cout << ans << '\n';
	}
	return 0;
}


/*
1�� n�� ü�� �̿��� ü�ο��� a���� b���� �ߺ��� �ִ��� ���ɴ�
�ߺ��� �Ͼ�� ü�� ������ �Ÿ��� ���� ū �� ü���� ���� n1 n2
(n2 - n1)*2 �� �� ü���� �ǳʰ��µ� �ʿ��� ���̴�
�� ü�� �������� (verNum[i] - b[i + 1]) + (a[i + 1] - 1)��ŭ �Ÿ��� �̵��Ѵ�
����Ŭ�� �� ���� c1�̰ų� cn�� �ƴ� ��쿡�� �糡 ü�ο����� �߰� �Ÿ��� ������
����Ŭ�� �� ���� c1�̰ų� cn�̸� �ش� ü�ο��� b[i - 1] - a[i - 1]��ŭ�� ����Ŭ ���̿� ���Ѵ�

ü���� �� �ܰ迡�� ������ ������ �Ǵ��Ѵ�
���� ü�ο��� �ݴ� ���� ���� ����� �ִ��� ���� ��� ����
�ݾƼ� ü���� �� ũ�� ���ؼ��� �ڿ� a[i] == b[i] �������� ������ ���� ���� �ִ񰪺��� Ŀ����
*/