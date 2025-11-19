class Solution {
public:
    // string reorganizeString(string s) {
    //     int hash[26]={0};

    //     for(int i=0; i <s.size(); i++){
    //         hash[s[i]- 'a']++;
    //     }//O(n);

    //     //find the most frequent char
    //     char max_freq_char;
    //     int max_freq = INT_MIN;
    //     for(int i =0; i<26 ; i++){
    //         if(hash[i] >max_freq){
    //             max_freq = hash[i];
    //             max_freq_char = i + 'a';
    //         }
    //     }

    //     int index=0;
    //     while(max_freq >0 && index < s.size()){
    //         s[index] = max_freq_char;
    //         max_freq--;
    //         index +=2;
    //     } //O(n)

    //     if(max_freq !=0){
    //         return "";
    //     }

    //     hash[max_freq_char - 'a']=0;

    //     //let's place the rest of the characters
    //     for(int i=0; i<26; i++){
    //         while(hash[i] >0){
    //             index = index >= s.size() ? 1 : index;
    //             s[index] = i + 'a';
    //             hash[i] --;
    //             index +=2;
    //         }
    //     } //O(n)
    //     return s;
    // }

    class Info{
        public:
        char val;
        int count;
        Info(char ch, int cnt){
            this->val = ch;
            this->count = cnt;
        }
    };

    class compare{
        public:
        bool operator()(Info*a , Info*b){
            return (a->count < b->count);
        }
    };

    string reorganizeString(string s){

        int freq[26]={0};
        for(int i =0 ; i< s.size(); i++){
            char ch = s[i];
            freq[ch - 'a']++;
        }

        priority_queue<Info* , vector<Info*> , compare>pq;
        for(int i =0; i<26; i++){
            if(freq[i] >0){
                Info* temp = new Info(i+'a' , freq[i]);
                pq.push(temp);
            }
        }
        string ans="";

        while(pq.size() >1){
            Info* top1 = pq.top();
            pq.pop();
            Info* top2 = pq.top();
            pq.pop();

            ans.push_back(top1->val);
            top1->count--;

            ans.push_back(top2->val);
            top2->count--;

            if(top1->count >0){
                pq.push(top1);
            }
            if(top2->count >0){
                pq.push(top2);
            }
        }
        if(pq.size() ==1){
            Info*first = pq.top();
            pq.pop();
        
        ans.push_back(first->val);
        first->count--;
        if(first->count != 0){
            return "";
        }
        }
        return ans;
    }
    
};