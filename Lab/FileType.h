#pragma once
#ifndef _FILETYPE_H
#define _FILETYPE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>
#include "DoublyLinkedList.h"

using namespace std;




/**
*	@brief ���� Ÿ�� Ŭ����.
*/
class FileType
{
public:
	/**
	*	@brief	�⺻ ������.
	*/
	FileType()
	{
		m_fName = "";
		m_fAddress = "";
		m_fBytes = 0;
		m_fDate = GetCurrentTimes();
		m_fReplaceDate = m_fDate;
		m_fExecuteDate = m_fDate;
		m_fExtension = "";
		m_OpenCount = 0;
	}

	/**
	*	@brief �Ҹ���.
	*/
	~FileType()
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
	*	@brief	���� ��¥ ��������.
	*	@pre	���� ��¥�� �����ؾ��Ѵ�.
	*	@post	����.
	*	@return	���� ��¥.
	*/
	string GetExtension()
	{
		return m_fExtension;
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
	*	@brief	���� ��¥ ����.
	*	@pre	����.
	*	@post	���� ��¥�� �����ȴ�.
	*	@param	inReplaceDate	���� ��¥.
	*/
	void SetReplaceDate(string inReplaceDate)
	{
		m_fReplaceDate = inReplaceDate;
	}

	/**
	*	@brief	���� ��¥ ����.
	*	@pre	����.
	*	@post	���� ��¥�� �����ȴ�.
	*	@param	inReplaceDate	���� ��¥.
	*/
	void SetExecuteDate(string inExecuteDate)
	{
		m_fExecuteDate = inExecuteDate;
	}

	/**
	*	@brief	���� ��¥ ����.
	*	@pre	����.
	*	@post	���� ��¥�� �����ȴ�.
	*	@param	inExtension	���� Ȯ����.
	*/
	void SetExtension(string inExtension)
	{
		m_fExtension = inExtension;
	}

	/**
	*	@brief	���� ���� ���.
	*	@pre	����.
	*	@post	���� ������ �����ȴ�.
	*	@param	inName	���� �̸�.
	*	@param	inAddress	���� ��ġ.
	*	@param	inBytes	���� ũ��.
	*	@param	inDate	���� ��¥.
	*	@param	inExtension ���� Ȯ����.
	*/
	void SetRecord(string inName, string inAddress, int inBytes, string inDate, string inExtension)
	{
		SetName(inName);
		SetAddress(inAddress);
		SetBytes(inBytes);
		SetDate(inDate);
		SetExtension(inExtension);
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
	*	@brief	���� Ȯ���� ���.
	*	@pre	���� Ȯ���ڰ� �����ؾ��Ѵ�.
	*	@post	���� Ȯ���ڰ� ��µȴ�.
	*/
	void DisplayExtensionOnScreen()
	{
		cout << "\tExtension : " << m_fExtension << endl;
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
		DisplayExtensionOnScreen();
	};


	/**
	*	@brief	Ű����κ��� ���� �̸��� �Է¹޴´�.
	*	@pre	����.
	*	@post	���� �̸� set.
	*/
	void SetNameFromKB();

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
	*	@brief	Ű����κ��� ���� ��¥�� �Է¹޴´�.
	*	@pre	����.
	*	@post	���� ��¥ set.
	*/
	void SetExtensionFromKB();

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
	*	@brief	���� ����.
	*	@pre	����.
	*	@post	���� ������ �������.
	*/
	void MakeEmpty();

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
	void AddCount()
	{
		m_OpenCount++;
	}
	/**
	*
	*	@brief	������ Ȯ��
	*/

	int isEqual(const FileType &data);
	/**
	*
	*	@brief	�̸����� ��
	*/
	RelationType CompareByName(const FileType &data);
	/**
	*
	*	@brief	����Ʈ ũ��� ��
	*/
	RelationType CompareByBytes(const FileType &data);
	/**
	*
	*	@brief	��¥�� ��
	*/
	RelationType CompareByDate(const FileType &data);
	/**
	*
	*	@brief	��������� ��
	*/
	RelationType CompareByCount(const FileType &data);
	/**
	*	
	*	@brief	������ ���۷����� = 
	*/
	FileType& operator=(const FileType& list);

	/**
	*
	*	@brief	������ ���۷����� <<
	*/
	bool operator<(const FileType& list);

	/**
	*
	*	@brief	������ ���۷����� ==
	*/

	bool operator==(const FileType& list);

	/**
	*
	*	@brief	 ���۷����� <<
	*/
	friend ostream& operator << (ostream& out, FileType& data)
	{
		out << "\tName : " << data.GetName() << "." << data.GetExtension() << endl;
		out << "\tAddress : " << data.GetAddress() << endl;
		out << "\tBytes : " << data.GetBytes() << endl;
		out << "\tDates : " << data.GetDate() << endl;

		return out;
	};

protected:
	string m_fName;		// ���� �̸�.
	string m_fAddress;	// ���� ��ġ.
	int m_fBytes;		// ���� ũ��.
	string m_fDate;		// ���� ��¥.
	string m_fReplaceDate;		// ���� ��¥.
	string m_fExecuteDate;		// ���� ��¥.
	string m_fExtension;// ���� Ȯ����.
	int m_OpenCount;// ���� ��� Ƚ��.
};

#endif	// _FILETYPE_H