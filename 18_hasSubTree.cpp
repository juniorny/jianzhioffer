bool DoesTree1HaveTree2(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
	if (pRoot1 == NULL)
		return false;

	if (pRoot2 == NULL)
		return true;

	if (pRoot1->value != pRoot2->value)
		return false;

	return (DoesTree1HaveTree2(pRoot1->left, pRoot2->left) 
			&& DoesTree1HaveTree2(pRoot1->right, pRoot2->right));
}

bool HasSubtree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
	bool result = false;

	if (pRoot1 != NULL && pRoot2 != NULL)
	{
		if (pRoot1->value == pRoot2->value)
		{
			result = DoesTree1HaveTree2(pRoot1, pRoot2);
		}

		if (!result)
		{
			result = HasSubtree(pRoot1->left, pRoot2);
		}

		if (!result)
		{
			result = HasSubtree(pRoot1->right, pRoot2);
		}
	}

	return result;
}