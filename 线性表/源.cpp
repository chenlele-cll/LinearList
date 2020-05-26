#include<iostream>
using namespace std;
template<class DataType>
class SequentialList
{
public:
	//构造函数
	SequentialList();
	SequentialList(int n);
	SequentialList(DataType q[],int n);
	//析构函数
	~SequentialList();

	//获取下标n的值
	DataType getindexvalue(int n);

	//在数组中查找value
	int find(int value);

	//在index位置插入元素value
	bool insert(int index, int value);

	//删除第index元素
	bool erase(int index);

	//输出
	void PrintList();

	//重载输出流输出
	friend ostream &operator<<(ostream &output, const SequentialList &D)
	{
		for (int i = 0; i < D.len; i++)
			output << D.a[i] << " ";
		output << endl;
		return output;
	}
	
private:
	DataType *a;
	int len;//当前数组长度
	int maxsize;//最大容量
};

//复制数组的构造函数
template<class DataType>
SequentialList<DataType>::SequentialList(DataType q[],int n)
{
	a = new DataType[n];
	maxsize = n;
	for (int i = 0; i < n; i++)
	{
		if (q[i] != '\0')
			a[i] = q[i];
		else
		{
			len = i;
			break;
		}
	}
}

//自定义最大容量大小的构造函数
template<class DataType>
SequentialList<DataType>::SequentialList(int n)
{
	a = new DataType[n];
	maxsize = n;
	len = 0;
}

//不带参数的构造函数
template<class DataType>
SequentialList<DataType>::SequentialList()
{
	maxsize = 10;
	a = new DataType[maxsize];
	len = 0;
}

//析构函数
template<class DataType>
SequentialList<DataType>::~SequentialList()
{
	//delete []a;
	//不知道为什么执行了以后关闭输出窗口会卡顿
}

//获取下标n的数组值
template<class DataType>
DataType SequentialList<DataType>::getindexvalue(int n)
{
	if ( n<0 || n >= len)
	{
		cerr << "下标越界" << endl;
	}
	else return a[n];
}

//查找值value的数组下标
template<class DataType>
int SequentialList<DataType>::find(int value)
{
	for (int i = 0; i < len; i++)
	{
		if (value == a[i])
			return i;
	}
	return -1;
}

//插入元素函数
template<class DataType>
bool SequentialList<DataType>::insert(int index, int value)
{
	if (index <= len)
	{
		for (int i = len - 1; i >= index; i--)
			a[i + 1] = a[i];
		a[index] = value;
		len++;
		return 1;
	}
	else
		return 0;
}

//删除元素函数
template<class DataType>
bool SequentialList<DataType>::erase(int index)
{
	if (index < len)
	{
		for (int i = index; i < len - 1; i++)
		{
			a[i] = a[i + 1];
		}
		a[len - 1]='/0';
		len--;
		return 1;
	}
	else return 0;
}

template<class DataType>
void SequentialList<DataType>::PrintList()
{
	for (int i = 0; i < len; i++)
		cout << a[i] << ' ';
	cout << endl;
}

int main()
{
	const int t = 10;
	int a[t] = { 1,2,3,4 };

	//构造函数测试
	SequentialList<int> p(t);
	SequentialList<int> q(a, t);

	//插入测试
	p.insert(0, 0);
	p.insert(1, 1);
	p.insert(2, 2);
	p.insert(1, 3);
	p.insert(0, 4);

	//输出函数测试
	p.PrintList();

	//获取下标数组值测试
	cout << "数组下标为3的值为：" << p.getindexvalue(3) << endl;

	//下标越界测试
	p.getindexvalue(5);

	//值查找测试
	if (p.find(3) != -1)
		cout << "值为3的数组下标为：" << p.find(3) << endl;
	if (p.find(5) != -1)
		cout << "值为5的数组下标为：" << p.find(5) << endl;
	else cout << "数组中没有值为5的元素" << endl;

	//删除元素测试
	q.erase(0);
	q.erase(2);
	cout << endl;
	//重载输出流测试
	cout << q;

	p.~SequentialList();
	q.~SequentialList();
	system("pause");
	return 0;
}
