#pragma once
#ifndef _DOUBLYSORTEDLINKEDLIST_H
#define _DOUBLYSORTEDLINKEDLIST_H

#include "DoublyIterator.h"


/**
*	@brief �� ��ü ������ ����.
*/
enum RelationType { LESS, GREATER, EQUAL };

using namespace std;

template<typename T>
class DoublyIterator;

/**
*	���Ḯ��Ʈ���� ���̴� NodeType�� ����ü
*/
template <typename T>
struct DoublyNodeType
{
	T data; ///< �� ����� ������.
	DoublyNodeType *prev; ///< ����� ���� ����Ű�� ������.
	DoublyNodeType *next; ///< ����� ������ ����Ű�� ������.
};

/**
*	���ĵ� �����Ḯ��Ʈ Ŭ����
*/
template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>; ///< DoublyIterator�� ģ�� Ŭ����.
public:
	/**
	*	����Ʈ ������.
	*/
	DoublySortedLinkedList();
	DoublySortedLinkedList(DoublySortedLinkedList<T>& copy);

	/**
	*	�Ҹ���.
	*/
	~DoublySortedLinkedList();

	/**
	*	@brief	����Ʈ�� ������� �ƴ��� �˻��Ѵ�.
	*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
	*	@post	������� �ƴ����� �˷��ش�.
	*	@return	��������� true, �ƴϸ� false�� ��ȯ.
	*/
	bool IsEmpty();

	/**
	*	@brief	����Ʈ�� ���� á���� �ƴ��� �˻��Ѵ�.
	*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
	*	@post	���� á���� �ƴ����� �˷��ش�.
	*	@return	���� �������� true, �ƴϸ� false�� ��ȯ.
	*/
	bool IsFull();

	/**
	*	@brief	����Ʈ�� ����.
	*	@pre	����.
	*	@post	m_pFirst�� m_pLast�� ������ ��� �����͸� �����.
	*/
	void MakeEmpty();

	/**
	*	@brief	����Ʈ�� ���̸� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	����Ʈ�� ���̸� ��ȯ.
	*	@return	m_nLength ����Ʈ�� ���� ��ȯ.
	*/
	int GetLength() const;

	/**
	*	@brief	���ο� �������� ����Ʈ�� �߰��Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�������� ����Ʈ�� �߰��Ѵ�.
	*	@return	���� �������� ������ 0�� ��ȯ�ϰ�, �Է¿� �����ϸ� 1�� ��ȯ.
	*/
	int Add(T item);

	/**
	*	@brief	�Է¹��� �������� ����Ʈ���� �����Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�Է¹��� �������� ����Ʈ���� ã�� �����Ѵ�.
	*/
	int Delete(T item);

	/**
	*	@brief	�Է¹��� ���������� ������ �ٲ۴�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	���ο� ������ ��ü�ȴ�.
	*/
	void Replace(T item);

	/**
	*	@brief	�Է¹��� �������� ������ ���Ͽ� ���� ����Ʈ�� �������� �����´�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�˻��� �����͸� �����ۿ� �ִ´�.
	*	@return	��ġ�ϴ� �����͸� ã���� 1, �׷��� ������ 0�� ��ȯ.
	*/
	int Get(T &item);

	/**
	*	@brief	��� ���
	*/
	void DisplayAll();

	/**
	*	@brief	������ ��������
	*/
	T* GetPoint(T& item);
	/**
	*	@brief	���Կ����� �����ε�
	*	@pre	������ ����Ʈ right�� �����ؾ���
	*	@post	this�� right�� ���� ���������ؼ� ��ȯ
	*/
	DoublySortedLinkedList<T>& operator=(DoublySortedLinkedList<T>& right)
	{
		MakeEmpty();
		right.ResetList();

		for (int i = 0; i < right.GetLength(); i++) {
			T* ptr = right.GetNextItem();
			Add(*ptr);
		}

		return *this;
	}

	/**
	*	@brief	����Ʈ ������ �߰�
	*	@pre	item�� ����.
	*	@post	item�� ����Ʈ ������ �߰��ȴ�.
	*	@return	�� ����Ǹ� 1, �ƴϸ� 0�� ��ȯ.
	*/
	int AddByBytes(T item);
	/**
	*	@brief	��¥ ������ �߰�
	*	@pre	item�� ����.
	*	@post	item�� ��¥ ������ �߰��ȴ�.
	*	@return	�� ����Ǹ� 1, �ƴϸ� 0�� ��ȯ.
	*/
	int AddByDate(T item);
	/**
	*	@brief	��� ������ �߰�
	*	@pre	item�� ����.
	*	@post	item�� ��� ������ �߰��ȴ�.
	*	@return	�� ����Ǹ� 1, �ƴϸ� 0�� ��ȯ.
	*/
	int AddByCount(T item);
	/**
	*	@brief	��¥ �������� �߰�
	*	@pre	item�� ����.
	*	@post	item�� ��¥ �������� �߰��ȴ�.
	*	@return	�� ����Ǹ� 1, �ƴϸ� 0�� ��ȯ.
	*/
	int AddByDateR(T item);
	/**
	*	@brief	��� �������� �߰�
	*	@pre	item�� ����.
	*	@post	item�� ��� �������� �߰��ȴ�.
	*	@return	�� ����Ǹ� 1, �ƴϸ� 0�� ��ȯ.
	*/
	int AddByCountR(T item);

