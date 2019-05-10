#include "Application.h"


//	프로그램 드라이버.
void Application::Run()
{
	int property = 0;
	InitialSetting(root);
	InitialSetting(Recycle);
	temp.MakeEmpty();
	while (1)
	{
		DisplayFolder();
		m_Command = GetCommand();
		switch (m_Command)
		{
		case 1:		// 폴더 관리.
			while (true)
			{
				system("cls");
				DisplayFolder();
				m_fCommand = GetFolderCommand();
				switch (m_fCommand)
				{
				case 1:		// 새로운 폴더 생성.
					NewFolder();
					break;
				case 2:		// 서브 폴더 삭제.
					DeleteFolder();
					break;
				case 3:		// 서브 폴더 이름 바꾸기.
					ReplaceFolder();
					break;
				case 4:		// 새로운 파일 생성.
					NewFile();
					break;
				case 5:		// 서브 파일 삭제.
					DeleteFiles();
					break;
				case 6:		// 서브 파일 이름 바꾸기.
					ReplaceFiles();
					break;
				case 7:		// 서브 폴더 잘라내기.
					CutFolder();
					break;
				case 8:		// 서브 폴더 잘라내기.
					CopyFolder();
					break;
				case 9:		// 서브 폴더 붙여넣기.
					PasteFolder();
					break;
				case 10:		// 서브 파일 잘라내기.
					CutFile();
					break;
				case 11:		// 서브 폴더 잘라내기.
					CopyFiles();
					break;
				case 12:		// 서브 파일 붙여넣기.
					PasteFile();
					break;
				case 13:		// 폴더 비우기.
					MakeEmpty();
					break;
				case 0:
					break;
				default:
					cout << "\tIllegal selection...\n";
					break;
				}	
				if (m_fCommand == 0)
					break;
			}
			break;
		case 2:		// 서브 폴더로 이동.
			MoveFolder();
			break;
		case 3:		// 서브 파일 열기.
			OpenFile();
			break;
		case 4:		// 상위 폴더 이동(큐).
			UpperFolder();
			break;
		case 5:
			GoRoot();
			break;
		case 6:		// 폴더 검색.
			RetrieveRecordByName();
			break;
		case 7:
			DisplayRecentlyFolder();
			break;
		case 8:
			DisplayRecentlyFile();
			break;
		case 9:		// 폴더 정보 출력.
			DisplayProperty();
			break;
		case 10:		// 폴더 정보 출력.
			GoRecycle();
			while (true)
			{
				system("cls");
				DisplayFolder(); 
				if(property == 1)
					DisplayProperty();
				m_fCommand = GetRecycleCommand();
				switch (m_fCommand)
				{
				case 1:		// 폴더 복원.
					RestoreFolder();
					break;
				case 2:		// 폴더 삭제.
					RemoveFolder();
					break;
				case 3:		// 파일 복원.
					RestoreFile();
					break;
				case 4:		// 파일 삭제
					RemoveFile();
					break;
				case 5:		// 휴지통 비우기.
					MakeEmpty();
					break;
				case 6:		// 휴지통 속성.
					ChangeProperty(property);
					break;
				case 0:		// 루트 폴더로 이동
					GoRoot();
					break;
				default:
					cout << "\tIllegal selection...\n";
					break;
				}
				if (m_fCommand == 0)
					break;
			}
			break;
		case 11:		// 뷰 모드
			ChangeViewMode();
			break;
		case 12:		// 자주 열어본 폴더
			DisplayFavorite();
			break;
		case 13:		// 즐겨찾기
			MakeBookMark();
			break;
		case 14:		// 즐겨찾기 비우기
			BookMark.MakeEmpty();
			break;
		case '0':
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

void Application::InitialSetting(FolderType& name)
{
	string target_directory;
	if(name.GetAddress() == "")
		target_directory = name.GetName();
	else
		target_directory = name.GetAddress() + "\\" + name.GetName();
	
	for (auto& dent : fs::directory_iterator(target_directory))
	{
		if (fs::is_directory(dent.status()))
		{
			FolderType temp;
			FolderType* tmpPtr;
			temp.SetName(dent.path().filename().string());
			name.AddFolder_LL(dent.path().filename().string());
			tmpPtr = name.GetLinkedList()->GetPoint(temp);
			InitialSetting(*tmpPtr);
			continue;
		}
		else if (fs::is_regular_file(dent.status()))
		{
			string fname ="";
			string extension = "";
			char *str = new char[dent.path().filename().string().length() + 1];
			strcpy(str, dent.path().filename().string().c_str());
			char* pch = strtok(str, ".");
			fname = pch;
			pch = strtok(NULL, ".");
			extension = pch;
			delete[] str;

			FileType dummy;
			dummy.SetName(fname);
			dummy.SetAddress(dent.path().parent_path().string());
			dummy.SetExtension(extension);
			dummy.SetBytes(fs::file_size(dent.path().string()));
			name.AddFile_Restore(dummy);
		}
	}
}

void Application::ChangeViewMode()
{
	system("cls");
	DisplayFolder();
	string command;
	cout << endl << endl;
	cout << "\t┏━━ ID ━━━  Command ━━━━━━━━━━━━┓" << endl;
	cout << "\t┃   0 : 이름 순 정렬\t\t┃" << endl;
	cout << "\t┃   1 : 날짜 순 정렬\t\t┃" << endl;
	cout << "\t┃   2 : 날짜 역순 정렬\t\t┃" << endl;
	cout << "\t┃   3 : 많이 열어본 순 정렬\t┃" << endl;
	cout << "\t┃   4 : 많이 열어본 역순 정렬\t┃" << endl;
	cout << "\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	if (atoi(command.c_str()))
		ViewMode = atoi(command.c_str());
	else
		ViewMode = 0;
	system("cls");
}

// 메뉴 출력.
int Application::GetCommand()
{
	string command;
	cout << endl << endl;
	cout << "\t┏━━ ID ━━━  Command ━━━━━━━━━━━━┓" << endl;
	cout << "\t┃   1 : 현재 폴더 관리\t\t┃" << endl;
	cout << "\t┃   2 : 폴더 열기\t\t┃" << endl;
	cout << "\t┃   3 : 파일 열기\t\t┃" << endl;
	cout << "\t┃   4 : 상위 폴더 이동\t\t┃" << endl;
	cout << "\t┃   5 : 최상위 폴더로 이동\t┃" << endl;
	cout << "\t┃   6 : 폴더 검색\t\t┃" << endl;
	cout << "\t┃   7 : 최근 열어본 폴더\t┃" << endl;
	cout << "\t┃   8 : 최근 열어본 파일\t┃" << endl;
	cout << "\t┃   9 : 현재 폴더 속성\t\t┃" << endl;
	cout << "\t┃  10 : 휴지통 바로가기 \t┃" << endl;
	cout << "\t┃  11 : 보기 모드\t\t┃" << endl;
	cout << "\t┃  12 : 자주 열어본 폴더\t┃" << endl;
	cout << "\t┃  13 : 즐겨찾기 추가\t\t┃" << endl;
	cout << "\t┃  14 : 즐겨찾기 비우기\t\t┃" << endl;
//	cout << "\t   9 : Write Data to File" << endl;
	cout << "\t┃   0 : Quit\t\t\t┃" << endl;
	cout << "\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	if (atoi(command.c_str()))
		return atoi(command.c_str());
	else if (command == "0")
		return 0;
	else
		return 100;
}


// 폴더 관리 메뉴 출력.
int Application::GetFolderCommand()
{
	string command;
	cout << endl << endl;
	cout << "\t┏━━ ID ━━━  Command ━━━━━━━━━━━━┓" << endl;
	cout << "\t┃   1 : 폴더 생성\t\t┃" << endl;
	cout << "\t┃   2 : 폴더 삭제\t\t┃" << endl;
	cout << "\t┃   3 : 폴더 갱신\t\t┃" << endl;
	cout << "\t┃   4 : 파일 생성\t\t┃" << endl;
	cout << "\t┃   5 : 파일 삭제\t\t┃" << endl;
	cout << "\t┃   6 : 파일 갱신\t\t┃" << endl;
	cout << "\t┃   7 : 폴더 잘라내기\t\t┃" << endl;
	cout << "\t┃   8 : 폴더 복사하기\t\t┃" << endl;
	cout << "\t┃   9 : 폴더 붙여넣기\t\t┃" << endl;
	cout << "\t┃  10 : 파일 잘라내기\t\t┃" << endl;
	cout << "\t┃  11 : 파일 복사하기\t\t┃" << endl;
	cout << "\t┃  12 : 파일 붙여넣기\t\t┃" << endl;
	cout << "\t┃  13 : 폴더 비우기\t\t┃" << endl;
	cout << "\t┃   0 : 뒤로 가기\t\t┃" << endl;
	cout << "\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	if (atoi(command.c_str()))
		return atoi(command.c_str());
	else
		return 0;
}


// 휴지통 메뉴 출력.
int Application::GetRecycleCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t┏━━ ID ━━━  Command ━━━━━━━━━━━━┓" << endl;
	cout << "\t┃   1 : 폴더 복원\t\t┃" << endl;
	cout << "\t┃   2 : 폴더 삭제\t\t┃" << endl;
	cout << "\t┃   3 : 파일 복원\t\t┃" << endl;
	cout << "\t┃   4 : 파일 삭제\t\t┃" << endl;
	cout << "\t┃   5 : 휴지통 비우기\t\t┃" << endl;
	cout << "\t┃   6 : 휴지통 속성\t\t┃" << endl;
	cout << "\t┃   0 : 루트 폴더로 이동\t┃" << endl;
	cout << "\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

//새로운 하위 폴더 생성.
int Application::NewFolder()
{
	if (curPoint->AddFolder_LL())
		return 1;
	else
	{
		cout << "\tAdd Folder Failed" << endl;
		return 0;
	}
		
}

//새로운 하위 파일 생성.
int Application::NewFile()
{
	if (curPoint->AddFile())
		return 1;
	else
	{
		cout << "\tAdd File Failed" << endl;
		return 0;
	}

}


//폴더 삭제.
int Application::DeleteFolder()
{
	if (curPoint->GetNumber() == 0)
	{
		cout << "\t<========No Folder EXISTED !=======>" << endl;
		return 0;
	}
	else
	{
		FolderType item;
		item.SetNameFromKB();
		
		FolderType* tmpPtr;

		tmpPtr = curPoint->GetLinkedList()->GetPoint(item);
		if (tmpPtr == NULL)
		{
			cout << "\t<========Folder Not EXISTED !=======>" << endl;
			return 0;
		}

		if (Recycle.GetLinkedList() != NULL)
		if (Recycle.GetLinkedList()->Get(item))
		{
			if (item.isEqual(*tmpPtr))
			{
				cout << "\t<========휴지통에 같은 폴더가 존재합니다 !=======>" << endl;
				return 0;
			}
			string choose;
			cout << "\t<========휴지통에 같은 이름의 폴더가 존재합니다 !=======>" << endl;
			cout << "\t<========영구 삭제를 진행 하시겠습니까 ? (Y(y)/else)=======>" << endl;
			cout << "\tChoose a Command--> ";
			cin >> choose;
			if (choose == "Y" || choose == "y")
			{
				curPoint->SetBytes_recursive(-(tmpPtr->GetBytes()));
				if (tmpPtr == &root)
					fs::remove_all(tmpPtr->GetName());
				else
					fs::remove_all(tmpPtr->GetAddress() + "\\" + tmpPtr->GetName());
				m_RecentlyFolder.Deduplication(tmpPtr);
				curPoint->GetLinkedList()->Delete(item);
				curPoint->SetNumber(curPoint->GetNumber() - 1);
				cout << "\t<========DELETE SUCCESS !===========>" << endl;
				return 1;
			}
			else
			{
				cout << "\t<========DELETE CANCELED !===========>" << endl;
				return 0;
			}
		}

		curPoint->SetBytes_recursive(-item.GetBytes());
		if (tmpPtr == &root)
			fs::rename(tmpPtr->GetName(), "Recycle\\" + tmpPtr->GetName());
		else
			fs::rename(tmpPtr->GetAddress() + "\\" + tmpPtr->GetName(),"Recycle\\" + tmpPtr->GetName());
		m_RecentlyFolder.Deduplication(tmpPtr);
		Recycle.AddFolder_LL_Restore(item);
		curPoint->GetLinkedList()->Delete(item);
		curPoint->SetNumber(curPoint->GetNumber() - 1);

		cout << "\t<========DELETE SUCCESS !===========>" << endl;
		return 1;
	}
}

//파일 삭제.
int Application::DeleteFiles()
{
	if (curPoint->GetFileNumber() == 0)
	{
		cout << "\t<========NO File EXISTED!===========>" << endl;
		return 0;
	}
	else
	{
		FileType item;
		item.SetNameFromKB();
		item.SetExtensionFromKB();
		FileType* tmpPtr;

		tmpPtr = curPoint->GetFileList()->GetPoint(item);
		if (tmpPtr == NULL)
		{
			cout << "\t<========File Doesn't EXISTED !=======>" << endl;
			return 0;
		}

		if (Recycle.GetFileList() != NULL)
			if (Recycle.GetFileList()->Get(item))
			{
				if (item.isEqual(*tmpPtr))
				{
					cout << "\t<========휴지통에 같은 폴더가 존재합니다 !=======>" << endl;
					return 0;
				}

				string choose;
				cout << "\t<========휴지통에 같은 이름의 파일이 존재합니다 !=======>" << endl;
				cout << "\t<========영구 삭제를 진행 하시겠습니까 ? (Y(y)/else)=======>" << endl;
				cout << "\tChoose a Command--> ";
				cin >> choose;
				if (choose == "Y" || choose == "y")
				{
					curPoint->SetBytes_recursive(-(tmpPtr->GetBytes()));
					fs::remove_all(tmpPtr->GetAddress() + "\\" + tmpPtr->GetName());
					m_RecentlyFile.Deduplication(tmpPtr);
					curPoint->GetFileList()->Delete(item);
					curPoint->SetFileNumber(curPoint->GetFileNumber() - 1);
					cout << "\t<========DELETE SUCCESS !===========>" << endl;
					return 1;
				}
				else
				{
					cout << "\t<========DELETE CANCELED !===========>" << endl;
					return 0;
				}
			}
		Recycle.AddFile_Restore(item);
		curPoint->SetBytes_recursive(-(tmpPtr->GetBytes()));
		fs::rename(tmpPtr->GetAddress() + "\\" + tmpPtr->GetName() + "." + tmpPtr->GetExtension(), "Recycle\\" + tmpPtr->GetName() + "." + tmpPtr->GetExtension());
		m_RecentlyFile.Deduplication(tmpPtr);
		curPoint->GetFileList()->Delete(item);
		curPoint->SetFileNumber(curPoint->GetFileNumber() - 1);

		cout << "\t<========DELETE SUCCESS !===========>" << endl;
		return 1;
	}


}


//폴더 갱신.
int Application::ReplaceFolder()
{
	if (curPoint->GetNumber() == 0)
	{
		cout << "\t<========NO FOLDER EXISTED!===========>" << endl;
		return 0;
	}
	
	curPoint->ReplaceFolder();
	return 1;
}


//파일 갱신.
int Application::ReplaceFiles()
{
	if (curPoint->GetFileNumber() == 0)
	{
		cout << "\t<========NO FILE EXISTED!===========>" << endl;
		return 0;
	}

	curPoint->ReplaceFiles();
	return 1;
}


//폴더 삭제.
int Application::CutFolder()
{
	if (curPoint->GetNumber() == 0)
	{
		cout << "\t<========No Folder EXISTED !=======>" << endl;
		return 0;
	}
	else
	{
		FolderType item;
		item.SetNameFromKB();

		FolderType* tmpPtr;

		tmpPtr = curPoint->GetLinkedList()->GetPoint(item);
		if (tmpPtr == NULL)
		{
			cout << "\t<========Folder Not EXISTED !=======>" << endl;
			return 0;
		}
		curPoint->SetNumber(curPoint->GetNumber() - 1);
		
		ReplicaFolder=item;

		curPoint->SetBytes(curPoint->GetBytes() - item.GetBytes());

		fs::rename(tmpPtr->GetAddress() + "\\" + tmpPtr->GetName() , "temp\\" + tmpPtr->GetName());
		m_RecentlyFolder.Deduplication(tmpPtr);
		curPoint->GetLinkedList()->Delete(item);

		return 1;
	}
}

//파일 잘라내기.
int Application::CutFile()
{
	if (curPoint->GetFileNumber() == 0)
	{
		cout << "\t<========NO File EXISTED!===========>" << endl;
		return 0;
	}
	else
	{
		FileType item;
		item.SetNameFromKB();
		item.SetExtensionFromKB();
		FileType* tmpPtr;

		tmpPtr = curPoint->GetFileList()->GetPoint(item);
		if (tmpPtr == NULL)
		{
			cout << "\t<========File Doesn't EXISTED !=======>" << endl;
			return 0;
		}

		curPoint->SetFileNumber(curPoint->GetFileNumber() - 1);

		ReplicaFile = item;

		curPoint->SetBytes(curPoint->GetBytes() - item.GetBytes());

		fs::rename(tmpPtr->GetAddress() + "\\" + tmpPtr->GetName() + "." + tmpPtr->GetExtension(), "temp\\" + tmpPtr->GetName() + "." + tmpPtr->GetExtension());
		m_RecentlyFile.Deduplication(tmpPtr);
		curPoint->GetFileList()->Delete(item);

		return 1;
	}


}


//폴더 삭제.
int Application::CopyFolder()
{
	if (curPoint->GetNumber() == 0)
	{
		cout << "\t<========No Folder EXISTED !=======>" << endl;
		return 0;
	}
	else
	{
		FolderType item;
		item.SetNameFromKB();

		FolderType* tmpPtr;

		tmpPtr = curPoint->GetLinkedList()->GetPoint(item);
		if (tmpPtr == NULL)
		{
			cout << "\t<========Folder Not EXISTED !=======>" << endl;
			return 0;
		}

		ReplicaFolder = item;

		curPoint->SetBytes(curPoint->GetBytes() + item.GetBytes());

		fs::copy(tmpPtr->GetAddress() + "\\" + tmpPtr->GetName(), "temp\\" + tmpPtr->GetName(),copy_options::recursive);
		return 1;
	}
}

//파일 삭제.
int Application::CopyFiles()
{
	if (curPoint->GetFileNumber() == 0)
	{
		cout << "\t<========NO File EXISTED!===========>" << endl;
		return 0;
	}
	else
	{
		FileType item;
		item.SetNameFromKB();
		item.SetExtensionFromKB();
		FileType* tmpPtr;

		tmpPtr = curPoint->GetFileList()->GetPoint(item);
		if (tmpPtr == NULL)
		{
			cout << "\t<========File Doesn't EXISTED !=======>" << endl;
			return 0;
		}

		ReplicaFile = item;

		curPoint->SetBytes(curPoint->GetBytes() + item.GetBytes());

		fs::copy(tmpPtr->GetAddress() + "\\" + tmpPtr->GetName() + "." + tmpPtr->GetExtension(), "temp\\" + tmpPtr->GetName() + "." + tmpPtr->GetExtension());
		return 1;
	}


}


//폴더 삭제.
int Application::PasteFolder()
{
	if (ReplicaFolder.GetName() == "")
	{
		cout << "\t<========붙여넣기할 폴더가 없습니다!=======>" << endl;
		return 0;
	}
	else
	{
		if (curPoint->AddFolder_LL(ReplicaFolder))
		{
			if(curPoint == &root)
				fs::rename("temp\\" + ReplicaFolder.GetName(), curPoint->GetName() + "\\" + ReplicaFolder.GetName());
			else
				fs::rename("temp\\" + ReplicaFolder.GetName(), curPoint->GetAddress() + "\\" + curPoint->GetName() + "\\" + ReplicaFolder.GetName());
			ReplicaFolder.MakeEmpty();
			return 1;
		}
		else
		{
			cout << "\tPaste Folder Failed" << endl;
			return 0;
		}
	}
}

//파일 삭제.
int Application::PasteFile()
{
	if (ReplicaFile.GetName() == "")
	{
		cout << "\t<========붙여넣기할 파일이 없습니다!=======>" << endl;
		return 0;
	}
	else
	{
		if (curPoint->AddFile(ReplicaFile))
		{
			if (curPoint == &root)
				fs::rename("temp\\" + ReplicaFile.GetName() + "." + ReplicaFile.GetExtension(), curPoint->GetName() + "\\" + ReplicaFile.GetName() + ReplicaFile.GetExtension());
			else
				fs::rename("temp\\" + ReplicaFile.GetName() + "." + ReplicaFile.GetExtension(), curPoint->GetAddress() + "\\" + curPoint->GetName() + "\\" + ReplicaFile.GetName() + "." + ReplicaFile.GetExtension());
			ReplicaFile.MakeEmpty();
			return 1;
		}
		else
		{
			cout << "\tPaste File Failed" << endl;
			return 0;
		}
	}
}

/**
*	@brief	새로운 폴더 추가.
*	@pre	리스트가 존재해야한다.
*	@post	새로운 폴더가 리스트에 추가된다.
*	@return	잘 작동되면 1을, 아닌경우에 0을 반환한다.
*/
void Application::MakeEmpty()
{
	curPoint->MakeEmpty();
}


// Display all records in the list on screen.
void Application::DisplayProperty()
{
	cout << "\n\tFolder Property" << endl;

	// list의 모든 데이터를 화면에 출력
	curPoint->DisplayRecordOnScreen();
}


// Display all records in the list on screen.
void Application::ChangeProperty(int& num)
{
	if (num == 0)
		num = 1;
	else
		num = 0;
}
// Display all records in the list on screen.
void Application::DisplayFolder()
{
	if (ViewMode == 1)
		DisplayFolder_D();
	else if (ViewMode == 2)
		DisplayFolder_DR();
	else if (ViewMode == 3)
		DisplayFolder_C();
	else if (ViewMode == 4)
		DisplayFolder_CR();
	else
		DisplayFolder_N();
}


// Display all records in the list on screen.
void Application::DisplayFolder_D()
{
	if (curPoint->GetAddress() == "")
		cout << "\n\tCurrent Path : root" << endl;
	else
		cout << "\n\tCurrent Path : " << curPoint->GetAddress() << endl;
	cout << "\n\t< " << curPoint->GetName() << "\t>" << "\t(날짜 순 정렬)" << endl;

	if (curPoint->GetNumber() == 0 && curPoint->GetFileNumber() == 0)
		cout << "\t이 폴더는 비어 있습니다." << endl << endl;
	if (curPoint->GetNumber() != 0)
	{
		// list의 모든 데이터를 화면에 출력
		FolderType tmp;
		int result = 0;

		FolderType* disPtr = &temp;

		DoublyIterator<FolderType> iter(*curPoint->GetLinkedList());
		// list의 모든 데이터를 추가
		while (iter.NotNull()) {
			disPtr->AddFolder_LL_D(tmp);
			iter.Next();
		}

		DoublyIterator<FolderType> iter2(*disPtr->GetLinkedList());
		int i = 0;
		while (iter2.NotNull()) {
			tmp = iter2.GetCurrentNode().data;
			if (result == 0) //처음 찾는 경우라면
				cout << "\t<============ \tFolder\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - ";
			tmp.DisplayNameOnScreen();
			result = 1;	//성공(1)
			iter2.Next();
		}
		if (result)	//발견한 경우
			cout << "\t<====================================>" << endl;
		else	//발견 못하는 경우
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
		disPtr->MakeEmpty();
	}
	if (curPoint->GetFileNumber() != 0)
	{
		// list의 모든 데이터를 화면에 출력
		FileType tmp;
		int result = 0;

		FolderType* disPtr = &temp;


		DoublyIterator<FileType> iter(*curPoint->GetFileList());
		// list의 모든 데이터를 추가
		while (iter.NotNull()) {
			disPtr->AddFile_D(tmp);
			iter.Next();
		}

		DoublyIterator<FileType> iter2(*disPtr->GetFileList());
		int i = 0;
		while (iter2.NotNull()) {
			tmp = iter2.GetCurrentNode().data;
			if (result == 0) //처음 찾는 경우라면
				cout << "\t<============ \tFile\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - " << tmp.GetName() << "." << tmp.GetExtension() << endl;;
			result = 1;	//성공(1)
			iter2.Next();
		}
		if (result)	//발견한 경우
			cout << "\t<====================================>" << endl;
		else	//발견 못하는 경우
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
		disPtr->MakeEmpty();
	}
	if (ReplicaFolder.GetName() != "")
	{
		cout << "\t클립보드에 저장된 폴더 : " << ReplicaFolder.GetName() << endl;
	}
	if (ReplicaFile.GetName() != "")
	{
		cout << "\t클립보드에 저장된 파일 : " << ReplicaFile.GetName() + "." + ReplicaFile.GetExtension() << endl;
	}


}


// Display all records in the list on screen.
void Application::DisplayFolder_DR()
{
	if (curPoint->GetAddress() == "")
		cout << "\n\tCurrent Path : root" << endl;
	else
		cout << "\n\tCurrent Path : " << curPoint->GetAddress() << endl;
	cout << "\n\t< " << curPoint->GetName() << "\t>" << "\t(날짜 역순 정렬)" << endl;

	if (curPoint->GetNumber() == 0 && curPoint->GetFileNumber() == 0)
		cout << "\t이 폴더는 비어 있습니다." << endl << endl;
	if (curPoint->GetNumber() != 0)
	{
		// list의 모든 데이터를 화면에 출력
		FolderType tmp;
		int result = 0;

		FolderType* disPtr = &temp;

		DoublyIterator<FolderType> iter(*curPoint->GetLinkedList());
		// list의 모든 데이터를 추가
		while (iter.NotNull()) {
			disPtr->AddFolder_LL_DR(tmp);
			iter.Next();
		}

		DoublyIterator<FolderType> iter2(*disPtr->GetLinkedList());
		int i = 0;
		while (iter2.NotNull()) {
			tmp = iter2.GetCurrentNode().data;
			if (result == 0) //처음 찾는 경우라면
				cout << "\t<============ \tFolder\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - ";
			tmp.DisplayNameOnScreen();
			result = 1;	//성공(1)
			iter2.Next();
		}
		if (result)	//발견한 경우
			cout << "\t<====================================>" << endl;
		else	//발견 못하는 경우
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
		disPtr->MakeEmpty();
	}
	if (curPoint->GetFileNumber() != 0)
	{
		// list의 모든 데이터를 화면에 출력
		FileType tmp;
		int result = 0;

		FolderType* disPtr = &temp;


		DoublyIterator<FileType> iter(*curPoint->GetFileList());
		// list의 모든 데이터를 추가
		while (iter.NotNull()) {
			disPtr->AddFile_DR(tmp);
			iter.Next();
		}

		DoublyIterator<FileType> iter2(*disPtr->GetFileList());
		int i = 0;
		while (iter2.NotNull()) {
			tmp = iter2.GetCurrentNode().data;
			if (result == 0) //처음 찾는 경우라면
				cout << "\t<============ \tFile\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - " << tmp.GetName() << "." << tmp.GetExtension() << endl;;
			result = 1;	//성공(1)
			iter2.Next();
		}
		if (result)	//발견한 경우
			cout << "\t<====================================>" << endl;
		else	//발견 못하는 경우
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
		disPtr->MakeEmpty();
	}
	if (ReplicaFolder.GetName() != "")
	{
		cout << "\t클립보드에 저장된 폴더 : " << ReplicaFolder.GetName() << endl;
	}
	if (ReplicaFile.GetName() != "")
	{
		cout << "\t클립보드에 저장된 파일 : " << ReplicaFile.GetName() + "." + ReplicaFile.GetExtension() << endl;
	}


}

// Display all records in the list on screen.
void Application::DisplayFolder_N()
{
	if(curPoint->GetAddress() == "")
		cout << "\n\tCurrent Path : root" << endl;
	else
		cout << "\n\tCurrent Path : " << curPoint->GetAddress() << endl;
	cout << "\n\t< " << curPoint->GetName() << "\t>"<< "\t(이름 순 정렬)" << endl;

	if (curPoint->GetNumber() == 0 && curPoint->GetFileNumber() ==0)
		cout << "\t이 폴더는 비어 있습니다." << endl << endl;
	if (curPoint->GetNumber() != 0)
	{
		// list의 모든 데이터를 화면에 출력
		FolderType tmp;
		int result = 0;

		DoublyIterator<FolderType> iter(*curPoint->GetLinkedList());
		int i = 0;
		iter.Next();
		while (iter.NextNotNull()) {
			tmp = iter.GetCurrentNode().data;
			if (result == 0) //처음 찾는 경우라면
				cout << "\t<============ \tFolder\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - ";
			tmp.DisplayNameOnScreen();
			result = 1;	//성공(1)
			iter.Next();
		}

		if (result)	//발견한 경우
			cout << "\t<====================================>" << endl;
		else	//발견 못하는 경우
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
	}
	if (curPoint->GetFileNumber() != 0)
	{
		// list의 모든 데이터를 화면에 출력
		FileType tmp;
		int result = 0;
		DoublyIterator<FileType> iter2(*curPoint->GetFileList());
		int i = 0;
		while (iter2.NotNull()) {
			tmp = iter2.GetCurrentNode().data;
			if (result == 0) //처음 찾는 경우라면
				cout << "\t<============ \tFile\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - " << tmp.GetName() << "." << tmp.GetExtension() << endl;;
			result = 1;	//성공(1)
			iter2.Next();
		}
		if (result)	//발견한 경우
			cout << "\t<====================================>" << endl;
		else	//발견 못하는 경우
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
	}
	if (ReplicaFolder.GetName() != "")
	{
		cout << "\t클립보드에 저장된 폴더 : " << ReplicaFolder.GetName() << endl;
	}
	if (ReplicaFile.GetName() != "")
	{
		cout << "\t클립보드에 저장된 파일 : " << ReplicaFile.GetName()+"."+ReplicaFile.GetExtension() << endl;
	}


}


// Display all records in the list on screen.
void Application::DisplayFolder_C()
{
	if (curPoint->GetAddress() == "")
		cout << "\n\tCurrent Path : root" << endl;
	else
		cout << "\n\tCurrent Path : " << curPoint->GetAddress() << endl;
	cout << "\n\t< " << curPoint->GetName() << "\t>" << "\t(많이 열어본 순 정렬)" << endl;

	if (curPoint->GetNumber() == 0 && curPoint->GetFileNumber() == 0)
		cout << "\t이 폴더는 비어 있습니다." << endl << endl;
	if (curPoint->GetNumber() != 0)
	{
		// list의 모든 데이터를 화면에 출력
		FolderType tmp;
		int result = 0;

		FolderType* disPtr = &temp;

		DoublyIterator<FolderType> iter(*curPoint->GetLinkedList());
		// list의 모든 데이터를 추가
		while (iter.NotNull()) {
			iter.Next();
			disPtr->AddFolder_LL_C(tmp);
		}

		DoublyIterator<FolderType> iter2(*disPtr->GetLinkedList());
		int i = 0;
		while (iter2.NotNull()) {
			iter2.Next();
			tmp = iter2.GetCurrentNode().data;
			if (result == 0) //처음 찾는 경우라면
				cout << "\t<============ \tFolder\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - ";
			tmp.DisplayNameOnScreen();
			result = 1;	//성공(1)
		}
		if (result)	//발견한 경우
			cout << "\t<====================================>" << endl;
		else	//발견 못하는 경우
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
		disPtr->MakeEmpty();
	}
	if (curPoint->GetFileNumber() != 0)
	{
		// list의 모든 데이터를 화면에 출력
		FileType tmp;
		int result = 0;

		FolderType* disPtr = &temp;


		DoublyIterator<FileType> iter(*curPoint->GetFileList());
		// list의 모든 데이터를 추가
		while (iter.NotNull()) {
			iter.Next();
			disPtr->AddFile_C(tmp);
		}

		DoublyIterator<FileType> iter2(*disPtr->GetFileList());
		int i = 0;
		while (iter2.NotNull()) {
			iter2.Next();
			tmp = iter2.GetCurrentNode().data;
			if (result == 0) //처음 찾는 경우라면
				cout << "\t<============ \tFile\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - " << tmp.GetName() << "." << tmp.GetExtension() << endl;;
			result = 1;	//성공(1)
		}
		if (result)	//발견한 경우
			cout << "\t<====================================>" << endl;
		else	//발견 못하는 경우
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
		disPtr->MakeEmpty();
	}
	if (ReplicaFolder.GetName() != "")
	{
		cout << "\t클립보드에 저장된 폴더 : " << ReplicaFolder.GetName() << endl;
	}
	if (ReplicaFile.GetName() != "")
	{
		cout << "\t클립보드에 저장된 파일 : " << ReplicaFile.GetName() + "." + ReplicaFile.GetExtension() << endl;
	}


}


// Display all records in the list on screen.
void Application::DisplayFolder_CR()
{
	if (curPoint->GetAddress() == "")
		cout << "\n\tCurrent Path : root" << endl;
	else
		cout << "\n\tCurrent Path : " << curPoint->GetAddress() << endl;
	cout << "\n\t< " << curPoint->GetName() << "\t>" << "\t(많이 열어본 역순 정렬)" << endl;

	if (curPoint->GetNumber() == 0 && curPoint->GetFileNumber() == 0)
		cout << "\t이 폴더는 비어 있습니다." << endl << endl;
	if (curPoint->GetNumber() != 0)
	{
		// list의 모든 데이터를 화면에 출력
		FolderType tmp;
		int result = 0;

		FolderType* disPtr = &temp;

		DoublyIterator<FolderType> iter(*curPoint->GetLinkedList());
		// list의 모든 데이터를 추가
		while (iter.NotNull()) {
			disPtr->AddFolder_LL_CR(tmp);
			iter.Next();
		}

		DoublyIterator<FolderType> iter2(*disPtr->GetLinkedList());
		int i = 0;
		while (iter2.NotNull()) {
			tmp = iter2.GetCurrentNode().data;
			if (result == 0) //처음 찾는 경우라면
				cout << "\t<============ \tFolder\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - ";
			tmp.DisplayNameOnScreen();
			result = 1;	//성공(1)
			iter2.Next();
		}
		if (result)	//발견한 경우
			cout << "\t<====================================>" << endl;
		else	//발견 못하는 경우
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
		disPtr->MakeEmpty();
	}
	if (curPoint->GetFileNumber() != 0)
	{
		// list의 모든 데이터를 화면에 출력
		FileType tmp;
		int result = 0;

		FolderType* disPtr = &temp;


		DoublyIterator<FileType> iter(*curPoint->GetFileList());
		// list의 모든 데이터를 추가
		while (iter.NotNull()) {
			disPtr->AddFile_CR(tmp);
			iter.Next();
		}

		DoublyIterator<FileType> iter2(*disPtr->GetFileList());
		int i = 0;
		while (iter2.NotNull()) {
			tmp = iter2.GetCurrentNode().data;
			if (result == 0) //처음 찾는 경우라면
				cout << "\t<============ \tFile\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - " << tmp.GetName() << "." << tmp.GetExtension() << endl;;
			result = 1;	//성공(1)
			iter2.Next();
		}
		if (result)	//발견한 경우
			cout << "\t<====================================>" << endl;
		else	//발견 못하는 경우
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
		disPtr->MakeEmpty();
	}
	if (ReplicaFolder.GetName() != "")
	{
		cout << "\t클립보드에 저장된 폴더 : " << ReplicaFolder.GetName() << endl;
	}
	if (ReplicaFile.GetName() != "")
	{
		cout << "\t클립보드에 저장된 파일 : " << ReplicaFile.GetName() + "." + ReplicaFile.GetExtension() << endl;
	}


}


// Display all records in the list on screen.
void Application::DisplayFavorite()
{
	if (BookMark.GetNumber() != 0)
	{

		// list의 모든 데이터를 화면에 출력
		FolderType tmp;
		int result = 0;


		DoublyIterator<FolderType> iter(*BookMark.GetLinkedList());
		int i = 0;
		while (iter.NotNull()) {
			tmp = iter.GetCurrentNode().data;
			if (result == 0) //처음 찾는 경우라면
				cout << "\t<============ \tBookMark\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - " << tmp.GetName() << "\t추가 날짜 : " << tmp.GetDate() << endl;
			result = 1;	//성공(1)
			iter.Next();
		}
	}
	if (Favorite.GetNumber() == 0 && Favorite.GetFileNumber() == 0)
		cout << "\t열어본 폴더나 파일이 없습니다." << endl << endl;
	if (Favorite.GetNumber() != 0)
	{
		// list의 모든 데이터를 화면에 출력
		FolderType tmp;
		int result = 0;


		DoublyIterator<FolderType> iter(*Favorite.GetLinkedList());
		int i = 0;
		while (iter.NotNull()) {
			iter.Next();
			tmp = iter.GetCurrentNode().data;
			if (result == 0) //처음 찾는 경우라면
				cout << "\t<============ \tFolder\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - " << tmp.GetName() << "\tCount : " << tmp.GetCount() << endl;
			result = 1;	//성공(1)
			iter.Next();
		}
		if (result)	//발견한 경우
			cout << "\t<====================================>" << endl;
		else	//발견 못하는 경우
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
	}
	if (Favorite.GetFileNumber() != 0)
	{
		// list의 모든 데이터를 화면에 출력
		FileType tmp;
		int result = 0;

		DoublyIterator<FileType> iter(*Favorite.GetFileList());
		int i = 0;
		while (iter.NotNull()) {
			iter.Next();
			tmp = iter.GetCurrentNode().data;
			if (result == 0) //처음 찾는 경우라면
				cout << "\t<============ \tFile\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - ";
			tmp.DisplayNameOnScreen();
			result = 1;	//성공(1)
		}
		if (result)	//발견한 경우
			cout << "\t<====================================>" << endl;
		else	//발견 못하는 경우
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;

	}

}

//폴더 이동한다.
int Application::MoveFolder()
{
	int moveTo = 0;
	cout << "\t[이름 순 정렬 기준] Move To Folder NO. : ";
	cin >> moveTo;
	if (moveTo > curPoint->GetNumber() || moveTo <= 0)
	{
		cout << "\t해당 폴더가 존재하지 않습니다.";
		return 0;
	}

	FolderType tmp;
	int result = 0;


	DoublyIterator<FolderType> iter(*curPoint->GetLinkedList());
	int count = 0;
	while (iter.NotNull()) {
		if (count >= moveTo - 1)
		{
			m_RecentlyFolder.Deduplication(iter.GetPoint());
			m_RecentlyFolder.EnQueue(iter.GetPoint());
			curPoint = iter.GetPoint();
			curPoint->AddCount();
			curPoint->DisplayRecordOnScreen();
			Favorite.AddFolder_LL_C(*curPoint);
			result = 1;	//성공(1)
			break;
		}
		count++;
		iter.Next();
	}

	return result;
}


//파일 이동한다.
int Application::OpenFile()
{
	int moveTo = 0;
	cout << "\tOpen File NO. : ";
	cin >> moveTo;
	if (moveTo > curPoint->GetFileNumber() || moveTo <= 0)
	{
		cout << "\t해당 파일이 존재하지 않습니다.";
		return 0;
	}

	FileType tmp;
	int result = 0;
	FileType* tmpPtr;


	DoublyIterator<FileType> iter(*curPoint->GetFileList());
	int count = 0;
	while (iter.NotNull()) {
		if (count >= moveTo - 1)
		{
			m_RecentlyFile.Deduplication(iter.GetPoint());
			m_RecentlyFile.EnQueue(iter.GetPoint());
			tmpPtr = iter.GetPoint();
			tmpPtr->DisplayRecordOnScreen();


			cout << "\tContent" << endl << "\t>>" << endl;
			string in_line;
			ifstream in(tmpPtr->GetAddress() + "\\" + tmpPtr->GetName() + "." + tmpPtr->GetExtension());
			while (getline(in, in_line))
			{
				cout << "\t\t" << in_line << endl;
			}
			in.close();
			tmpPtr->AddCount();
			tmpPtr->SetExecuteDate(tmp.GetCurrentTimes());
			ShellExecute(NULL, "open", (tmpPtr->GetAddress() + "\\" + tmpPtr->GetName() + "." + tmpPtr->GetExtension()).c_str(), NULL, NULL, SW_SHOW);
			result = 1;	//성공(1)
			break;
		}
		count++;
	}
	return result;
}



//폴더 이동한다.
int Application::UpperFolder()
{
	if (curPoint->GetPrevFolder() == NULL)
	{
		cout << "\t최상위 폴더 '"<< curPoint->GetName() << "' 입니다." <<endl;
		return 0;
	}
	else
	{
		m_RecentlyFolder.Deduplication(curPoint->GetPrevFolder());
		m_RecentlyFolder.EnQueue(curPoint->GetPrevFolder());
		curPoint = curPoint->GetPrevFolder();
		return 1;
	}
}


//폴더 이동한다.
int Application::GoRoot()
{
	curPoint = &root;
	m_RecentlyFolder.Deduplication(curPoint);
	m_RecentlyFolder.EnQueue(curPoint);
	if (curPoint != &root)
		return 0;
	return 1;
}


//폴더 이동한다.
int Application::GoRecycle()
{
	curPoint = &Recycle;
	if (curPoint != &Recycle)
		return 0;
	return 1;
}



// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}


//이름을 입력받은 item으로 리스트에서 item을 찾아서 출력한다.
int Application::RetrieveRecordByName()
{
	if (curPoint->GetNumber() == 0 && curPoint->GetFileNumber() == 0)
	{
		cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
		return 0;
	}
	FolderType item;
	item.SetNameFromKB(); //name을 입력받는다.

	if (SearchAll(item)) //0이 아니면(찾으면)
		return 1;	//성공(1)을 리턴
	return 0;	//실패(0)을 리턴
}


//이름으로 item을 찾아서 출력한다.
int Application::SearchAll(FolderType &inData)
{
	FileType tmp;
	tmp.SetName(inData.GetName());

	if (curPoint->RetrieveFolderByName(inData))
	{
		curPoint->RetrieveFileByName(tmp);
		return 1;
	}
	else
	{
		if (curPoint->RetrieveFileByName(tmp))
			return 1;
	}
	return 0;
}


//이름으로 item을 찾아서 출력한다.
int Application::SearchAllFolder(FolderType &inData)
{
	if (curPoint->RetrieveFolderByName(inData))
		return 1;
	else
		return 0;
}


//이름으로 item을 찾아서 출력한다.
int Application::SearchAllFile(FileType &inData)
{
	if (curPoint->RetrieveFileByName(inData))
		return 1;
	else
		return 0;
}


// Display all records in the list on screen.
void Application::DisplayRecentlyFolder()
{
	cout << "\n\tRecently Folder" << endl;

	FolderType* dummy;
	
	// list의 모든 데이터를 화면에 출력
	int m_iFront = m_RecentlyFolder.Front();
	int m_iRear = m_RecentlyFolder.Rear();
	int m_nMaxQueue = m_RecentlyFolder.MAX();
	for (int i = (m_iFront + 1) % m_nMaxQueue; i != (m_iRear + 1) % m_nMaxQueue; i = (i + 1) % m_nMaxQueue) //큐의 처음+1에서 출발해서 큐의 마지막까지 확인한다. 모든 검색시 mod로 순환하게 한다.
	{
		m_RecentlyFolder.DeQueue(dummy);
		m_RecentlyFolder.EnQueue(dummy);
		if(dummy != NULL)
			dummy->DisplayNameOnScreen();
	}
}


// Display all records in the list on screen.
void Application::DisplayRecentlyFile()
{
	cout << "\n\tRecently File" << endl;

	FileType* dummy;


	// list의 모든 데이터를 화면에 출력
	int m_iFront = m_RecentlyFile.Front();
	int m_iRear = m_RecentlyFile.Rear();
	int m_nMaxQueue = m_RecentlyFile.MAX();
	for (int i = (m_iFront + 1) % m_nMaxQueue; i != (m_iRear + 1) % m_nMaxQueue; i = (i + 1) % m_nMaxQueue) //큐의 처음+1에서 출발해서 큐의 마지막까지 확인한다. 모든 검색시 mod로 순환하게 한다.
	{
		m_RecentlyFile.DeQueue(dummy);
		m_RecentlyFile.EnQueue(dummy);
		if (dummy != NULL)
			dummy->DisplayNameOnScreen();
	}
}

int Application::RestoreFolder()
{
	if (Recycle.GetNumber() == 0)
	{
		cout << "\t휴지통에 폴더가 존재하지 않습니다.";
		return 0;
	}
	int moveTo = 0;
	cout << "\tRestore Folder No. : ";
	cin >> moveTo;
	if (moveTo > curPoint->GetNumber() || moveTo <= 0)
	{
		cout << "\t해당 폴더가 존재하지 않습니다.";
		return 0;
	}

	FolderType tmp;
	int result = 0;




	DoublyIterator<FolderType> iter(*curPoint->GetLinkedList());
	int count = 0;
	while (iter.NotNull()) {
		if (count >= moveTo - 1)
		{
			FolderType* tmpPtr;
			tmpPtr = iter.GetPoint();
			tmpPtr->GetPrevFolder()->AddFolder_LL_Restore(*tmpPtr);
			curPoint->SetBytes(curPoint->GetBytes() - tmpPtr->GetBytes());
			tmpPtr->DisplayRecordOnScreen();
			fs::rename("Recycle\\" + tmpPtr->GetName(), tmpPtr->GetAddress() + "\\" + tmpPtr->GetName());
			curPoint->GetLinkedList()->Delete(*tmpPtr);
			curPoint->SetNumber(curPoint->GetNumber() - 1);
			result = 1;	//성공(1)
			break;
		}
		iter.Next();
		count++;
	}
	return result;
}


//폴더 삭제.
int Application::RemoveFolder()
{
	if (curPoint->GetNumber() == 0)
	{
		cout << "\t<========No Folder EXISTED !=======>" << endl;
		return 0;
	}
	else
	{
		FolderType item;
		item.SetNameFromKB();

		FolderType* tmpPtr;

		tmpPtr = curPoint->GetLinkedList()->GetPoint(item);
		if (tmpPtr == NULL)
		{
			cout << "\t<========Folder Not EXISTED !=======>" << endl;
			return 0;
		}
		curPoint->SetBytes(curPoint->GetBytes() - item.GetBytes());
		if (tmpPtr == &root)
			remove_all(tmpPtr->GetName());
		else
			remove_all(tmpPtr->GetAddress() + "\\" + tmpPtr->GetName());
		curPoint->GetLinkedList()->Delete(item);
		curPoint->SetNumber(curPoint->GetNumber() - 1);

		cout << "\t<========DELETE SUCCESS !===========>" << endl;
		return 1;
	}
}

int Application::RestoreFile()
{
	if (Recycle.GetFileNumber() == 0)
	{
		cout << "\t휴지통에 파일이 존재하지 않습니다.";
		return 0;
	}
	int moveTo = 0;
	cout << "\tRestore File No. : ";
	cin >> moveTo;
	if (moveTo > curPoint->GetFileNumber() || moveTo <= 0)
	{
		cout << "\t해당 파일이 존재하지 않습니다.";
		return 0;
	}

	FileType tmp;
	int result = 0;

	DoublyIterator<FileType> iter(*curPoint->GetFileList());
	int count = 0;
	while (true) //리스트의 마지막까지 반복
	{
		iter.Next();
		if (count >= moveTo - 1)
		{
			FileType* tmpPtr = iter.GetPoint();
			FolderType* moveTo = &root;
			char *str = new char[tmpPtr->GetAddress().length() + 1];
			strcpy(str, tmpPtr->GetAddress().c_str());
			char* pch = strtok(str, "\\");
			pch = strtok(NULL, "\\");
			while (pch != NULL)
			{
				FolderType dummy;
				dummy.SetName(pch);
				if (moveTo->GetLinkedList() != NULL)
					moveTo = moveTo->GetLinkedList()->GetPoint(dummy);
				else
				{
					moveTo->AddFolder_LL(pch);
					moveTo = moveTo->GetLinkedList()->GetPoint(dummy);
				}
				pch = strtok(NULL, "\\");
			}
			delete[] str;
			moveTo->AddFile_Restore(*tmpPtr);
			curPoint->SetBytes(curPoint->GetBytes() - tmpPtr->GetBytes());
			tmpPtr->DisplayRecordOnScreen();
			fs::rename("Recycle\\" + tmpPtr->GetName() + "." + tmpPtr->GetExtension(), moveTo->GetAddress() + "\\" + tmpPtr->GetName() + "." + tmpPtr->GetExtension());
			curPoint->GetFileList()->Delete(*tmpPtr);
			curPoint->SetFileNumber(curPoint->GetFileNumber() - 1);
			result = 1;	//성공(1)
			break;
		}
		count++;
	}
	return result;
}

//파일 삭제.
int Application::RemoveFile()
{
	if (curPoint->GetFileNumber() == 0)
	{
		cout << "\t<========NO File EXISTED!===========>" << endl;
		return 0;
	}
	else
	{
		FileType item;
		item.SetNameFromKB();
		item.SetExtensionFromKB();
		FileType* tmpPtr;

		tmpPtr = curPoint->GetFileList()->GetPoint(item);
		if (tmpPtr == NULL)
		{
			cout << "\t<========File Doesn't EXISTED !=======>" << endl;
			return 0;
		}

		curPoint->SetBytes(curPoint->GetBytes() - item.GetBytes());

		remove(tmpPtr->GetAddress() + "\\" + tmpPtr->GetName() + "." + tmpPtr->GetExtension());
		curPoint->SetFileNumber(curPoint->GetFileNumber() - 1);

		cout << "\t<========DELETE SUCCESS !===========>" << endl;
		return 1;
	}


}

int Application::MakeBookMark()
{
	FolderType dummy = *curPoint;
	if (BookMark.GetLinkedList() != NULL)
		if(BookMark.GetLinkedList()->Get(dummy))
			BookMark.GetLinkedList()->Delete(dummy);
	dummy.SetDate(dummy.GetCurrentTimes());
	BookMark.AddFolder_LL_D(dummy);
	return 1;
}