#ifndef _ARRAY_BASED_STACK_
#define _ARRAY_BASED_STACK_
#include "Main.h"

template<typename T>
class ArraybasedStack
{
private:
	T *m_array;
	int m_top;
	int m_size;
	int m_growSize;

private:
	bool Expand()
	{
		if (m_growSize <= 0)
			return false;
		assert(m_array != NULL);
		T *temp = new T[m_size + m_growSize];
		assert(temp != NULL);
		memcpy(temp, m_array, sizeof(T) * m_size);
		delete[] m_array;
		m_array = temp;
		m_size += m_growSize;
		return true;
	}

public:
	ArraybasedStack(int size, int growBy = 1) : m_size(0), m_top(-1), m_array(0), m_growSize(0)
	{
		if (size)
		{
			m_size = size;
			m_array = new T[m_size];
			assert(m_array != NULL);
			memset(m_array, 0, sizeof(T) * m_size);
			m_growSize = ((growBy < 0) ? growBy : 0);
		}
	}

	~ArraybasedStack()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}

	// Similar to insertion
	void push(T val)
	{
		assert(m_array != NULL);
			if (isFull())
				Expand();
		m_array[++m_top] = val;
	}

	// Similar to removal
	void pop()
	{
		if (!isEmpty())
			m_top--;
	}

	// Acces of top-most element
	const T& top()
	{
		assert(m_array != NULL);
		assert(m_top >= 0);
		return m_array[m_top];
	}

	int GetSize() { return m_top; }
	int GetMaxSize() { return m_size; }
	int isEmpty() { return (m_top == -1); }
	int isFull() { return (m_top == m_size - 1); }
};

#endif