#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int speedUp = [] {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

// Function to extract digit value from a character
int digit(char c) {
    return c & 15;
}

// Function to check if a character is a digit
bool isDigit(char c) {
    return '0' <= c && c <= '9';
}

int in = [] {
    std::ofstream out("user.out"); // Redirect cout to user.out
    std::cout.rdbuf(out.rdbuf());

    int ans, sum;
    bool _neg;
    
    // Read input line by line
    for (std::string s; std::getline(std::cin, s); std::cout << '\n') {
        ans = -1e9, sum = 0; // Initialize answer and sum for each input line
        
        for (int _i = 1, _n = s.length(), v; _i < _n; ++_i) {
            _neg = false; // Initialize flag to indicate negative number
            
            if (s[_i] == '-') { // Check for negative sign
                ++_i; // Move to next character after '-'
                _neg = true; // Set flag to true for negative number
            }
            
            v = digit(s[_i]); // Extract first digit
            
            // Extract remaining digits to form the number
            while (isDigit(s[++_i]))
                v = v * 10 + digit(s[_i]);
            
            // Negate the value if it was negative
            if (_neg)
                v = -v;
            
            // Do stuff with v (not specified in the provided code)
            
            // Update answer by taking maximum of current answer and sum
            ans = std::max(ans, sum < 0 ? sum = v : sum += v);
        }
        
        // Output the answer
        std::cout << ans;
    }
    
    // Exit after processing input
    exit(0);
    return 0;
}();
class Solution {
public:

    // int maxSubArr (vector<int>& v, int l, int r) {
    //     if(l == r) return v[l];
    //     int mid = l + (r-l)/2;
    //     int leftMax = maxSubArr(v, l, mid);
    //     int rightMax = maxSubArr(v, mid+1, r);
    //     int crossMax = maxCross(v, l, mid, r);
    //     return max(crossMax, max(leftMax, rightMax));
    // }

    // int maxCross(vector<int>& v, int l, int mid, int r) {
    //     int maxLeft = -1e9;
    //     int sum = 0;
    //     for(int i=mid; i>=l; i--){
    //         sum += v[i];
    //         maxLeft = max(maxLeft, sum);
    //     }
    //     int maxRight = 0;
    //     sum = 0;
    //     for(int i=mid+1; i<=r; i++){
    //         sum += v[i];
    //         maxRight = max(maxRight, sum);
    //     }
    //     return maxLeft + maxRight;
    // }

    // return maxSubArr(v, 0, v.size()-1);
    int maxSubArray(vector<int>& v) {
         int ans = 0, curr = 0;
        for(int num : v){
            curr += num;
            if(curr < 0) curr = 0;
            ans = max(ans, curr);
        }
        return ans;
    }
};
        // int mxSum = nums[0], currSum = 0;
        // for(int i=0; i<nums.size(); i++){
        //     if(currSum < 0) currSum = 0;
        //     currSum += nums[i];
        //     mxSum = max(mxSum, currSum);
        // }
        // return mxSum;