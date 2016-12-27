#pragma once
#include "iostream";
#include <vector>;

using namespace std;

/*
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class HouseHeater {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* resultHead = new ListNode(0);

        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        int remainder = 0;
        while (curr1 != NULL || curr2 != NULL)
        {
            int v1 = 0;
            int v2 = 0;
            if (curr1 != NULL)
            {
                v1 = curr1->val;
                curr1 = curr1->next;
            }

            if (curr2 != NULL)
            {
                v2 = curr2->val;
                curr2 = curr2->next;
            }

            int result = (v1 + v2) % 10 + remainder;
            remainder = (v1 + v2) / 10;
            ListNode* node = new ListNode(result);
            // ListNode* nodeR = new ListNode(remainder);

            //build result and remainder
            ListNode* temp = resultHead->next;
            resultHead->next = node;
            node->next = temp;

        }
        //last node
        if (remainder != 0)
        {
            ListNode* node = new ListNode(remainder);
            ListNode* temp = resultHead->next;
            resultHead->next = node;
            node->next = temp;
        }

        ListNode* currNode = resultHead->next;
        while (currNode->next != NULL)
        {
            ListNode* temp = currNode->next;
            currNode->next = temp->next;
            temp->next = resultHead->next;
            resultHead->next = temp;
        }

        return resultHead->next;

    };

    void testItself()
    {
        ListNode* l1 = new ListNode(2);
        ListNode n2(4);
        ListNode n3(3);
        //ListNode n4(4);
        l1->next = &n2;
        n2.next = &n3;
        //n3.next = &n4;

        ListNode* l2 = new ListNode(5);
        ListNode nn2(6);
        ListNode nn3(4);
        // ListNode nn4(6);
        l2->next = &nn2;
        nn2.next = &nn3;
        // nn3.next = &nn4;

        ListNode* result = addTwoNumbers(l1, l2);
        while (result != NULL)
        {
            cout << result->val << endl;
            result = result->next;
        }
    }
};
