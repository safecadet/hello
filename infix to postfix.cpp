#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
	if (c == '^')
	{
        return 3;
    }
	else if (c == '/' || c == '*')
	{
    	return 2;
    }
	else if (c == '+' || c == '-')
    {
    	return 1;
    }
	else
	{
        return -1;
    }
}

void infixToPostfix(string s)
{

	stack<char> st; 
	string result;

	for (int i = 0; i < s.length(); i++)
    {
		char c = s[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
    		result += c;
        }
		else if (c == '(')
		{
            st.push('(');
        }
		else if (c == ')')
        {
			while (st.top() != '(') 
            {
				result += st.top();
				st.pop();
			}
			st.pop();
		}
		else {
			while (!st.empty()
				&& prec(s[i]) <= prec(st.top())) {
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
	}
	while (!st.empty()) {
		result += st.top();
		st.pop();
	}

	cout << result << endl;
}

int main()
{
	cout << "Enter the Expression : ";
	string exp;
	cin >> exp;
    int n = exp.length();
    int flag = 0;
    for(int i = 0;i< n - 1;i++)
    {
        if((exp[i] == '*' && exp[i+1] == '*') || (exp[i] == '/' && exp[i+1] == '/'))
        {
            flag = 1;
            break;
        }
    }
	if(flag == 1)
    {
        cout << "Invalid String\n";
    }
    else
    {	
      infixToPostfix(exp);
    }
	return 0;
}

