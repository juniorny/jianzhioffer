void MirrorRecursively(BinaryTreeNode *pNode)
{
	if (pNode == NULL || (pNode->left == NULL && pNode->right == NULL))
		return;

	BinaryTreeNode *tmp = pNode->left;
	pNode->left = pNode->right;
	pNode->right = tmp;

	if (pNode->left != NULL)
	{
		MirrorRecursively(pNode->left);		
	}

	if (pNode->right != NULL)
	{
		MirrorRecursively(pNode->right);
	}
}