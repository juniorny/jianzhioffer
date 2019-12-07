voi FindPath(BinaryTreeNode *pRoot, int expectedSum)
{
	if (!pRoot)
		return;

	std::vector<int> path;
	int currentSum = 0;
	FindPathRecurisvely(pRoot, expectedSum, path, currentSum);
}


void FindPathRecurisvely(BinaryTreeNode *pRoot, int expectedSum, std::vector<int> &path, int &currentSum)
{
	currentSum += pRoot->value;
	path.push_back(pRoot->value);

	bool isleaf = (pRoot->left == NULL && pRoot->right == NULL);
	if (isleaf && currentSum == expectedSum)
	{
		printf("A path is found: ");
		std::vector<int>::iterator iter = path.begin();
		for (; iter < path.end(); iter++)
			printf("%d\n", *iter);

		printf("\n");
	}

	if (pRoot->left)
		FindPathRecurisvely(pRoot->left, expectedSum, path, currentSum);
	if (pRoot->right)
		FindPathRecurisvely(pRoot->right, expectedSum, path, currentSum);

	currentSum -= pRoot->value;
	path.pop_back();
}