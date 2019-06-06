#include "pch.h"
#include "Cluster.h"
#include <iomanip>
#include <iostream>

Cluster::Cluster(BYTE * newData, int newSize)
{
	data = newData;
	size = newSize;
}



void Cluster::ShowData()
{
	cout << std::setfill('0'); //1.
	for (int i = 1; i < size + 1; i++) 
	{
		//cout << data[i - 1] << " ";    //Если необходимо представление в символьном виде, 1 и 2 закомментировать, а эту строку раскомментить
		cout << std::hex << std::setw(2) << (int)data[i-1] << " ";  //2.

		if (i % 16 == 0) {
			cout << endl;
		}
		else if (i % 8 == 0)
		{
			cout << " ";
		}
	}
}

Cluster::~Cluster() 
{

}
