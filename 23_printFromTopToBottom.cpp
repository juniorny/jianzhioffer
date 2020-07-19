void PrintFromTopToBottom(BinaryTreeNode *pTreeRoot)
{
	if (!pTreeRoot)
		return;

	std::deque<BinaryTreeNode *> dequeTreeNode;

	dequeTreeNode.push_back(pTreeRoot);

	while (dequeTreeNode.size())
	{
		BinaryTreeNode *treeNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();

		printf("%d ", treeNode->value);

		if (treeNode->left)
			dequeTreeNode.push_back(treeNode->left);

		if (treeNode->right)
			dequeTreeNode.push_back(treeNode->right);
	}
}