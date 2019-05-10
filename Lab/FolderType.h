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
*	@brief 폴더 타입 클래스.
*/
class FolderType
{
public:
	/**
	*	@brief	기본 생성자.
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
	*	@brief 소멸자.
	*/
	~FolderType()
	{
	}

	/**
	*	@brief	폴더 이름 가져오기.
	*	@pre	폴더 이름이 존재해야한다.
	*	@post	없음.
	*	@return	폴더 이름.
	*/
	string GetName()
	{
		return m_fName;
	}

	/**
	*	@brief	폴더 위치 가져오기.
	*	@pre	폴더 위치가 존재해야한다.
	*	@post	없음.
	*	@return	폴더 위치.
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
	*	@brief	폴더 개수 가져오기.
	*	@pre	폴더 개수가 존재해야한다.
	*	@post	없음.
	*	@return	폴더 개수.
	*/
	int GetNumber()
	{
		return m_fNumber;
	}

	/**
	*	@brief	파일 개수 가져오기.
	*	@pre	파일 개수가 존재해야한다.
	*	@post	없음.
	*	@return	파일 개수.
	*/
	int GetFileNumber()
	{
		return m_FileNumber;
	}

	/**
	*	@brief	폴더 링크드 리스트 가져오기.
	*	@pre	폴더 링크드 리스트가 존재해야한다.
	*	@post	없음.
	*	@return	폴더 링크드 리스트 포인터.
	*/
	DoublySortedLinkedList<FolderType>* GetLinkedList()
	{
		return m_fLinkedList;
	}

