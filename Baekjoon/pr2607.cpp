#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

void get_frequency(const string& word, int freq[26]) {
  for (int i = 0; i < 26; ++i) {
    freq[i] = 0;
  }
  for (char c : word) {
    freq[c - 'A']++;
  }
}

bool is_similar(const int base_freq[26], const int target_freq[26]) {
  int diff_plus = 0;   // target에 더 많은 문자의 개수
  int diff_minus = 0;  // target에 더 적은 문자의 개수

  for (int i = 0; i < 26; ++i) {
    int diff = target_freq[i] - base_freq[i];
    
    if (diff > 0) {
      diff_plus += diff;
    } else if (diff < 0) {
      diff_minus += abs(diff);
    }
  }

  // 비슷한 단어 조건: (추가 <= 1) 이고 (삭제 <= 1)
  if (diff_plus <= 1 && diff_minus <= 1) {
    return true;
  }
  
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  cin >> tc;

  string base_word;
  cin >> base_word;
  
  int base_freq[26];
  get_frequency(base_word, base_freq);

  int ans = 0;
  for (int i = 0; i < tc - 1; ++i) {
    string target_word;
    cin >> target_word;

    int target_freq[26];
    get_frequency(target_word, target_freq);

    if (is_similar(base_freq, target_freq)) {
      ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}