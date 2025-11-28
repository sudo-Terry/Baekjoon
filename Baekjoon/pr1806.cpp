#include <iostream>
#include <vector>
using namespace std;


int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N, S;
  vector<int> arr;

  cin >> N >> S;
  int arr_sum = 0;
  for(int i = 0; i < N; i++){
    int temp;
    cin >> temp;
    arr.push_back(temp);
    arr_sum += temp;
  }

  if(arr_sum < S){
    cout << 0;
    return 0;
  }

  int left = 0;
  int right = 0;
  int ans = N; 
  int sum = arr[0];
  while(true){
    if (left > right && left < N) {
      right = left;
      sum = arr[left];
    }

    if(sum >= S){
      ans = min(ans, right - left + 1); 
      
      sum -= arr[left];
      left++;
    }else{
      if(right == N - 1) break;

      right++;
      sum += arr[right];
    }

    // cout << ans << endl;
    // cout << left << ' ' << right << ' ' << sum << endl;
  }

  cout << ans;

  return 0;
}