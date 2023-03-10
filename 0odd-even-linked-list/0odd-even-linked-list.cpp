/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *oddNode = head, *evenNode = head->next, *firstEvenNode = head->next;
        
        while(oddNode != NULL && evenNode != NULL) {
            oddNode->next = evenNode->next;
            if(evenNode->next) {
                evenNode->next = evenNode->next->next;
            }
            else break;
            oddNode = oddNode->next;
            evenNode = evenNode->next;
        }
        
        oddNode->next = firstEvenNode;
        return head;
    }
};