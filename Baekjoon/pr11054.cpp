#include <iostream>
#define MAX 1000

using namespace std;
int n = 0;
int arr[MAX + 1] = { 0, };
int dp[MAX + 1] = { 0, }; //memoization

//�������� �Ǵ� ���� Sk����, �� �찡 ��� �۾�����.
//dp[n-2] �� �����ϱ⸸ �ϴ� ������� �κм����� ��츦 �����غ���
//n��° ���� n-1��° ������ Ŭ ��� getArr(n-1) return dp[n-1] = dp[n-2] + 1
//n���� ���� n-1��° ������ ���� ��쿡�� ��������� ���Һκ��� �� ���� �ְ� ��������� �ٲ� ���� �ִ�? getArr(n-1) return dp[n-1]= 
//dp[n-2]�� ������� �κм����� �����ϴ� �κп� �ش��ϴµ� n��° ���� n-1���� ������ getArr(n-1) return dp[n-1] = dp[n-2] + 1
//�ݴ�� n��° ���� n-1���� ũ�ٸ� getArr(n-1) return dp[n-1]=

int getArr(int n) {

}

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << dp[n - 1];
	return 0;
}