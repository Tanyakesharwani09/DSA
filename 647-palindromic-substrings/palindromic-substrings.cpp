class Solution {
public:
    // bool isPalindrome(string s,int i,int j){
    //     while(i<=j){
    //         if(s[i]!= s[j]) return false; 
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    // int countSubstrings(string s) {
    //     int ans=0;
    //     for(int i = 0 ; i< s.length() ; i++){
    //         for(int j =i ; j<s.length(); j++){
    //            if(isPalindrome(s,i,j)){
    //              ans++;
    //            }
    //         }
    //     }
    //     return ans;
    // }

    int expandIndex(string s , int i , int j){
        int count =0;
        while(i>=0 && j < s.length()  && s[i] == s[j]){
            count ++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s){
        int count =0;
        for(int i=0; i <s.length(); i++){
            //odd
            int oddKaAns = expandIndex(s, i , i);
            count = count + oddKaAns;

            //even 
            int evenkaAns = expandIndex(s,i,i+1);
            count = count + evenkaAns;
            
        }
        return count;
    }
};