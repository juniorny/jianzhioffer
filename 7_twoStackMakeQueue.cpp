template<typename T> void CQueue<T>::appendTail(const T& element)
{
	stack1.push(element);
}


template<typename T> T CQueue<T>::deleteHead()
{

	if (stack2.size() <= 0)
	{
		while (stack1.size() > 0)
		{
			T& tmp = stack1.top();
			stack1.pop();
			stack2.push(tmp);
		}
	}

	if (stack2.size() == 0)
		throw new exception("queue is empty");

	T data = stack2.top();
	stack2.pop();

	return data;
}