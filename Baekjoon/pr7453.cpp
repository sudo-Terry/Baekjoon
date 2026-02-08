#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N;

void push_vector(vector<int>& vec){
  for(int i = 0; i < N; i++){
    int temp;
    cin >> temp;
    vec.push_back(temp);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> A, B, C, D;
  vector<int> AB, CD;
  cin >> N;
  push_vector(A);
  push_vector(B);
  push_vector(C);
  push_vector(D);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      AB.push_back(A[i] + B[j]);
    }
  }
  sort(AB.begin(), AB.end());
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      CD.push_back(C[i] + D[j]);
    }
  }
  sort(CD.begin(), CD.end(), [](int& a, int& b){
    return a > b;
  });

  /*
  0 0 -1 -1 -2 -2 -3 -3 -3
  3 3 2 1 0 0 -1
  */
  long long ans = 0;
  int i = 0, j = 0;
  while (i < AB.size() && j < CD.size()) {
    long long sum = AB[i] + CD[j];

    if (sum == 0) {
      int abVal = AB[i];
      int cdVal = CD[j];

      long long abCnt = 0;
      long long cdCnt = 0;

      while (i < AB.size() && AB[i] == abVal) {
        abCnt++;
        i++;
      }
      while (j < CD.size() && CD[j] == cdVal) {
        cdCnt++;
        j++;
      }

      ans += abCnt * cdCnt;
    }
    else if (sum < 0) i++;
    else j++;
  }

  cout << ans;

  return 0;
}