#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  string name;
  cin >> name;

  string ans = name;
  sort(name.begin(), name.end());
  if(name.size() % 2 == 0){
    for(size_t i = 0; i < name.size(); i += 2){
      if(name[i] == name[i+1]){
        ans[i / 2] = name[i];
        ans[ans.size() - 1 - i/2] = name[i+1];
      }else{
        cout << "I'm Sorry Hansoo";
        return 0;
      }
    }
  }else{
    bool flag = false; // 중심에 있을 char 찾음
    for(size_t i = 0; i < name.size(); i += 2){
      if(name[i] == name[i+1]){
        ans[i / 2] = name[i];
        ans[ans.size() - 1 - i/2] = name[i+1];
      }else{
        if(!flag){
          ans[(int)(ans.size() / 2)] = name[i]; // ans 중앙에 문자 넣기
          flag = true;
          i--; // 다음 루프는 한칸만 증가
        }else{
          cout << "I'm Sorry Hansoo";
          return 0;
        }
      }
    }
  }

  cout << ans;

  return 0;
}