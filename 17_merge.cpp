ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	else if (pHead2 == NULL)
		return pHead1;

	ListNode *pMergeHead;

	if (pHead1->value < pHead2->value)
	{
		pMergeHead = pHead1;
		pMergeHead->next = Merge(pHead1->next, pHead2);
	}
	else
	{
		pMergeHead = pHead2;
		pMergeHead->next = Merge(pHead2->next, pHead1);
	}

	return pMergeHead;
}