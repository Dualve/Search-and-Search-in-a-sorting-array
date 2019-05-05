#include <iostream>

using namespace std;

struct WORKER
{
	char name[15];
	char position[15];
	char number[15];
	int salary;
};
template< class T >
void shellSort(T* arr, int size);

template< class T >
void selectSort(T* arr, int size);

void search_record(WORKER* arr[], int size, char check_other[]);
void search_record(WORKER* arr[], int size, int check_sal);
void search_record(WORKER* arr[], int left, int right, int key);
void search_record(WORKER* arr[], int left, int right, char key[15]);

int main()
{
	setlocale(LC_ALL, "Rus");
	system("color F0");

	int check;
	int check_sal;
	int choiser;
	char check_other[15];
	const int NUM = 12;
	WORKER* arr[NUM];

	FILE* ZName;
	fopen_s(&ZName, "D:\\213\\universe\\ОАИП\\лаба 12\\Project1\\Project1\\members.txt", "r+b");


	for (int i = 0; i < NUM; i++)
	{
		arr[i] = new WORKER;
	}

	for (int i = 0; i < NUM; i++)
	{
		fread(arr[i], sizeof(*arr[i]), 1, ZName);
	}


	while (true)
	{
		cout << "\nМассив отсортирован? \n1)Да\n2)Нет" << endl;
		cin >> choiser;
		cout << "Что будем искать:\n1)Имя\n2)Работу\n3)Номер телефона\n4)Зарплату\n5)Exit" << endl;
		cin >> check;
		if (check == 1)
		{
			cout << "Введите искомое имя:" << endl;
			cin >> check_other;
			cout << endl;
			search_record(arr, NUM, check_other);
		}
		else if (check == 2)
		{
			cout << "Введите искомую работу:" << endl;
			cin >> check_other;
			cout << endl;
			if (choiser == 2)
			{
				search_record(arr, NUM, check_other);
			}
			else
			{
				shellSort(arr, NUM);
				search_record(arr, 0, NUM, check_other);
			}
		}
		else if (check == 3)
		{
			cout << "Введите искомый телефон:" << endl;
			cin >> check_other;
			cout << endl;
			search_record(arr, NUM, check_other);
		}
		else if (check == 4)
		{
			cout << "Введите искомую зарплату:" << endl;
			cin >> check_sal;
			cout << endl;
			if (choiser == 2)
			{
				search_record(arr, NUM, check_sal);
			}
			else
			{
				selectSort(arr, NUM);
				search_record(arr, 0, NUM, check_sal);
			}
		}
		else if (check == 5) 
		{
			break;
		}
		else
		{
			cout << "Error" << endl;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		delete[] arr[i];
	}

	fclose(ZName);

	system("Pause");
	return 0;
}

void search_record(WORKER* arr[], int size, char check_other[])
{
	bool flag = false;

	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i]->name, check_other) == 0 || strcmp(arr[i]->position, check_other) == 0 || strcmp(arr[i]->number, check_other) == 0)
		{
			cout << arr[i]->name << endl;
			cout << arr[i]->position << endl;
			cout << arr[i]->number << endl;
			cout << arr[i]->salary << endl;
			cout << endl;
			flag = true;
		}
	}

	if (!flag)
	{
		cout << "Элемента с такими данными нет" << endl;
	}
}

void search_record(WORKER* arr[], int size, int check_sal) 
{
	bool flag = false;

	for (int i = 0; i < size; i++)
	{
		if (arr[i]->salary == check_sal)
		{	
			cout << arr[i]->name << endl;
			cout << arr[i]->position << endl;
			cout << arr[i]->number << endl;
			cout << arr[i]->salary << endl;
			cout << endl;
			flag = true;
		}
	}

	if (!flag)
	{
		cout << "Элемента с такой зарплатой нет" << endl;
	}
}

void search_record(WORKER* arr[], int left, int right, int key)
{
	bool flag = true;
	int midd = 0;
	while (flag)
	{
		midd = (left + right) / 2;

		if (key < arr[midd]->salary)
		{
			left = midd - 1;
		}
		else if (key > arr[midd]->salary)
		{
			right = midd + 1;
		}
		else
		{
			cout << arr[midd]->name << endl;
			cout << arr[midd]->position << endl;
			cout << arr[midd]->number << endl;
			cout << arr[midd]->salary << endl;
			cout << endl;
			flag = false;
		}
		if (right > left)
		{
			cout << "Такого элемента не существует." << endl;
			flag = false;
		}
	}
}

void search_record(WORKER* arr[], int left, int right, char key[15])
{
	bool flag = true;
	int midd = 0;
	while (flag)
	{
		midd = (left + right) / 2;

		if (strcmp(key, arr[midd]->position) < 0 )
		{
			right = midd - 1;
		}
		else if (strcmp(key, arr[midd]->position) > 0 )
		{
			left = midd + 1;
		}
		else
		{
			cout << arr[midd]->name << endl;
			cout << arr[midd]->position << endl;
			cout << arr[midd]->number << endl;
			cout << arr[midd]->salary << endl;
			cout << endl;
			flag = false;
		}
		if (right < left)
		{
			cout << "Такого элемента не существует." << endl;
			flag = false;
		}
	}
}

template< class T >
void selectSort(T* arr, int size)
{
	int tmp_salary;
	T tmp;
	for (int i = 0; i < size; i++) // i - номер текущего шага
	{
		int pos = i;
		tmp = arr[i];
		tmp_salary = tmp->salary;
		for (int j = i + 1; j < size; j++) // цикл выбора наименьшего элемента
		{
			if (arr[j]->salary > tmp_salary)
			{
				pos = j;
				tmp = arr[j];
				tmp_salary = tmp->salary;
			}
		}
		arr[pos] = arr[i];
		arr[i] = tmp; // меняем местами наименьший с a[i]
	}
}

int increment(int inc[], int size)
{
	int p1, p2, p3, s;
	p1 = p2 = p3 = 1;
	s = -1;
	do
	{
		if (++s % 2)
		{
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else
		{
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * inc[s] < size);

	return s > 0 ? --s : 0;
}


template< class T >
void shellSort(T* arr, int size)
{
	int inc, i, j, seq[40];
	int s;

	s = increment(seq, size); // вычисление последовательности приращений
	while (s >= 0)  // сортировка вставками с инкрементами inc[] 
	{
		inc = seq[s--];
		for (i = inc; i < size; i++)
		{
			T temp = arr[i];
			for (j = i; (j >= inc) && (strcmp(temp->position, arr[j - inc]->position) < 0); j -= inc)
			{
				arr[j] = arr[j - inc];
			}
			arr[j] = temp;
		}
	}
}