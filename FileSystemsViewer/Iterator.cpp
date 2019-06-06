#include "pch.h"
#include "Iterator.h"
#include "Foundation.h"

Iterator::Iterator(Foundation * newReader)
{
	currentClusterNumber = 0;
	reader = newReader;
}

Cluster* Iterator::GetNext() {
	// ����������� ����� �������� ��������, ��� �� �������� ���������
	currentClusterNumber++;
	return reader->GetCluster(currentClusterNumber);
}

bool Iterator::HasMore() {
	// �������, ������ �� ����� ���������� ��������, ��� ����� ���������� ���������
	return (currentClusterNumber + 1) < reader->totalClusters;
}

Iterator::~Iterator() 
{

}
