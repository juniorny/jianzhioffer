BinaryTreeNode *Convert(BinaryTreeNode *pRootOfTree)
{
	BinaryTreeNode *pLastNodeInList = NULL;
	ConverNode(pRootOfTree, &pLastNodeInList);

	BinaryTreeNode *pHeadOfList = pLastNodeInList;
	while (pHeadOfList != NULL && pHeadOfList->left != NULL)
		pHeadOfList = pHeadOfList->left;

	return pHeadOfList;
}


void ConverNode(BinaryTreeNode *pNode, BinaryTreeNode **pLastNodeInList)
{
	if (pNode == NULL)
		return;

	BinaryTreeNode *pCurrent = pNode;

	if (pCurrent->left != NULL)
		ConverNode(pCurrent->left, pLastNodeInList);

	pCurrent->left = *pLastNodeInList;
	if (*pLastNodeInList != NULL)
		(*pLastNodeInList)->right = pCurrent;

	*pLastNodeInList = pCurrent；

	if (pCurrent->right != NULL)
		ConverNode(pCurrent->right, pLastNodeInList);

}