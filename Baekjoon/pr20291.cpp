#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<string> file_vec(N);
  map<string, int> ext_count;
  for(int i = 0; i < N; i++) cin >> file_vec[i];

  for(int i = 0; i < N; i++){
    int sep_idx;

    for(int j = 0; j < file_vec[i].size(); j++){
      char c = file_vec[i][j];
      if( c == '.'){
        sep_idx = j;
        break;
      }
    }

    string ext = file_vec[i].substr(sep_idx + 1, file_vec[i].size());
    if(ext_count.find(ext) != ext_count.end()){
      ext_count[ext]++;
    }else{
      ext_count.insert({ext, 1});
    }
  }

  vector<pair<string, int>> ans(ext_count.begin(), ext_count.end());
  sort(ans.begin(), ans.end());
  for(size_t i = 0; i < ans.size(); i++){
    cout << ans[i].first << ' ' << ans[i].second << '\n';
  }

  return 0;
}