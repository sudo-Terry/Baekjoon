#include <iostream>
#define MAX 60
using namespace std;

int r, c, t;
int Arc[MAX][MAX];

int main() {
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int temp; cin >> temp;
			Arc[i][j] = temp;
		}
	}
}