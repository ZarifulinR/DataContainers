#include<iostream>
using namespace std;
#define tab "\t"

class Element
{
	int Data;		//�������� ��������
	Element* pNext;	//����� ����������
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
class ForwardList	//Forward- �����������, ����������������
{
	Element* Head;	//������ ������-�������� ��������� �� ������� ������� ������
public:
	ForwardList()
	{
		Head = nullptr;	//���� ������ ���� �� ��� ������ ��������� �� 0
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}
			///Adding elements
	void push_front(int Data)
	{
		//������� ����� �������
		Element* New = new Element(Data);
		//2) ����� ������� ������ ��������� �� ������ ������
		New->pNext = Head;
		//3) ������ ������ ��������� �� ����� �������
		Head = New;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		//������� ����� �������
		Element* New = new Element(Data);
		//������� �� ����� ������
		Element* Temp = Head;
		while (Temp->pNext)
			Temp = Temp->pNext;
		//��������� ������� � ����� ������
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
		Element* Temp = Head;	//Temp ��� ��������
					//��������- ��� ��������� , ��� ������ �������� ����� �������� ������
					// � ��������� ��������� ������
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;//������� �� ��������� �������
		}
	}
};
void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ ������:"; cin >> n;
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