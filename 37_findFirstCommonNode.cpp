ListNode *findFirstCommonNode(ListNode *pHead1, ListNode *phead2)
{
	unsigned int nLength1 = GetListLength(pHead1);
	unsigned int nLength2 = GetListLength(pHead2);

	int nLengthDiff = nLength1 - nLength2;

	ListNode *pListHeaadLong = pHead1;
	ListNode *pListHeaadShort = pHead2;

	if (nLength2 > nLength1)
	{
		pListHeaadLong = pHead2;
		pListHeaadShort = pHead1;
		nLengthDiff = nLength2 - nLength1;
	}

	for (int i = 0; i < nLengthDiff; i++)
		pListHeaadLong = pListHeaadLong->next;

	while (pListHeaadLong != NULL 
		&& pListHeaadShort != NULL 
		&& pListHeaadLong != pListHeaadShort)
	{
		pListHeaadLong = pListHeaadLong->next;
		pListHeaadShort = pListHeaadShort->next;
	}

	return pListHeaadLong;
}

unsigned int GetListLength(ListNode *pHead)
{
	int len = 0;
	ListNode *pNode = pHead;

	while (pNode != NULL)
	{
		len++;
		pNode = pNode->next;
	}

	return len;
}