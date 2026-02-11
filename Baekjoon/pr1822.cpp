#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int na, nb;
  cin >> na >> nb;
  vector<int> A(na);
  vector<int> B(nb);
  for(int i = 0; i < na; i++) cin >> A[i];
  for(int i = 0; i < nb; i++) cin >> B[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  vector<int> ans;
  for(int i = 0; i < na; i++){
    int target = A[i];
    int start = 0;
    int end = nb - 1;
    bool flag = false;

    while(start <= end){
      int mid = (start + end) / 2;

      if(B[mid] > target){
        end = mid - 1;
      }else if(B[mid] < target){
        start = mid + 1;
      }else if(B[mid] == target){
        flag = true;
        break;
      }
    }

    if(!flag) ans.push_back(target);
  }

  if(!ans.empty()){
    cout << ans.size() << '\n';
    for(size_t i = 0; i < ans.size(); i++){
      cout << ans[i] << ' ';
    }
  }else{
    cout << "0";
  }

  return 0;
}