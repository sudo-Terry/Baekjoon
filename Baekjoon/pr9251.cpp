#include <iostream>
#include <string>
#include <algorithm>
#define MAX 1000

using namespace std;

int dp[MAX + 1][MAX + 1] = { 0, };
//dp���̺� ���� dp[i][j] = i������ ���ڿ��� j������ ���ڿ��� LCS ����
//LCS���̰� ���ϴ� ������ i+1, j+1�� ���� ���ڰ� ��Ÿ���� ���
//i�� j��° ���ڰ� ���� ��� dp[i+1][j+1] = dp[i][j] + 1;
//���� dp[i+1][j+2]~ dp[i+1][������] �� dp[i+2][0]~dp[i+2][j+1]������ dp[i+1][j+1]������ ä���
//dp[i+2][j+2]���� �ٽ� j+2~���� i+1��°�� j+1��° ���ڰ� �������� ������ ã�� �̸� �ݺ��Ѵ�. 


int main(void) {
	string str1, str2;
	cin >> str1 >> str2;

	for (int i = 1; i < str1.length() + 1; i++) {
		for (int j = 1; j < str2.length() + 1; j++) {
			if (str1.at(i - 1) == str2.at(j - 1))
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	
	cout << dp[str1.length()][str2.length()];

	return 0;
}