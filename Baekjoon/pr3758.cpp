#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int tc;
  cin >> tc;

  while(tc--){
    //팀의 개수 n, 문제의 개수 k, 당신 팀의 ID t, 로그 엔트리의 개수 m
    int n, k, t, m;
    cin >> n >> k >> t >> m;
    vector<int> score_sum;
    vector<int> submit_count;
    vector<int> last_submit_index;
    vector<vector<int>> final_score; //[n][m] -> n번팀의 m번문제 점수

    score_sum.resize(n + 1 , 0);
    submit_count.resize(n + 1 , 0);
    last_submit_index.resize(n + 1 , 0);
    final_score.resize(n + 1);
    for(int a = 0; a < n; a++){
      final_score[a].resize(k + 1, 0);
    }

    for(int a = 0; a <= m; a++){
      //팀 ID i, 문제 번호 j, 획득한 점수 s
      int i, j, s;
      cin >> i >> j >> s;

      submit_count[i]++;
      last_submit_index[i] = a;
      if (s > final_score[i][j]) {
        score_sum[i] += (s - final_score[i][j]);
        final_score[i][j] = s;
      }
    }

    int ranking = 1;
    for (int i = 1; i <= n; i++) {
      if (i == t) continue;

      if (score_sum[i] > score_sum[t]) ranking++;
      else if (score_sum[i] == score_sum[t]) {
        if (submit_count[i] < submit_count[t]) ranking++;
        else if (submit_count[i] == submit_count[t]) {
          if (last_submit_index[i] < last_submit_index[t]) ranking++;
        }
      }
    }
    cout << ranking << '\n';
  }

  return 0;
}