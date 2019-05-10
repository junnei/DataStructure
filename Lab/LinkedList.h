#pragma once
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H


/**
*	@brief �� ��ü ������ ����.
*/
enum RelationType { LESS, GREATER, EQUAL };

using namespace std;

/**
*	@brief ��ũ�帮��Ʈ ������ ���� ���Ÿ��.
*/
template <typename T>
struct NodeType
{
	T data;	///< A data for each node.
	NodeType* next;	///< A node pointer to point succeed node.
};


/**
*	@brief ���� ������ ���� SortedLinkedList Ŭ����.
*/
template <typename T>
class SortedLinkedList
{
public:
	/**
	*	@brief �⺻ ������.
	*/
	SortedLinkedList();
	SortedLinkedList(SortedLinkedList<T>& copy);

	/**
	*	@brief �Ҹ���.
	*/
	~SortedLinkedList();

	/**
	*	@brief	����Ʈ�� ����.
	*	@pre	����.
	*	@post	����Ʈ�� �������.
	*/
	void MakeEmpty();

	/**
	*	@brief	����Ʈ�� ���̸� �����´�.
	*	@pre	����Ʈ�� �����Ѵ�.
	*	@post	����Ʈ�� ���̰� ���ϵȴ�.
	*	@return	����Ʈ�� ����.
	*/
	int GetLength() const;

	/**
	*	@brief	����Ʈ�� item�� �߰��Ѵ�.
	*	@pre	�ùٸ� item�� �Է¹޴´�.
	*	@post	�ߺ��˻縦 ����ϸ� item�� ����Ʈ�� �߰��ȴ�.
	*	@return	�� �۵��Ǹ� 1��, �ƴѰ�쿡 0�� ����.
	*/
	int Add(T item);
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

	/**
	*	@brief	�Է¹��� item�� �����ϸ� �ش� ���ڵ��� ������ �����´�.
	*	@pre	�ùٸ� item�� �Է¹޴´�.
	*	@post	�˻��� ���ڵ带 item�� �ִ´�.
	*	@return	��ġ�ϴ� ���ڵ带 ã���� 1, �׷��� ������ 0�� ��ȯ.
	*/
	int Get(T& item);

	/**
	*	@brief	����Ʈ�� ���� ������ �����͸� �ʱ�ȭ�Ѵ�.
	*	@pre	����.
	*	@post	������ �����Ͱ� �ʱ�ȭ�ȴ�.
	*/
	void ResetList();

	/**
	*	@brief	����Ʈ�� ���� ���ڵ带 �����´�.
	*	@pre	���� ������ �����Ͱ� �����ؾ��Ѵ�.
	*	@post	���� ������ �����Ͱ� ���� item�� ����Ų��. ���ڵ尡 item�� ����ȴ�.
	*/
	T* GetPoint();

	/**
	*	@brief	����Ʈ�� ���� ���ڵ带 �����´�.
	*	@pre	���� ������ �����Ͱ� �����ؾ��Ѵ�.
	*	@post	���� ������ �����Ͱ� ���� item�� ����Ų��. ���ڵ尡 item�� ����ȴ�.
	*/
	void GetNextItem(T& item);
	/**
	*	@brief	item�� ��ġ�ϴ� ���ڵ带 ����.
	*	@pre	�ش��ϴ� ���ڵ尡 �־����
	*	@post	�ش� ���ڵ尡 ���ŵ�.
	*/
	int Delete(T item);
	/**
	*	@brief	item�� ��ġ�ϴ� ���ڵ带 ����.
	*	@pre	�ش��ϴ� ���ڵ尡 �־����
	*	@post	�ش� ���ڵ尡 item�� �������� ���ŵ�.
	*/
	int Replace(T item);