private:
	DoublyNodeType<T>* m_pFirst; ///< �ּҰ��� ������ ����Ʈ�� �� ó��.
	DoublyNodeType<T>* m_pLast; ///< �ִ��� ������ ����Ʈ�� �� ��.
	int m_nLength; ///< ����Ʈ�� ����.
};

// ����Ʈ�� �� ó���� ���� ���θ� ����Ű�� �����ϰ� ����Ʈ�� ���̸� 0���� �ʱ�ȭ���ѳ��´�.
template <typename T>
DoublySortedLinkedList<T> ::DoublySortedLinkedList()
{
	m_pFirst = new DoublyNodeType<T>;
	m_pLast = new DoublyNodeType<T>;

	m_pFirst->next = m_pLast; // ���� ó���� ���θ� ����Ű�� �ʱ�ȭ.
	m_pFirst->prev = NULL; // ó��.

	m_pLast->next = NULL; // ��.
	m_pLast->prev = m_pFirst; // ���� ó���� ���θ� ����Ű�� �ʱ�ȭ.

	m_nLength = 0; // ���̴� 0.
}

// Class constructor
template <typename T>
DoublySortedLinkedList<T>::DoublySortedLinkedList(DoublySortedLinkedList<T>& copy)
{
	m_pFirst = NULL;
	m_pLast = NULL;
	m_nLength = copy.m_nLength;

	if (copy.m_pFirst != NULL)
	{
		
		DoublyIterator<T> itor(copy);
		DoublyNodeType<T> *pItem;
		itor.Next(); // �������� �̵�.

		while (itor.NextNotNull())
		{
			pItem = itor.m_pCurPointer;
			Add(itor.GetCurrentNode().data);
			itor.Next(); // ���� �����͸� �������� �̵�.
		}
	}
}



// �Ҹ���.
template <typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList()
{
	delete m_pFirst;
	delete m_pLast;
}

// ����Ʈ�� ������� �˻��Ѵ�.
template <typename T>
bool DoublySortedLinkedList<T>::IsEmpty()
{
	if (m_nLength == 0)
		return true;
	else
		return false;
}

// ����Ʈ�� �� ���ִ��� �˻��Ѵ�.
template <typename T>
bool DoublySortedLinkedList<T>::IsFull()
{
	if (m_nLength == 10)
		return true;
	else
		return false;
}

// ����Ʈ�� ����.
template <typename T>
void DoublySortedLinkedList<T>::MakeEmpty()
{
	DoublyNodeType<T> *pItem;
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	while (itor.NextNotNull())
	{
		pItem = itor.m_pCurPointer;
		itor.Next(); // ���� �����͸� �������� �̵�.
		delete pItem;
	}

	m_pFirst->next = m_pLast;
	m_pFirst->prev = NULL;
	m_pLast->prev = m_pFirst;
	m_pLast->next = NULL;

	return;
}

// ����Ʈ�� ���̸� ��ȯ�Ѵ�.
template <typename T>
int DoublySortedLinkedList<T>::GetLength() const
{
	return m_nLength;
}

