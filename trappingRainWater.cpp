#include <vector>
using namespace std;
class Solution1 {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        int waterTotal = 0;
        vector<int> maxL(sz, 0);
        vector<int> maxR(sz, 0);

        maxL[0] = height[0]; // contains the maximum height to the left of the ith box. 
        maxR[sz - 1] = height[sz - 1]; // contains the maximum height to the right of the ith box.
        // fill maxL and maxR. 
        for (int i = 1; i < sz; ++i) { // only need to compare the current index with the previous one to find new max each time. 
            maxL[i] = max(height[i], maxL[i - 1]);
            maxR[sz - i - 1] = max(height[sz - i - 1], maxR[sz - i]); // start from the end for maxR. 
        }

        // calculate how much water is stored at index i: min(maxL[i], maxR[i]) - height[i]; 
        int temp = 0;
        for (int i = 0; i < sz; ++i) {
            temp = min(maxL[i], maxR[i]) - height[i];
            if (temp > 0) waterTotal += temp;
        }

        return waterTotal;
    }
};