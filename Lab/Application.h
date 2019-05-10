#pragma once
#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <time.h> //생성 시간.
#include <filesystem>
#include <Windows.h>
#include "FolderType.h"
#include "QueueType.h"
#include "DoublyLinkedList.h"
#include "DoublyIterator.h"


#define FILENAMESIZE 1024

namespace fs = std::experimental::filesystem;
/**
*	@brief	프로그램 드라이버 클래스.
*/
class Application
{
public:
	/**
	*	@brief	생성자.
	*/
	Application()
	{
		root.SetName("root");
		Recycle.SetName("Recycle");
		temp.SetName("temp");
		m_Command = 0;
		m_fCommand = 0;
		curPoint = &root;
		m_RecentlyFolder.EnQueue(&root);
		create_directory("root");
		create_directory("Recycle");
		create_directory("temp");
		ViewMode = 0;
	}

	/**
	*	@brief	소멸자.
	*/
	~Application() {}

	/**
	*	@brief	프로그램 드라이버.
	*	@pre	프로그램이 실행된다.
	*	@post	프로그램이 종료된다.
	*/
	void Run();

	/**
	*	@brief  화면에 뷰모드 커맨드를 띄우고 입력값을 입력받는다.
	*	@pre	없음.
	*	@post	커맨드값을 입력받는다.
	*/
	void ChangeViewMode();
	/**
	*	@brief  화면에 커맨드를 띄우고 입력값을 입력받는다.
	*	@pre	없음.
	*	@post	커맨드값을 입력받는다.
	*	@return	command
	*/
	int GetCommand();
	/**
	*	@brief  화면에 폴더 커맨드를 띄우고 입력값을 입력받는다.
	*	@pre	없음.
	*	@post	커맨드값을 입력받는다.
	*	@return	command
	*/
	int GetFolderCommand();
	/**
	*	@brief  화면에 휴지통 커맨드를 띄우고 입력값을 입력받는다.
	*	@pre	없음.
	*	@post	커맨드값을 입력받는다.
	*	@return	command
	*/
	int GetRecycleCommand();

	/**
	*	@brief	새로운 폴더 추가.
	*	@pre	리스트가 존재해야한다.
	*	@post	새로운 폴더가 리스트에 추가된다.
	*	@return	잘 작동되면 1을, 아닌경우에 0을 반환한다.
	*/
	int NewFolder();

	/**
	*	@brief	새로운 파일 추가.
	**/
	int NewFile();

	/**
	*	@brief	폴더 삭제.
	*	@pre	폴더가 리스트에 존재해야한다.
	*	@post	폴더가 리스트에서 삭제된다.
	*	@return	잘 작동되면 1을, 아닌경우에 0을 반환한다.
	*/
	int DeleteFolder();

	/**
	*	@brief	파일 삭제
	*/
	int DeleteFiles();


	/**
	*	@brief	폴더 갱신
	*/
	int ReplaceFolder();

	/**
	*	@brief	파일 갱신
	*/
	int ReplaceFiles();

	/**
	*	@brief	폴더 자르기
	*/
	int CutFolder();

	/**
	*	@brief	파일 자르기
	*/
	int CutFile();

	/**
	*	@brief	폴더 복사
	*/
	int CopyFolder();

	/**
	*	@brief	파일 복사
	*/
	int CopyFiles();

	/**
	*	@brief	폴더 붙여넣기
	*/
	int PasteFolder();

	/**
	*	@brief	파일 붙여넣기
	*/
	int PasteFile();

	/**
	*	@brief	파일 열기
	*/
	int OpenFile();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

	/**
	*	@brief	현재 폴더의 정보를 출력한다.
	*	@pre	폴더가 존재해야한다.
	*	@post	없음.
	*/
	void DisplayProperty();

	/**
	*	@brief	현재 폴더의 위치와 하위 폴더들을 출력한다.
	*	@pre	폴더가 존재해야한다.
	*	@post	없음.
	*/
	void DisplayFolder();

	/**
	*	@brief	폴더 이름 순 정렬
	*/
	void DisplayFolder_N();

	/**
	*	@brief	폴더 날짜 순 정렬
	*/
	void DisplayFolder_D();

	/**
	*	@brief	폴더 열어본 순 정렬
	*/
	void DisplayFolder_C();
//	void DisplayFolder_NR();

	/**
	*	@brief	폴더 날짜 역순 정렬
	*/
	void DisplayFolder_DR();

	/**
	*	@brief	폴더 열어본 역순 정렬
	*/
	void DisplayFolder_CR();

