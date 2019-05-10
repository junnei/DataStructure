#include "FolderType.h"

#include <experimental/filesystem> 
namespace fs = std::experimental::filesystem;
// Set student name from keyboard.
void FolderType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_fName;
}

// Set student name from keyboard.
void FolderType::SetRecord_Auto()
{
	cout << "\tName : ";
	cin >> m_fName;


	if (prevFolder != NULL)
		SetAddress(prevFolder->GetAddress()+GetName());
	m_fAddress = "";
	m_fBytes = 0;
	m_fDate = GetCurrentTimes();
	m_fNumber = 0;
	m_FileNumber = 0;
	m_OpenCount = 0;
	m_fLinkedList = NULL;
	m_FileList = NULL;
	prevFolder = NULL;
}


// Set student address from keyboard.
void FolderType::SetAddressFromKB()
{
	cout << "\tAddress : ";
	cin >> m_fAddress;
}


// Set student address from keyboard.
void FolderType::SetBytesFromKB()
{
	cout << "\tBytes : ";
	cin >> m_fBytes;
}


// Set student address from keyboard.
void FolderType::SetDateFromKB()
{
	cout << "\tDate : ";
	cin >> m_fDate;
}


// Set student address from keyboard.
void FolderType::SetNumberFromKB()
{
	cout << "\tFolderNumber : ";
	cin >> m_fNumber;
}


// Set student address from keyboard.
void FolderType::SetFileNumberFromKB()
{
	cout << "\tFileNumber : ";
	cin >> m_FileNumber;
}


// Set student record from keyboard.
void FolderType::SetRecordFromKB()
{
	SetNameFromKB();
	SetAddressFromKB();
	SetBytesFromKB();
	SetDateFromKB();
	SetNumberFromKB();
	SetFileNumberFromKB();
}


void FolderType::MakeEmpty()
{
	if (m_fLinkedList != NULL)
	{
		m_fLinkedList->MakeEmpty();
		delete m_fLinkedList;
		m_fLinkedList = NULL;
	}
	if (m_FileList != NULL)
	{
		m_FileList->MakeEmpty();
		delete m_FileList;
		m_FileList = NULL;
	}
	m_fNumber = 0;
	m_FileNumber = 0;
	m_fBytes = 0;
	if (this->GetAddress() == "")
	{
		remove_all(this->GetName());
		create_directories(this->GetName());
	}
	else
	{
		remove_all(this->GetAddress() + "\\" + this->GetName());
		create_directories(this->GetAddress() + "\\" + this->GetName());
	}
}

void FolderType::AddCount()
{
	m_OpenCount++;
}


int FolderType::AddFolder_LL()
{
	if (m_fNumber == 0)
		m_fLinkedList = new DoublySortedLinkedList<FolderType>;
	FolderType data;
	data.SetNameFromKB();
	if (m_fLinkedList->Get(data))
		return 0;
	if (m_fAddress != "")
		data.SetAddress(m_fAddress + '\\' + m_fName);
	else
		data.SetAddress(m_fName);
	data.SetDate(GetCurrentTimes());
	data.prevFolder = this;
	if (m_fLinkedList->Add(data))
		m_fNumber++;
	create_directories(data.GetAddress() + "\\" + data.GetName());
	return 1;
}


int FolderType::AddFolder_LL(string name)
{
	if (m_fNumber == 0)
		m_fLinkedList = new DoublySortedLinkedList<FolderType>;
	FolderType data;
	data.SetName(name);
	if (m_fLinkedList->Get(data))
		return 0;
	if (m_fAddress != "")
		data.SetAddress(m_fAddress + '\\' + m_fName);
	else
		data.SetAddress(m_fName);
	data.SetDate(GetCurrentTimes());
	data.prevFolder = this;
	if (m_fLinkedList->Add(data))
		m_fNumber++;
	create_directories(data.GetAddress() + "\\" + data.GetName());
	return 1;
}


