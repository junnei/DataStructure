#include "Application.h"


//	���α׷� ����̹�.
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
		case 1:		// ���� ����.
			while (true)
			{
				system("cls");
				DisplayFolder();
				m_fCommand = GetFolderCommand();
				switch (m_fCommand)
				{
				case 1:		// ���ο� ���� ����.
					NewFolder();
					break;
				case 2:		// ���� ���� ����.
					DeleteFolder();
					break;
				case 3:		// ���� ���� �̸� �ٲٱ�.
					ReplaceFolder();
					break;
				case 4:		// ���ο� ���� ����.
					NewFile();
					break;
				case 5:		// ���� ���� ����.
					DeleteFiles();
					break;
				case 6:		// ���� ���� �̸� �ٲٱ�.
					ReplaceFiles();
					break;
				case 7:		// ���� ���� �߶󳻱�.
					CutFolder();
					break;
				case 8:		// ���� ���� �߶󳻱�.
					CopyFolder();
					break;
				case 9:		// ���� ���� �ٿ��ֱ�.
					PasteFolder();
					break;
				case 10:		// ���� ���� �߶󳻱�.
					CutFile();
					break;
				case 11:		// ���� ���� �߶󳻱�.
					CopyFiles();
					break;
				case 12:		// ���� ���� �ٿ��ֱ�.
					PasteFile();
					break;
				case 13:		// ���� ����.
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
		case 2:		// ���� ������ �̵�.
			MoveFolder();
			break;
		case 3:		// ���� ���� ����.
			OpenFile();
			break;
		case 4:		// ���� ���� �̵�(ť).
			UpperFolder();
			break;
		case 5:
			GoRoot();
			break;
		case 6:		// ���� �˻�.
			RetrieveRecordByName();
			break;
		case 7:
			DisplayRecentlyFolder();
			break;
		case 8:
			DisplayRecentlyFile();
			break;
		case 9:		// ���� ���� ���.
			DisplayProperty();
			break;
		case 10:		// ���� ���� ���.
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
				case 1:		// ���� ����.
					RestoreFolder();
					break;
				case 2:		// ���� ����.
					RemoveFolder();
					break;
				case 3:		// ���� ����.
					RestoreFile();
					break;
				case 4:		// ���� ����
					RemoveFile();
					break;
				case 5:		// ������ ����.
					MakeEmpty();
					break;
				case 6:		// ������ �Ӽ�.
					ChangeProperty(property);
					break;
				case 0:		// ��Ʈ ������ �̵�
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
		case 11:		// �� ���
			ChangeViewMode();
			break;
		case 12:		// ���� ��� ����
			DisplayFavorite();
			break;
		case 13:		// ���ã��
			MakeBookMark();
			break;
		case 14:		// ���ã�� ����
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
	cout << "\t������ ID ������  Command ��������������������������" << endl;
	cout << "\t��   0 : �̸� �� ����\t\t��" << endl;
	cout << "\t��   1 : ��¥ �� ����\t\t��" << endl;
	cout << "\t��   2 : ��¥ ���� ����\t\t��" << endl;
	cout << "\t��   3 : ���� ��� �� ����\t��" << endl;
	cout << "\t��   4 : ���� ��� ���� ����\t��" << endl;
	cout << "\t������������������������������������������������������������������" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	if (atoi(command.c_str()))
		ViewMode = atoi(command.c_str());
	else
		ViewMode = 0;
	system("cls");
}

// �޴� ���.
int Application::GetCommand()
{
	string command;
	cout << endl << endl;
	cout << "\t������ ID ������  Command ��������������������������" << endl;
	cout << "\t��   1 : ���� ���� ����\t\t��" << endl;
	cout << "\t��   2 : ���� ����\t\t��" << endl;
	cout << "\t��   3 : ���� ����\t\t��" << endl;
	cout << "\t��   4 : ���� ���� �̵�\t\t��" << endl;
	cout << "\t��   5 : �ֻ��� ������ �̵�\t��" << endl;
	cout << "\t��   6 : ���� �˻�\t\t��" << endl;
	cout << "\t��   7 : �ֱ� ��� ����\t��" << endl;
	cout << "\t��   8 : �ֱ� ��� ����\t��" << endl;
	cout << "\t��   9 : ���� ���� �Ӽ�\t\t��" << endl;
	cout << "\t��  10 : ������ �ٷΰ��� \t��" << endl;
	cout << "\t��  11 : ���� ���\t\t��" << endl;
	cout << "\t��  12 : ���� ��� ����\t��" << endl;
	cout << "\t��  13 : ���ã�� �߰�\t\t��" << endl;
	cout << "\t��  14 : ���ã�� ����\t\t��" << endl;
//	cout << "\t   9 : Write Data to File" << endl;
	cout << "\t��   0 : Quit\t\t\t��" << endl;
	cout << "\t������������������������������������������������������������������" << endl;

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


// ���� ���� �޴� ���.
int Application::GetFolderCommand()
{
	string command;
	cout << endl << endl;
	cout << "\t������ ID ������  Command ��������������������������" << endl;
	cout << "\t��   1 : ���� ����\t\t��" << endl;
	cout << "\t��   2 : ���� ����\t\t��" << endl;
	cout << "\t��   3 : ���� ����\t\t��" << endl;
	cout << "\t��   4 : ���� ����\t\t��" << endl;
	cout << "\t��   5 : ���� ����\t\t��" << endl;
	cout << "\t��   6 : ���� ����\t\t��" << endl;
	cout << "\t��   7 : ���� �߶󳻱�\t\t��" << endl;
	cout << "\t��   8 : ���� �����ϱ�\t\t��" << endl;
	cout << "\t��   9 : ���� �ٿ��ֱ�\t\t��" << endl;
	cout << "\t��  10 : ���� �߶󳻱�\t\t��" << endl;
	cout << "\t��  11 : ���� �����ϱ�\t\t��" << endl;
	cout << "\t��  12 : ���� �ٿ��ֱ�\t\t��" << endl;
	cout << "\t��  13 : ���� ����\t\t��" << endl;
	cout << "\t��   0 : �ڷ� ����\t\t��" << endl;
	cout << "\t������������������������������������������������������������������" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	if (atoi(command.c_str()))
		return atoi(command.c_str());
	else
		return 0;
}


// ������ �޴� ���.
int Application::GetRecycleCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t������ ID ������  Command ��������������������������" << endl;
	cout << "\t��   1 : ���� ����\t\t��" << endl;
	cout << "\t��   2 : ���� ����\t\t��" << endl;
	cout << "\t��   3 : ���� ����\t\t��" << endl;
	cout << "\t��   4 : ���� ����\t\t��" << endl;
	cout << "\t��   5 : ������ ����\t\t��" << endl;
	cout << "\t��   6 : ������ �Ӽ�\t\t��" << endl;
	cout << "\t��   0 : ��Ʈ ������ �̵�\t��" << endl;
	cout << "\t������������������������������������������������������������������" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

//���ο� ���� ���� ����.
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

//���ο� ���� ���� ����.
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


//���� ����.
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
				cout << "\t<========�����뿡 ���� ������ �����մϴ� !=======>" << endl;
				return 0;
			}
			string choose;
			cout << "\t<========�����뿡 ���� �̸��� ������ �����մϴ� !=======>" << endl;
			cout << "\t<========���� ������ ���� �Ͻðڽ��ϱ� ? (Y(y)/else)=======>" << endl;
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

//���� ����.
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
					cout << "\t<========�����뿡 ���� ������ �����մϴ� !=======>" << endl;
					return 0;
				}

				string choose;
				cout << "\t<========�����뿡 ���� �̸��� ������ �����մϴ� !=======>" << endl;
				cout << "\t<========���� ������ ���� �Ͻðڽ��ϱ� ? (Y(y)/else)=======>" << endl;
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


