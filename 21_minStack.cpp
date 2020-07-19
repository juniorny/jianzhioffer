template <template T> void StackWithMin<T>::push(const T& value)
{
	m_data.push(value);

	if (min_data.size() == 0 || min_data.top() > value)
		min_data.push(value);
	else
		min_data.push(min_data.top());
}


template <template T> void StackWithMin<T>::pop()
{
	assert(m_data.size() > 0 && min_data.size() > 0);

	m_data.pop();
	min_data.pop();
}


template <template T> T& StackWithMin<T>::min()
{
	assert(m_data.size() > 0 && min_data.size() > 0);
	
	return min_data.top();
}