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
*	@brief 파일 타입 클래스.
*/
class FileType
{
public:
	/**
	*	@brief	기본 생성자.
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
	*	@brief 소멸자.
	*/
	~FileType()
	{
	}

	/**
	*	@brief	파일 이름 가져오기.
	*	@pre	파일 이름이 존재해야한다.
	*	@post	없음.
	*	@return	파일 이름.
	*/
	string GetName()
	{
		return m_fName;
	}

	/**
	*	@brief	파일 위치 가져오기.
	*	@pre	파일 위치가 존재해야한다.
	*	@post	없음.
	*	@return	파일 위치.
	*/
	string GetAddress()
	{
		return m_fAddress;
	}

	/**
	*	@brief	폴더 크기 가져오기.
	*	@pre	폴더 크기가 존재해야한다.
	*	@post	없음.
	*	@return	폴더 크기.
	*/
	int GetBytes()
	{
		return m_fBytes;
	}

	/**
	*	@brief	생성 날짜 가져오기.
	*	@pre	생성 날짜가 존재해야한다.
	*	@post	없음.
	*	@return	생성 날짜.
	*/
	string GetDate()
	{
		return m_fDate;
	}

	/**
	*	@brief	생성 날짜 가져오기.
	*	@pre	생성 날짜가 존재해야한다.
	*	@post	없음.
	*	@return	생성 날짜.
	*/
	string GetExtension()
	{
		return m_fExtension;
	}

	/**
	*	@brief	폴더 이름 지정.
	*	@pre	없음.
	*	@post	폴더 이름이 지정된다.
	*	@param	inName	폴더 이름.
	*/
	void SetName(string inName)
	{
		m_fName = inName;
	}

	/**
	*	@brief	폴더 위치 지정.
	*	@pre	없음.
	*	@post	폴더 위치가 지정된다.
	*	@param	inAddress	폴더 위치.
	*/
	void SetAddress(string inAddress)
	{
		m_fAddress = inAddress;
	}

	/**
	*	@brief	폴더 크기 지정.
	*	@pre	없음.
	*	@post	폴더 크기가 지정된다.
	*	@param	inBytes	폴더 크기.
	*/
	void SetBytes(int inBytes)
	{
		m_fBytes = inBytes;
	}

	/**
	*	@brief	생성 날짜 지정.
	*	@pre	없음.
	*	@post	생성 날짜가 지정된다.
	*	@param	inDate	생성 날짜.
	*/
	void SetDate(string inDate)
	{
		m_fDate = inDate;
	}

	/**
	*	@brief	수정 날짜 지정.
	*	@pre	없음.
	*	@post	수정 날짜가 지정된다.
	*	@param	inReplaceDate	수정 날짜.
	*/
	void SetReplaceDate(string inReplaceDate)
	{
		m_fReplaceDate = inReplaceDate;
	}

	/**
	*	@brief	실행 날짜 지정.
	*	@pre	없음.
	*	@post	실행 날짜가 지정된다.
	*	@param	inReplaceDate	실행 날짜.
	*/
	void SetExecuteDate(string inExecuteDate)
	{
		m_fExecuteDate = inExecuteDate;
	}

	/**
	*	@brief	생성 날짜 지정.
	*	@pre	없음.
	*	@post	생성 날짜가 지정된다.
	*	@param	inExtension	파일 확장자.
	*/
	void SetExtension(string inExtension)
	{
		m_fExtension = inExtension;
	}

	/**
	*	@brief	폴더 정보 기록.
	*	@pre	없음.
	*	@post	폴더 정보가 지정된다.
	*	@param	inName	폴더 이름.
	*	@param	inAddress	폴더 위치.
	*	@param	inBytes	폴더 크기.
	*	@param	inDate	생성 날짜.
	*	@param	inExtension 파일 확장자.
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
	*	@brief	폴더 이름 출력.
	*	@pre	폴더 이름이 존재해야한다.
	*	@post	폴더 이름이 출력된다.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tName : " << m_fName << endl;
	};

	/**
	*	@brief	폴더 위치 출력.
	*	@pre	폴더 위치가 존재해야한다.
	*	@post	폴더 위치가 출력된다.
	*/
	void DisplayAddressOnScreen()
	{
		cout << "\tAddress : " << m_fAddress << endl;
	};