	/**
	*	@brief	������ [] �����ε� [n]��°������ �ּ� ��ȯ
	*	@pre	x��° ���Ұ� �����ؾ���
	*	@post	����
	*/
	T*  operator[](const int x)
	{
		ResetList();
		m_pCurPointer = m_pList;
		for (int i = 0; i < x; i++) {
			m_pCurPointer = m_pCurPointer->next;
		}
		return &m_pCurPointer->data;
	}

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
	SortedLinkedList<T>& operator=(SortedLinkedList<T>& right)
	{
		MakeEmpty();
		right.ResetList();

		for (int i = 0; i < right.GetLength(); i++) {
			T* ptr = right.GetNextItem();
			Add(*ptr);
		}

		return *this;
	}
private:
	NodeType<T>* m_pList;		// Pointer for pointing a first node.
	NodeType<T>* m_pCurPointer;	// Node pointer for pointing current node to use iteration.
	int m_nLength;				// Number of node in the list.
};





// Class constructor
template <typename T>
SortedLinkedList<T>::SortedLinkedList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}

// Class constructor
template <typename T>
SortedLinkedList<T>::SortedLinkedList(SortedLinkedList<T>& copy)
{
	m_pList = NULL;
	m_pCurPointer = NULL;
	m_nLength = copy.m_nLength;

	if (copy.m_pList != NULL)
	{
		MakeEmpty();
		copy.ResetList();
		T dummy;

		for (int i = 0; i < copy.GetLength(); i++)
		{
			copy.GetNextItem(dummy);
			Add(dummy);
		}
	}

}


// Class destructor
template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
	//����Ʈ���� ��� node ����
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void SortedLinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<T>* tempPtr;

	while (m_pList != NULL)
	{
		tempPtr = m_pList;
		m_pList = m_pList->next;
		delete tempPtr;
	}

	m_nLength = 0;
}


// Get number of elements in the list.
template <typename T>
int SortedLinkedList<T>::GetLength() const
{
	return m_nLength;
}


