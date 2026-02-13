#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<int> inputs;
  vector<int> inputs_sorted;

  for(int i = 0; i < N; i++){
    int temp;
    cin >> temp;
    inputs.push_back(temp);
    inputs_sorted.push_back(temp);
  }
  sort(inputs_sorted.begin(), inputs_sorted.end());
  inputs_sorted.erase(
    unique(inputs_sorted.begin(), inputs_sorted.end()),
    inputs_sorted.end()
  );

  for(size_t i = 0; i < inputs.size(); i++){
    int start = 0;
    int end = inputs_sorted.size() - 1;

    while(start <= end){
      int target = inputs[i];
      int mid = (start + end)/2;

      if(inputs_sorted[mid] == target){
        cout << mid << ' ';
        break;
      }else if(inputs_sorted[mid] > target){
        end = mid - 1;
      }else if(inputs_sorted[mid] < target){
        start = mid + 1;
      }
    }
  }

  return 0;
}