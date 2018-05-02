//#ifndef SORT_H
#define SORT_H
#include<iostream>
#include <cassert>
template<class T>
class sort_interface
{
	public:
	//	virtual void sort(T *i, size_t n)=0;
		sort_interface() {}
		virtual void sort(T *i, size_t n)=0;

};

template <class T>
class bubble_sort : public sort_interface<T> //ok
{
	
	public:
		
		void sort(T *i, size_t n);
	private:
		void swapy(T *xp, T *yp);
	
};

template <class T>
class quick_sort : public sort_interface<T>// NPI
{
	public:
		void sort(T *i, size_t n);
	
};

template <class T>
class insert_sort : public sort_interface<T>//ok
{
	public:
		void sort(T *i, size_t n);
	
};

template <class T>
class shell_sort: public sort_interface<T>//ok
{
	public:
		void sort(T *i, size_t n);
};

template <class T>
class merge_sort: public sort_interface<T> //ok
{

	public:
		void sort(T *i, size_t n);
	private:
		void merge(T *a,int low, int high, int mid);
		void merging(T *a, int low, int high);
		
};
/*
template <class T>
class heap_sort: public sort_interface<T>
{
	private:
		T *i;
		size_t n;
	public:
		heap_sort(T *_i,size_t _n);
		void sort();
	private:
		void heapify(T *a, size_ t _n, int j);
		void swapy(T *xp, T *yp);

}
*/
#include "sort.inl"
//#endif SORT_H
