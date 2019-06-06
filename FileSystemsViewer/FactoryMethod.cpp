#include "pch.h"
#include <iostream> 
#include "FactoryMethod.h"

using namespace std;

Foundation* FactoryMethod::CreateReader(FileHandle* handle)
{
	// Читаем начало файла и смотрим сигнатуру
	OEMName *oemName = (OEMName*)handle->GetData(0, 1024);
	if (strcmp(oemName->OEMName, "MSDOS5.0") == 0) {
		cout << "FAT" << endl;
		return new FATReader(handle);
	}
	if (strcmp(oemName->OEMName, "EXFAT   ") == 0) {
		cout << "EXFAT" << endl;
		return new EXFATReader(handle);
	}
	if (strcmp(oemName->OEMName, "NTFS    ") == 0) {
		cout << "NTFS" << endl;
		return new NTFSReader(handle);
	}
}

FactoryMethod::FactoryMethod() 
{

}

FactoryMethod::~FactoryMethod() 
{ 

}