#pragma once
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H


/**
*	@brief 두 개체 사이의 관계.
*/
enum RelationType { LESS, GREATER, EQUAL };

using namespace std;

/**
*	@brief 링크드리스트 구조를 위한 노드타입.
*/
template <typename T>
struct NodeType
{
	T data;	///< A data for each node.
	NodeType* next;	///< A node pointer to point succeed node.
};


/**
*	@brief 파일 관리를 위한 SortedLinkedList 클래스.
*/
template <typename T>
class SortedLinkedList
{
public:
	/**
	*	@brief 기본 생성자.
	*/
	SortedLinkedList();
	SortedLinkedList(SortedLinkedList<T>& copy);

	/**
	*	@brief 소멸자.
	*/
	~SortedLinkedList();

	/**
	*	@brief	리스트를 비운다.
	*	@pre	없음.
	*	@post	리스트가 비워진다.
	*/
	void MakeEmpty();

	/**
	*	@brief	리스트의 길이를 가져온다.
	*	@pre	리스트가 존재한다.
	*	@post	리스트의 길이가 리턴된다.
	*	@return	리스트의 길이.
	*/
	int GetLength() const;

	/**
	*	@brief	리스트에 item을 추가한다.
	*	@pre	올바른 item을 입력받는다.
	*	@post	중복검사를 통과하면 item이 리스트에 추가된다.
	*	@return	잘 작동되면 1을, 아닌경우에 0을 리턴.
	*/
	int Add(T item);
	/**
	*	@brief	바이트 순으로 추가
	*	@pre	item이 존재.
	*	@post	item이 바이트 순으로 추가된다.
	*	@return	잘 실행되면 1, 아니면 0을 반환.
	*/
	int AddByBytes(T item);
	/**
	*	@brief	날짜 순으로 추가
	*	@pre	item이 존재.
	*	@post	item이 날짜 순으로 추가된다.
	*	@return	잘 실행되면 1, 아니면 0을 반환.
	*/
	int AddByDate(T item);
	/**
	*	@brief	열어본 순으로 추가
	*	@pre	item이 존재.
	*	@post	item이 열어본 순으로 추가된다.
	*	@return	잘 실행되면 1, 아니면 0을 반환.
	*/
	int AddByCount(T item);
	/**
	*	@brief	날짜 역순으로 추가
	*	@pre	item이 존재.
	*	@post	item이 날짜 역순으로 추가된다.
	*	@return	잘 실행되면 1, 아니면 0을 반환.
	*/
	int AddByDateR(T item);
	/**
	*	@brief	열어본 역순으로 추가
	*	@pre	item이 존재.
	*	@post	item이 열어본 역순으로 추가된다.
	*	@return	잘 실행되면 1, 아니면 0을 반환.
	*/
	int AddByCountR(T item);

	/**
	*	@brief	입력받은 item이 존재하면 해당 레코드의 정보를 가져온다.
	*	@pre	올바른 item을 입력받는다.
	*	@post	검색된 레코드를 item에 넣는다.
	*	@return	일치하는 레코드를 찾으면 1, 그렇지 않으면 0을 반환.
	*/
	int Get(T& item);

	/**
	*	@brief	리스트의 현재 지시자 포인터를 초기화한다.
	*	@pre	없음.
	*	@post	지시자 포인터가 초기화된다.
	*/
	void ResetList();

	/**
	*	@brief	리스트의 다음 레코드를 가져온다.
	*	@pre	현재 지시자 포인터가 존재해야한다.
	*	@post	현재 지시자 포인터가 다음 item을 가리킨다. 레코드가 item에 복사된다.
	*/
	T* GetPoint();

	/**
	*	@brief	리스트의 다음 레코드를 가져온다.
	*	@pre	현재 지시자 포인터가 존재해야한다.
	*	@post	현재 지시자 포인터가 다음 item을 가리킨다. 레코드가 item에 복사된다.
	*/
	void GetNextItem(T& item);
	/**
	*	@brief	item과 일치하는 레코드를 제거.
	*	@pre	해당하는 레코드가 있어야함
	*	@post	해당 레코드가 제거됨.
	*/
	int Delete(T item);
	/**
	*	@brief	item과 일치하는 레코드를 갱신.
	*	@pre	해당하는 레코드가 있어야함
	*	@post	해당 레코드가 item의 내용으로 갱신됨.
	*/
	int Replace(T item);

