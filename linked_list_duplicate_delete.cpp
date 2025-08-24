#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include "LLnode.h"

using namespace std;
/**
 * Definition for singly-linked list.
 * LLnode.h
 * 
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
    ListNode* deleteDuplicates(ListNode* head) {
        
        //small List size edge cases
        if (!head || !head->next) return head;

        ListNode* trail = head, * lead = head->next;

        while (lead != nullptr) {
            //deletion program
            if (lead != nullptr && trail->val == lead->val) {
                lead = lead->next;
                //delete trail->next;
                trail->next = lead;
            }
            else {
                trail = lead;
                lead = lead->next;
            }
        }
        return head;
    }
};
