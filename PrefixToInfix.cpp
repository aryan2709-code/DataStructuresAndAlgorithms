#include<iostream>
#include<stack>
using namespace std;

bool isOperand(char c)
{
if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') )
return true;
        
     return false;
}

string preToInfix(string pre_exp) {
        string str = pre_exp;
        int n = str.size();
        stack<string> st;
        int i = n-1;
        while(i >= 0)
        {
            char c = str[i];
            if(isOperand(c))
            {
                string temp = "";
                temp += c;
                st.push(temp);
            }
            else
            {
                string top1 = st.top(); st.pop();
                string top2 = st.top(); st.pop();
                
                string newStr = '(' + top1 + c + top2 + ')';
                st.push(newStr);
            }
            i--;
        }
        return st.top();
    }

    int main()
    {
        cout << preToInfix("/-AB+CD")<<endl;
        cout << preToInfix("-+A*BCD")<<endl;
    }