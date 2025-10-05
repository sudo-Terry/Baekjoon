#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAX 150100

int N, atk_start;
bool is_monster[MAX];
long long atk[MAX];
long long hp[MAX];
long long low = 0;
long long high = 1e18; // 1 * 10^18
long long mid;

bool simulate_game(long long atk_start, long long hp_start){
  long long hero_hp = hp_start;
  long long hero_atk = atk_start;
  for(int i = 0; i < N; i++){
    if(is_monster[i]){
      /*
      용사의 공격력 HATK만큼 몬스터의 생명력을 깎습니다.
      몬스터의 생명력이 0 이하이면 전투가 종료되고 용사는 다음 방으로 이동합니다.
      몬스터의 공격력만큼 용사의 생명력 HCurHP를 깎습니다.
      용사의 생명력이 0 이하이면 전투가 종료되고 용사는 사망합니다.
      다시 1부터 진행합니다.
      */
      long long monster_hp = hp[i];
      long long monster_atk = atk[i];
      
      long long turns_to_win = (monster_hp + hero_atk - 1) / hero_atk;
      long long damage_taken = (turns_to_win - 1) * monster_atk;
      
      hero_hp -= damage_taken;
      if (hero_hp <= 0) return false;
    }else{
      hero_atk += atk[i];
      hero_hp = min(hp_start, hero_hp + hp[i]);
    }
  }
  return true;
}

void solve(){
  while (low < high - 1) {
    mid = (low + high) / 2;

    if(simulate_game(atk_start, mid)){
      high = mid;
    }else{
      low = mid;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> N >> atk_start;
  for(int i = 0; i < N; i++){
    int room_type;
    cin >> room_type;
    is_monster[i] = room_type == 1;
    cin >> atk[i] >> hp[i];
  }

  solve();

  cout << high;

  return 0;
}
