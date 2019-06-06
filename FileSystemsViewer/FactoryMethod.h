#pragma once
#include "Foundation.h"
#include "FileHandle.h"
#include "NTFS.h"
#include "FAT.h"
#include "EXFAT.h"

typedef struct
{
	BYTE Padding1[3];
	char OEMName[8];
} OEMName;

class FactoryMethod
{
public:
	static Foundation* CreateReader(FileHandle* fileReader);
	FactoryMethod();
	~FactoryMethod();
};

