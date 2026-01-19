#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> dq;
bool front_flag;
string func, arr;
int arr_size;

void do_func(){
  for(size_t i = 0; i < func.size(); i++){
    if(func[i] == 'R'){
      front_flag = !front_flag;
    }else if(func[i] == 'D'){
      if(dq.empty()) {
        cout << "error" << '\n';
        return;
      }

      if(front_flag){
        dq.pop_front();
      }else{
        dq.pop_back();
      }
    }
  }

  cout << '[';
  if(front_flag){
    for (int i = 0; i < dq.size(); i++) {
      cout << dq[i];
      if(i != dq.size() - 1) cout << ",";
    }
  }else{
    for (int i = dq.size() - 1; i >= 0; i--) {
      cout << dq[i];
      if(i != 0) cout << ",";
    }
  }
  cout << ']' << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc;
  cin >> tc;

  while(tc--){
    front_flag = true;
    dq.clear();

    cin >> func;
    cin >> arr_size;
    cin >> arr;

    int num = 0;
    bool is_num = false;

    for (char c : arr) {
      if (isdigit(c)) {
        num = num * 10 + (c - '0');
        is_num = true;
      } else {
        if (is_num) {
          dq.push_back(num);
          num = 0;
          is_num = false;
        }
      }
    }
    if (is_num) dq.push_back(num);

    do_func();
  }

  return 0;
}