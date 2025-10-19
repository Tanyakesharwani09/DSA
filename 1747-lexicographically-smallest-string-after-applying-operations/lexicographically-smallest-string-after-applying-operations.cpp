class Solution {
public:
    string rotate(string&s , int b){
        int n = s.size();
        string last = s.substr(0,b);
        string first = s.substr(b, n-b);
        return first + last ;
    }

    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string mini = s;
        queue<string>q;
        unordered_map<string, int>vis;
        q.push(s);
        vis[s] =1;

        while(!q.empty()){
            string node = q.front();
            q.pop();
            mini = min(mini , node);

            //rotate
            string rotatedNode =rotate(node , b);
            if(vis.find(rotatedNode) == vis.end()){
                q.push(rotatedNode);
                vis[rotatedNode] =1;
            }

            //odd indices add
            string cycleNode = node;
            for(int j=1; j<n; j+=2){
                int val = node[j] - '0';
                val = (val + a) % 10;
                cycleNode[j] = val + '0';
            }

            if(vis.find(cycleNode) == vis.end()){
                q.push(cycleNode);
                vis[cycleNode] = 1;
            }
        }
        return mini;
    }
};