// Add item into this list.
template <typename T>
int SortedLinkedList<T>::Add(T item)
{
	// ����Ʈ �ʱ�ȭ
	ResetList();

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;
	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;

	// list �� node �� �������� �ʴ� ���
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		// ���� ������ node �� �̵� �� ����
		while (1)
		{
			// ���� ��带 ����Ű�� ������ ����
			pre = m_pCurPointer;

			// iteration �� �̿��� node ������ ����.
			GetNextItem(dummy);

			if (node->data.CompareByName(dummy) == LESS)  //���� node�� �����Ͱ� �� �۾����� ����; �� ������ �´� ����
			{
				if (pre == NULL)	//��ó������ ���� ���ߵǴ� ���, node�� data���� ���� ������
				{
					node->next = m_pCurPointer;
					m_pList = node;		//��ó������ �ٲ�;
					break;
				}
				else		//�߰��� ���� ���� ����
				{
					pre->next = node;
					node->next = m_pCurPointer;
					break;
				}
			}


			// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_pCurPointer->next == NULL)
			{
				// ������ node �� ���ο� node ����
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_nLength++;

	return 1;
}


// Add item into this list.
template <typename T>
int SortedLinkedList<T>::AddByBytes(T item)
{
	// ����Ʈ �ʱ�ȭ
	ResetList();

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;
	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;

	// list �� node �� �������� �ʴ� ���
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		// ���� ������ node �� �̵� �� ����
		while (1)
		{
			// ���� ��带 ����Ű�� ������ ����
			pre = m_pCurPointer;

			// iteration �� �̿��� node ������ ����.
			GetNextItem(dummy);

			if (node->data.CompareByBytes(dummy) == LESS)  //���� node�� �����Ͱ� �� �۾����� ����; �� ������ �´� ����
			{
				if (pre == NULL)	//��ó������ ���� ���ߵǴ� ���, node�� data���� ���� ������
				{
					node->next = m_pCurPointer;
					m_pList = node;		//��ó������ �ٲ�;
					break;
				}
				else		//�߰��� ���� ���� ����
				{
					pre->next = node;
					node->next = m_pCurPointer;
					break;
				}
			}


			// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_pCurPointer->next == NULL)
			{
				// ������ node �� ���ο� node ����
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_nLength++;

	return 1;
}


// Add item into this list.
template <typename T>
int SortedLinkedList<T>::AddByDate(T item)
{
	// ����Ʈ �ʱ�ȭ
	ResetList();

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;
	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;

	// list �� node �� �������� �ʴ� ���
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		// ���� ������ node �� �̵� �� ����
		while (1)
		{
			// ���� ��带 ����Ű�� ������ ����
			pre = m_pCurPointer;

			// iteration �� �̿��� node ������ ����.
			GetNextItem(dummy);

			if (node->data.CompareByDate(dummy) == LESS)  //���� node�� �����Ͱ� �� �۾����� ����; �� ������ �´� ����
			{
				if (pre == NULL)	//��ó������ ���� ���ߵǴ� ���, node�� data���� ���� ������
				{
					node->next = m_pCurPointer;
					m_pList = node;		//��ó������ �ٲ�;
					break;
				}
				else		//�߰��� ���� ���� ����
				{
					pre->next = node;
					node->next = m_pCurPointer;
					break;
				}
			}


			// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_pCurPointer->next == NULL)
			{
				// ������ node �� ���ο� node ����
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_nLength++;

	return 1;
}


// Add item into this list.
template <typename T>
int SortedLinkedList<T>::AddByCount(T item)
{
	// ����Ʈ �ʱ�ȭ

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;
	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;

	dummy = item;
	if (this->Get(dummy))
		this->Delete(dummy);
	ResetList();

	// list �� node �� �������� �ʴ� ���
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		// ���� ������ node �� �̵� �� ����
		while (1)
		{
			// ���� ��带 ����Ű�� ������ ����
			pre = m_pCurPointer;

			// iteration �� �̿��� node ������ ����.
			GetNextItem(dummy);

			if (node->data.CompareByCount(dummy) == GREATER)  //���� node�� �����Ͱ� �� �۾����� ����; �� ������ �´� ����
			{
				if (pre == NULL)	//��ó������ ���� ���ߵǴ� ���, node�� data���� ���� ������
				{
					node->next = m_pCurPointer;
					m_pList = node;		//��ó������ �ٲ�;
					break;
				}
				else		//�߰��� ���� ���� ����
				{
					pre->next = node;
					node->next = m_pCurPointer;
					break;
				}
			}


			// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_pCurPointer->next == NULL)
			{
				// ������ node �� ���ο� node ����
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_nLength++;

	return 1;
}


// Add item into this list.
template <typename T>
int SortedLinkedList<T>::AddByDateR(T item)
{
	// ����Ʈ �ʱ�ȭ
	ResetList();

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;
	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;

	// list �� node �� �������� �ʴ� ���
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		// ���� ������ node �� �̵� �� ����
		while (1)
		{
			// ���� ��带 ����Ű�� ������ ����
			pre = m_pCurPointer;

			// iteration �� �̿��� node ������ ����.
			GetNextItem(dummy);

			if (node->data.CompareByDate(dummy) == GREATER)  //���� node�� �����Ͱ� �� �۾����� ����; �� ������ �´� ����
			{
				if (pre == NULL)	//��ó������ ���� ���ߵǴ� ���, node�� data���� ���� ������
				{
					node->next = m_pCurPointer;
					m_pList = node;		//��ó������ �ٲ�;
					break;
				}
				else		//�߰��� ���� ���� ����
				{
					pre->next = node;
					node->next = m_pCurPointer;
					break;
				}
			}


			// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_pCurPointer->next == NULL)
			{
				// ������ node �� ���ο� node ����
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_nLength++;

	return 1;
}


// Add item into this list.
template <typename T>
int SortedLinkedList<T>::AddByCountR(T item)
{
	// ����Ʈ �ʱ�ȭ

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;
	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;

	dummy = item;
	if (this->Get(dummy))
		this->Delete(dummy);
	ResetList();

	// list �� node �� �������� �ʴ� ���
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		// ���� ������ node �� �̵� �� ����
		while (1)
		{
			// ���� ��带 ����Ű�� ������ ����
			pre = m_pCurPointer;

			// iteration �� �̿��� node ������ ����.
			GetNextItem(dummy);

			if (node->data.CompareByCount(dummy) == LESS)  //���� node�� �����Ͱ� �� �۾����� ����; �� ������ �´� ����
			{
				if (pre == NULL)	//��ó������ ���� ���ߵǴ� ���, node�� data���� ���� ������
				{
					node->next = m_pCurPointer;
					m_pList = node;		//��ó������ �ٲ�;
					break;
				}
				else		//�߰��� ���� ���� ����
				{
					pre->next = node;
					node->next = m_pCurPointer;
					break;
				}
			}


			// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_pCurPointer->next == NULL)
			{
				// ������ node �� ���ο� node ����
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_nLength++;

	return 1;
}


// Retrieve list element whose key matches item's key (if present).
template <typename T>
int SortedLinkedList<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}

	if (found)
		return 1;
	else
		return 0;
}

template<typename T>
T* SortedLinkedList<T>::GetPoint(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;

	location = m_pList;
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


// Initializes current pointer for an iteration through the list.
template <typename T>
void SortedLinkedList<T>::ResetList()
{
	// current pointer �ʱ�ȭ
	m_pCurPointer = NULL;
}

template<typename T>
T* SortedLinkedList<T>::GetPoint()
{
	return &m_pCurPointer->data;
}


// Gets the next element in list.
template <typename T>
void SortedLinkedList<T>::GetNextItem(T& item)
{
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;

	//item �� current position �� info �� ����
	item = m_pCurPointer->data;
}


// Gets the next element in list.
template <typename T>
void SortedLinkedList<T>::DisplayAll()
{

	T item;
	m_pCurPointer = m_pList;
	while(true)
	{
		//item �� current position �� info �� ����
		item = m_pCurPointer->data;
		cout << item;
		//���� ��尡 NULL�̸� break
		if (m_pCurPointer->next == NULL)
			break;
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;
	}
}


template <typename T>
int SortedLinkedList<T>::Delete(T item)
{
	NodeType<T> *pre;
	NodeType<T> *toDel;
	ResetList();
	T tmp;
	bool found = false;

	if (Get(item) == 0)	//�ش��ϴ� ���� ������, 0������ ����
		return 0;

	while (1)
	{
		pre = m_pCurPointer;
		GetNextItem(tmp);
		if (tmp == item)		//id���� ��ġ
		{
			if (pre == NULL) //�����ؾ��� ��尡 ��ó���϶�
			{
				toDel = m_pList;	//��� �Űܵΰ� ����
				m_pList = m_pList->next;	//��ó���� �ι�°�ιٲ�
				delete toDel;
				found = true;
				break;
			}
			else
			{
				toDel = m_pCurPointer;
				pre->next = m_pCurPointer->next;	//�� �����Ϳ� ���������͸� ����
				delete toDel;
				found = true;
				break;
			}
		}
		if (m_pCurPointer->next == NULL)	//�Ǹ�����, ������ �ٵ�������
			break;


	}
	m_nLength--;
	if (found)
		return 1;
	else
		return 0;

}

/**
*	@brief	����
*/
template <typename T>
int SortedLinkedList<T>::Replace(T item)
{
	NodeType<T> *pre;
	ResetList();
	T isthere = item;
	T tmp;
	bool found = false;
	//Get(T& item)�� pass by reference������ �����Ϳְ�߻�
	if (Get(isthere) == 0)	//�ش��ϴ� ���� ������, 0������ ����
		return 0;

	while (1)
	{
		pre = m_pCurPointer;
		GetNextItem(tmp);
		if (tmp == item)			//'=='�����ڸ� id���� ���� �����ε�����. 	
		{
			m_pCurPointer->data = item;	//id���� ������ �����͸� ��ü
			found = true;
			break;
		}
		if (m_pCurPointer->next == NULL)	//�Ǹ�����
		{
			found = true;
			break;
		}

	}
	if (found)
		return 1;
	else
		return 0;

}


#endif	// LINKED_LIST