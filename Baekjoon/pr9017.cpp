#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define MEMBER_COUNT 6

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int T, N;

  cin >> T;

  while(T--){
    vector<int> rating;
    map<int, int> member_count;
    map<int, int> team_score;      // 팀별 상위 4명 점수 합
    map<int, int> team_p5_score;   // 팀별 5번 주자의 실제 등수
    map<int, int> team_passed_cnt; // 점수 계산에 포함된 주자 수
    cin >> N;

    for(int i = 0 ; i < N; i++){
      int team;
      cin >> team;
      rating.push_back(team);
      member_count[rating[i]]++; 
    }

    int score_counter = 1;
    for(size_t i = 0; i < rating.size(); i++){
      if(member_count[rating[i]] == MEMBER_COUNT){
        team_passed_cnt[rating[i]]++;

        if(team_passed_cnt[rating[i]] <= 4){
          team_score[rating[i]] += score_counter;
        }
        if(team_passed_cnt[rating[i]] == 5){
          team_p5_score[rating[i]] = score_counter;
        }

        score_counter++;
      }
    }

    int min_val = 987654321; // 1 ~ 1000까지의 합보다만 크면됨 -> n(n+1)/2 
    int win_team;
    for (auto &p : team_score) {
      if (p.second < min_val) { 
        min_val = p.second;
        win_team = p.first;
      }
      else if (p.second == min_val) {
        // 동점의 경우에는 다섯 번째 주자가 가장 빨리 들어온 팀
        if(team_p5_score[p.first] < team_p5_score[win_team]){
          win_team = p.first;
        }
      }
    }   

    cout << win_team << '\n';
  }
  

  return 0;
}