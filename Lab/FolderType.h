#pragma once
#ifndef _FOLDERTYPE_H
#define _FOLDERTYPE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>
#include "DoublyLinkedList.h"
#include "DoublyIterator.h"
#include "FileType.h"
using namespace std;


using namespace std::experimental::filesystem;


/**
*	@brief ���� Ÿ�� Ŭ����.
*/
class FolderType
{
public:
	/**
	*	@brief	�⺻ ������.
	*/
	FolderType()
	{
		m_fName = "";
		m_fAddress = "";
		m_fBytes = 0;
		m_fDate = GetCurrentTimes();
		m_fNumber = 0;
		m_FileNumber = 0;
		m_fLinkedList = NULL;
		m_FileList = NULL;
		prevFolder = NULL;
	}

	/**
	*	@brief �Ҹ���.
	*/
	~FolderType()
	{
	}

	/**
	*	@brief	���� �̸� ��������.
	*	@pre	���� �̸��� �����ؾ��Ѵ�.
	*	@post	����.
	*	@return	���� �̸�.
	*/
	string GetName()
	{
		return m_fName;
	}

	/**
	*	@brief	���� ��ġ ��������.
	*	@pre	���� ��ġ�� �����ؾ��Ѵ�.
	*	@post	����.
	*	@return	���� ��ġ.
	*/
	string GetAddress()
	{
		return m_fAddress;
	}

	/**
	*	@brief	���� ũ�� ��������.
	*	@pre	���� ũ�Ⱑ �����ؾ��Ѵ�.
	*	@post	����.
	*	@return	���� ũ��.
	*/
	int GetBytes()
	{
		return m_fBytes;
	}

	/**
	*	@brief	���� ��¥ ��������.
	*	@pre	���� ��¥�� �����ؾ��Ѵ�.
	*	@post	����.
	*	@return	���� ��¥.
	*/
	string GetDate()
	{
		return m_fDate;
	}

	/**
	*	@brief	���� ���� ��������.
	*	@pre	���� ������ �����ؾ��Ѵ�.
	*	@post	����.
	*	@return	���� ����.
	*/
	int GetNumber()
	{
		return m_fNumber;
	}

	/**
	*	@brief	���� ���� ��������.
	*	@pre	���� ������ �����ؾ��Ѵ�.
	*	@post	����.
	*	@return	���� ����.
	*/
	int GetFileNumber()
	{
		return m_FileNumber;
	}

	/**
	*	@brief	���� ��ũ�� ����Ʈ ��������.
	*	@pre	���� ��ũ�� ����Ʈ�� �����ؾ��Ѵ�.
	*	@post	����.
	*	@return	���� ��ũ�� ����Ʈ ������.
	*/
	DoublySortedLinkedList<FolderType>* GetLinkedList()
	{
		return m_fLinkedList;
	}

	/**
	*	@brief	���� ����Ʈ ��������.
	*	@pre	���� ����Ʈ�� �����ؾ��Ѵ�.
	*	@post	����.
	*	@return	���� ����Ʈ ������.
	*/
	DoublySortedLinkedList<FileType>* GetFileList()
	{
		return m_FileList;
	}

	/**
	*	@brief	���� �̸� ����.
	*	@pre	����.
	*	@post	���� �̸��� �����ȴ�.
	*	@param	inName	���� �̸�.
	*/
	void SetName(string inName)
	{
		m_fName = inName;
	}

	/**
	*	@brief	���� ��ġ ����.
	*	@pre	����.
	*	@post	���� ��ġ�� �����ȴ�.
	*	@param	inAddress	���� ��ġ.
	*/
	void SetAddress(string inAddress)
	{
		m_fAddress = inAddress;
	}

	/**
	*	@brief	���� ũ�� ����.
	*	@pre	����.
	*	@post	���� ũ�Ⱑ �����ȴ�.
	*	@param	inBytes	���� ũ��.
	*/
	void SetBytes(int inBytes)
	{
		m_fBytes = inBytes;
	}

	/**
	*	@brief	���� ��¥ ����.
	*	@pre	����.
	*	@post	���� ��¥�� �����ȴ�.
	*	@param	inDate	���� ��¥.
	*/
	void SetDate(string inDate)
	{
		m_fDate = inDate;
	}

	/**
	*	@brief	���� ���� ����.
	*	@pre	����.
	*	@post	���� ������ �����ȴ�.
	*	@param	inNumber ���� ����.
	*/
	void SetNumber(int inNumber)
	{
		m_fNumber = inNumber;
	}

