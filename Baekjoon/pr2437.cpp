#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�˰����� > �����߸� ������������ �����Ͽ� ���԰� ���� �������� �����Ѵ�.
//�츮�� �����߸� �̿��Ͽ� ������ �� �ִ� ���Ե��� �������� ������ �� �ִ�.
//�츮�� ������ �� �ִ� ������ ������ ������ ���̸� ������ �� ���� ���� �ּ��� ������ ������ �ҿ����� ���̴�.
//���� �ҿ����� ������ �߻��� ��� �����߰� ������������ ���ĵǾ� ������ �����غ��� �� �ҿ����� ������ �ٽô� �޿��� �� �����Ƿ� ó������ �ҿ����� �߻��� ������ ���ϰ��� �ϴ� ���̴�.

//ex ���� ������ a�� ����ϸ鼭 �ҿ����� ������ �߻��Ͽ� A~B, (A+a)~(B+a)������ �����̰� �Ǿ��ٰ� ����.
//�������� ����ϴ� ������ b�� ���� �˰����� ���� a���� ũ�ų� �����Ƿ� ������ A~B, (A+a)~(B+a), (A+b)~(B+b), (A+a+b)~(B+a+b)�� �ȴ�.
// ��, ó������ �ҿ����� ������ �߻��ϸ�, �̴� �޿��� �� ����.
//�ҿ����� �߻��Ϸ��� B+1 < A+a �̾�� �ϸ� �� ��� �ҿ����� ������ B+1�̴�.

int main(void) {
	
	int n = 0;
	int begin = 0;
	int end = 0;
	int tempWeight = 0;
	vector<int> sinkers;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tempWeight;
		sinkers.push_back(tempWeight);
	}
	sort(sinkers.begin(), sinkers.end());

	if (sinkers[0] != 1) { //���� ������ �����߰� 1�� �ƴϸ� 1�� ������ �� ����
		cout << 1;
		return 0;
	}

	//���� ������ �����߰� 1�� ���
	end = 1; //�ʱⰪ
	for (int i = 1; i < n; i++) {
		if (end + 1 < sinkers[i]) {
			break;
		}
		end += sinkers[i];
	}

	cout << end + 1 << endl;
	return 0;
}