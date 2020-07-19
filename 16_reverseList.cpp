ListNode *ReverseList(ListNode *pHead)
{

	ListNode *preNode = NULL;
	ListNode *node = pHead;
	ListNode *revsersedHead = NULL;

	while (node != NULL)
	{
		ListNode *nextNode = node->next;
		if (nextNode == NULL)
			revsersedHead = node;

		node->next = preNode;

		preNode = node;
		node = node->next;
	}

	return revsersedHead;
}


ListNode *ReverseListR(ListNode *pHead)
{
	if (pHead == NULL || pHead->next == NULL)
		return phead;

	ListNode *newHead = ReverseListR(pHead->next);

	pHead->next->next = pHead;
	pHead->next = NULL;

	return newHead;
}