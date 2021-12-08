#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode* y): val(x), next(y) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr) return head;

		ListNode dummy(INT16_MIN);
		ListNode* nHead = &dummy;
		dummy.next = head;
		ListNode* ahead = nHead; // Tail that moves ahead of the other pointer.
		ListNode* behind = nHead; // Tail that moves behind the ahead pointer. 
		// First move the ahead pointer by n+1 nodes so that it finds the end first.
		for (int i = 0; i <= n; i++) {
			ahead = ahead->next;
		}

		while (ahead != nullptr) {
			ahead = ahead->next;
			behind = behind->next;
		}

		behind->next = (behind->next)->next;
		// We can simply return the head we were given as an argument.
        return dummy.next;
    }
};

int main() {
	Solution S;
	
	return 0; 
}