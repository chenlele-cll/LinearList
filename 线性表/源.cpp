#include<iostream>
using namespace std;
template<class DataType>
class SequentialList
{
public:
	//���캯��
	SequentialList();
	SequentialList(int n);
	SequentialList(DataType q[],int n);
	//��������
	~SequentialList();

	//��ȡ�±�n��ֵ
	DataType getindexvalue(int n);

	//�������в���value
	int find(int value);

	//��indexλ�ò���Ԫ��value
	bool insert(int index, int value);

	//ɾ����indexԪ��
	bool erase(int index);

	//���
	void PrintList();

	//������������
	friend ostream &operator<<(ostream &output, const SequentialList &D)
	{
		for (int i = 0; i < D.len; i++)
			output << D.a[i] << " ";
		output << endl;
		return output;
	}
	
private:
	DataType *a;
	int len;//��ǰ���鳤��
	int maxsize;//�������
};

//��������Ĺ��캯��
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

//�Զ������������С�Ĺ��캯��
template<class DataType>
SequentialList<DataType>::SequentialList(int n)
{
	a = new DataType[n];
	maxsize = n;
	len = 0;
}

//���������Ĺ��캯��
template<class DataType>
SequentialList<DataType>::SequentialList()
{
	maxsize = 10;
	a = new DataType[maxsize];
	len = 0;
}

//��������
template<class DataType>
SequentialList<DataType>::~SequentialList()
{
	//delete []a;
	//��֪��Ϊʲôִ�����Ժ�ر�������ڻῨ��
}

//��ȡ�±�n������ֵ
template<class DataType>
DataType SequentialList<DataType>::getindexvalue(int n)
{
	if ( n<0 || n >= len)
	{
		cerr << "�±�Խ��" << endl;
	}
	else return a[n];
}

//����ֵvalue�������±�
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

//����Ԫ�غ���
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

//ɾ��Ԫ�غ���
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

	//���캯������
	SequentialList<int> p(t);
	SequentialList<int> q(a, t);

	//�������
	p.insert(0, 0);
	p.insert(1, 1);
	p.insert(2, 2);
	p.insert(1, 3);
	p.insert(0, 4);

	//�����������
	p.PrintList();

	//��ȡ�±�����ֵ����
	cout << "�����±�Ϊ3��ֵΪ��" << p.getindexvalue(3) << endl;

	//�±�Խ�����
	p.getindexvalue(5);

	//ֵ���Ҳ���
	if (p.find(3) != -1)
		cout << "ֵΪ3�������±�Ϊ��" << p.find(3) << endl;
	if (p.find(5) != -1)
		cout << "ֵΪ5�������±�Ϊ��" << p.find(5) << endl;
	else cout << "������û��ֵΪ5��Ԫ��" << endl;

	//ɾ��Ԫ�ز���
	q.erase(0);
	q.erase(2);
	cout << endl;
	//�������������
	cout << q;

	p.~SequentialList();
	q.~SequentialList();
	system("pause");
	return 0;
}
