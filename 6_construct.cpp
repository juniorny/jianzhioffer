struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* left_child;
	BinaryTreeNode* right_child;
};

BinaryTreeNode* constructCore(int *preorderStart, int *preorderEnd, int *inorderStart, int *inorderEnd)
{
	int root_value = preorderStart[0];
	BinaryTreeNode *root = new BinaryTreeNode();
	root->value = root_value;
	root->left_child = NULL;
	root->right_child = NULL;

	if (preorderStart == preorderEnd)
	{
		if (inorderStart == inorderEnd && *preorderStart == *inorderStart)
			return root;
		else
			throw std::exception("Invaild input");
	}

	int *root_inorder = inorderStart;
	while (root_inorder <= inorderEnd && *root_inorder != root_value)
		root_inorder++;

	int left_len = root_inorder - inorderStart;

	if (left_len > 0)
		root->left_child =  constructCore(preorderStart + 1, preorderStart + left_len, inorderStart, root_inorder - 1);
	if (left_len < preorderEnd - preorderStart)
		root->right_child =  constructCore(preorderStart + left_len + 1, preorderEnd, root_inorder + 1, inorderEnd);

	return root;
}

BinaryTreeNode* construct(int *preorder, int *inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;

	return constructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);

}