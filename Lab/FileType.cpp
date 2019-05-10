#include "FileType.h"

// Set student name from keyboard.
void FileType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_fName;
}


// Set student address from keyboard.
void FileType::SetAddressFromKB()
{
	cout << "\tAddress : ";
	cin >> m_fAddress;
}


// Set student address from keyboard.
void FileType::SetBytesFromKB()
{
	cout << "\tBytes : ";
	cin >> m_fBytes;
}


// Set student address from keyboard.
void FileType::SetDateFromKB()
{
	cout << "\tDate : ";
	cin >> m_fDate;
}

// Set student address from keyboard.
void FileType::SetExtensionFromKB()
{
	cout << "\tExtension : ";
	cin >> m_fExtension;
}


// Set student record from keyboard.
void FileType::SetRecordFromKB()
{
	SetNameFromKB();
	SetAddressFromKB();
	SetBytesFromKB();
	SetDateFromKB();
	SetExtensionFromKB();
}

// Read a record from file.
int FileType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_fName;
	fin >> m_fAddress;
	fin >> m_fBytes;
	fin >> m_fDate;
	fin >> m_fExtension;

	return 1;
};

// Write a record into file.
int FileType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_fName << " ";
	fout << m_fAddress << " ";
	fout << m_fBytes << " ";
	fout << m_fDate << " ";
	fout << m_fExtension;

	return 1;
}

// Compare two itemtypes.
int FileType::isEqual(const FileType &data)
{
	if (this->m_fName == data.m_fName && this->m_fAddress == data.m_fAddress && this->m_fBytes == data.m_fBytes && this->m_fDate == data.m_fDate)
		return 1;
	else
		return 0;
}


// Compare two itemtypes.
RelationType FileType::CompareByName(const FileType &data)
{
	if (this->m_fName > data.m_fName)
		return GREATER;
	else if (this->m_fName < data.m_fName)
		return LESS;
	else
		return EQUAL;
}


// Compare two itemtypes.
RelationType FileType::CompareByBytes(const FileType &data)
{
	if (this->m_fBytes > data.m_fBytes)
		return GREATER;
	else if (this->m_fBytes < data.m_fBytes)
		return LESS;
	else
		return EQUAL;
}


// Compare two itemtypes.
RelationType FileType::CompareByDate(const FileType &data)
{
	if (this->m_fDate > data.m_fDate)
		return GREATER;
	else if (this->m_fDate < data.m_fDate)
		return LESS;
	else
		return EQUAL;
}


// Compare two itemtypes.
RelationType FileType::CompareByCount(const FileType &data)
{
	if (this->m_OpenCount > data.m_OpenCount)
		return GREATER;
	else if (this->m_OpenCount < data.m_OpenCount)
		return LESS;
	else
		return EQUAL;
}

// Get current time for record
string FileType::GetCurrentTimes()
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



void FileType::MakeEmpty()
{
	this->m_fName = "";
	this->m_fAddress = "";
	this->m_fBytes = 0;
	this->m_fDate = "";
	this->m_fReplaceDate = "";
	this->m_fExecuteDate = "";
	this->m_fExtension = "";
	this->m_OpenCount = 0;
}

FileType& FileType::operator=(const FileType& list)
{
	this->m_fName = list.m_fName;
	this->m_fAddress = list.m_fAddress;
	this->m_fBytes = list.m_fBytes;
	this->m_fDate = list.m_fDate;
	this->m_fReplaceDate = list.m_fReplaceDate;
	this->m_fExecuteDate = list.m_fExecuteDate;
	this->m_fExtension = list.m_fExtension;
	this->m_OpenCount = list.m_OpenCount;

	return *this;
}


bool FileType::operator<(const FileType& list)
{
	if (this->m_fName < list.m_fName)
		return true;
	else
		return false;
}


bool FileType::operator==(const FileType& list)
{
	if (this->m_fName == list.m_fName)
	{
		if (this->m_fExtension == list.m_fExtension)
			return true;
		else
			return false;
	}
	else
		return false;
}