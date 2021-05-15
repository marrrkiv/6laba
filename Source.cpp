
//Створити шаблонний клас – однозв’язний кільцевий список у динамічній пам’яті.Тип елементів списку визначається параметром
//шаблона(цілі числа, дійсні числа, символи). Передбачити функції для виконання таких операцій : 
//занесення заданого елемента до списку, пошук мінімального та максимального елементів, виведення заданої кількості 
//елементів кільцевого списку на екран.

#include <iostream>

using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();
	void Get_Data() { return data; }
	void addToEmpty(T value);
	void addBegin(T value);
	void addEnd(T value);
	void addAfter(T value, T value2);
	void Output(int count);
	void maxandmin();
	
private:
	template<typename T>
	struct Node {
		Node* next;
		T data;

		Node(T data = T(), Node* pnext = nullptr) {
			this->data = data;
			this->next = pnext;
		}
	};

	Node<T>* list;
	int Num_of_Nodes;
};


int main()
{
	List<int> list;
	List<double> list1;
	List<char> list2;
	List<string> list3;

	list.addToEmpty(1);    //1
	list.addBegin(32);    //32 1
	list.addEnd(4);       //32 1 4
	list.addBegin(2);     //2 32 1 4
	list.addEnd(10);      //2 32 1 4 10
	list.addAfter(214, 1); //2 32 1 214 4 10
	list.addAfter(10, 2);   //...
	list.addBegin(756);
	list.Output(8);
	list.maxandmin();

	cout << endl;
	list1.addToEmpty(0.3);
	list1.addBegin(4.2);
	list1.addEnd(52.1);
	list1.addBegin(2.002);
	list1.addEnd(98.4);
	list1.addAfter(2.45, 4.2);
	list1.addAfter(10.0, 2.45);
	list1.addBegin(7.56);
	list1.Output(4);
	list1.maxandmin();

	cout << endl;
	list2.addToEmpty('a');
	list2.addBegin('b');
	list2.addEnd('c');
	list2.addBegin('d');
	list2.addEnd('r');
	list2.addAfter('o', 'd');
	list2.Output(5);
	list2.maxandmin();
  
	return 0;
}

template<typename T>
List<T>::List()
{
	Num_of_Nodes = 0;
	list = nullptr;
}

template<typename T>
List<T>::~List() {
	Node<T>* p, *temp;
	int i;
	if (Num_of_Nodes > 1) {
		p = list;
		for (i = 0; i < Num_of_Nodes - 1; i++) {
			temp = p;
			p = p->next;
			delete temp;
		}
		delete p;
	}
	else {
		delete list;
	}
}

template<typename T>
void List<T>::addToEmpty(T data) {
	if (list != NULL)
		return;

	Node<T>* new_node = new Node<T>(data);
	new_node->next = new_node;
	list = new_node;

	Num_of_Nodes++;
}

template<typename T>
void List<T>::addBegin(T data) {
	if (list == NULL)
		return addToEmpty(data);

	Node<T>* temp =
		new Node<T>(data);

	temp->next = list->next;
	list->next = temp;
	Num_of_Nodes++;
}
template<typename T>
void List<T>::addEnd(T data) {
	if (list == NULL)
		return addToEmpty(data);

	Node<T>* temp =
		new Node<T>(data);


	temp->next = list->next;
	list->next = temp;
	list = temp;
	Num_of_Nodes++;
}
template<typename T>
void List<T>::addAfter(T data, T item) {
	if (list == NULL)
		return;

	Node<T>* temp, *p;
	p = list->next;
	do {
		if (p->data == item) {
			temp = new Node<T>(data);
			temp->next = p->next;
			p->next = temp;

			if (p == list) {
				list = temp;
				return;
			}
		}
		p = p->next;
	} while (p != list->next);

	Num_of_Nodes++;
}


template<typename T>
void List<T>::Output(int count) {
	Node<T>* p;
	int i = 0;
	for (p = list; i < count; p = p->next, i++) {
		cout << p->data << endl;
	}
}

template<typename T>
void List<T>::maxandmin()
{
	Node<T>* p = list;
	T pmax = p->data, pmin = p->data;
	p = p->next;
	int i;

		for (i = 0; i < this->Num_of_Nodes; i++, p = p->next) {
			if (p->data < pmin) {
				pmin = p->data;
			}
		}
	p = list; p = p->next;
	for (i = 0; i < this->Num_of_Nodes; i++, p = p->next) {
		if (p->data > pmax) {
			pmax = p->data;
		}
	}
	cout << "minimum is : " << pmin << endl;
	cout << "maximum is : " << pmax << endl;
}
