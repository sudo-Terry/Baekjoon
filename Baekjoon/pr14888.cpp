#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define PLUS 0
#define MINUS 1
#define MULTIPLY 2
#define DIVIDE 3

int N;
int min_val = 1111111111;
int max_val = -1111111111;
vector<int> vec;
int func[4];

void backtrack(int idx, int cur_val){
  if(idx == N){
    max_val = max(max_val, cur_val);
    min_val = min(min_val, cur_val);
    return;
  }

  if(func[0] > 0){
    func[0]--;
    backtrack(idx + 1, cur_val + vec[idx]);
    func[0]++;
  }

  if(func[1] > 0){
    func[1]--;
    backtrack(idx + 1, cur_val - vec[idx]);
    func[1]++;
  }

  if(func[2] > 0){
    func[2]--;
    backtrack(idx + 1, cur_val * vec[idx]);
    func[2]++;
  }

  if(func[3] > 0){
    func[3]--;
    backtrack(idx + 1, (int)(cur_val / vec[idx]));
    func[3]++;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  for(int i = 0; i < N; i++){
    int temp;
    cin >> temp;
    vec.push_back(temp);
  }
  for(int i = 0; i < 4; i++){
    cin >> func[i];
  }

  backtrack(1, vec[0]);

  cout << max_val << '\n';
  cout << min_val << '\n';

  return 0;
}