class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(string token:tokens){
            // we will check for operator
             if(token=="+"||token=="-"||token=="*"||token=="/"){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();

                // now the calculation accordingly and push the solution
                if (token == "+") {
                   st.push(a + b);
                }
                else if (token == "-") {
                   st.push(a - b);
                }
                else if (token == "*") {
                   st.push(a * b);
                }
                else {
                  st.push(a / b);
                }   
             }
             // we have number
             // string to integer conversion is important
             else{
                st.push(stoi(token));
             }
        }
        return st.top();
    }
};
