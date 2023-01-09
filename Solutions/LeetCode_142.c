#include<vcruntime.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* detectCycle(struct ListNode* head)
{
	//1.������򵥽ڵ��޻�����
	if (!head || !(head->next))
		return NULL;
	//2.����ָ���״�����ʱ����ָ����뻷��ھ���Ϊk=m%n������mΪ�ǻ����ֳ��ȣ�nΪ������
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
	//3.��ʼ��ͷ�ڵ��ָ������ָ�������ڻ������
	struct ListNode* p = head;
	while (p != slow)
	{
		p = p->next;
		slow = slow->next;
	}
	return p;
}