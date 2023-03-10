#include<iostream>
using namespace std;
#define tab "\t"

class Element
{
	int Data;		//Значение элемента
	Element* pNext;	//Адрес следующего
public:
	Element(int Data, Element* pNext = nullptr) : Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};
class ForwardList	//Forward- односвязный, однонаправленный
{
	Element* Head;	//голова списка-содержит указатель на нулевой элемент списка
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
		//Создаем новый элемент
		Element* New = new Element(Data);
		//2) Новый элемент должен указывать на начало списка
		New->pNext = Head;
		//3) Голову списка переводим на новый элемент
		Head = New;
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
		
	}
	//					Removing elements:
	void pop_front()
	{
		Element* buffer = Head;
		Head = Head->pNext;
		delete buffer;

	}
	void pop_back()
	{
		if (Head == nullptr)return;
		if (Head->pNext == nullptr)return pop_front();
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = nullptr;
		
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
	list.pop_front();
	list.Print();
	list.pop_back();
	list.Print();

}