	/**
	*	@brief	연산자 [] 오버로드 [n]번째원소의 주소 반환
	*	@pre	x번째 원소가 존재해야함
	*	@post	없음
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
	*	@brief	모두 출력
	*/
	void DisplayAll();

	/**
	*	@brief	포인터 가져오기
	*/
	T* GetPoint(T& item);
	/**
	*	@brief	대입연산자 오버로딩
	*	@pre	대입할 리스트 right가 존재해야함
	*	@post	this가 right의 값을 깊은복사해서 반환
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
	//리스트내의 모든 node 제거
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void SortedLinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
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
	// 리스트 초기화
	ResetList();

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;
	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		// 가장 마지막 node 로 이동 후 삽입
		while (1)
		{
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			// iteration 을 이용해 node 포인터 갱신.
			GetNextItem(dummy);

			if (node->data.CompareByName(dummy) == LESS)  //값이 node의 데이터가 더 작아지는 순간; 즉 순서에 맞는 순간
			{
				if (pre == NULL)	//맨처음으로 값이 들어가야되는 경우, node의 data값이 가장 작을때
				{
					node->next = m_pCurPointer;
					m_pList = node;		//맨처음으로 바꿈;
					break;
				}
				else		//중간에 값이 들어가는 순간
				{
					pre->next = node;
					node->next = m_pCurPointer;
					break;
				}
			}


			// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->next == NULL)
			{
				// 마지막 node 와 새로운 node 연결
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
	// 리스트 초기화
	ResetList();

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;
	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		// 가장 마지막 node 로 이동 후 삽입
		while (1)
		{
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			// iteration 을 이용해 node 포인터 갱신.
			GetNextItem(dummy);

			if (node->data.CompareByBytes(dummy) == LESS)  //값이 node의 데이터가 더 작아지는 순간; 즉 순서에 맞는 순간
			{
				if (pre == NULL)	//맨처음으로 값이 들어가야되는 경우, node의 data값이 가장 작을때
				{
					node->next = m_pCurPointer;
					m_pList = node;		//맨처음으로 바꿈;
					break;
				}
				else		//중간에 값이 들어가는 순간
				{
					pre->next = node;
					node->next = m_pCurPointer;
					break;
				}
			}


			// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->next == NULL)
			{
				// 마지막 node 와 새로운 node 연결
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
	// 리스트 초기화
	ResetList();

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;
	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		// 가장 마지막 node 로 이동 후 삽입
		while (1)
		{
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			// iteration 을 이용해 node 포인터 갱신.
			GetNextItem(dummy);

			if (node->data.CompareByDate(dummy) == LESS)  //값이 node의 데이터가 더 작아지는 순간; 즉 순서에 맞는 순간
			{
				if (pre == NULL)	//맨처음으로 값이 들어가야되는 경우, node의 data값이 가장 작을때
				{
					node->next = m_pCurPointer;
					m_pList = node;		//맨처음으로 바꿈;
					break;
				}
				else		//중간에 값이 들어가는 순간
				{
					pre->next = node;
					node->next = m_pCurPointer;
					break;
				}
			}


			// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->next == NULL)
			{
				// 마지막 node 와 새로운 node 연결
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
	// 리스트 초기화

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;
	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	dummy = item;
	if (this->Get(dummy))
		this->Delete(dummy);
	ResetList();

	// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		// 가장 마지막 node 로 이동 후 삽입
		while (1)
		{
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			// iteration 을 이용해 node 포인터 갱신.
			GetNextItem(dummy);

			if (node->data.CompareByCount(dummy) == GREATER)  //값이 node의 데이터가 더 작아지는 순간; 즉 순서에 맞는 순간
			{
				if (pre == NULL)	//맨처음으로 값이 들어가야되는 경우, node의 data값이 가장 작을때
				{
					node->next = m_pCurPointer;
					m_pList = node;		//맨처음으로 바꿈;
					break;
				}
				else		//중간에 값이 들어가는 순간
				{
					pre->next = node;
					node->next = m_pCurPointer;
					break;
				}
			}


			// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->next == NULL)
			{
				// 마지막 node 와 새로운 node 연결
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
	// 리스트 초기화
	ResetList();

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;
	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		// 가장 마지막 node 로 이동 후 삽입
		while (1)
		{
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			// iteration 을 이용해 node 포인터 갱신.
			GetNextItem(dummy);

			if (node->data.CompareByDate(dummy) == GREATER)  //값이 node의 데이터가 더 작아지는 순간; 즉 순서에 맞는 순간
			{
				if (pre == NULL)	//맨처음으로 값이 들어가야되는 경우, node의 data값이 가장 작을때
				{
					node->next = m_pCurPointer;
					m_pList = node;		//맨처음으로 바꿈;
					break;
				}
				else		//중간에 값이 들어가는 순간
				{
					pre->next = node;
					node->next = m_pCurPointer;
					break;
				}
			}


			// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->next == NULL)
			{
				// 마지막 node 와 새로운 node 연결
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
	// 리스트 초기화

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;
	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	dummy = item;
	if (this->Get(dummy))
		this->Delete(dummy);
	ResetList();

	// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		// 가장 마지막 node 로 이동 후 삽입
		while (1)
		{
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			// iteration 을 이용해 node 포인터 갱신.
			GetNextItem(dummy);

			if (node->data.CompareByCount(dummy) == LESS)  //값이 node의 데이터가 더 작아지는 순간; 즉 순서에 맞는 순간
			{
				if (pre == NULL)	//맨처음으로 값이 들어가야되는 경우, node의 data값이 가장 작을때
				{
					node->next = m_pCurPointer;
					m_pList = node;		//맨처음으로 바꿈;
					break;
				}
				else		//중간에 값이 들어가는 순간
				{
					pre->next = node;
					node->next = m_pCurPointer;
					break;
				}
			}


			// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->next == NULL)
			{
				// 마지막 node 와 새로운 node 연결
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
	// current pointer 초기화
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
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;

	//item 에 current position 의 info 를 삽입
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
		//item 에 current position 의 info 를 삽입
		item = m_pCurPointer->data;
		cout << item;
		//다음 노드가 NULL이면 break
		if (m_pCurPointer->next == NULL)
			break;
		//current position 을 다음 노드로 이동
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

	if (Get(item) == 0)	//해당하는 값이 없으면, 0보내고 종료
		return 0;

	while (1)
	{
		pre = m_pCurPointer;
		GetNextItem(tmp);
		if (tmp == item)		//id값이 일치
		{
			if (pre == NULL) //삭제해야할 노드가 맨처음일때
			{
				toDel = m_pList;	//잠시 옮겨두고 삭제
				m_pList = m_pList->next;	//맨처음을 두번째로바꿈
				delete toDel;
				found = true;
				break;
			}
			else
			{
				toDel = m_pCurPointer;
				pre->next = m_pCurPointer->next;	//전 포인터와 다음포인터를 연결
				delete toDel;
				found = true;
				break;
			}
		}
		if (m_pCurPointer->next == NULL)	//맨마지막, 루프를 다돌았을때
			break;


	}
	m_nLength--;
	if (found)
		return 1;
	else
		return 0;

}

/**
*	@brief	변경
*/
template <typename T>
int SortedLinkedList<T>::Replace(T item)
{
	NodeType<T> *pre;
	ResetList();
	T isthere = item;
	T tmp;
	bool found = false;
	//Get(T& item)이 pass by reference임으로 데이터왜곡발생
	if (Get(isthere) == 0)	//해당하는 값이 없으면, 0보내고 종료
		return 0;

	while (1)
	{
		pre = m_pCurPointer;
		GetNextItem(tmp);
		if (tmp == item)			//'=='연산자를 id값에 대해 오버로딩했음. 	
		{
			m_pCurPointer->data = item;	//id값이 같으면 데이터를 대체
			found = true;
			break;
		}
		if (m_pCurPointer->next == NULL)	//맨마지막
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