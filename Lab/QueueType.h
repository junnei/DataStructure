#pragma once
#include <iostream>

using namespace std;

#define MAX_ITEMS 30

/**
*	@brief	ť�� ��á�� �� ���� Ŭ����.
*/
class FullQueue
{
public:
	/**
	*	@brief	ť�� ��á�� �� �޼��� ���.
	*/
	void print()
	{
		cout << "FullQueue exception thrown." << endl;
	}
};

/**
*	@brief	ť�� ����� �� ���� Ŭ����.
*/
class EmptyQueue
{
public:
	/**
	*	@brief	ť�� ����� �� �޼��� ���.
	*/
	void print()
	{
		cout << "EmtpyQueue exception thrown." << endl;
	}
};

/**
*	@brief	ť Ŭ����.
*/
template <class T>
class CircularQueueType
{
public:
	/**
	*	@brief	MAX_ITEMS��ŭ�� ����� ���� ť�� �ʱ�ȭ�Ѵ�.
	*	@pre	MAX_ITEMS�� ���ǵǾ���Ѵ�.
	*	@post	�Ҵ�� ����Ʈ�� ����Ų��.
	*/
	CircularQueueType();

	/**
	*	@brief	max��ŭ�� ����� ���� ť�� �ʱ�ȭ�Ѵ�.
	*	@pre	max�� ���ǵǾ���Ѵ�.
	*	@post	�Ҵ�� ����Ʈ�� ����Ų��.
	*	@param	ť�� ������
	*/
	CircularQueueType(int max);

	/**
	*	@brief	�Ҹ���
	*/
	~CircularQueueType();

	/**
	*	@brief	ť�� ��á���� Ȯ���Ѵ�.
	*	@pre	ť�� �ʱ�ȭ �Ǿ���Ѵ�.
	*	@post	����.
	*	@return	ť�� ��á���� 1, �ƴ� ��쿡 0�� ���.
	*/
	bool IsFull();

	/**
	*	@brief	ť�� ������� Ȯ���Ѵ�.
	*	@pre	ť�� �ʱ�ȭ �Ǿ���Ѵ�.
	*	@post	����.
	*	@return	ť�� ������� 1, �ƴ� ��쿡 0�� ���.
	*/
	bool IsEmpty();

	/**
	*	@brief	ť���� ������ ��� �����Ѵ�.
	*	@pre	ť�� �����ؾ��Ѵ�.
	*	@post	ť�� �������.
	*/
	void MakeEmpty();

	/**
	*	@brief	ť�� ���ο� �ڷḦ �߰��Ѵ�.
	*	@pre	ť�� �����ؾ��Ѵ�.
	*	@post	ť�� ���ο� �ڷḦ �߰��ȴ�.
	*/
	void EnQueue(T newItem);

	/**
	*	@brief	ť�� ���� ���� ���� �ڷ���� ����Ѵ�.
	*	@pre	ť�� �����ؾ��Ѵ�.
	*	@post	ť�� �����͸� �����Ѵ�.
	*/
	void DeQueue(T& item);

	/**
	*	@brief	ť�� ��� �������� ����Ѵ�
	*	@pre	ť�� �����ؾ��Ѵ�.
	*	@post	����.
	*/
	void Print();

	/**
	*	@brief	m_iFront�� ����Ѵ�
	*	@pre	ť�� �����ؾ��Ѵ�.
	*	@post	����.
	*	@return m_iFront
	*/
	int Front();

	/**
	*	@brief	m_iRear�� ����Ѵ�
	*	@pre	ť�� �����ؾ��Ѵ�.
	*	@post	����.
	*	@return m_iRear 
	*/
	int Rear();

	/**
	*	@brief	m_nMaxQueue�� ����Ѵ�
	*	@pre	ť�� �����ؾ��Ѵ�.
	*	@post	����.
	*	@return m_nMaxQueue
	*/
	int MAX();

	/**
	*	@brief	ť�� �������� �����ϸ� �����Ѵ�.
	*	@pre	ť�� �����ؾ��Ѵ�.
	*	@post	�������� �����ȴ�.
	*	@return ������ �����ϸ� 1��, �ƴѰ�쿡 0�� ��ȯ�Ѵ�.
	*/
	int Deduplication(T inData);

private:
	int m_iFront;			//ť�� ���� ��Ÿ���� �÷���
	int m_iRear;			//ť�� �ڸ� ��Ÿ���� �÷���
	int m_nMaxQueue;		//ť�� ������
	T* m_pItems;		// ������Ÿ�� ������ ����

};


/***********************************************************************************************************************************************************/

