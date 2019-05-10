#pragma once
#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <time.h> //���� �ð�.
#include <filesystem>
#include <Windows.h>
#include "FolderType.h"
#include "QueueType.h"
#include "DoublyLinkedList.h"
#include "DoublyIterator.h"


#define FILENAMESIZE 1024

namespace fs = std::experimental::filesystem;
/**
*	@brief	���α׷� ����̹� Ŭ����.
*/
class Application
{
public:
	/**
	*	@brief	������.
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
	*	@brief	�Ҹ���.
	*/
	~Application() {}

	/**
	*	@brief	���α׷� ����̹�.
	*	@pre	���α׷��� ����ȴ�.
	*	@post	���α׷��� ����ȴ�.
	*/
	void Run();

	/**
	*	@brief  ȭ�鿡 ���� Ŀ�ǵ带 ���� �Է°��� �Է¹޴´�.
	*	@pre	����.
	*	@post	Ŀ�ǵ尪�� �Է¹޴´�.
	*/
	void ChangeViewMode();
	/**
	*	@brief  ȭ�鿡 Ŀ�ǵ带 ���� �Է°��� �Է¹޴´�.
	*	@pre	����.
	*	@post	Ŀ�ǵ尪�� �Է¹޴´�.
	*	@return	command
	*/
	int GetCommand();
	/**
	*	@brief  ȭ�鿡 ���� Ŀ�ǵ带 ���� �Է°��� �Է¹޴´�.
	*	@pre	����.
	*	@post	Ŀ�ǵ尪�� �Է¹޴´�.
	*	@return	command
	*/
	int GetFolderCommand();
	/**
	*	@brief  ȭ�鿡 ������ Ŀ�ǵ带 ���� �Է°��� �Է¹޴´�.
	*	@pre	����.
	*	@post	Ŀ�ǵ尪�� �Է¹޴´�.
	*	@return	command
	*/
	int GetRecycleCommand();

	/**
	*	@brief	���ο� ���� �߰�.
	*	@pre	����Ʈ�� �����ؾ��Ѵ�.
	*	@post	���ο� ������ ����Ʈ�� �߰��ȴ�.
	*	@return	�� �۵��Ǹ� 1��, �ƴѰ�쿡 0�� ��ȯ�Ѵ�.
	*/
	int NewFolder();

	/**
	*	@brief	���ο� ���� �߰�.
	**/
	int NewFile();

	/**
	*	@brief	���� ����.
	*	@pre	������ ����Ʈ�� �����ؾ��Ѵ�.
	*	@post	������ ����Ʈ���� �����ȴ�.
	*	@return	�� �۵��Ǹ� 1��, �ƴѰ�쿡 0�� ��ȯ�Ѵ�.
	*/
	int DeleteFolder();

	/**
	*	@brief	���� ����
	*/
	int DeleteFiles();


	/**
	*	@brief	���� ����
	*/
	int ReplaceFolder();

	/**
	*	@brief	���� ����
	*/
	int ReplaceFiles();

	/**
	*	@brief	���� �ڸ���
	*/
	int CutFolder();

	/**
	*	@brief	���� �ڸ���
	*/
	int CutFile();

	/**
	*	@brief	���� ����
	*/
	int CopyFolder();

	/**
	*	@brief	���� ����
	*/
	int CopyFiles();

	/**
	*	@brief	���� �ٿ��ֱ�
	*/
	int PasteFolder();

	/**
	*	@brief	���� �ٿ��ֱ�
	*/
	int PasteFile();

	/**
	*	@brief	���� ����
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
	*	@brief	���� ������ ������ ����Ѵ�.
	*	@pre	������ �����ؾ��Ѵ�.
	*	@post	����.
	*/
	void DisplayProperty();

	/**
	*	@brief	���� ������ ��ġ�� ���� �������� ����Ѵ�.
	*	@pre	������ �����ؾ��Ѵ�.
	*	@post	����.
	*/
	void DisplayFolder();

	/**
	*	@brief	���� �̸� �� ����
	*/
	void DisplayFolder_N();

	/**
	*	@brief	���� ��¥ �� ����
	*/
	void DisplayFolder_D();

	/**
	*	@brief	���� ��� �� ����
	*/
	void DisplayFolder_C();
//	void DisplayFolder_NR();

	/**
	*	@brief	���� ��¥ ���� ����
	*/
	void DisplayFolder_DR();

	/**
	*	@brief	���� ��� ���� ����
	*/
	void DisplayFolder_CR();