// �������� �Է¹޾� ����Ʈ�� �´� �ڸ��� ã�� �����Ѵ�.
template <typename T>
int DoublySortedLinkedList<T>::Add(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	if (IsEmpty()) // ó�� ������ ��
	{
		DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
		pItem->data = item;
		m_pFirst->next = pItem;
		pItem->prev = m_pFirst;
		pItem->next = m_pLast;
		m_pLast->prev = pItem; // ó���� �� ���̿� ����.
		m_nLength++;
		return 1;
	}
	else // ó���� �ƴ� ��
	{
		while (1)
		{
			if (item < itor.m_pCurPointer->data) // �´� �ڸ��� ã�´�.
			{
				DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
				pItem->data = item;
				pItem->prev = itor.m_pCurPointer->prev;
				pItem->next = itor.m_pCurPointer;
				itor.m_pCurPointer->prev->next = pItem;
				itor.m_pCurPointer->prev = pItem; // �������� ����.
				m_nLength++;
				return 1;
			}
			else if (item == itor.m_pCurPointer->data) // ���� ������ �������� ������
				return 0; // 0�� ��ȯ.
			else if (itor.m_pCurPointer->next == m_pLast)
			{
				DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
				pItem->data = item;
				itor.m_pCurPointer->next = pItem;
				pItem->prev = itor.m_pCurPointer;
				pItem->next = m_pLast;
				itor.m_pCurPointer = pItem; // �������� ����.
				m_nLength++;
				return 1;
			}
			else
				itor.Next(); // �������� �̵�.
		}
			
	}
}

// �Է¹��� �������� �����Ϳ��� ã�Ƴ��� �����Ѵ�.
template <typename T>
int DoublySortedLinkedList<T>::Delete(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item) // ��ġ�ϴ� �����͸� ã�´�.
		{
			DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
			pItem = itor.m_pCurPointer;
			itor.Next();
			pItem->prev->next = itor.m_pCurPointer;
			itor.m_pCurPointer->prev = pItem->prev; // �����ϴ� ����� �հ� �ڸ� ���� �̾��ش�.
			delete pItem; // ����.
			m_nLength--; // ���� ����.
			return 1;
		}
		else
			itor.Next();
	}
	return 0;
}

// �Է¹��� �������� ������ ��ü�Ѵ�.
template <typename T>
void DoublySortedLinkedList<T>::Replace(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item)
		{
			itor.m_pCurPointer->data = item; // ������ ��ü.
			return;
		}
		else
			itor.Next();
	}

	return;
}

// �Է¹��� �����۰� ��ġ�ϴ� �������� ����Ʈ���� ã�� �����´�.
template <typename T>
int DoublySortedLinkedList<T>::Get(T &item)
{
	DoublyIterator<T> itor(*this);
	itor.Next();

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item)
		{
			item = itor.m_pCurPointer->data;
			return 1; // ��ġ�ϸ� 1�� ��ȯ.
		}
		else
			itor.Next(); // �������� �̵�.
	}

	return 0; // ��ġ���� ������ 0�� ��ȯ.
}


// Gets the next element in list.
template <typename T>
void DoublySortedLinkedList<T>::DisplayAll()
{
	DoublyIterator<T> itor(*this);
	itor.Next();
	T item;

	while (itor.m_pCurPointer != m_pLast)
	{
		item = itor.m_pCurPointer->data;
		cout << item;
		itor.Next(); // �������� �̵�.
	}
}


template<typename T>
T* DoublySortedLinkedList<T>::GetPoint(T& item)
{
	bool moreToSearch, found;
	DoublyNodeType<T>* location;

	location = m_pFirst;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
			return &location->data;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}
	return NULL;
}

// �������� �Է¹޾� ����Ʈ�� �´� �ڸ��� ã�� �����Ѵ�.
template <typename T>
int DoublySortedLinkedList<T>::AddByBytes(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	if (IsEmpty()) // ó�� ������ ��
	{
		DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
		pItem->data = item;
		m_pFirst->next = pItem;
		pItem->prev = m_pFirst;
		pItem->next = m_pLast;
		m_pLast->prev = pItem; // ó���� �� ���̿� ����.
		m_nLength++;
		return 1;
	}
	else // ó���� �ƴ� ��
	{
		while (1)
		{
			if (itor.GetCurrentNode()->CompareByBytes(item) == LESS) // �´� �ڸ��� ã�´�.
			{
				DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
				pItem->data = item;
				pItem->prev = itor.m_pCurPointer->prev;
				pItem->next = itor.m_pCurPointer;
				itor.m_pCurPointer->prev->next = pItem;
				itor.m_pCurPointer->prev = pItem; // �������� ����.
				m_nLength++;
				return 1;
			}
			else if (item == itor.m_pCurPointer->data) // ���� ������ �������� ������
				return 0; // 0�� ��ȯ.
			else
				itor.Next(); // �������� �̵�.
		}
	}
}

