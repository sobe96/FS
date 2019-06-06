#include "pch.h"
#include "FileHandle.h"

using namespace std;

FileHandle::FileHandle(wstring fileName)
{
	// Код из лекции
	wstring wFileName(fileName.begin(), fileName.end());
	fileHandle = CreateFileW(wFileName.c_str(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
}

BYTE* FileHandle::GetData(int start, int bufferSize)
{
	// Код из лекции
	LARGE_INTEGER position = { start };
	BOOL ok = SetFilePointerEx(fileHandle, position, nullptr, FILE_BEGIN);
	BYTE *buffer = new BYTE[bufferSize];
	DWORD read;
	ok = ReadFile(fileHandle, buffer, bufferSize, &read, nullptr);

	return buffer;
}

FileHandle::~FileHandle()
{
	CloseHandle(fileHandle);
}
