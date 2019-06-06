#pragma once

#include <iostream>
#include <string> 
#include <windows.h> 

using namespace std;

class FileHandle
{
public:
	HANDLE fileHandle;
	FileHandle(wstring fileName);
	BYTE* GetData(int start, int bufferSize);
	~FileHandle();
};