int FolderType::AddFolder_LL(FolderType inFolder)
{
	if (m_fNumber == 0)
		m_fLinkedList = new DoublySortedLinkedList<FolderType>;
	FolderType data = inFolder;
	if (m_fLinkedList->Get(data))
		return 0;
	if (m_fAddress != "")
		data.SetAddress(m_fAddress + '\\' + m_fName);
	else
		data.SetAddress(m_fName);
	data.SetDate(GetCurrentTimes());
	data.prevFolder = this;
	if (m_fLinkedList->Add(data))
		m_fNumber++;
	this->SetBytes_recursive(inFolder.GetBytes());
	return 1;
}


void FolderType::AddFolder_LL_D(FolderType inFolder)
{
	if (m_fNumber == 0)
		m_fLinkedList = new DoublySortedLinkedList<FolderType>;
	if (m_fLinkedList->AddByDate(inFolder))
		m_fNumber++;
	this->SetBytes_recursive(inFolder.GetBytes());
}


void FolderType::AddFolder_LL_C(FolderType inFolder)
{
	if (m_fNumber == 0)
		m_fLinkedList = new DoublySortedLinkedList<FolderType>;
	if (m_fLinkedList->AddByCount(inFolder))
		m_fNumber++;
	this->SetBytes_recursive(inFolder.GetBytes());
}


void FolderType::AddFolder_LL_DR(FolderType inFolder)
{
	if (m_fNumber == 0)
		m_fLinkedList = new DoublySortedLinkedList<FolderType>;
	if (m_fLinkedList->AddByDateR(inFolder))
		m_fNumber++;
	this->SetBytes_recursive(inFolder.GetBytes());
}


void FolderType::AddFolder_LL_CR(FolderType inFolder)
{
	if (m_fNumber == 0)
		m_fLinkedList = new DoublySortedLinkedList<FolderType>;
	if (m_fLinkedList->AddByCountR(inFolder))
		m_fNumber++;
	this->SetBytes_recursive(inFolder.GetBytes());
}


int FolderType::AddFolder_LL_Restore(FolderType inData)
{
	if (m_fNumber == 0)
		m_fLinkedList = new DoublySortedLinkedList<FolderType>;
	if (m_fLinkedList->Add(inData))
		m_fNumber++;
	this->SetBytes_recursive(inData.GetBytes());
	return 1;
}


int FolderType::AddFile()
{
	if (m_FileNumber == 0)
		m_FileList = new DoublySortedLinkedList<FileType>;
	FileType data;
	data.SetNameFromKB();
	data.SetExtensionFromKB();
	if (m_FileList->Get(data))
		return 0;
	if (m_fAddress != "")
		data.SetAddress(m_fAddress + '\\' + m_fName);
	else
		data.SetAddress(m_fName);
	data.SetDate(GetCurrentTimes());
	if (m_FileList->Add(data))
		m_FileNumber++;

	cout << "\t파일 내용을 입력하십시오. (\\Q:종료) " << endl;
	string out_line;
	ofstream out(data.GetAddress() + "\\" + data.GetName() + "." + data.GetExtension());
	cout << endl << "\t>>" <<endl;
	while (true)
	{
		cout << "\t";
		cin >> out_line;
		if (out_line == "\\Q" || out_line == "\\q")
			break;
		out << out_line << endl;
	}
	out.close();

	int bytes;
	if(m_fAddress == "")
		bytes = fs::file_size(m_fName + "\\" + data.GetName() + "." + data.GetExtension());
	else
		bytes = fs::file_size(m_fAddress + "\\" + m_fName + "\\" + data.GetName() + "." + data.GetExtension());
	this->SetBytes_recursive(bytes);
	return 1;
}


int FolderType::AddFile(FileType inFile)
{
	if (m_FileNumber == 0)
		m_FileList = new DoublySortedLinkedList<FileType>;
	FileType data = inFile;
	if (m_FileList->Get(data))
		return 0;
	if (m_fAddress != "")
		data.SetAddress(m_fAddress + '\\' + m_fName);
	else
		data.SetAddress(m_fName);
	data.SetDate(GetCurrentTimes());
	data.SetReplaceDate(GetCurrentTimes());
	data.SetExecuteDate(GetCurrentTimes());
	if (m_FileList->Add(data))
		m_FileNumber++;
	cout << data.GetAddress() + "\\" + data.GetName() + "." + data.GetExtension();
	this->SetBytes_recursive(inFile.GetBytes());
	return 1;
}


