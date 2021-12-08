#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> st; // Stack to store the opening brackets in input string.
		char t; // temp variable to store the top value of the stack. 

		if (s.length() % 2 != 0) // check just in case the input string is odd length.
			return false;
		
		for (auto c : s) {
			if (c == '(' || c == '{' || c == '[') 
				st.push(c);
			else {
				t = st.top();  
				if (st.empty() || (t == '(' and c != ')') || (t == '{' and c != '}') || (t == '[' and c != ']')) 
					return false;
				st.pop();
			}
		}

		return st.empty();
		
	}
};
