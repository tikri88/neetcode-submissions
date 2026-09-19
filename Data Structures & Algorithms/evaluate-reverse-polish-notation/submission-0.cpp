class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>stRp;
        for(auto token : tokens)
        {
            if(token != "+" && token != "-" && token != "*" && token != "/")
            {
                int val = stoi(token);
                stRp.push(val);
            }
            else
            {
                int val1 = stRp.top();
                stRp.pop();
                int val2 = stRp.top();
                stRp.pop();
                switch(token[0]) //Extract first char, last car is end of string char \0
                {
                    case '+':
                        stRp.push(val2+val1);
                        break;
                    case '-':
                        stRp.push(val2-val1);
                        break;
                    case '*':
                        stRp.push(val2*val1);
                        break;
                    case '/':
                        stRp.push(val2/val1);
                        break;
                }
            }
        }
        return stRp.top();
    }
};
