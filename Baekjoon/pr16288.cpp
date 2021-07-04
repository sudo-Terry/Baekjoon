#include <iostream>
#include <vector>
#define MAX 100

using namespace std;

//�˰��� >�� �ɻ� â�������� ������ �°��� ��ȣ���̾�� �Ѵ�.
//���������� �°��� ��ȣ�� ������ ��쿡�� �ٸ� �ɻ� â���� ��������.	

int main(void) {
	int n, k;
	int tempNum = 0;
	bool check = false;
	vector<int> exitNum;
	vector<int> passport;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> tempNum;
		exitNum.push_back(tempNum);
	}
	for (int i = 0; i < MAX; i++) {
		passport.push_back(0);
	}

	for (int i = 0; i < n; i++) {
		check = false;
		for (int j = 0; j < k; j++) {
			if (passport[j] < exitNum[i]) {
				passport[j] = exitNum[i];
				check = true;
				break;
			}
		}
		if (check == false) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}