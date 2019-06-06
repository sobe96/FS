#pragma once
#include "Foundation.h"

typedef struct
{
	BYTE Padding1[3];
	BYTE OEM_Name[8];
	BYTE BytesPerSector[2];
	BYTE SectorsPerCluster;
	BYTE Padding2[5];
	BYTE TotalSectorsSmall[2];
	BYTE Padding3[11];
	long TotalSectorsBig;

} FATBootRecord;

class FATReader :
	public Foundation
{
public:
	FATReader(FileHandle* fileHandle);
	~FATReader();
};

