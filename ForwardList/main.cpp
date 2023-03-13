#include<iostream>
using namespace std;
#define tab "\t"

class Element
{
	int Data;		//Значение элемента
	Element* pNext;	//Адрес следующего
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) : Data(Data), pNext(pNext)
	{
		count++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};
 int Element::count = 0; //Инициализируем статическую переменную обьявленную в классе!"Element"
class ForwardList	//Forward- односвязный, однонаправленный
{
	Element* Head;	//голова списка-содержит указатель на нулевой элемент списка
	int size ;
public:
	ForwardList()
	{
		Head = nullptr;	//Если список пуст то его голова указывает на 0
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}
			///Adding elements
	void push_front(int Data)
	{
		/*Создаем новый элемент
		Element* New = new Element(Data);
		2) Новый элемент должен указывать на начало списка
		New->pNext = Head;
		3) Голову списка переводим на новый элемент
		Head = New;*/
		Head = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		//Создаем новый элемент
		Element* New = new Element(Data);
		//Доходим до конца списка
		Element* Temp = Head;
		while (Temp->pNext)
			Temp = Temp->pNext;
		//Добавляем элемент в конец списка
		Temp->pNext = New;
		size++;
	}
	//					Removing elements:
	void pop_front()
	{
		Element* buffer = Head;
		Head = Head->pNext;
		delete buffer;
		size--;
	}
	void pop_back()
	{
		if (Head == nullptr)return;
		if (Head->pNext == nullptr)return pop_front();
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}
	void insert(int index, int Data)
	{
		if (index == 0)return push_front(Data);
		if (index > size)return;
		Element* New = new Element(Data);
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}
		/// Metods
	void Print()const
	{
		Element* Temp = Head;	//Temp это итератор
					//Итератор- это указатель , при помощи которого можно получить доступ
					// к элементам структуры данных
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;//Переход на следующий элемент
		}
		cout << "Количество элементов в списке:" << size << endl;
		cout << "Общее количество элементов:   " << Element::count << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер списка:"; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
		//list.push_back(rand() % 100);
	}
	list.Print();
	//list.push_back(132);
	//list.Print();
	//list.pop_front();
	//list.Print();
	int value;
	int index;
	cout << "Введите индукс добовляемого значения:"; cin >> index;
	cout << "Введите значение добовляемого значения:"; cin >> value;
	list.insert(index, value);
	list.Print();
	//list.pop_back();
	list.Print();

	ForwardList list2;
	list2.push_back(3);
	list2.push_back(5);
	list2.push_back(8);
	list2.Print();


}