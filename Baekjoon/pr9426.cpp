#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define MAX 66000

int n, k, ans;
vector<int> segTree;
vector<int> input;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    segTree.resize(MAX * 2);
    for (int i = 1; i <= n; i++) {
        cin >> input[i];
    }

    return 0;
}