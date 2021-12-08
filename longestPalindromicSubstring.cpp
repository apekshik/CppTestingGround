#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		string result;
		int s_size = s.length();
        if (s_size == 1) return s;
		if (s_size == 0) return " ";

		int dpt[s_size][s_size]; // table for dynamic programming. 
		// populate dpt table with 0s. 
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < s.length(); j++) {
				dpt[i][j] = 0;
			}
		}
		// Setup first level of base case (which is top-left to bottom-right diagonal of matrix)
		for (int i = 0; i < s_size; ++i) {
			dpt[i][i] = 1;
		} 

		// Setup second level of base case (which is the level right above the 
		// longest diagonal). So, second longest diagonal.
		for (int i = 0; i < s_size - 1; i++) {
			if (s[i] == s[i+1]) 
				dpt[i][i+1] = 1;
			else 
				dpt[i][i+1] = 0;
		}

		
		// note to self: it's an iterative solution dumbass, not recursive.z
		for (int lenSubstring = 2; lenSubstring < s_size; lenSubstring++)
			for (int row_index = 0; row_index < s_size - lenSubstring + 1; row_index++) {
				// There needs to be two checks in every iteration:
				// 1) whether the first and last element of the substring are equal.
				// 2) whether the substring excluding the first and last element is a 
				//    valid palindrome.
				if (s[row_index] != s[row_index + lenSubstring]) 
					dpt[row_index][row_index + lenSubstring] = 0;
				else if (dpt[row_index + 1][row_index + lenSubstring - 1] == 1) 
					dpt[row_index][row_index + lenSubstring] = 1;
			}
		// Print function to see what dpt looks like.
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < s_size; j++)
				cout << dpt[i][j] << " "; 
			cout << endl;
		}
		// after filling table dpt, we find the substring of greatest length.
		int start = 0;// we use these to store the start index of the result.
		int maxPalLen = 0; // Length of the substring that is the largest palindrome. 
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < s_size; j++)
				if (dpt[i][j] == 1)
					if (abs(i - j) + 1 > maxPalLen) {
						maxPalLen = abs(i-j) + 1;
						start = i;
					}
		} 
		cout << start << endl;
		cout << maxPalLen << endl;
		return s.substr(start, maxPalLen);
    }
};