// �������� �Է¹޾� ����Ʈ�� �´� �ڸ��� ã�� �����Ѵ�.
template <typename T>
int DoublySortedLinkedList<T>::AddByDate(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	if (IsEmpty()) // ó�� ������ ��
	{
		DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
		pItem->data = item;
		m_pFirst->next = pItem;
		pItem->prev = m_pFirst;
		pItem->next = m_pLast;
		m_pLast->prev = pItem; // ó���� �� ���̿� ����.
		m_nLength++;
		return 1;
	}
	else // ó���� �ƴ� ��
	{
		while (1)
		{
			if (itor.GetCurrentNode().data.CompareByDate(item) == LESS) // �´� �ڸ��� ã�´�.
			{
				DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
				pItem->data = item;
				pItem->prev = itor.m_pCurPointer->prev;
				pItem->next = itor.m_pCurPointer;
				itor.m_pCurPointer->prev->next = pItem;
				itor.m_pCurPointer->prev = pItem; // �������� ����.
				m_nLength++;
				return 1;
			}
			else if (item == itor.m_pCurPointer->data) // ���� ������ �������� ������
				return 0; // 0�� ��ȯ.
			else
				itor.Next(); // �������� �̵�.
		}
	}
}

// �������� �Է¹޾� ����Ʈ�� �´� �ڸ��� ã�� �����Ѵ�.
template <typename T>
int DoublySortedLinkedList<T>::AddByCount(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	if (IsEmpty()) // ó�� ������ ��
	{
		DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
		pItem->data = item;
		m_pFirst->next = pItem;
		pItem->prev = m_pFirst;
		pItem->next = m_pLast;
		m_pLast->prev = pItem; // ó���� �� ���̿� ����.
		m_nLength++;
		return 1;
	}
	else // ó���� �ƴ� ��
	{
		while (1)
		{
			if (itor.GetCurrentNode().data.CompareByCount(item) == GREATER) // �´� �ڸ��� ã�´�.
			{
				DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
				pItem->data = item;
				pItem->prev = itor.m_pCurPointer->prev;
				pItem->next = itor.m_pCurPointer;
				itor.m_pCurPointer->prev->next = pItem;
				itor.m_pCurPointer->prev = pItem; // �������� ����.
				m_nLength++;
				return 1;
			}
			else if (item == itor.m_pCurPointer->data) // ���� ������ �������� ������
				return 0; // 0�� ��ȯ.
			else
				itor.Next(); // �������� �̵�.
		}
	}
}

// �������� �Է¹޾� ����Ʈ�� �´� �ڸ��� ã�� �����Ѵ�.
template <typename T>
int DoublySortedLinkedList<T>::AddByDateR(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	if (IsEmpty()) // ó�� ������ ��
	{
		DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
		pItem->data = item;
		m_pFirst->next = pItem;
		pItem->prev = m_pFirst;
		pItem->next = m_pLast;
		m_pLast->prev = pItem; // ó���� �� ���̿� ����.
		m_nLength++;
		return 1;
	}
	else // ó���� �ƴ� ��
	{
		while (1)
		{
			if (itor.GetCurrentNode().data.CompareByDate(item) == GREATER) // �´� �ڸ��� ã�´�.
			{
				DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
				pItem->data = item;
				pItem->prev = itor.m_pCurPointer->prev;
				pItem->next = itor.m_pCurPointer;
				itor.m_pCurPointer->prev->next = pItem;
				itor.m_pCurPointer->prev = pItem; // �������� ����.
				m_nLength++;
				return 1;
			}
			else if (item == itor.m_pCurPointer->data) // ���� ������ �������� ������
				return 0; // 0�� ��ȯ.
			else
				itor.Next(); // �������� �̵�.
		}
	}
}

// �������� �Է¹޾� ����Ʈ�� �´� �ڸ��� ã�� �����Ѵ�.
template <typename T>
int DoublySortedLinkedList<T>::AddByCountR(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	if (IsEmpty()) // ó�� ������ ��
	{
		DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
		pItem->data = item;
		m_pFirst->next = pItem;
		pItem->prev = m_pFirst;
		pItem->next = m_pLast;
		m_pLast->prev = pItem; // ó���� �� ���̿� ����.
		m_nLength++;
		return 1;
	}
	else // ó���� �ƴ� ��
	{
		while (1)
		{
			if (item.CompareByCount(itor.GetCurrentNode().data) == LESS) // �´� �ڸ��� ã�´�.
			{
				DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
				pItem->data = item;
				pItem->prev = itor.m_pCurPointer->prev;
				pItem->next = itor.m_pCurPointer;
				itor.m_pCurPointer->prev->next = pItem;
				itor.m_pCurPointer->prev = pItem; // �������� ����.
				m_nLength++;
				return 1;
			}
			else if (item == itor.m_pCurPointer->data) // ���� ������ �������� ������
				return 0; // 0�� ��ȯ.
			else
				itor.Next(); // �������� �̵�.
		}
	}
}

#endif _DOUBLYSORTEDLINKEDLIST_H