//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。 
//
// 请你将两个数相加，并以相同形式返回一个表示和的链表。 
//
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。 
//
// 
//
// 示例 1： 
// 
// 
//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[7,0,8]
//解释：342 + 465 = 807.
// 
//
// 示例 2： 
//
// 
//输入：l1 = [0], l2 = [0]
//输出：[0]
// 
//
// 示例 3： 
//
// 
//输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//输出：[8,9,9,9,0,0,0,1]
// 
//
// 
//
// 提示： 
//
// 
// 每个链表中的节点数在范围 [1, 100] 内 
// 0 <= Node.val <= 9 
// 题目数据保证列表表示的数字不含前导零 
// 
//
// Related Topics 递归 链表 数学 👍 9119 👎 0

/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));// 创建一个空节点，后续就操作该指针
    struct ListNode *res = dummy;// 最后实际返回的
    int flag = 0;// 标记为，两数相加之后是否大于10
    int tmp1, tmp2;

    while (l1 != NULL || l2 != NULL) {
        if (l1 != NULL) {
            tmp1 = l1->val;
            l1 = l1->next;
        } else {
            tmp1 = 0;
        }
        if (l2 != NULL) {
            tmp2 = l2->val;
            l2 = l2->next;
        } else {
            tmp2 = 0;
        }
        int sum = tmp1 + tmp2 + flag;
        flag = sum / 10;
        int cur = sum % 10;
        dummy->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        dummy->next->val = cur;
        dummy->next->next = NULL;
        dummy = dummy->next;
    }
    if (flag) {
        dummy->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        dummy->next->val = flag;
        dummy->next->next = NULL;
    }
    return res->next;
}
// @lc code=end

