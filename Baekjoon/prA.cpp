#include<iostream>
using namespace std;
 
long long n, k;
 
int main() {
	long long tc = 0;
	cin >> tc;
	while (tc--) {
        cin >> n >> k;
        if (n % k == 0)
        {
            cout << 1 << endl;
        }
        else if (n > k)
        {
            cout << 2 << endl;
        }
        else if (k % n == 0)
        {
            cout << k / n << endl;
        }
        else
        {
            cout << k / n + 1 << endl;
        }
	}
	return 0;
}