#include <iostream>
#include <string>
#include <stack>

using namespace std;

//�˰��� > ���ڸ� �����ϴ� �ڷᱸ���� ������ �����ϴ� �ڷᱸ���� ���� �����.
//������ �����ϴ� �ڷᱸ������ - ���� +���� ���� -�� ��ȯ�ϰ� �ٽ� ������ �����Ͽ� ����Ѵ�.

int main(void) {
    string input ="";
    string tempnum = "";
    int num = 0;
    bool flag = false;
    bool firstflag = true;
    char tempchar = '+';

    cin >> input;

    //����ǥ����� ����ǥ������� ��ȯ


    //���
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '-' || input[i] == '+') { //���Ŀ��� - +�ϰ��
            if (flag) { //�տ� -�� �������� ������ -ó��
                num -= stoi(tempnum);
            }
            else if (tempchar == '-') { //�տ� -�� �ȳ������� ���ڿ� �˸°� + �Ǵ� -ó��
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
        else { //���Ŀ��� ������ ��� �ӽ÷� ����
            tempnum += input[i]; 
        }
    }
    if (flag) { //�տ� -�� �������� ������ -ó��
        num -= stoi(tempnum);
    }
    else if (tempchar == '-') { //�տ� -�� �ȳ������� ���ڿ� �˸°� + �Ǵ� -ó��
        flag = true;
        num -= stoi(tempnum);
    }
    else {
        num += stoi(tempnum);
    }


    cout << num;

    return 0;
}