#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class ForwardList
{
	class Element
	{
		int Data;
		Element* pNext;
		static int count;
	public:
		Element(int Data, Element* pNext = nullptr)
		{
			this->Data = Data;
			this->pNext = pNext;
			count++;
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			count--;
			cout << "EDesconstructor:\t" << this << endl;
		}
		friend class ForwardList;
	};

	Element* Head;
public:
	ForwardList()
	{
		this->Head = nullptr;
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}
	//    Methods:
	void push_back(int Data)
	{
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Element* New = new Element(Data);
		Temp->pNext = New;

	}
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
	}
	void insert(int Index, int Data)
	{
		if (Index == 0)push_front(Data); return;
		//1) Создаём элемент:
		Element* New = new Element(Data);
		//2) Доходим до нужной позиции в списке:
		Element* Temp = Head;
		for (int i = 0; i < Index-1; i++)
		{
			Temp = Temp->pNext;
		}
		//3) Вставляем новый элемент в список:
		New->pNext = Temp->pNext;
		Temp->pNext = New;
	}
	void pop_front()
	{
		Element* Temp = Head;
		Head = Head->pNext;

		delete Temp;

	}

	void pop_back()
	{
		//Удаление с конца спискв.
	}
	void erase(int index)
	{

	}

	void print()
	{
		Element* Temp = Head;   //Temp = итератор.
		while (Temp != nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext; //Переход на следующий элемент.
		}
	}
};

int ForwardList::Element::count = 0;

void main()
{
	setlocale(LC_ALL, "");

	int n;
	cout << "Input list size: ";
	cin >> n;
	cout << endl;

	ForwardList fl;
	for (size_t i = 0; i < n; i++)
	{
		fl.push_front(rand() % 100);
	}
	fl.push_back(123);
	fl.print();
	fl.pop_front();
	fl.print();
	int index;
	int data;
	cout << "Input index: "; cin >> index; cout << endl;
	cout << "Input value: "; cin >> data; cout << endl;
	fl.insert(index, data);
	fl.print();
}