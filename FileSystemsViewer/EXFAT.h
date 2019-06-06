#pragma once
#include "Foundation.h"

typedef struct
{
	BYTE Padding1[3];
	BYTE OEM_Name[8];
	BYTE Padding2[61];
	ULONGLONG TotalSectors;
	DWORD FATStartSector;
	DWORD FATSizeInSectors;
	DWORD FirstDataSector;
	DWORD TotalClusters;
	DWORD RootDirCluster;
	BYTE Padding3[8];
	BYTE SectorFactor;
	BYTE ClusterFactor;

} EXFATBootRecord;

class EXFATReader :
	public Foundation
{
public:
	EXFATReader(FileHandle* fileHandle);
	~EXFATReader();
};