int FolderType::AddFile_Restore(FileType inFile)
{
	if (m_FileNumber == 0)
		m_FileList = new DoublySortedLinkedList<FileType>;
	if (m_FileList->Get(inFile))
		return 0;
	if (m_FileList->Add(inFile))
		m_FileNumber++;
	int bytes = fs::file_size(inFile.GetAddress() + "\\" + inFile.GetName() + "." + inFile.GetExtension());
	this->SetBytes_recursive(bytes);
	return 1;
}


int FolderType::SetBytes_recursive(int bytes)
{
	this->SetBytes(this->GetBytes() + bytes);
	if(this->prevFolder != NULL)
		this->prevFolder->SetBytes_recursive(bytes);
	return 1;
}



void FolderType::AddFile_D(FileType inFile)
{
	if (m_fNumber == 0)
		m_FileList = new DoublySortedLinkedList<FileType>;
	if (m_FileList->AddByDate(inFile))
		m_FileNumber++;
	this->SetBytes_recursive(inFile.GetBytes());
}


void FolderType::AddFile_C(FileType inFile)
{
	if (m_fNumber == 0)
		m_FileList = new DoublySortedLinkedList<FileType>;
	if (m_FileList->AddByCount(inFile))
		m_FileNumber++;
	this->SetBytes_recursive(inFile.GetBytes());
}


void FolderType::AddFile_DR(FileType inFile)
{
	if (m_fNumber == 0)
		m_FileList = new DoublySortedLinkedList<FileType>;
	if (m_FileList->AddByDateR(inFile))
		m_FileNumber++;
	this->SetBytes_recursive(inFile.GetBytes());
}


void FolderType::AddFile_CR(FileType inFile)
{
	if (m_fNumber == 0)
		m_FileList = new DoublySortedLinkedList<FileType>;
	if (m_FileList->AddByCountR(inFile))
		m_FileNumber++;
	this->SetBytes_recursive(inFile.GetBytes());
}

void FolderType::ReplaceFolder()
{
	if (m_fNumber != 0)
	{
		FolderType* tmpPtr;
		FolderType tmp;
		FolderType dummy;
		if (this->GetLinkedList() != NULL)
		{
			cout << "\t 갱신할 폴더 이름 :";
			tmp.SetNameFromKB();
			if (this->GetLinkedList()->Get(tmp))
			{
				DoublyIterator<FolderType> iter(*this->GetLinkedList());

				while (iter.NotNull()) {
					iter.Next();
					if (tmp == iter.GetCurrentNode().data)
					{
						tmpPtr = iter.GetPoint();
						cout << "\t 변경할 폴더 이름 :";
						tmpPtr->SetNameFromKB();
						tmpPtr->ReplaceFolderByName();
						fs::rename(dummy.GetAddress() + "\\" + dummy.GetName(), tmpPtr->GetAddress() + "\\" + tmpPtr->GetName());
						break;
					}
				}
			}
			else
				cout << "\t<========해당 폴더가 존재하지 않습니다 !=======>" << endl;
		}
		else
			cout << "\t<========하위 폴더가 존재하지 않습니다 !=======>" << endl;
	}
}


void FolderType::ReplaceFolderByName()
{
	FolderType tmp;
	FolderType* tmpPtr;
	if (this->GetLinkedList() != NULL)
	{
		DoublyIterator<FolderType> iter(*this->GetLinkedList());

		while (iter.NotNull()) {
			iter.Next();
			tmp = iter.GetCurrentNode().data;
			tmpPtr = iter.GetPoint();
			if (this->GetAddress() != "")
				tmpPtr->SetAddress(tmpPtr->prevFolder->GetAddress() + '\\' + this->GetName());
			if (tmpPtr->GetNumber() != 0)
				tmpPtr->ReplaceFolderByName();

		}
	}
}


