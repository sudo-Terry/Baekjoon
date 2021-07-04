#include <iostream>
#include <string>
#include <stack>

using namespace std;

//알고리즘 > 숫자를 저장하는 자료구조와 수식을 저장하는 자료구조를 따로 만든다.
//수식을 저장하는 자료구조에서 - 뒤의 +들은 전부 -로 변환하고 다시 수식을 구성하여 계산한다.

int main(void) {
    string input ="";
    string tempnum = "";
    int num = 0;
    bool flag = false;
    bool firstflag = true;
    char tempchar = '+';

    cin >> input;

    //중위표기식을 후위표기식으로 변환


    //계산
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '-' || input[i] == '+') { //수식에서 - +일경우
            if (flag) { //앞에 -가 나왔으면 무조건 -처리
                num -= stoi(tempnum);
            }
            else if (tempchar == '-') { //앞에 -가 안나왔으면 문자에 알맞게 + 또는 -처리
                flag = true;
                num -= stoi(tempnum);
            }
            else {
                num += stoi(tempnum);
            }
            if (input[i] == '+') {
                tempchar = '+';
            }
            else {
                tempchar = '-';
            }
            tempnum = "";
        } 
        else { //수식에서 숫자일 경우 임시로 저장
            tempnum += input[i]; 
        }
    }
    if (flag) { //앞에 -가 나왔으면 무조건 -처리
        num -= stoi(tempnum);
    }
    else if (tempchar == '-') { //앞에 -가 안나왔으면 문자에 알맞게 + 또는 -처리
        flag = true;
        num -= stoi(tempnum);
    }
    else {
        num += stoi(tempnum);
    }


    cout << num;

    return 0;
}