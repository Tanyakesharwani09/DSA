class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int totalTime = 0;
        vector<int> freq(26, 0);

        // Count frequency of each task
        for (int i = 0; i < tasks.size(); i++) {
            char task = tasks[i];
            freq[task - 'A']++;
        }

        // Priority queue for task frequencies
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        // Process tasks
        while (!pq.empty()) {

            vector<int> remainingFreq;

            // Execute up to (n+1) tasks in this interval
            for (int i = 0; i < n + 1; i++) {
                if (!pq.empty()) {
                    int currentFreq = pq.top();
                    pq.pop();
                    currentFreq--;

                    remainingFreq.push_back(currentFreq);
                }
            }

            // Push remaining counts back into pq
            for (int i = 0; i < remainingFreq.size(); i++) {
                if (remainingFreq[i] > 0) {
                    pq.push(remainingFreq[i]);
                }
            }

            // Time calculation
            if (pq.empty()) {
                totalTime += remainingFreq.size();
            } else {
                totalTime += (n + 1);
            }
        }

        return totalTime;
    }
};
