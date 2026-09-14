class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        std::stack<char>st;
        while(i<s.size())
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else if(s[i] == ')')
            {
                if(!st.empty())
                {
                    char ch = st.top();
                    if (ch != '(')
                        return false;
                    st.pop();
                }
                else
                    return false;
            }
            else if(s[i] == '}')
            {
                if(!st.empty())
                {
                    char ch = st.top();
                    if (ch != '{')
                        return false;
                    st.pop();
                }
                else
                    return false;

            }
            else if(s[i] == ']')
            {
                if(!st.empty())
                {
                    char ch = st.top();
                    if (ch != '[')
                        return false;
                    st.pop();
                }
                else
                    return false;

            }
            i++;
        }
        return (st.empty());
        
    }
};
