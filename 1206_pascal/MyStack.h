#include <iostream>
#include <cstring>

template <typename elem_type>
class mylist
{
public:
	virtual size_t length() const = 0;
	virtual void insert(size_t, const elem_type&) = 0;
	virtual elem_type remove(size_t) = 0;
	virtual int search(elem_type) const = 0;
	virtual elem_type& operator[](size_t) const = 0;
	virtual ~mylist() {};
};


/*

***********************
*	 栈线性表实现      *
***********************

*/

template <typename elem_type>
class mystack :public mylist<elem_type>
{
public:
	mystack(size_t max) :len(0), cap(max), data(new elem_type[max]) {};
	//拷贝构造函数，防止默认拷贝指针副本
	mystack(const mystack& li);

	mystack& operator=(const mystack& li);

	size_t length() const { return len; }
	size_t capacity() const { return cap; }
	bool isfull() const { return length() == capacity(); }
	bool isempty() const { return !length(); }
	elem_type& back() { return data[len - 1]; }

	//将元素插入到指定元素的前面
	void insert(size_t, const elem_type&);

	//删除指定元素
	elem_type remove(size_t);

	//查找对应值
	int search(elem_type) const;

	//使用[]运算符访问表内元素
	elem_type& operator[](size_t) const;

	//pop,push
	void push(const elem_type& val) { insert(len, val); }
	elem_type pop() { return remove(len - 1); }


	//遍历表内元素并输出（可选间隔符）
	void traverse(const char*) const;

	//（虚）析构函数要释放内存
	virtual ~mystack() { delete[] data; }

protected:
	//表的长度，最大长度和指向表头的指针

	size_t len;
	size_t cap;
	elem_type* data;

	//重设线性表大小（只能增大）
	void resize(size_t);
};

template <typename elem_type>
mystack<elem_type>::mystack(const mystack<elem_type>& li)
	:len(li.len), cap(li.cap), data(new elem_type[cap])
{
	for (size_t i = 0; i < length(); i++)
		data[i] = li.data[i];
}

template <typename elem_type>
mystack<elem_type>& mystack<elem_type>::operator=(const mystack<elem_type>& li)
{
	len = li.len;
	cap = li.cap;
	for (size_t i = 0; i < length(); i++)
		data[i] = li.data[i];
	return *this;
}

template <typename elem_type>
void mystack<elem_type>::insert(size_t pos, const elem_type& val)
{
	if (pos <= length())
	{
		if (isfull())
		{
			resize(capacity()*1.5 + 1);
		}
		for (size_t i = length(); i > pos; --i)
			data[i] = data[i - 1];
		data[pos] = val;
		len++;
	}
}

template <typename elem_type>
elem_type mystack<elem_type>::remove(size_t pos)
{
	if (pos < length())
	{
		elem_type ret = data[pos];
		for (size_t i = pos; i < length() - 1; ++i)
			data[i] = data[i + 1];
		len--;
		return ret;
	}

}

template <typename elem_type>
int mystack<elem_type>::search(elem_type val) const
{
	for (size_t i = 0; i < length(); i++)
	{
		if (val == data[i])
			return i;
	}
	return -1;
}

template <typename elem_type>
elem_type& mystack<elem_type>::operator[](size_t pos) const
{
	if (pos < length())
	{
		return data[pos];
	}
}

template <typename elem_type>
void mystack<elem_type>::traverse(const char* s) const
{
	for (size_t i = 0; i < length(); i++)
		std::cout << data[i] << s;
}

template <typename elem_type>
mystack<elem_type> link(mystack<elem_type> &rhs,
	mystack<elem_type> &lhs)
{
	mystack<elem_type> ret(rhs.capacity() + lhs.capacity());
	for (size_t i = 0; i < rhs.length(); i++)
		//使用insert而非设置为友元修改data是为了不直接修改len防止错误
		ret.insert(i, rhs[i]);
	for (size_t i = 0; i < lhs.length(); i++)
		ret.insert(i + rhs.length(), lhs[i]);
	return ret;
}

template <typename elem_type>
void mystack<elem_type>::resize(size_t n)
{
	if (n > capacity())
	{
		//新建存储空间后给新空间元素赋值
		elem_type* nlist = new elem_type[n];
		for (int i = 0; i < length(); i++)
		{
			nlist[i] = data[i];
		}
		//建立临时指针存储原数据值，稍后删除
		elem_type* temp = data;
		//将指针绑定到新空间，并设置capacity
		data = nlist;
		cap = n;
		//删除原数据
		delete[] temp;
	}
}
