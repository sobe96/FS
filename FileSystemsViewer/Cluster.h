#pragma once
#include <windows.h>
#include <iostream>

using namespace std;

class Cluster
{
private:
	
public:
	BYTE * data;
	int size;
	Cluster(BYTE * data, int size);
	void ShowData();
	~Cluster();
};

