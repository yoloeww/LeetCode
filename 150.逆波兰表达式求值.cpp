class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for (auto t : tokens) {
            if (t == "+"|| t ==  "-" || t ==  "*" || t ==  "/") {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if (t == "+") st.push(num2 + num1);
                if (t == "-") st.push(num2 - num1);
                if (t == "*") st.push(num2 * num1);
                if (t == "/") st.push(num2 / num1);
            }
            else {
                st.push(stoll(t));
            }
        }
        long long res = st.top();
        st.pop();
        return res;
    }
};
