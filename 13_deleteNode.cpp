void deleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
{
	if (pListHead == NULL || pToBeDeleted == NULL)
		return ;

	if (pToBeDeleted->next != NULL)
	{
		ListNode *p_next = pToBeDeleted->next;
		pToBeDeleted->value = p_next->value;
		pToBeDeleted->next = p_next->next;

		delete p_next;
		p_next = NULL;
	}
	else if (*pListHead == pToBeDeleted)
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	else
	{
		ListNode *tmp = *pListHead;
		while (tmp->next != pToBeDeleted)
			tmp = tmp->next;

		tmp->next = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}