	/**
	*	@brief	폴더 크기 출력.
	*	@pre	폴더 크기가 존재해야한다.
	*	@post	폴더 크기가 출력된다.
	*/
	void DisplayBytesOnScreen()
	{
		cout << "\tBytes : " << m_fBytes << endl;
	};

	/**
	*	@brief	생성 날짜 출력.
	*	@pre	생성 날짜가 존재해야한다.
	*	@post	생성 날짜가 출력된다.
	*/
	void DisplayDateOnScreen()
	{
		cout << "\tDate : " << m_fDate << endl;
	};

	/**
	*	@brief	파일 확장자 출력.
	*	@pre	파일 확장자가 존재해야한다.
	*	@post	파일 확장자가 출력된다.
	*/
	void DisplayExtensionOnScreen()
	{
		cout << "\tExtension : " << m_fExtension << endl;
	};

	/**
	*	@brief	파일 정보 출력.
	*	@pre	파일 정보가 존재해야한다.
	*	@post	파일 정보가 출력된다.
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
	*	@brief	키보드로부터 폴더 이름을 입력받는다.
	*	@pre	없음.
	*	@post	폴더 이름 set.
	*/
	void SetNameFromKB();

	/**
	*	@brief	키보드로부터 폴더 위치를 입력받는다.
	*	@pre	없음.
	*	@post	폴더 위치 set.
	*/
	void SetAddressFromKB();

	/**
	*	@brief	키보드로부터 폴더 크기를 입력받는다.
	*	@pre	없음.
	*	@post	폴더 크기 set.
	*/
	void SetBytesFromKB();

	/**
	*	@brief	키보드로부터 생성 날짜를 입력받는다.
	*	@pre	없음.
	*	@post	생성 날짜 set.
	*/
	void SetDateFromKB();

	/**
	*	@brief	키보드로부터 생성 날짜를 입력받는다.
	*	@pre	없음.
	*	@post	생성 날짜 set.
	*/
	void SetExtensionFromKB();

	/**
	*	@brief	키보드로부터 폴더 정보를 입력받는다.
	*	@pre	없음.
	*	@post	폴더 정보 set.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	현재 시간 가져오기.
	*	@pre	없음.
	*	@post	현재 시간을 가져온다.
	*	@return	현재 시간.
	*/
	string GetCurrentTimes();

	/**
	*	@brief	파일 비우기.
	*	@pre	없음.
	*	@post	파일 내용이 비워진다.
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
	*	@brief	같은지 확인
	*/

	int isEqual(const FileType &data);
	/**
	*
	*	@brief	이름으로 비교
	*/
	RelationType CompareByName(const FileType &data);
	/**
	*
	*	@brief	바이트 크기로 비교
	*/
	RelationType CompareByBytes(const FileType &data);
	/**
	*
	*	@brief	날짜로 비교
	*/
	RelationType CompareByDate(const FileType &data);
	/**
	*
	*	@brief	열어본순으로 비교
	*/
	RelationType CompareByCount(const FileType &data);
	/**
	*	
	*	@brief	연산자 오퍼레이터 = 
	*/
	FileType& operator=(const FileType& list);

	/**
	*
	*	@brief	연산자 오퍼레이터 <<
	*/
	bool operator<(const FileType& list);

	/**
	*
	*	@brief	연산자 오퍼레이터 ==
	*/

	bool operator==(const FileType& list);

	/**
	*
	*	@brief	 오퍼레이터 <<
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
	string m_fName;		// 폴더 이름.
	string m_fAddress;	// 폴더 위치.
	int m_fBytes;		// 폴더 크기.
	string m_fDate;		// 생성 날짜.
	string m_fReplaceDate;		// 수정 날짜.
	string m_fExecuteDate;		// 실행 날짜.
	string m_fExtension;// 파일 확장자.
	int m_OpenCount;// 파일 열어본 횟수.
};

#endif	// _FILETYPE_H