	/**
	*	@brief	자주 사용한 폴더와 파일 출력
	*/
	void DisplayFavorite();

	/**
	*	@brief	모든 폴더 제거.
	*	@pre	폴더가 존재해야한다.
	*	@post	모든 폴더가 제거된다.
	*/
	void MakeEmpty();


	/**
	*	@brief	폴더 이동.
	*	@pre	폴더가 존재해야한다.
	*	@post	폴더를 이동한다.
	*	@return	폴더가 이동하면 1을, 아닌경우에 0을 반환한다.
	*/
	int MoveFolder();


	/**
	*	@brief	상위 폴더 이동.
	*	@pre	상위 폴더가 존재해야한다.
	*	@post	상위 폴더로 이동한다.
	*	@return	상위 폴더로 이동하면 1을, 아닌경우에 0을 반환한다.
	*/
	int UpperFolder();



	/**
	*	@brief	하위 폴더 검색.
	*	@pre	하위 폴더가 존재해야한다.
	*	@post	하위 폴더를 검색한다.
	*	@return	검색이 성공하면 1을, 아닌경우에 0을 반환한다.
	*/
	int RetrieveRecordByName();


	/**
	*	@brief	폴더와 파일 검색.
	*	@pre	폴더이나 파일이 존재해야한다.
	*	@post	폴더와 파일을 검색한다.
	*	@return	검색이 성공하면 1을, 아닌경우에 0을 반환한다.
	*/
	int SearchAll(FolderType &inData);


	/**
	*	@brief	폴더 검색.
	*	@pre	폴더가 존재해야한다.
	*	@post	폴더를 검색한다.
	*	@return	검색이 성공하면 1을, 아닌경우에 0을 반환한다.
	*/
	int SearchAllFolder(FolderType &inData);


	/**
	*	@brief	파일 검색.
	*	@pre	파일이 존재해야한다.
	*	@post	파일을 검색한다.
	*	@return	검색이 성공하면 1을, 아닌경우에 0을 반환한다.
	*/
	int SearchAllFile(FileType &inData);


	/**
	*	@brief	최상위 폴더로 이동.
	*	@pre	루트 폴더가 존재해야한다.
	*	@post	최상위 폴더로 이동한다.
	*	@return	최상위 폴더로 이동하면 1을, 아닌경우에 0을 반환한다.
	*/
	int GoRoot();


	/**
	*	@brief	휴지통으로 이동.
	*	@pre	휴지통 폴더가 존재해야한다.
	*	@post	휴지통으로 이동한다.
	*	@return	휴지통 폴더로 이동하면 1을, 아닌경우에 0을 반환한다.
	*/
	int GoRecycle();


	/**
	*	@brief	최근 폴더 목록 출력.
	*	@pre	최근 폴더 목록이 존재해야한다.
	*	@post	최근 폴더 목록이 출력된다.
	*/
	void DisplayRecentlyFolder();

	/**
	*	@brief	최초셋팅. 폴더 파일 불러오기.
	*	@pre	없음.
	*	@post	기존 폴더와 파일들을 불러온다.
	*/
	void InitialSetting(FolderType& name);

	/**
	*	@brief	최근 파일 목록 출력.
	*	@pre	최근 파일 목록이 존재해야한다.
	*	@post	최근 파일 목록이 출력된다.
	*/
	void DisplayRecentlyFile();

	/**
	*	@brief	휴지통 폴더 복구.
	*/
	int RestoreFolder();

	/**
	*	@brief	휴지통 속성 보기.
	*/
	void ChangeProperty(int& num);

	/**
	*	@brief	휴지통 폴더 영구 삭제.
	*/
	int RemoveFolder();

	/**
	*	@brief	휴지통 파일 복구.
	*/
	int RestoreFile();

	/**
	*	@brief	휴지통 파일 영구 삭제.
	*/
	int RemoveFile();

	/**
	*	@brief	북마크 설정.
	*/
	int MakeBookMark();

private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	FolderType root;
	FolderType* curPoint;
	CircularQueueType<FolderType*> m_RecentlyFolder;
	CircularQueueType<FileType*> m_RecentlyFile;

	FolderType Recycle;

	FolderType ReplicaFolder;
	FileType ReplicaFile;

	FolderType BookMark;
	FolderType Favorite;
	FolderType temp;

	int ViewMode;
	int m_Command;			///< current command number.
	int m_fCommand;			///< current command number.
};

#endif	// _APPLICATION_H