void FolderType::ReplaceFiles()
{
	if (m_FileNumber != 0)
	{
		FileType tmp;
		FileType dummy;
		cout << "\t갱신할 파일 -" << endl;
		dummy.SetNameFromKB();
		dummy.SetExtensionFromKB();
		if (this->GetFileList()->Get(dummy))
		{
			tmp = dummy;
			cout << endl << "\t변경할 파일 -" << endl;
			tmp.SetNameFromKB();
			tmp.SetExtensionFromKB();

			char* filename_old = new char[dummy.GetAddress().length() + dummy.GetName().length() + dummy.GetExtension().length() + 3];
			strcpy(filename_old, (dummy.GetAddress() + "\\" + dummy.GetName()+"."+dummy.GetExtension()).c_str());
			char* filename_new = new char[tmp.GetAddress().length() + tmp.GetName().length() + tmp.GetExtension().length() + 3];
			strcpy(filename_new, (tmp.GetAddress() + "\\" + tmp.GetName() + "." + tmp.GetExtension()).c_str());

			if (rename(filename_old, filename_new) != 0)
			{
				fputs("파일명 변경 에러\n", stderr);
			}
			else
			{
				if (m_FileList->Delete(dummy))
				{
					tmp.SetReplaceDate(tmp.GetCurrentTimes());
					m_FileList->Add(tmp);
				}
				puts("성공적으로 이름 변경");
			}
			delete[] filename_old;
			delete[] filename_new;
		}
		else
			cout << "\t<========해당 파일이 존재하지 않습니다 !=======>" << endl;
	}
}


int FolderType::RetrieveFolderByName(FolderType inData)
{
	if (this->GetLinkedList() == NULL)
		return 0;

	FolderType tmp;
	int result = 0;
	FolderType* tmpPtr;

	DoublyIterator<FolderType> iter(*this->GetLinkedList());

	while (iter.NotNull()) {
		iter.Next();
		tmp = iter.GetCurrentNode().data;
		if (tmp.GetName().find(inData.GetName()) != -1) //만약 해당 리스트의 이름에 inData의 이름이 존재하면
		{
			if (result == 0) //처음 찾는 경우라면
				cout << "<============ FOUND FOLDER '" + inData.GetName() + "'" << "in '" << tmp.GetAddress() << "'==========>" << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;	//성공(1)
		}
	}
	if (result)	//발견한 경우
		cout << "<====================================>" << endl;
	else	//발견 못하는 경우
		cout << "<========I CAN'T FIND FOLDER !==========>" << endl;
	

	DoublyIterator<FolderType> iter2(*this->GetLinkedList());

	while (iter2.NotNull()) {
		iter2.Next();
		tmp = iter2.GetCurrentNode().data;
		tmpPtr = iter2.GetPoint();
		if (tmpPtr->GetNumber() != 0)
			tmpPtr->RetrieveFolderByName(inData);
		if (tmpPtr->GetFileNumber() != 0)
		{
			FileType dummy;
			dummy.SetName(inData.GetName());
			tmpPtr->RetrieveFileByName(dummy);
		}
	}

	return result;
}


int FolderType::RetrieveFileByName(FileType inData)
{
	if (this->GetFileList() == NULL)
		return 0;

	FileType tmp;
	int result = 0;


	DoublyIterator<FileType> iter(*this->GetFileList());

	while (iter.NotNull()) {
		iter.Next();
		tmp = iter.GetCurrentNode().data;
		if (tmp.GetName().find(inData.GetName()) != -1) //만약 해당 리스트의 이름에 inData의 이름이 존재하면
		{
			if (result == 0) //처음 찾는 경우라면
				cout << "<============ FOUND FILE '" + inData.GetName() + "'" << "in '" << tmp.GetAddress() << "'==========>" << endl;
			cout << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;	//성공(1)
		}
	}

	FolderType tmpFolder;
	tmpFolder.SetName(tmp.GetName());
	FolderType* tmpPtr;


	DoublyIterator<FolderType> iter2(*this->GetLinkedList());

	while (iter2.NotNull()) {
		iter2.Next();
		tmpFolder = iter2.GetCurrentNode().data;
		tmpPtr = iter2.GetPoint();
		if (tmpPtr->GetFileNumber() != 0)
			tmpPtr->RetrieveFileByName(inData);
	}
	if (result)	//발견한 경우
		cout << "<====================================>" << endl;
	else	//발견 못하는 경우
		cout << "<========I CAN'T FIND FILE !==========>" << endl;
	return result;
}


