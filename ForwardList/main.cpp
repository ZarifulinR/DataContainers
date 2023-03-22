#include<iostream>
using namespace std;
#define tab "\t"
using std::cin;
using std::cout;
using std::endl;

class Element
{
	int Data;		//�������� ��������
	Element* pNext;	//����� ����������
	static int count;
public:
	begin()
	{

	}
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
 int Element::count = 0; //�������������� ����������� ���������� ����������� � ������!"Element"
class ForwardList	//Forward- �����������, ����������������
{	
	Element* Head;	//������ ������-�������� ��������� �� ������� ������� ������
	int size ;
public:
	ForwardList()
	{
		Head = nullptr;	//���� ������ ���� �� ��� ������ ��������� �� 0
		size=0;
		cout << "LConstructor:\t" << this << endl;
	}
	ForwardList(const std::initializer_list<int>& il) :ForwardList()
	{
		//il- initializer_list
		//initializer_list-��� ��������.
		//��������� - ��� ������, ������� ���������� �������� ������ �������� � ������.
		// ��� � � ������ ������� ���������� � in ���� ������ begin() � end()
		//begin()-���������� �������� �� ������ �����������
		//end()-���������� �� ����� ����������.
		cout << typeid(il.begin()).name() << endl;
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}
			///Adding elements
	void push_front(int Data)
	{
		/*������� ����� �������
		Element* New = new Element(Data);
		2) ����� ������� ������ ��������� �� ������ ������
		New->pNext = Head;
		3) ������ ������ ��������� �� ����� �������
		Head = New;*/
		Head = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		//������� ����� �������
		//Element* New =;
		//������� �� ����� ������
		Element* Temp = Head;
		while (Temp->pNext)
			Temp = Temp->pNext;
		//��������� ������� � ����� ������
		Temp->pNext = new Element(Data);
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
		//Element* New = );
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
		//New->pNext = Temp->pNext;
		Temp->pNext = new Element(Data, Temp->pNext);
		size++;
	}
		/// Metods
	void Print()const
	{
		/*Element* Temp = Head;	//Temp ��� ��������
					//��������- ��� ��������� , ��� ������ �������� ����� �������� ������
					// � ��������� ��������� ������
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;//������� �� ��������� �������
		}*/
		for (Element* Temp = Head; Temp; Temp=Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "���������� ��������� � ������:" << size << endl;
		cout << "����� ���������� ���������:   " << Element::count << endl;
	}
};
//#define BASE_CHECK
//#define RANGE_BASED_FOR_ARRAY
void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
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
	//list.pop_front();
	//list.Print();
	int value;
	int index;
	cout << "������� ������ ������������ ��������:"; cin >> index;
	cout << "������� �������� ������������ ��������:"; cin >> value;
	list.insert(index, value);
	list.Print();
	//list.pop_back();
	list.Print();

	ForwardList list2;
	list2.push_back(3);
	list2.push_back(5);
	list2.push_back(8);
	list2.Print();
#endif // BASE_CHECK
#ifdef RANGE_BASED_FOR_ARRAY
	int arr[] = { 3,5,8,13,21 };
	/*for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		cout << arr[i]  << tab;
	}
	cout << endl;*/
	//Range-based for
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // RANGE_BASED_FOR_ARRAY
	ForwardList list = { 3,5,8,13,21 };
	//list.Print();
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;

}