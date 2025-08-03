class Solution {
public:
    bool isValid(string s){
        if (s.size() % 2 != 0) return false;
        stack<char>st;
        for(int i =0; i<s.length() ; i++){
            char ch = s[i];
            if(ch == '(' || ch =='[' || ch =='{'){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    char topElement = st.top();
                    if(topElement == '(' && ch ==')'){
                        st.pop();
                    }
                    else if(topElement == '[' && ch ==']'){
                        st.pop();
                    }
                    else if(topElement == '{' && ch =='}'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
         if(st.empty()){
                return true;
            }
            else{
                return false;
            }
    }

    // bool isValid(string s){
    //     if (s.size() % 2 != 0) return false;
    //     stack<char>st;
    //     for(int i=0; i<s.length(); i++){
    //         char ch = s[i];
    //         if(ch=='(' || ch == '{' || ch == '['){
    //             st.push(ch);
    //         }
    //         else{
    //             if( !st.empty()){
    //                 char topch = st.top();
    //                 if(ch==')' && topch == '('){
    //                     st.pop();
    //                 }
    //                 else if(ch=='}' && topch == '{'){
    //                     st.pop();
    //                 }
    //                  else if(ch==']' && topch == '['){
    //                     st.pop();
    //                 }
    //                 else{
    //                     return false;
    //                 }
    //             }
    //             else{
    //                 return false;
    //             }
    //         }
    //     }
    //     if(st.empty()){
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }
    // }

   
};