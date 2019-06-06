#include "pch.h"
#include "FAT.h"

FATReader::FATReader(FileHandle* fileReader) : Foundation(fileReader)
{
	FATBootRecord *fatBootRecord = (FATBootRecord*)fileHandle->GetData(0, 1024);
	bytesPerSector = *(unsigned short*)fatBootRecord->BytesPerSector;
	int sectorsPerCluster = (unsigned short)fatBootRecord->SectorsPerCluster;
	bytesPerCluster = bytesPerSector * sectorsPerCluster;
	int totalSectorsSmall = *(unsigned short*)fatBootRecord->TotalSectorsSmall;
	// � FAT ���������� �������� ����� ���� �������� � 2� ������
	if (totalSectorsSmall == 0) {
		totalSectors = fatBootRecord->TotalSectorsBig;
	}
	else
	{
		totalSectors = totalSectorsSmall;
	}
	totalBytes = bytesPerSector * totalSectors;
	totalClusters = totalSectors / sectorsPerCluster;
}

FATReader::~FATReader() { }
