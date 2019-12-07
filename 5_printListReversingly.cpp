struct ListNode
{
	int value;
	ListNode *next;
};

void printListReversingly(ListNode *pHead)
{
	if (pHead == NULL)
		return ;

	if (pHead->next != NULL)
		printListReversingly(pHead->next);
	else
		cout << pHead->value << endl;
}