//���� ����.
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


//���� ����.
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


//���� ����.
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

//���� �߶󳻱�.
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


//���� ����.
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

//���� ����.
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


//���� ����.
int Application::PasteFolder()
{
	if (ReplicaFolder.GetName() == "")
	{
		cout << "\t<========�ٿ��ֱ��� ������ �����ϴ�!=======>" << endl;
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

//���� ����.
int Application::PasteFile()
{
	if (ReplicaFile.GetName() == "")
	{
		cout << "\t<========�ٿ��ֱ��� ������ �����ϴ�!=======>" << endl;
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
*	@brief	���ο� ���� �߰�.
*	@pre	����Ʈ�� �����ؾ��Ѵ�.
*	@post	���ο� ������ ����Ʈ�� �߰��ȴ�.
*	@return	�� �۵��Ǹ� 1��, �ƴѰ�쿡 0�� ��ȯ�Ѵ�.
*/
void Application::MakeEmpty()
{
	curPoint->MakeEmpty();
}


// Display all records in the list on screen.
void Application::DisplayProperty()
{
	cout << "\n\tFolder Property" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
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
	cout << "\n\t< " << curPoint->GetName() << "\t>" << "\t(��¥ �� ����)" << endl;

	if (curPoint->GetNumber() == 0 && curPoint->GetFileNumber() == 0)
		cout << "\t�� ������ ��� �ֽ��ϴ�." << endl << endl;
	if (curPoint->GetNumber() != 0)
	{
		// list�� ��� �����͸� ȭ�鿡 ���
		FolderType tmp;
		int result = 0;

		FolderType* disPtr = &temp;

		DoublyIterator<FolderType> iter(*curPoint->GetLinkedList());
		// list�� ��� �����͸� �߰�
		while (iter.NotNull()) {
			disPtr->AddFolder_LL_D(tmp);
			iter.Next();
		}

		DoublyIterator<FolderType> iter2(*disPtr->GetLinkedList());
		int i = 0;
		while (iter2.NotNull()) {
			tmp = iter2.GetCurrentNode().data;
			if (result == 0) //ó�� ã�� �����
				cout << "\t<============ \tFolder\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - ";
			tmp.DisplayNameOnScreen();
			result = 1;	//����(1)
			iter2.Next();
		}
		if (result)	//�߰��� ���
			cout << "\t<====================================>" << endl;
		else	//�߰� ���ϴ� ���
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
		disPtr->MakeEmpty();
	}
	if (curPoint->GetFileNumber() != 0)
	{
		// list�� ��� �����͸� ȭ�鿡 ���
		FileType tmp;
		int result = 0;

		FolderType* disPtr = &temp;


		DoublyIterator<FileType> iter(*curPoint->GetFileList());
		// list�� ��� �����͸� �߰�
		while (iter.NotNull()) {
			disPtr->AddFile_D(tmp);
			iter.Next();
		}

		DoublyIterator<FileType> iter2(*disPtr->GetFileList());
		int i = 0;
		while (iter2.NotNull()) {
			tmp = iter2.GetCurrentNode().data;
			if (result == 0) //ó�� ã�� �����
				cout << "\t<============ \tFile\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - " << tmp.GetName() << "." << tmp.GetExtension() << endl;;
			result = 1;	//����(1)
			iter2.Next();
		}
		if (result)	//�߰��� ���
			cout << "\t<====================================>" << endl;
		else	//�߰� ���ϴ� ���
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
		disPtr->MakeEmpty();
	}
	if (ReplicaFolder.GetName() != "")
	{
		cout << "\tŬ�����忡 ����� ���� : " << ReplicaFolder.GetName() << endl;
	}
	if (ReplicaFile.GetName() != "")
	{
		cout << "\tŬ�����忡 ����� ���� : " << ReplicaFile.GetName() + "." + ReplicaFile.GetExtension() << endl;
	}


}


// Display all records in the list on screen.
void Application::DisplayFolder_DR()
{
	if (curPoint->GetAddress() == "")
		cout << "\n\tCurrent Path : root" << endl;
	else
		cout << "\n\tCurrent Path : " << curPoint->GetAddress() << endl;
	cout << "\n\t< " << curPoint->GetName() << "\t>" << "\t(��¥ ���� ����)" << endl;

	if (curPoint->GetNumber() == 0 && curPoint->GetFileNumber() == 0)
		cout << "\t�� ������ ��� �ֽ��ϴ�." << endl << endl;
	if (curPoint->GetNumber() != 0)
	{
		// list�� ��� �����͸� ȭ�鿡 ���
		FolderType tmp;
		int result = 0;

		FolderType* disPtr = &temp;

		DoublyIterator<FolderType> iter(*curPoint->GetLinkedList());
		// list�� ��� �����͸� �߰�
		while (iter.NotNull()) {
			disPtr->AddFolder_LL_DR(tmp);
			iter.Next();
		}

		DoublyIterator<FolderType> iter2(*disPtr->GetLinkedList());
		int i = 0;
		while (iter2.NotNull()) {
			tmp = iter2.GetCurrentNode().data;
			if (result == 0) //ó�� ã�� �����
				cout << "\t<============ \tFolder\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - ";
			tmp.DisplayNameOnScreen();
			result = 1;	//����(1)
			iter2.Next();
		}
		if (result)	//�߰��� ���
			cout << "\t<====================================>" << endl;
		else	//�߰� ���ϴ� ���
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
		disPtr->MakeEmpty();
	}
	if (curPoint->GetFileNumber() != 0)
	{
		// list�� ��� �����͸� ȭ�鿡 ���
		FileType tmp;
		int result = 0;

		FolderType* disPtr = &temp;


		DoublyIterator<FileType> iter(*curPoint->GetFileList());
		// list�� ��� �����͸� �߰�
		while (iter.NotNull()) {
			disPtr->AddFile_DR(tmp);
			iter.Next();
		}

		DoublyIterator<FileType> iter2(*disPtr->GetFileList());
		int i = 0;
		while (iter2.NotNull()) {
			tmp = iter2.GetCurrentNode().data;
			if (result == 0) //ó�� ã�� �����
				cout << "\t<============ \tFile\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - " << tmp.GetName() << "." << tmp.GetExtension() << endl;;
			result = 1;	//����(1)
			iter2.Next();
		}
		if (result)	//�߰��� ���
			cout << "\t<====================================>" << endl;
		else	//�߰� ���ϴ� ���
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
		disPtr->MakeEmpty();
	}
	if (ReplicaFolder.GetName() != "")
	{
		cout << "\tŬ�����忡 ����� ���� : " << ReplicaFolder.GetName() << endl;
	}
	if (ReplicaFile.GetName() != "")
	{
		cout << "\tŬ�����忡 ����� ���� : " << ReplicaFile.GetName() + "." + ReplicaFile.GetExtension() << endl;
	}


}

// Display all records in the list on screen.
void Application::DisplayFolder_N()
{
	if(curPoint->GetAddress() == "")
		cout << "\n\tCurrent Path : root" << endl;
	else
		cout << "\n\tCurrent Path : " << curPoint->GetAddress() << endl;
	cout << "\n\t< " << curPoint->GetName() << "\t>"<< "\t(�̸� �� ����)" << endl;

	if (curPoint->GetNumber() == 0 && curPoint->GetFileNumber() ==0)
		cout << "\t�� ������ ��� �ֽ��ϴ�." << endl << endl;
	if (curPoint->GetNumber() != 0)
	{
		// list�� ��� �����͸� ȭ�鿡 ���
		FolderType tmp;
		int result = 0;

		DoublyIterator<FolderType> iter(*curPoint->GetLinkedList());
		int i = 0;
		iter.Next();
		while (iter.NextNotNull()) {
			tmp = iter.GetCurrentNode().data;
			if (result == 0) //ó�� ã�� �����
				cout << "\t<============ \tFolder\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - ";
			tmp.DisplayNameOnScreen();
			result = 1;	//����(1)
			iter.Next();
		}

		if (result)	//�߰��� ���
			cout << "\t<====================================>" << endl;
		else	//�߰� ���ϴ� ���
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
	}
	if (curPoint->GetFileNumber() != 0)
	{
		// list�� ��� �����͸� ȭ�鿡 ���
		FileType tmp;
		int result = 0;
		DoublyIterator<FileType> iter2(*curPoint->GetFileList());
		int i = 0;
		while (iter2.NotNull()) {
			tmp = iter2.GetCurrentNode().data;
			if (result == 0) //ó�� ã�� �����
				cout << "\t<============ \tFile\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - " << tmp.GetName() << "." << tmp.GetExtension() << endl;;
			result = 1;	//����(1)
			iter2.Next();
		}
		if (result)	//�߰��� ���
			cout << "\t<====================================>" << endl;
		else	//�߰� ���ϴ� ���
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
	}
	if (ReplicaFolder.GetName() != "")
	{
		cout << "\tŬ�����忡 ����� ���� : " << ReplicaFolder.GetName() << endl;
	}
	if (ReplicaFile.GetName() != "")
	{
		cout << "\tŬ�����忡 ����� ���� : " << ReplicaFile.GetName()+"."+ReplicaFile.GetExtension() << endl;
	}


}


// Display all records in the list on screen.
void Application::DisplayFolder_C()
{
	if (curPoint->GetAddress() == "")
		cout << "\n\tCurrent Path : root" << endl;
	else
		cout << "\n\tCurrent Path : " << curPoint->GetAddress() << endl;
	cout << "\n\t< " << curPoint->GetName() << "\t>" << "\t(���� ��� �� ����)" << endl;

	if (curPoint->GetNumber() == 0 && curPoint->GetFileNumber() == 0)
		cout << "\t�� ������ ��� �ֽ��ϴ�." << endl << endl;
	if (curPoint->GetNumber() != 0)
	{
		// list�� ��� �����͸� ȭ�鿡 ���
		FolderType tmp;
		int result = 0;

		FolderType* disPtr = &temp;

		DoublyIterator<FolderType> iter(*curPoint->GetLinkedList());
		// list�� ��� �����͸� �߰�
		while (iter.NotNull()) {
			iter.Next();
			disPtr->AddFolder_LL_C(tmp);
		}

		DoublyIterator<FolderType> iter2(*disPtr->GetLinkedList());
		int i = 0;
		while (iter2.NotNull()) {
			iter2.Next();
			tmp = iter2.GetCurrentNode().data;
			if (result == 0) //ó�� ã�� �����
				cout << "\t<============ \tFolder\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - ";
			tmp.DisplayNameOnScreen();
			result = 1;	//����(1)
		}
		if (result)	//�߰��� ���
			cout << "\t<====================================>" << endl;
		else	//�߰� ���ϴ� ���
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
		disPtr->MakeEmpty();
	}
	if (curPoint->GetFileNumber() != 0)
	{
		// list�� ��� �����͸� ȭ�鿡 ���
		FileType tmp;
		int result = 0;

		FolderType* disPtr = &temp;


		DoublyIterator<FileType> iter(*curPoint->GetFileList());
		// list�� ��� �����͸� �߰�
		while (iter.NotNull()) {
			iter.Next();
			disPtr->AddFile_C(tmp);
		}

		DoublyIterator<FileType> iter2(*disPtr->GetFileList());
		int i = 0;
		while (iter2.NotNull()) {
			iter2.Next();
			tmp = iter2.GetCurrentNode().data;
			if (result == 0) //ó�� ã�� �����
				cout << "\t<============ \tFile\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - " << tmp.GetName() << "." << tmp.GetExtension() << endl;;
			result = 1;	//����(1)
		}
		if (result)	//�߰��� ���
			cout << "\t<====================================>" << endl;
		else	//�߰� ���ϴ� ���
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
		disPtr->MakeEmpty();
	}
	if (ReplicaFolder.GetName() != "")
	{
		cout << "\tŬ�����忡 ����� ���� : " << ReplicaFolder.GetName() << endl;
	}
	if (ReplicaFile.GetName() != "")
	{
		cout << "\tŬ�����忡 ����� ���� : " << ReplicaFile.GetName() + "." + ReplicaFile.GetExtension() << endl;
	}


}


// Display all records in the list on screen.
void Application::DisplayFolder_CR()
{
	if (curPoint->GetAddress() == "")
		cout << "\n\tCurrent Path : root" << endl;
	else
		cout << "\n\tCurrent Path : " << curPoint->GetAddress() << endl;
	cout << "\n\t< " << curPoint->GetName() << "\t>" << "\t(���� ��� ���� ����)" << endl;

	if (curPoint->GetNumber() == 0 && curPoint->GetFileNumber() == 0)
		cout << "\t�� ������ ��� �ֽ��ϴ�." << endl << endl;
	if (curPoint->GetNumber() != 0)
	{
		// list�� ��� �����͸� ȭ�鿡 ���
		FolderType tmp;
		int result = 0;

		FolderType* disPtr = &temp;

		DoublyIterator<FolderType> iter(*curPoint->GetLinkedList());
		// list�� ��� �����͸� �߰�
		while (iter.NotNull()) {
			disPtr->AddFolder_LL_CR(tmp);
			iter.Next();
		}

		DoublyIterator<FolderType> iter2(*disPtr->GetLinkedList());
		int i = 0;
		while (iter2.NotNull()) {
			tmp = iter2.GetCurrentNode().data;
			if (result == 0) //ó�� ã�� �����
				cout << "\t<============ \tFolder\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - ";
			tmp.DisplayNameOnScreen();
			result = 1;	//����(1)
			iter2.Next();
		}
		if (result)	//�߰��� ���
			cout << "\t<====================================>" << endl;
		else	//�߰� ���ϴ� ���
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
		disPtr->MakeEmpty();
	}
	if (curPoint->GetFileNumber() != 0)
	{
		// list�� ��� �����͸� ȭ�鿡 ���
		FileType tmp;
		int result = 0;

		FolderType* disPtr = &temp;


		DoublyIterator<FileType> iter(*curPoint->GetFileList());
		// list�� ��� �����͸� �߰�
		while (iter.NotNull()) {
			disPtr->AddFile_CR(tmp);
			iter.Next();
		}

		DoublyIterator<FileType> iter2(*disPtr->GetFileList());
		int i = 0;
		while (iter2.NotNull()) {
			tmp = iter2.GetCurrentNode().data;
			if (result == 0) //ó�� ã�� �����
				cout << "\t<============ \tFile\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - " << tmp.GetName() << "." << tmp.GetExtension() << endl;;
			result = 1;	//����(1)
			iter2.Next();
		}
		if (result)	//�߰��� ���
			cout << "\t<====================================>" << endl;
		else	//�߰� ���ϴ� ���
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
		disPtr->MakeEmpty();
	}
	if (ReplicaFolder.GetName() != "")
	{
		cout << "\tŬ�����忡 ����� ���� : " << ReplicaFolder.GetName() << endl;
	}
	if (ReplicaFile.GetName() != "")
	{
		cout << "\tŬ�����忡 ����� ���� : " << ReplicaFile.GetName() + "." + ReplicaFile.GetExtension() << endl;
	}


}


// Display all records in the list on screen.
void Application::DisplayFavorite()
{
	if (BookMark.GetNumber() != 0)
	{

		// list�� ��� �����͸� ȭ�鿡 ���
		FolderType tmp;
		int result = 0;


		DoublyIterator<FolderType> iter(*BookMark.GetLinkedList());
		int i = 0;
		while (iter.NotNull()) {
			tmp = iter.GetCurrentNode().data;
			if (result == 0) //ó�� ã�� �����
				cout << "\t<============ \tBookMark\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - " << tmp.GetName() << "\t�߰� ��¥ : " << tmp.GetDate() << endl;
			result = 1;	//����(1)
			iter.Next();
		}
	}
	if (Favorite.GetNumber() == 0 && Favorite.GetFileNumber() == 0)
		cout << "\t��� ������ ������ �����ϴ�." << endl << endl;
	if (Favorite.GetNumber() != 0)
	{
		// list�� ��� �����͸� ȭ�鿡 ���
		FolderType tmp;
		int result = 0;


		DoublyIterator<FolderType> iter(*Favorite.GetLinkedList());
		int i = 0;
		while (iter.NotNull()) {
			iter.Next();
			tmp = iter.GetCurrentNode().data;
			if (result == 0) //ó�� ã�� �����
				cout << "\t<============ \tFolder\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - " << tmp.GetName() << "\tCount : " << tmp.GetCount() << endl;
			result = 1;	//����(1)
			iter.Next();
		}
		if (result)	//�߰��� ���
			cout << "\t<====================================>" << endl;
		else	//�߰� ���ϴ� ���
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
	}
	if (Favorite.GetFileNumber() != 0)
	{
		// list�� ��� �����͸� ȭ�鿡 ���
		FileType tmp;
		int result = 0;

		DoublyIterator<FileType> iter(*Favorite.GetFileList());
		int i = 0;
		while (iter.NotNull()) {
			iter.Next();
			tmp = iter.GetCurrentNode().data;
			if (result == 0) //ó�� ã�� �����
				cout << "\t<============ \tFile\t ===========>" << endl;
			cout << "\tNO." << i + 1 << " - ";
			tmp.DisplayNameOnScreen();
			result = 1;	//����(1)
		}
		if (result)	//�߰��� ���
			cout << "\t<====================================>" << endl;
		else	//�߰� ���ϴ� ���
			cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;

	}

}

//���� �̵��Ѵ�.
int Application::MoveFolder()
{
	int moveTo = 0;
	cout << "\t[�̸� �� ���� ����] Move To Folder NO. : ";
	cin >> moveTo;
	if (moveTo > curPoint->GetNumber() || moveTo <= 0)
	{
		cout << "\t�ش� ������ �������� �ʽ��ϴ�.";
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
			result = 1;	//����(1)
			break;
		}
		count++;
		iter.Next();
	}

	return result;
}


//���� �̵��Ѵ�.
int Application::OpenFile()
{
	int moveTo = 0;
	cout << "\tOpen File NO. : ";
	cin >> moveTo;
	if (moveTo > curPoint->GetFileNumber() || moveTo <= 0)
	{
		cout << "\t�ش� ������ �������� �ʽ��ϴ�.";
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
			result = 1;	//����(1)
			break;
		}
		count++;
	}
	return result;
}



//���� �̵��Ѵ�.
int Application::UpperFolder()
{
	if (curPoint->GetPrevFolder() == NULL)
	{
		cout << "\t�ֻ��� ���� '"<< curPoint->GetName() << "' �Դϴ�." <<endl;
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


//���� �̵��Ѵ�.
int Application::GoRoot()
{
	curPoint = &root;
	m_RecentlyFolder.Deduplication(curPoint);
	m_RecentlyFolder.EnQueue(curPoint);
	if (curPoint != &root)
		return 0;
	return 1;
}


//���� �̵��Ѵ�.
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

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_OutFile)	return 0;
	else	return 1;
}


//�̸��� �Է¹��� item���� ����Ʈ���� item�� ã�Ƽ� ����Ѵ�.
int Application::RetrieveRecordByName()
{
	if (curPoint->GetNumber() == 0 && curPoint->GetFileNumber() == 0)
	{
		cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
		return 0;
	}
	FolderType item;
	item.SetNameFromKB(); //name�� �Է¹޴´�.

	if (SearchAll(item)) //0�� �ƴϸ�(ã����)
		return 1;	//����(1)�� ����
	return 0;	//����(0)�� ����
}


//�̸����� item�� ã�Ƽ� ����Ѵ�.
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


//�̸����� item�� ã�Ƽ� ����Ѵ�.
int Application::SearchAllFolder(FolderType &inData)
{
	if (curPoint->RetrieveFolderByName(inData))
		return 1;
	else
		return 0;
}


//�̸����� item�� ã�Ƽ� ����Ѵ�.
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
	
	// list�� ��� �����͸� ȭ�鿡 ���
	int m_iFront = m_RecentlyFolder.Front();
	int m_iRear = m_RecentlyFolder.Rear();
	int m_nMaxQueue = m_RecentlyFolder.MAX();
	for (int i = (m_iFront + 1) % m_nMaxQueue; i != (m_iRear + 1) % m_nMaxQueue; i = (i + 1) % m_nMaxQueue) //ť�� ó��+1���� ����ؼ� ť�� ���������� Ȯ���Ѵ�. ��� �˻��� mod�� ��ȯ�ϰ� �Ѵ�.
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


	// list�� ��� �����͸� ȭ�鿡 ���
	int m_iFront = m_RecentlyFile.Front();
	int m_iRear = m_RecentlyFile.Rear();
	int m_nMaxQueue = m_RecentlyFile.MAX();
	for (int i = (m_iFront + 1) % m_nMaxQueue; i != (m_iRear + 1) % m_nMaxQueue; i = (i + 1) % m_nMaxQueue) //ť�� ó��+1���� ����ؼ� ť�� ���������� Ȯ���Ѵ�. ��� �˻��� mod�� ��ȯ�ϰ� �Ѵ�.
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
		cout << "\t�����뿡 ������ �������� �ʽ��ϴ�.";
		return 0;
	}
	int moveTo = 0;
	cout << "\tRestore Folder No. : ";
	cin >> moveTo;
	if (moveTo > curPoint->GetNumber() || moveTo <= 0)
	{
		cout << "\t�ش� ������ �������� �ʽ��ϴ�.";
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
			result = 1;	//����(1)
			break;
		}
		iter.Next();
		count++;
	}
	return result;
}


//���� ����.
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
		cout << "\t�����뿡 ������ �������� �ʽ��ϴ�.";
		return 0;
	}
	int moveTo = 0;
	cout << "\tRestore File No. : ";
	cin >> moveTo;
	if (moveTo > curPoint->GetFileNumber() || moveTo <= 0)
	{
		cout << "\t�ش� ������ �������� �ʽ��ϴ�.";
		return 0;
	}

	FileType tmp;
	int result = 0;

	DoublyIterator<FileType> iter(*curPoint->GetFileList());
	int count = 0;
	while (true) //����Ʈ�� ���������� �ݺ�
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
			result = 1;	//����(1)
			break;
		}
		count++;
	}
	return result;
}

//���� ����.
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