// Allocate dynamic array whose size is MAX_ITEMS 30.
template <class T>
CircularQueueType<T>::CircularQueueType()
{
	m_nMaxQueue = MAX_ITEMS + 1;		// ���� ť�� �ִ� ũ�⸦ MAX_ITEM +1�� �����ؼ� ��ĭ�� ����Ѵ�.
	m_iFront = m_nMaxQueue - 1;		// ���� ť�� ���θ� �ִ�ũ�� -1 �� ����
	m_iRear = m_nMaxQueue - 1;			// ���� ť�� �Ĺ̸� �ִ�ũ�� -1 �� ����
	m_pItems = new T[m_nMaxQueue];
}

// ť�� ����� �޾ƿ� ��ŭ �Ҵ����ش�.
template <class T>
CircularQueueType<T>::CircularQueueType(int max)
{
	m_nMaxQueue = max + 1;			// ���� ť�� �ִ� ũ�⸦ max�� �����ؼ� ��ĭ�� ����Ѵ�.
	m_iFront = m_nMaxQueue - 1;			// ���� ť�� ���θ� �ִ�ũ�� -1 �� ����
	m_iRear = m_nMaxQueue - 1;			// ���� ť�� �Ĺ̸� �ִ�ũ�� -1 �� ����
	m_pItems = new T[m_nMaxQueue];
}

// Destruct the object. Free the array dynamically allocated.
template <class T>
CircularQueueType<T>::~CircularQueueType()
{
	delete[] m_pItems;
}

// Determines whether the queue is full.
template <class T>
bool CircularQueueType<T>::IsFull()
{
	if ((m_iRear + 1) % m_nMaxQueue == m_iFront)  // ���ο� �Ĺ��� ��ġ�� ���Ͽ� ť�� �����ִ��� Ȯ��. �Ĺ̰� ���θ� �����ϸ� �ȵ�.
		return true;
	else
		return false;
}

// Determines whether the queue is empty.
template <class T>
bool CircularQueueType<T>::IsEmpty()
{
	if (m_iFront == m_iRear) // ���ο� �Ĺ��� ��ġ�� ���Ͽ� ť�� ����ִ��� Ȯ��
		return true;
	else
		return false;
}

//ť�� ����ش�.
template <class T>
void CircularQueueType<T>::MakeEmpty()
{
	m_iFront = m_iRear;				// ���ο� �Ĺ��� ��ġ�� ���� �Ͽ� ť�� ���
}

// Adds newItem to the top of the queue.
template <class T>
void CircularQueueType<T>::EnQueue(T newItem)
{
	if (IsFull())
	{
		throw FullQueue();
	}
	else
	{
		m_iRear = (m_iRear + 1) % m_nMaxQueue;		// ť�� ������ �ʾҴٸ� �Ĺ��� ��ġ�� �Ѵܰ� �ű��
		m_pItems[m_iRear] = newItem;				// �ű� ��ġ�� ���ο� ������ �迭�� �߰�
	}
}

// Removes top item from the queue.
template <class T>
void CircularQueueType<T>::DeQueue(T& item)
{
	if (IsEmpty())
	{
		throw EmptyQueue();
	}
	else
	{
		m_iFront = (m_iFront + 1) % m_nMaxQueue;		// ť�� ������� �ʴٸ� ������ ��ġ�� �Ѵܰ� �ű��
		item = m_pItems[m_iFront];					// �ű� ��ġ�� ������ �迭�� ����
	}
}

// Print all the items in the queue on screen
template <class T>
void CircularQueueType<T>::Print()
{
	// Stack ���� ��� element ���.
	for (int i = (m_iFront + 1) % m_nMaxQueue; i != (m_iRear + 1) % m_nMaxQueue; i = (i + 1) % m_nMaxQueue) //ť�� ó��+1���� ����ؼ� ť�� ���������� Ȯ���Ѵ�. ��� �˻��� mod�� ��ȯ�ϰ� �Ѵ�.
	{
		cout << m_pItems[i] << " - ";
	}
	cout << endl;
}

template <class T>
int CircularQueueType<T>::Deduplication(T inData)
{
	// Stack ���� ��� element ���.
	for (int i = (m_iFront + 1) % m_nMaxQueue; i != (m_iRear + 1) % m_nMaxQueue; i = (i + 1) % m_nMaxQueue) //ť�� ó��+1���� ����ؼ� ť�� ���������� Ȯ���Ѵ�. ��� �˻��� mod�� ��ȯ�ϰ� �Ѵ�.
	{
		if (inData == m_pItems[i])
		{
			for (;i != (m_iRear + 1) % m_nMaxQueue; i = (i + 1) % m_nMaxQueue)
			{
				m_pItems[i] = m_pItems[i + 1];
			}
			if (m_iRear == 0)
				m_iRear = m_nMaxQueue - 1;
			else
				m_iRear = m_iRear - 1 ;
			return 1;
		}
	}
	return 0;
}


template <class T>
int CircularQueueType<T>::Front()
{
	return m_iFront;
}


template <class T>
int CircularQueueType<T>::Rear()
{
	return m_iRear;
}


template <class T>
int CircularQueueType<T>::MAX()
{
	return m_nMaxQueue;
}