	/**
	*	@brief	���� ���� ����.
	*	@pre	����.
	*	@post	���� ������ �����ȴ�.
	*	@param	inNumber ���� ����.
	*/
	void SetFileNumber(int inFileNumber)
	{
		m_FileNumber = inFileNumber;
	}

	/**
	*	@brief	���� ��ũ�� ����Ʈ ����.
	*	@pre	����.
	*	@post	���� ��ũ�� ����Ʈ�� �����ȴ�.
	*	@param	inList ���� ��ũ�� ����Ʈ.
	*/
	void SetLinkedList(DoublySortedLinkedList<FolderType>* inLinkedList)
	{
		m_fLinkedList = inLinkedList;
	}

	/**
	*	@brief	���� ���� ���.
	*	@pre	����.
	*	@post	���� ������ �����ȴ�.
	*	@param	inName	���� �̸�.
	*	@param	inAddress	���� ��ġ.
	*	@param	inBytes	���� ũ��.
	*	@param	inDate	���� ��¥.
	*	@param	inNumber ���� ����.
	*	@param	inFileNumber ���� ����.
	*/
	void SetRecord(string inName, string inAddress, int inBytes, string inDate, int inNumber, int inFileNumber)
	{
		SetName(inName);
		SetAddress(inAddress);
		SetBytes(inBytes);
		SetDate(inDate);
		SetNumber(inNumber);
		SetFileNumber(inFileNumber);
	}

	/**
	*	@brief	���� �̸� ���.
	*	@pre	���� �̸��� �����ؾ��Ѵ�.
	*	@post	���� �̸��� ��µȴ�.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tName : " << m_fName << endl;
	};

	/**
	*	@brief	���� ��ġ ���.
	*	@pre	���� ��ġ�� �����ؾ��Ѵ�.
	*	@post	���� ��ġ�� ��µȴ�.
	*/
	void DisplayAddressOnScreen()
	{
		cout << "\tAddress : " << m_fAddress << endl;
	};

	/**
	*	@brief	���� ũ�� ���.
	*	@pre	���� ũ�Ⱑ �����ؾ��Ѵ�.
	*	@post	���� ũ�Ⱑ ��µȴ�.
	*/
	void DisplayBytesOnScreen()
	{
		cout << "\tBytes : " << m_fBytes << endl;
	};

	/**
	*	@brief	���� ��¥ ���.
	*	@pre	���� ��¥�� �����ؾ��Ѵ�.
	*	@post	���� ��¥�� ��µȴ�.
	*/
	void DisplayDateOnScreen()
	{
		cout << "\tDate : " << m_fDate << endl;
	};

	/**
	*	@brief	���� ���� ���.
	*	@pre	���� ������ �����ؾ��Ѵ�.
	*	@post	���� ������ ��µȴ�.
	*/
	void DisplayNumberOnScreen()
	{
		cout << "\tFolderNumber : " << m_fNumber << endl;
	};

	/**
	*	@brief	���� ���� ���.
	*	@pre	���� ������ �����ؾ��Ѵ�.
	*	@post	���� ������ ��µȴ�.
	*/
	void DisplayFileNumberOnScreen()
	{
		cout << "\tFileNumber : " << m_FileNumber << endl;
	};

	/**
	*	@brief	���� ��� Ƚ�� ���.
	*	@pre	���� ��� Ƚ���� �����ؾ��Ѵ�.
	*	@post	���� ��� Ƚ���� ��µȴ�.
	*/
	void DisplayOpenCountOnScreen()
	{
		cout << "\tOpenCount : " << m_OpenCount << endl;
	};

	/**
	*	@brief	���� ��ũ�� ����Ʈ ���.
	*	@pre	���� ��ũ�� ����Ʈ�� �����ؾ��Ѵ�.
	*	@post	���� ��ũ�� ����Ʈ�� ��µȴ�.
	*/
	void DisplayLinkedListOnScreen()
	{
		if (GetLinkedList() != NULL)
			GetLinkedList()->DisplayAll();
	};

	/**
	*	@brief	���� ����Ʈ ���.
	*	@pre	���� ����Ʈ�� �����ؾ��Ѵ�.
	*	@post	���� ����Ʈ�� ��µȴ�.
	*/
	void DisplayFileListOnScreen()
	{
		if (GetFileList() != NULL)
			GetFileList()->DisplayAll();
	};

