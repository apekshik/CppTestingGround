#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {} 
};

class Solution {
public:

	ListNode* reverseList(ListNode* head) {
		if (head == nullptr) return head;

		ListNode* front = head->next; 
		ListNode* back = nullptr;

		// Probably the only important part of this algorithm. 
		// very important to think through each step.
		while (front != nullptr) {
			head->next = back;
			back = head;
			head = front;
			front = front->next;
		}

		head->next = back;
		return head;

	}
    ListNode* reverseList2(ListNode* head) {
        if (head == nullptr) return head;
        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp->next != nullptr) {
            st.push(temp);
            cout << temp->val; 
            temp = temp->next; 
        }
        head = temp; // temp currently holds pointer to last node.
        while (!st.empty()) {
            cout << temp->val;
            temp->next = st.top();
            temp = st.top();
            st.pop();
        }
        temp->next = nullptr;
        return head;
    }
};