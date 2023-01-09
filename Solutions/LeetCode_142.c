#include<vcruntime.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* detectCycle(struct ListNode* head)
{
	//1.空链表或单节点无环链表
	if (!head || !(head->next))
		return NULL;
	//2.快慢指针首次相遇时，慢指针距离环入口距离为k=m%n，其中m为非环部分长度，n为环长度
	struct ListNode* slow = head->next, * fast = head->next->next;
	while (slow != fast)
	{
		if (!fast)
			return NULL;
		slow = slow->next;
		fast = fast->next;
		if (!fast)
			return NULL;
		fast = fast->next;
	}
	//3.初始在头节点的指针与慢指针相遇在环的入口
	struct ListNode* p = head;
	while (p != slow)
	{
		p = p->next;
		slow = slow->next;
	}
	return p;
}