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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (0 == lists.size())    return nullptr;
        unsigned int start_pos = 0;
        unsigned int end_pos   = lists.size() - 1;
        
        return merge(lists, start_pos, end_pos);
    }

// 借用前面的合并两有序链表代码~, N个拆解为N/2对
private:
    ListNode* mergeTwo(ListNode* list1, ListNode* list2){
        if (nullptr == list1) return list2;
        if (nullptr == list2) return list1;

        if (list1->val <= list2->val){
            list1->next = mergeTwo(list1->next, list2);
            return list1;
        } else{
            list2->next = mergeTwo(list2->next, list1);
            return list2; 
        }
    }

    ListNode* merge(vector<ListNode* >& lists, unsigned int start, unsigned int end)
    {
        /* 如果存在落单的，直接返回落单的~ */
        if (start == end)    return lists[start];
        /* 两两合并直到只剩一个~ */
        int mid_pos = (start + end)>>1;
        return mergeTwo(merge(lists, start, mid_pos), merge(lists, mid_pos + 1, end));
    }
};