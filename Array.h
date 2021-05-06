#pragma once
#include <iostream>

using namespace std;

class Array
{
public:
private:
	static const size_t minsize = 10; // мінімальний розмір масиву
	size_t Size; // виділення пам'яті для елементів
	size_t Count; // кількість елементів в масиві 
	size_t First; // значення іедексу першого елемента в масиві
	double* elems; // вказівник на дані
public:
	// конструктори/копіювання/деструктор
	Array(const size_t& n = minsize)	//конструктор для створення контейнера(масива) за розміром
		throw(bad_alloc, invalid_argument);
	Array(const Array&) //конструктор коміювання
		throw(bad_alloc);
	Array(const double* first, const double* last) //конструктор для створення контейнера/масива за першим та останнім елементом
		throw(bad_alloc, invalid_argument);
	Array(const size_t first, const size_t last) //конструктор для створення контейнера/масива за першим та останнім елементом
		throw(bad_alloc, invalid_argument);
	~Array();//деструктор
	Array& operator=(const Array&);//перевантаження операції присвоєння

	// ітератори
	double* begin() { return elems; }  //ітератор, що вказує на початок масиву
	const double* begin() const { return elems; }  //ітератор const, що вказує на початку масиву
	double* end() { return elems + Count; }  //ітератор, що вказує на кінець масиву
	const double* end() const { return elems + Count; }  //ітератор const, що вказує на кінець масиву

	// розміри
	size_t size() const; // поточний розмір
	bool empty() const; // якщо є елементи
	size_t capacity() const; // потенційний розмір
	void resize(size_t newsize) // змінити розмір
		throw(bad_alloc);

	// доступ до елементів
	double& operator[](size_t) throw(out_of_range);
	const double& operator[](size_t) const throw(out_of_range);
	double& front() { return elems[0]; }
	const double& front() const { return elems[0]; }
	double& back() { return elems[size() - 1]; }
	const double& back() const { return elems[size() - 1]; }

	// методи-модифікатори
	void push_back(const double& v); // добавити елемент в кінець
	void pop_back(); // видалити останній елемент
	void clear() { Count = 0; } // очистити масив
	void swap(Array& other); // поміняти з другим масивом

	friend ostream& operator <<(ostream& out, const Array& a);
	friend istream& operator >>(istream& in, Array& a);

	double Sum();
	double SeredneZnachennia();
	void SumaVKinets();
	void SeredZnachVKinets();
	void Change();

};
