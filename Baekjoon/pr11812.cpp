#include <iostream>
#include <algorithm>
#include <stdlib.h>
//#include <bits/stdc++.h>

using namespace std;

//�˰���
//��� ��ȣ�� ������ k�� �̿��Ͽ� ǥ���Ѵ� 1 / 2~k+1 / k+2~k^2+k+1 
//�� ������ �ش��ϴ� ���� k^level�� ��ŭ �ִ� 
//�ڽ� ����� ��ȣ�� ����ȣ�� n�� ��� (n-1)*k+2 ~ n*k+1 �θ� ����� ��ȣ�� [n+k-2/k]
//���ϴ� �� ����� ū ��带 �θ���� �ø��鼭 ���θ� ���Ͽ� ���� �θ� �����ұ��� �ݺ��ϸ� len�� 1�� ���Ѵ�
long long n, k ,q;//n: ����� �� k: k�� q: ������ ��

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> k >> q;
	while (q--) {
		long long a, b;
		long long len = 0;
		cin >> a >> b;
		if (k == 1)
			len = abs(a - b);
		else {
			while (a != b) {
				if (a > b) {
					a = (a + k - 2) / k;
					len++;
				}
				else {
					b = (b + k - 2) / k;
					len++;
				}
			}
		}
		cout << len << '\n';
	}
	return 0;
}