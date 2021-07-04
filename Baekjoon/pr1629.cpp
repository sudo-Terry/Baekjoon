#include <iostream>
using namespace std;

long long a, b, c;

long long solve(long long num1, long long num2) {
	if (num2 == 0) //기저
		return 1;
	long long temp = solve(num1, num2 / 2);
	if (num2 % 2 == 1) //나누는 수가 홀수일 경우 뒤에 (a^2)^(b-1/2)^a = a^b-1 * a = a^b
		return ((temp * temp) % c )* num1 % c;
	else
		return (temp * temp) % c;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> a >> b >> c;
	cout << solve(a, b);

	return 0;
}