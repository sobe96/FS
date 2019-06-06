#include "pch.h" 
#include <string> 
#include <iostream> 
#include <windows.h> 
#include "Cluster.h"
#include "Iterator.h"
#include "Decorator.h"
#include "Foundation.h"
#include "FileHandle.h"
#include "FactoryMethod.h"

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	// Узнаем доступные диски и выводим их на экран
	DWORD driveType;
	WCHAR driveList[MAX_PATH];
	WCHAR * drive;
	GetLogicalDriveStringsW(MAX_PATH, (LPWSTR)driveList);
	drive = driveList;
	driveType = GetDriveTypeW(drive);

	cout << "Доступные диски [";
	// ----- Обработка первого диска -----
	if (*drive && (driveType == DRIVE_REMOVABLE || driveType == DRIVE_FIXED)) {
		wcout << drive[0];
	}
	drive += wcslen(drive) + 1;
	// -----------------------------------

	// Если дисков больше одного, то узнаем их буквы
	while (*drive) {
		driveType = GetDriveTypeW(drive);

		if (driveType == DRIVE_REMOVABLE or driveType == DRIVE_FIXED) {
			wcout << "," << drive[0];
		}
		drive += wcslen(drive) + 1;
	}

	cout << "].";

	// Узнаем у пользователя имя интересующего диска
	wstring diskLetter = L"";
	cout << endl << "Выберите один: ";
	diskLetter += L"\\\\.\\";
	diskLetter += cin.get();
	diskLetter += L":";

	// чтение данных производится в отдельном классе
	FileHandle *fileHandle = new FileHandle(diskLetter);
	// с помощью шаблона Фабричный Метод создадим Reader
	Foundation *reader = FactoryMethod::CreateReader(fileHandle);
	// Вывод данных о ФС
	reader->ShowInfo();

	// Чтение первого кластера с помощью итератора
	cout << "Начало первого кластера" << endl;
	Iterator *iterator = new Iterator(reader);
	while(iterator->HasMore()) {
		Cluster *cluster = iterator->GetNext();
		cluster->ShowData();
		break;
	}
	cout << endl << "Конец первого кластера" << endl;

	// Чтение первого четного кластера с помощью декоратора
	cout << "Начало первого четного кластера" << endl;
	// Декоратор для итератора, который выводит четные кластеры
	Iterator *decorator = new Decorator(iterator);
	while (decorator->HasMore()) {
		Cluster *cluster = decorator->GetNext();
		cluster->ShowData();
		break;
	}
	cout << endl << "Конец первого четного кластера" << endl;
	system("pause");
}