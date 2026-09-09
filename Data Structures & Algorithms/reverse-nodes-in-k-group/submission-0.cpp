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

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;

        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    ListNode* getKthNode(ListNode* temp, int k) {
        while (temp && k > 1) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while (temp) {

            ListNode* kthNode = getKthNode(temp, k);

            if (kthNode == nullptr) {
                if (prevLast)
                    prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;

            ListNode* newHead = reverse(temp);

            if (temp == head)
                head = newHead;
            else
                prevLast->next = newHead;

            prevLast = temp;
            temp->next = nextNode;
            temp = nextNode;
        }

        return head;
    }
};