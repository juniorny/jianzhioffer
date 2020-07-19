bool IsBalanced(BinaryTreeNode *pRoot, int *pDepth)
{
	if (pRoot == NULL)
	{
		*pDepth = 0;
		return true;
	}

	int left, right;
	if (IsBalanced(pRoot->left, &left)
		&& IsBalanced(pRoot->right, &right))
	{
		int diff = left - right;
		if (diff <= 1 && diff >= -1)
		{
			*pDepth = 1 + (left > right ? left : right);
			return true;
		}
	}

	return false;
}