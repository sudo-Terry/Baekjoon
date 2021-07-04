#include <iostream>
#include <stack>
using namespace std;

string infix;
stack<char> st;

void solve() {

    for (int i = 0; i < infix.length(); i++){
        if (infix[i] >= 'A' && infix[i] <= 'Z')
            cout << infix[i];
        else{
            if (infix[i] == '(')
                st.push(infix[i]);
            else if (infix[i] == '*' || infix[i] == '/'){
                while (!st.empty() && (st.top() == '*' || st.top() == '/')){
                    cout << st.top();
                    st.pop();
                }
                st.push(infix[i]);
            }
            else if (infix[i] == '+' || infix[i] == '-'){
                while (!st.empty() && st.top() != '('){
                    cout << st.top();
                    st.pop();
                }
                st.push(infix[i]);
            }
            else if (infix[i] == ')'){
                while (!st.empty() && st.top() != '('){
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            }
        }
    }
    while (!st.empty()){
        cout << st.top();
        st.pop();
    }
}

int main() {
	cin >> infix;
	solve();
}