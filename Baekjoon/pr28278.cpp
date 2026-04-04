#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<int> vec;

  int temp;
  for(int i = 0; i < N; i++){
    cin >> temp;

    if(temp == 1){
      cin >> temp;
      vec.push_back(temp);
    }else if(temp == 2){
      if(vec.size() > 0){
        cout << vec[vec.size() - 1] << '\n';
        vec.pop_back();
      }else{
        cout << "-1" << '\n';
      }
    }else if(temp == 3){
      cout << vec.size() << '\n';
    }else if(temp == 4){
      if(vec.size() > 0){
        cout << "0" << '\n';
      }else{
        cout << "1" << '\n';
      }
    }else{
      if(vec.size() > 0){
        cout << vec[vec.size() - 1] << '\n';
      }else{
        cout << "-1" << '\n';
      }
    }
  }


  return 0;
}