// Read a record from file.
int FolderType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_fName;
	fin >> m_fAddress;
	fin >> m_fBytes;
	fin >> m_fDate;
	fin >> m_fNumber;
	fin >> m_FileNumber;

	return 1;
};

// Write a record into file.
int FolderType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_fName << " ";
	fout << m_fAddress << " ";
	fout << m_fBytes << " ";
	fout << m_fDate << " ";
	fout << m_fNumber << " ";
	fout << m_FileNumber;

	return 1;
}


// Compare two itemtypes.
int FolderType::isEqual(const FolderType &data)
{
	if (this->m_fName == data.m_fName && this->m_fAddress == data.m_fAddress && this->m_fBytes == data.m_fBytes && this->m_fDate == data.m_fDate)
		return 1;
	else 
		return 0;
}


// Compare two itemtypes.
RelationType FolderType::CompareByName(const FolderType &data)
{
	if (this->m_fName > data.m_fName)
		return GREATER;
	else if (this->m_fName < data.m_fName)
		return LESS;
	else
		return EQUAL;
}


// Compare two itemtypes.
RelationType FolderType::CompareByBytes(const FolderType &data)
{
	if (this->m_fBytes > data.m_fBytes)
		return GREATER;
	else if (this->m_fBytes < data.m_fBytes)
		return LESS;
	else
		return EQUAL;
}


// Compare two itemtypes.
RelationType FolderType::CompareByDate(const FolderType &data)
{
	if (this->m_fDate > data.m_fDate)
		return GREATER;
	else if (this->m_fDate < data.m_fDate)
		return LESS;
	else
		return EQUAL;
}


// Compare two itemtypes.
RelationType FolderType::CompareByCount(const FolderType &data)
{
	if (this->m_OpenCount > data.m_OpenCount)
		return GREATER;
	else if (this->m_OpenCount < data.m_OpenCount)
		return LESS;
	else
		return EQUAL;
}

// Get current time for record
string FolderType::GetCurrentTimes()
{
	time_t r;
	struct tm * pTime;
	time(&r);
	pTime = localtime(&r);
	int cTime1 =
		(10000)*(pTime->tm_year + 1900) +
		(100)*(pTime->tm_mon + 1) +
		(pTime->tm_mday);
	int cTime2 =
		(10000)*(pTime->tm_hour) +
		(100)*(pTime->tm_min) +
		pTime->tm_sec;
	string cTime2ToStr;
	if (cTime2 < 100000)
		cTime2ToStr = "0" + to_string(cTime2);
	else
		cTime2ToStr = to_string(cTime2);
	return to_string(cTime1) + cTime2ToStr;
}

FolderType& FolderType::operator=(const FolderType& list)
{
	if (list.m_fLinkedList != NULL)
		this->m_fLinkedList = new DoublySortedLinkedList<FolderType>(*list.m_fLinkedList);
	if (list.m_FileList != NULL)
		this->m_FileList = new DoublySortedLinkedList<FileType>(*list.m_FileList);
		
	this->m_fName = list.m_fName;
	this->m_fAddress = list.m_fAddress;
	this->m_fBytes = list.m_fBytes;
	this->m_fDate = list.m_fDate;
	this->m_fNumber = list.m_fNumber;
	this->m_FileNumber = list.m_FileNumber;
	this->m_OpenCount = list.m_OpenCount;
	this->prevFolder = list.prevFolder;

	return *this;
}


bool FolderType::operator<(const FolderType& list)
{
	if (this->m_fName < list.m_fName)
		return true;
	else
		return false;
}


bool FolderType::operator==(const FolderType& list)
{
	if (this->m_fName == list.m_fName)
		return true;
	else
		return false;
}