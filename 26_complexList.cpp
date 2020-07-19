void CloneNodes(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	while (pNode != NULL)
	{
		ComplexListNode *cloneNode = new ComplexListNode();

		cloneNode->value = pNode->value;
		cloneNode->m_pSibling = NULL;
		cloneNode->next = pNode->next;
		pNode->next = cloneNode;

		pNode = cloneNode->next;
	}
}

void ConnectSiblingNodes(ComplexListNode *pHead)
{

	ComplexListNode *pNode = pHead;
	while (pNode != NULL)
	{
		ComplexListNode *cloneNode = pNode->next;
		if (pNode->m_pSibling != NULL)
			cloneNode->m_pSibling = pNode->m_pSibling->next;
		pNode = cloneNode->next;
	}
}

ComplexListNode *ReconnectNodes(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	ComplexListNode *cloneNode = NULL;
	ComplexListNode *cloneHead = NULL;

	if (pNode != NULL)
	{
		cloneHead = cloneNode = pNode->next;
		pNode->next = cloneNode->next;
		pNode = pNode->next;
	}

	while (pNode != NULL)
	{
		cloneNode->next = pNode->next;
		cloneNode = pNode->next;
		pNode->next = cloneNode->next;
		pNode = pNode->next;
	}

	return cloneHead;
}