	/**
	*	@brief	파일 리스트 가져오기.
	*	@pre	파일 리스트가 존재해야한다.
	*	@post	없음.
	*	@return	파일 리스트 포인터.
	*/
	DoublySortedLinkedList<FileType>* GetFileList()
	{
		return m_FileList;
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
	*	@brief	폴더 개수 지정.
	*	@pre	없음.
	*	@post	폴더 개수가 지정된다.
	*	@param	inNumber 폴더 개수.
	*/
	void SetNumber(int inNumber)
	{
		m_fNumber = inNumber;
	}

	/**
	*	@brief	파일 개수 지정.
	*	@pre	없음.
	*	@post	파일 개수가 지정된다.
	*	@param	inNumber 파일 개수.
	*/
	void SetFileNumber(int inFileNumber)
	{
		m_FileNumber = inFileNumber;
	}

	/**
	*	@brief	폴더 링크드 리스트 지정.
	*	@pre	없음.
	*	@post	폴더 링크드 리스트가 지정된다.
	*	@param	inList 폴더 링크드 리스트.
	*/
	void SetLinkedList(DoublySortedLinkedList<FolderType>* inLinkedList)
	{
		m_fLinkedList = inLinkedList;
	}

	/**
	*	@brief	폴더 정보 기록.
	*	@pre	없음.
	*	@post	폴더 정보가 지정된다.
	*	@param	inName	폴더 이름.
	*	@param	inAddress	폴더 위치.
	*	@param	inBytes	폴더 크기.
	*	@param	inDate	생성 날짜.
	*	@param	inNumber 폴더 개수.
	*	@param	inFileNumber 파일 개수.
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
	*	@brief	폴더 개수 출력.
	*	@pre	폴더 개수가 존재해야한다.
	*	@post	폴더 개수가 출력된다.
	*/
	void DisplayNumberOnScreen()
	{
		cout << "\tFolderNumber : " << m_fNumber << endl;
	};

	/**
	*	@brief	파일 개수 출력.
	*	@pre	파일 개수가 존재해야한다.
	*	@post	파일 개수가 출력된다.
	*/
	void DisplayFileNumberOnScreen()
	{
		cout << "\tFileNumber : " << m_FileNumber << endl;
	};

	/**
	*	@brief	폴더 열어본 횟수 출력.
	*	@pre	폴더 열어본 횟수가 존재해야한다.
	*	@post	폴더 열어본 횟수가 출력된다.
	*/
	void DisplayOpenCountOnScreen()
	{
		cout << "\tOpenCount : " << m_OpenCount << endl;
	};

	/**
	*	@brief	폴더 링크드 리스트 출력.
	*	@pre	폴더 링크드 리스트가 존재해야한다.
	*	@post	폴더 링크드 리스트가 출력된다.
	*/
	void DisplayLinkedListOnScreen()
	{
		if (GetLinkedList() != NULL)
			GetLinkedList()->DisplayAll();
	};

	/**
	*	@brief	파일 리스트 출력.
	*	@pre	파일 리스트가 존재해야한다.
	*	@post	파일 리스트가 출력된다.
	*/
	void DisplayFileListOnScreen()
	{
		if (GetFileList() != NULL)
			GetFileList()->DisplayAll();
	};

	/**
	*	@brief	폴더 정보 출력.
	*	@pre	폴더 정보가 존재해야한다.
	*	@post	폴더 정보가 출력된다.
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
	*	@brief	이전 폴더 포인터를 가져온다
	*	@pre	이전 폴더가 존재해야한다.
	*	@post	이전 폴더 정보가 반환된다.
	*	@return	prevFolder.
	*/
	FolderType* GetPrevFolder()
	{
		return prevFolder;
	}

	/**
	*	@brief	이전 폴더 포인터 지정.
	*	@pre	없음.
	*	@post	이전 폴더 포인터가 지정된다.
	*	@param	inPrevFolder	이전 폴더 포인터.
	*/
	void SetPrevFolder(FolderType* inPrevFolder)
	{
		prevFolder = inPrevFolder;
	}

	/**
	*	@brief	Count 가져오기
	*/
	int GetCount()
	{
		return m_OpenCount;
	}

	/**
	*	@brief	Count 정하기
	*/
	void SetCount(int inCount)
	{
		m_OpenCount = inCount;
	}


	/**
	*	@brief	키보드로부터 폴더 이름을 입력받는다.
	*	@pre	없음.
	*	@post	폴더 이름 set.
	*/
	void SetNameFromKB();
	/**
	*	@brief	자동 셋팅
	*/
	void SetRecord_Auto();

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
	*	@brief	키보드로부터 폴더 개수를 입력받는다.
	*	@pre	없음.
	*	@post	폴더 개수 set.
	*/
	void SetNumberFromKB();

	/**
	*	@brief	키보드로부터 파일 개수를 입력받는다.
	*	@pre	없음.
	*	@post	파일 개수 set.
	*/
	void SetFileNumberFromKB();

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
	*	@brief	서브 폴더를 모두 삭제한다.
	*	@pre	해당 폴더가 존재해야한다.
	*	@post	서브 폴더가 모두 삭제된다.
	*/
	void MakeEmpty();

	/**
	*	@brief	LinkedList에 추가
	*/
	int AddFolder_LL();
	/**
	*	@brief	LinkedList에 휴지통 폴더 복구
	*/
	int AddFolder_LL_Restore(FolderType inFolder);
	/**
	*	@brief	LinkedList에 추가
	*/
	int AddFolder_LL(string name);
	/**
	*	@brief	LinkedList에 추가를 위한 함수
	*/
	int AddFolder_LL(FolderType inFolder);
	/**
	*	@brief	ViewMode 날짜 순 정렬을 위한 함수
	*/
	void AddFolder_LL_D(FolderType inFolder);
	/**
	*	@brief	ViewMode 열어본 순 정렬을 위한 함수
	*/
	void AddFolder_LL_C(FolderType inFolder);
	/**
	*	@brief	ViewMode 날짜 역순 정렬을 위한 함수
	*/
	void AddFolder_LL_DR(FolderType inFolder);
	/**
	*	@brief	ViewMode 열어본 역순 정렬을 위한 함수
	*/
	void AddFolder_LL_CR(FolderType inFolder);

	/**
	*	@brief	서브 파일를 생성한다.
	*	@pre	해당 폴더가 존재해야한다.
	*	@post	서브 파일가 생성된다.
	*/
	int AddFile();
	/**
	*	@brief	파일 복구를 위한 함수
	*/
	int AddFile_Restore(FileType inFile);
	/**
	*	@brief	파일 추가를 위한 함수
	*/
	int AddFile(FileType inFile);
	/**
	*	@brief	ViewMode 날짜 순 정렬을 위한 함수
	*/
	void AddFile_D(FileType inFile);
	/**
	*	@brief	ViewMode 열어본 순 정렬을 위한 함수
	*/
	void AddFile_C(FileType inFile);
	/**
	*	@brief	ViewMode 날짜 역순 정렬을 위한 함수
	*/
	void AddFile_DR(FileType inFile);
	/**
	*	@brief	ViewMode 열어본 역순 정렬을 위한 함수
	*/
	void AddFile_CR(FileType inFile);
	/**
	*	@brief	count 증가
	*/
	void AddCount();

	/**
	*	@brief	서브 폴더를 갱신한다.
	*	@pre	서브 폴더가 존재해야한다.
	*	@post	서브 폴더가 갱신된다.
	*/
	void ReplaceFolder();

	/**
	*	@brief	서브 파일을 갱신한다.
	*	@pre	서브 파일이 존재해야한다.
	*	@post	서브 파일이 갱신된다.
	*/
	void ReplaceFiles();

	/**
	*	@brief	바이트크기 갱신.
	*	@pre	바이트 크기를 받아온다.
	*	@post	바이트크기가 갱신된다.
	*/
	int SetBytes_recursive(int bytes);

	/**
	*	@brief	서브 폴더를 검색한다.
	*	@pre	서브 폴더가 존재해야한다.
	*	@post	서브 폴더가 검색된다.
	*/
	int RetrieveFolderByName(FolderType inData);

	/**
	*	@brief	서브 파일을 검색한다.
	*	@pre	서브 파일이 존재해야한다.
	*	@post	서브 파일이 검색된다.
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
	*	@brief	폴더 경로 변경.
	*/
	void ReplaceFolderByName();

	/**
	*	@brief	같은 폴더타입인지 확인.
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
	*	@brief	연산자 오퍼레이터 = 오버로딩
	*/
	FolderType& operator= (const FolderType& data);
	/**
	*	@brief	연산자 오퍼레이터 < 오버로딩
	*/
	bool operator< (const FolderType& data);
	/**
	*	@brief	연산자 오퍼레이터 == 오버로딩
	*/
	bool operator== (const FolderType& data);

	/**
	*	@brief	오퍼레이터 << 오버로딩
	*/
	friend ostream& operator << (ostream& out, FolderType& data)
	{
		out << "\t폴더 이름 : " << data.GetName() << endl;
		out << "\t폴더 위치 : " << data.GetAddress() << endl;
		out << "\t폴더 크기 : " << data.GetBytes() << endl;
		out << "\t생성 날짜 : " << data.GetDate() << endl;
		out << "\t폴더 개수 : " << data.GetNumber() << endl;
		out << "\t파일 개수 : " << data.GetFileNumber() << endl;
		out << "\t열어본 횟수 : " << data.GetCount() << endl;
		if(data.GetLinkedList()!=NULL)
			data.GetLinkedList()->DisplayAll();
		if (data.GetFileList() != NULL)
			data.GetFileList()->DisplayAll();
		return out;
	};
protected:
	string m_fName;		// 폴더 이름.
	string m_fAddress;	// 폴더 위치.
	int m_fBytes;		// 폴더 크기.
	string m_fDate;		// 생성 날짜.
	int m_fNumber;		// 폴더 개수.
	int m_FileNumber;		// 폴더 개수.
	int m_OpenCount;	// 폴더 열어본 횟수.
	DoublySortedLinkedList<FolderType>* m_fLinkedList; //폴더 리스트.
	DoublySortedLinkedList<FileType>* m_FileList; //파일 리스트.
	FolderType* prevFolder;	// 이전 폴더.
};

#endif	// _ITEMTYPE_H
