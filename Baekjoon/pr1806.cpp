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
  for(int i = 0; i < N; i++){
    int temp;
    cin >> temp;
    arr.push_back(temp);
  }

  int left = 0;
  int right = 0;
  int ans = N; 
  while(true){
    int sum = 0;
    for(int i = left; i <= right; i++){
      sum += arr[i];
    }

    if(sum >= S){
      ans = min(ans, right - left + 1); 
      
      left++;      
    }else{
      if(right == N) break;

      right++;
    }
  }

  cout << ans;

  return 0;
}