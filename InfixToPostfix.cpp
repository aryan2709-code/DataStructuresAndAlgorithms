#include<iostream>
#include<stack>
using namespace std;

    int priority(char c)
    {
        if(c == '^')
        return 3;
        else if(c == '*' || c == '/')
        return 2;
        else if(c == '+' || c == '-')
        return 1;
        
        return -1;
    }
    bool isOperand(char c)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') )
        return true;
        
        return false;
    }
    string infixToPostfix(const string& s) {
        int n = s.size();
        stack<char> st;   //Operators will be handled here
        string ans = ""; //Operands will be added here
        int i=0;
        while(i < n)
        {
            char c = s[i];
            if(isOperand(c))
            ans += c;
            else if(c == '(')
            st.push(c);
            else if(c == ')')
            {
                while(!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop(); // Popping the opening bracket
            }
            else //Operator
            {
                // We can only push a operator to the stack if and only if
                // the top most operator present at the stack has a lesser 
                // priority than the current operator in hand
                while(!st.empty() && priority(st.top()) >= priority(c))
                {
                   ans += st.top();
                   st.pop(); 
                }
                st.push(c);
            }
            i++;
        }
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }

    int main()
    {
        cout << infixToPostfix("a+b*c-d") << endl;
        cout << infixToPostfix("x*(y-z+w)/v")<<endl;
        return 0;
    }
