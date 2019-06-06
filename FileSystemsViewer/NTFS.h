#pragma once
#include "Foundation.h"
#include "FileHandle.h"

typedef struct
{
	BYTE Padding1[3];
	BYTE OEM_Name[8];
	BYTE BytesPerSector[2];
	BYTE SectorsPerCluster[1];
	BYTE Padding2[23];
	long TotalSectors;

} NTFSBootRecord;

class NTFSReader :
	public Foundation
{
public:
	NTFSReader(FileHandle* fileHandle);
	~NTFSReader();
};

