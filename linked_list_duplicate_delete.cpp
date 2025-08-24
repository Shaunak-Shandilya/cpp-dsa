#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include "LLnode.h"

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        //small List size edge cases
        if (head == nullptr) return head;
        if (head->next == nullptr) return head;

        ListNode* trail = head, * lead = head;

        while (lead != nullptr) {
            
            lead = lead->next;

            //deletion program
            if (lead != nullptr &&  trail->val == lead->val) {
                lead = lead->next;
                free(trail->next);
                trail->next = lead;
            }
            trail = lead;
        }
        return head;
    }
};
