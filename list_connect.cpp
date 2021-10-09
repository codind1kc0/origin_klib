
/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode() : val(0), next(nullptr) {}
 *       *     ListNode(int x) : val(x), next(nullptr) {}
 *        *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 *         * };
 *          */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if ( !l1 )    return l2;
        if ( !l2 )    return l1;
        
        ListNode* list1 = l1, *list2 = l2;
        ListNode  pro2_front(-111, l2);
        ListNode* pro2  = &pro2_front;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                ListNode* tmp = list1->next;
                add_node(pro2, list1);  
                pro2  = list1;  
                list1 = tmp;
            } else if (list2->val <= list1->val) {
                pro2  = list2;
                if ( (list1 != nullptr) && (list2->next == nullptr) ) {
                    list2->next = list1;
                    break;
                }
                list2 = list2->next;
            }
        }
 
         ListNode* ret = pro2_front.next;
         

         return ret;
     }

 private:
     void  add_node(ListNode* old_node, ListNode* new_add)
     {
         new_add ->next = old_node->next;
         old_node->next = new_add;
     }
 };
