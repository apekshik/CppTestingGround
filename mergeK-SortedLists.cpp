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
	// Custom comparotor (which is a functor: a class that acts as a function) for the priority queue to use to compare two nodes. 
	struct myComparator {
		bool operator()(ListNode* n1, ListNode* n2) {
			return n1->val > n2->val;
		}
	};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		// Always cover base, trivial, and edge cases.
        if (lists.size() == 0 || lists.empty() == true)
			return NULL;
			
		// We setup our priority queue which maintains a vector of ListNode* pointers. 
		// We pass in our custom comparotor that the container will use to maintain the 
		// priority queue. Note: myComparator doesn't need to be followed by () for some reason. Odd.
        priority_queue<ListNode*, vector<ListNode*>, myComparator> pq; 

		// Next, we iterate through the given lists-vector and dump each node-pointer into the priority-queue.
		int listSize = lists.size();
		for (int i = 0; i < listSize; i++)
			if (lists.at(i)) // This if check is important to handle an edge case where you might be passed a null node. 
				pq.push(lists.at(i)); // We could've used the [] operator, but .at() is safer 
			// because it throws exception when index accessed is out of bound.

		// We then simply pop out elements from the priority-queue and attach them to a new head pointer 
		// and return the head->next as our answer. 
		ListNode dummy(0);
		ListNode* head = &dummy;
		ListNode* tail = head; // tail pointer needed to create our linked list. 
		// for a pq, you see the topmost element using top(), and delete it (no return value) using pop(). 
		while (!pq.empty()) {
			ListNode* temp = pq.top();
			tail->next = temp;
			tail = tail->next;
			pq.pop();
			if (temp->next) 
				pq.push(temp->next);
		}
		// Finally, assign the tail pointer's (which is pionting to the last node) next pointer to NULL to end the linked list. 
		tail->next = nullptr;

		return dummy.next; // alternatively head->next;
    }
};