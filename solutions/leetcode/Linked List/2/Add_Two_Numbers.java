//https://leetcode.com/problems/add-two-numbers/submissions/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Add_Two_Numbers {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
                ListNode curr = l1;
        ListNode curr2 = l2; 
        ListNode ans = new ListNode(0);
        ListNode advance = ans;
        boolean plusOne = false;
        //or b/c l1.length != l2.length all the time
        while (curr != null || curr2 != null) {
            int sum = 0;
            if (curr == null) {
                sum += curr2.val;
                curr2 = curr2.next;
            } else if (curr2 == null) {
                sum += curr.val;
                curr = curr.next;
            } else {
                sum += curr.val + curr2.val;
                curr = curr.next;
                curr2 = curr2.next;
            }
            if (plusOne) {
                sum++;
            }
            if (sum >= 10) {
                sum -= 10;
                plusOne = true;
            } else {
                plusOne = false;
            }
            //advance.print();
            ListNode n = new ListNode(sum);
            //have to do next 2 lines to prevent NPS on advance.next
            advance.next = new ListNode(0);
            advance = advance.next;
        }
        if (plusOne) {
            //if carry over is on last 2 nodes
            advance.next = new ListNode(1);
        }
        return ans.next;
    }
}