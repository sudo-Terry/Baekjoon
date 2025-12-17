#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N;
  cin >> N;

  vector<string> channels(N);
  int kbs1_idx = 0;
  int kbs2_idx = 0;

  for (int i = 0; i < N; ++i) {
    cin >> channels[i];
    if (channels[i] == "KBS1") kbs1_idx = i;
    if (channels[i] == "KBS2") kbs2_idx = i;
  }

  for (int i = 0; i < kbs1_idx; ++i) {
    cout << "1";
  }
  for (int i = 0; i < kbs1_idx; ++i) {
    cout << "4";
  }


  if (kbs2_idx < kbs1_idx) {
    kbs2_idx++;
  }

  for (int i = 0; i < kbs2_idx; ++i) {
    cout << "1";
  }
  for (int i = 0; i < kbs2_idx - 1; ++i) {
    cout << "4";
  }

  return 0;
}