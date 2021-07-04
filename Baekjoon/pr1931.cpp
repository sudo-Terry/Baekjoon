#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

//�˰��� > �� �� �ִ� ȸ�� �߿��� ȸ�ǰ� ������ �ð��� ���� �̸� ���� ���� �ȴ�.

int main(void) {
	int n, temp, min; //n: ȸ���� ��      temp: int �ӽú��� 
	int count = 0;//�����
	vector<pair<int, int>> conference;//ȸ�� <����, ��> pair
	int tempS, tempE;//ȸ�� ���� �� �ӽú���
	int confEndMin = 0;
	int confStartMax;
	
	cin >> n;//ȸ���� �� �Է�
	
	for (int i = 0; i < n; i++) {//ȸ�� ���� �� �Է�
		cin >> tempS >> tempE;
		conference.push_back(make_pair(tempS, tempE));
	}
	sort(conference.begin(), conference.end()); //pair�� first �������� ��������(default) ����

	int k = conference.size();
	confStartMax = conference[k - 1].first;

	temp = conference[0].second;
	//���̻� ȸ�Ǹ� �� �� ���������� �̸� �ݺ��Ѵ�.
	//��, ���� ȸ���� ����ð��� ��� ȸ�� ���� �ð�(ȸ�� ���� �ð��� �ִ�)���� Ŭ ��� �ݺ��� �����Ѵ�.
	while (confEndMin <= confStartMax) {//ȸ�� �ð��߿��� ȸ�ǰ� ������ �ð��� ���� �̸� ���� ã�� count ���� ������Ų��.
		for (int i = 0; i < conference.size(); i++) {//��� ȸ�ǵ� ��
			if (conference[i].first >= confEndMin) {//ȸ�� ������ �͵�(�ռ� ȸ�� ���� �ð��� ȸ�� ���� �ð����� �۰ų� ���ƾ���) ��
				if (conference[i].second < temp)//ȸ�� ���� �ð��� ���� �̸� ȸ�Ǹ� ����
					temp = conference[i].second;
			}
		}
		confEndMin = temp;
		count++;
	}

	cout << count;

	return 0;
}