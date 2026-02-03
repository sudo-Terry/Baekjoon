#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Lecture {
  int start;
  int end;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<Lecture> lectures(N);
  for (int i = 0; i < N; i++) {
    cin >> lectures[i].start >> lectures[i].end;
  }

  sort(lectures.begin(), lectures.end(), [](const Lecture& a, const Lecture& b) {
    return a.start < b.start;
  });

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < N; i++) {
    if (!pq.empty() && pq.top() <= lectures[i].start) {
      pq.pop();
    }
    pq.push(lectures[i].end);
  }

  cout << pq.size() << '\n';
  return 0;
}