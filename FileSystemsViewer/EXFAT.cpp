#include "pch.h"
#include "EXFAT.h"

EXFATReader::EXFATReader(FileHandle* fileHandle) : Foundation(fileHandle)
{
	EXFATBootRecord *exfatBootRecord = (EXFATBootRecord*)fileHandle->GetData(0, 1024);
	bytesPerSector = pow(2, exfatBootRecord->SectorFactor);
	int sectorsPerCluster = pow(2, exfatBootRecord->ClusterFactor);
	bytesPerCluster = bytesPerSector * sectorsPerCluster;
	totalSectors = exfatBootRecord->TotalSectors;
	totalClusters = totalSectors / sectorsPerCluster;
	totalBytes = bytesPerSector * totalSectors;
}

EXFATReader::~EXFATReader() { }