	/**
	*	@brief	���� ���� ���.
	*	@pre	���� ������ �����ؾ��Ѵ�.
	*	@post	���� ������ ��µȴ�.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
		DisplayAddressOnScreen();
		DisplayBytesOnScreen();
		DisplayDateOnScreen();
		DisplayNumberOnScreen();
		DisplayFileNumberOnScreen();
		DisplayOpenCountOnScreen();
	};

	/**
	*	@brief	���� ���� �����͸� �����´�
	*	@pre	���� ������ �����ؾ��Ѵ�.
	*	@post	���� ���� ������ ��ȯ�ȴ�.
	*	@return	prevFolder.
	*/
	FolderType* GetPrevFolder()
	{
		return prevFolder;
	}

	/**
	*	@brief	���� ���� ������ ����.
	*	@pre	����.
	*	@post	���� ���� �����Ͱ� �����ȴ�.
	*	@param	inPrevFolder	���� ���� ������.
	*/
	void SetPrevFolder(FolderType* inPrevFolder)
	{
		prevFolder = inPrevFolder;
	}

	/**
	*	@brief	Count ��������
	*/
	int GetCount()
	{
		return m_OpenCount;
	}

	/**
	*	@brief	Count ���ϱ�
	*/
	void SetCount(int inCount)
	{
		m_OpenCount = inCount;
	}


	/**
	*	@brief	Ű����κ��� ���� �̸��� �Է¹޴´�.
	*	@pre	����.
	*	@post	���� �̸� set.
	*/
	void SetNameFromKB();
	/**
	*	@brief	�ڵ� ����
	*/
	void SetRecord_Auto();

	/**
	*	@brief	Ű����κ��� ���� ��ġ�� �Է¹޴´�.
	*	@pre	����.
	*	@post	���� ��ġ set.
	*/
	void SetAddressFromKB();

	/**
	*	@brief	Ű����κ��� ���� ũ�⸦ �Է¹޴´�.
	*	@pre	����.
	*	@post	���� ũ�� set.
	*/
	void SetBytesFromKB();

	/**
	*	@brief	Ű����κ��� ���� ��¥�� �Է¹޴´�.
	*	@pre	����.
	*	@post	���� ��¥ set.
	*/
	void SetDateFromKB();

	/**
	*	@brief	Ű����κ��� ���� ������ �Է¹޴´�.
	*	@pre	����.
	*	@post	���� ���� set.
	*/
	void SetNumberFromKB();

	/**
	*	@brief	Ű����κ��� ���� ������ �Է¹޴´�.
	*	@pre	����.
	*	@post	���� ���� set.
	*/
	void SetFileNumberFromKB();

	/**
	*	@brief	Ű����κ��� ���� ������ �Է¹޴´�.
	*	@pre	����.
	*	@post	���� ���� set.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	���� �ð� ��������.
	*	@pre	����.
	*	@post	���� �ð��� �����´�.
	*	@return	���� �ð�.
	*/
	string GetCurrentTimes();

	/**
	*	@brief	���� ������ ��� �����Ѵ�.
	*	@pre	�ش� ������ �����ؾ��Ѵ�.
	*	@post	���� ������ ��� �����ȴ�.
	*/
	void MakeEmpty();

	/**
	*	@brief	LinkedList�� �߰�
	*/
	int AddFolder_LL();
	/**
	*	@brief	LinkedList�� ������ ���� ����
	*/
	int AddFolder_LL_Restore(FolderType inFolder);
	/**
	*	@brief	LinkedList�� �߰�
	*/
	int AddFolder_LL(string name);
	/**
	*	@brief	LinkedList�� �߰��� ���� �Լ�
	*/
	int AddFolder_LL(FolderType inFolder);
	/**
	*	@brief	ViewMode ��¥ �� ������ ���� �Լ�
	*/
	void AddFolder_LL_D(FolderType inFolder);
	/**
	*	@brief	ViewMode ��� �� ������ ���� �Լ�
	*/
	void AddFolder_LL_C(FolderType inFolder);
	/**
	*	@brief	ViewMode ��¥ ���� ������ ���� �Լ�
	*/
	void AddFolder_LL_DR(FolderType inFolder);
	/**
	*	@brief	ViewMode ��� ���� ������ ���� �Լ�
	*/
	void AddFolder_LL_CR(FolderType inFolder);

