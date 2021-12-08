#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
		string tempStringBuilder; // although it's type string, it's acting as a stack for this solution. // We use this to build each solution which we then push into our result variable. 
		vector<string> digitsToLettersMap{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // Could've alternatively used a map. 
		// The two empty strings are there to reindex the digits 2-9 to the correct set of letters. Genius idea actually.

		if (digits != "" && digits.length() != 0) {
			int index = 0;
			dfs(digits, result, tempStringBuilder, digitsToLettersMap, index);
		}
		return result;

    }

private: 
	void dfs(string digits, vector<string> &result, string tempStringBuilder, vector<string> digitsToLetterMap, int index) {
		// Base case of recursion.
		if (index == digits.length()) {
			result.push_back(tempStringBuilder);
			return; 
		}

		int digit = digits[index] - '0'; // extract current digit with the correct INDEX.
		string letters = digitsToLetterMap[digit]; // extract the letters for the specific digit. 

		// This for loop is important. 
		for (int j = 0; j < letters.size(); j++) {
			tempStringBuilder.push_back(letters[j]);
			dfs(digits, result, tempStringBuilder, digitsToLetterMap, index + 1);
			tempStringBuilder.pop_back(); // This pop_back() is subtle but very crucial.
		}

		return; 
	}
};