	/**
	*	@brief	���� ����� ������ ���� ���
	*/
	void DisplayFavorite();

	/**
	*	@brief	��� ���� ����.
	*	@pre	������ �����ؾ��Ѵ�.
	*	@post	��� ������ ���ŵȴ�.
	*/
	void MakeEmpty();


	/**
	*	@brief	���� �̵�.
	*	@pre	������ �����ؾ��Ѵ�.
	*	@post	������ �̵��Ѵ�.
	*	@return	������ �̵��ϸ� 1��, �ƴѰ�쿡 0�� ��ȯ�Ѵ�.
	*/
	int MoveFolder();


	/**
	*	@brief	���� ���� �̵�.
	*	@pre	���� ������ �����ؾ��Ѵ�.
	*	@post	���� ������ �̵��Ѵ�.
	*	@return	���� ������ �̵��ϸ� 1��, �ƴѰ�쿡 0�� ��ȯ�Ѵ�.
	*/
	int UpperFolder();



	/**
	*	@brief	���� ���� �˻�.
	*	@pre	���� ������ �����ؾ��Ѵ�.
	*	@post	���� ������ �˻��Ѵ�.
	*	@return	�˻��� �����ϸ� 1��, �ƴѰ�쿡 0�� ��ȯ�Ѵ�.
	*/
	int RetrieveRecordByName();


	/**
	*	@brief	������ ���� �˻�.
	*	@pre	�����̳� ������ �����ؾ��Ѵ�.
	*	@post	������ ������ �˻��Ѵ�.
	*	@return	�˻��� �����ϸ� 1��, �ƴѰ�쿡 0�� ��ȯ�Ѵ�.
	*/
	int SearchAll(FolderType &inData);


	/**
	*	@brief	���� �˻�.
	*	@pre	������ �����ؾ��Ѵ�.
	*	@post	������ �˻��Ѵ�.
	*	@return	�˻��� �����ϸ� 1��, �ƴѰ�쿡 0�� ��ȯ�Ѵ�.
	*/
	int SearchAllFolder(FolderType &inData);


	/**
	*	@brief	���� �˻�.
	*	@pre	������ �����ؾ��Ѵ�.
	*	@post	������ �˻��Ѵ�.
	*	@return	�˻��� �����ϸ� 1��, �ƴѰ�쿡 0�� ��ȯ�Ѵ�.
	*/
	int SearchAllFile(FileType &inData);


	/**
	*	@brief	�ֻ��� ������ �̵�.
	*	@pre	��Ʈ ������ �����ؾ��Ѵ�.
	*	@post	�ֻ��� ������ �̵��Ѵ�.
	*	@return	�ֻ��� ������ �̵��ϸ� 1��, �ƴѰ�쿡 0�� ��ȯ�Ѵ�.
	*/
	int GoRoot();


	/**
	*	@brief	���������� �̵�.
	*	@pre	������ ������ �����ؾ��Ѵ�.
	*	@post	���������� �̵��Ѵ�.
	*	@return	������ ������ �̵��ϸ� 1��, �ƴѰ�쿡 0�� ��ȯ�Ѵ�.
	*/
	int GoRecycle();


	/**
	*	@brief	�ֱ� ���� ��� ���.
	*	@pre	�ֱ� ���� ����� �����ؾ��Ѵ�.
	*	@post	�ֱ� ���� ����� ��µȴ�.
	*/
	void DisplayRecentlyFolder();

	/**
	*	@brief	���ʼ���. ���� ���� �ҷ�����.
	*	@pre	����.
	*	@post	���� ������ ���ϵ��� �ҷ��´�.
	*/
	void InitialSetting(FolderType& name);

	/**
	*	@brief	�ֱ� ���� ��� ���.
	*	@pre	�ֱ� ���� ����� �����ؾ��Ѵ�.
	*	@post	�ֱ� ���� ����� ��µȴ�.
	*/
	void DisplayRecentlyFile();

	/**
	*	@brief	������ ���� ����.
	*/
	int RestoreFolder();

	/**
	*	@brief	������ �Ӽ� ����.
	*/
	void ChangeProperty(int& num);

	/**
	*	@brief	������ ���� ���� ����.
	*/
	int RemoveFolder();

	/**
	*	@brief	������ ���� ����.
	*/
	int RestoreFile();

	/**
	*	@brief	������ ���� ���� ����.
	*/
	int RemoveFile();

	/**
	*	@brief	�ϸ�ũ ����.
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