	/**
	*	@brief	���� ���ϸ� �����Ѵ�.
	*	@pre	�ش� ������ �����ؾ��Ѵ�.
	*	@post	���� ���ϰ� �����ȴ�.
	*/
	int AddFile();
	/**
	*	@brief	���� ������ ���� �Լ�
	*/
	int AddFile_Restore(FileType inFile);
	/**
	*	@brief	���� �߰��� ���� �Լ�
	*/
	int AddFile(FileType inFile);
	/**
	*	@brief	ViewMode ��¥ �� ������ ���� �Լ�
	*/
	void AddFile_D(FileType inFile);
	/**
	*	@brief	ViewMode ��� �� ������ ���� �Լ�
	*/
	void AddFile_C(FileType inFile);
	/**
	*	@brief	ViewMode ��¥ ���� ������ ���� �Լ�
	*/
	void AddFile_DR(FileType inFile);
	/**
	*	@brief	ViewMode ��� ���� ������ ���� �Լ�
	*/
	void AddFile_CR(FileType inFile);
	/**
	*	@brief	count ����
	*/
	void AddCount();

	/**
	*	@brief	���� ������ �����Ѵ�.
	*	@pre	���� ������ �����ؾ��Ѵ�.
	*	@post	���� ������ ���ŵȴ�.
	*/
	void ReplaceFolder();

	/**
	*	@brief	���� ������ �����Ѵ�.
	*	@pre	���� ������ �����ؾ��Ѵ�.
	*	@post	���� ������ ���ŵȴ�.
	*/
	void ReplaceFiles();

	/**
	*	@brief	����Ʈũ�� ����.
	*	@pre	����Ʈ ũ�⸦ �޾ƿ´�.
	*	@post	����Ʈũ�Ⱑ ���ŵȴ�.
	*/
	int SetBytes_recursive(int bytes);

	/**
	*	@brief	���� ������ �˻��Ѵ�.
	*	@pre	���� ������ �����ؾ��Ѵ�.
	*	@post	���� ������ �˻��ȴ�.
	*/
	int RetrieveFolderByName(FolderType inData);

	/**
	*	@brief	���� ������ �˻��Ѵ�.
	*	@pre	���� ������ �����ؾ��Ѵ�.
	*	@post	���� ������ �˻��ȴ�.
	*/
	int RetrieveFileByName(FileType inData);

	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	student record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new student record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout);

	/**
	*	@brief	���� ��� ����.
	*/
	void ReplaceFolderByName();

	/**
	*	@brief	���� ����Ÿ������ Ȯ��.
	*/
	int isEqual(const FolderType &data);
	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item name.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.name < data.name,
	*			return GREATER if this.name > data.name then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByName(const FolderType &data);

	/**
	*	@brief	Compare two item types by item bytes.
	*/
	RelationType CompareByBytes(const FolderType &data);
	/**
	*	@brief	Compare two item types by item date.
	*/
	RelationType CompareByDate(const FolderType &data);
	/**
	*	@brief	Compare two item types by item count.
	*/
	RelationType CompareByCount(const FolderType &data);

	/**
	*	
	*	@brief	������ ���۷����� = �����ε�
	*/
	FolderType& operator= (const FolderType& data);
	/**
	*	@brief	������ ���۷����� < �����ε�
	*/
	bool operator< (const FolderType& data);
	/**
	*	@brief	������ ���۷����� == �����ε�
	*/
	bool operator== (const FolderType& data);

	/**
	*	@brief	���۷����� << �����ε�
	*/
	friend ostream& operator << (ostream& out, FolderType& data)
	{
		out << "\t���� �̸� : " << data.GetName() << endl;
		out << "\t���� ��ġ : " << data.GetAddress() << endl;
		out << "\t���� ũ�� : " << data.GetBytes() << endl;
		out << "\t���� ��¥ : " << data.GetDate() << endl;
		out << "\t���� ���� : " << data.GetNumber() << endl;
		out << "\t���� ���� : " << data.GetFileNumber() << endl;
		out << "\t��� Ƚ�� : " << data.GetCount() << endl;
		if(data.GetLinkedList()!=NULL)
			data.GetLinkedList()->DisplayAll();
		if (data.GetFileList() != NULL)
			data.GetFileList()->DisplayAll();
		return out;
	};
protected:
	string m_fName;		// ���� �̸�.
	string m_fAddress;	// ���� ��ġ.
	int m_fBytes;		// ���� ũ��.
	string m_fDate;		// ���� ��¥.
	int m_fNumber;		// ���� ����.
	int m_FileNumber;		// ���� ����.
	int m_OpenCount;	// ���� ��� Ƚ��.
	DoublySortedLinkedList<FolderType>* m_fLinkedList; //���� ����Ʈ.
	DoublySortedLinkedList<FileType>* m_FileList; //���� ����Ʈ.
	FolderType* prevFolder;	// ���� ����.
};

#endif	// _ITEMTYPE_H
