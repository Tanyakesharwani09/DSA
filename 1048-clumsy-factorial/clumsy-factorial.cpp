// class Solution {
// public:
//     int clumsy(int n) {
//         if (n <= 2) return n;
//         if (n == 3) return 6;
        
//         // Start with the first group: n * (n-1) / (n-2) + (n-3)
//         int result = n * (n - 1) / (n - 2) + (n - 3);
//         n -= 4;
        
//         // For remaining numbers, follow the pattern: - i * (i-1) / (i-2) + (i-3)
//         while (n >= 4) {
//             result = result - n * (n - 1) / (n - 2) + (n - 3);
//             n -= 4;
//         }
        
//         // Handle remaining numbers
//         if (n == 3) {
//             result -= n * (n - 1) / (n - 2);  // - 3 * 2 / 1
//         } else if (n == 2) {
//             result -= n * (n - 1);            // - 2 * 1
//         } else if (n == 1) {
//             result -= n;                      // - 1
//         }
        
//         return result;
//     }
// };

class Solution {
public:
    int clumsy(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 6;
        if (n == 4) return 7;
        if (n % 4 == 0) return n + 1;
        if (n % 4 == 1 || n % 4 == 2) return n + 2;
        return n - 1;
    }

};
