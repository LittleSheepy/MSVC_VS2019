#include <iostream>
#include <vector>
using namespace std;
template<typename T>
void print(vector<T>& v)//打印模板函数
{
	cout << '[';
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ",";
	}
	cout << ']' << endl;
}

// 创建容器
void myvect_creat() {
    vector<int> myvector1;                           // 
    vector<char> myvector2 = { 'a' , 'b', 'c' };     //使用列表初始化
    myvector2.push_back('d');
	print(myvector2);
	vector<int> v2(10, 2); // size为10，capacity为10
	print(v2);

}
void myvect_for() {
	vector<char> myvector1 = { 'a' , 'b', 'c' };
	//第一种遍历方式，下标
	for (unsigned int i = 0; i < myvector1.size(); ++i)
	{
		cout << myvector1[i] << " ";
	}
	cout << endl;
	//第二种遍历方式，迭代器
	vector<char>::iterator it = myvector1.begin();
	// vector<int>::const_iterator iter=v.begin();
	for (; it != myvector1.end(); ++it)
	{
		cout << (*it) << " ";
	}
	cout << endl;
	//第三种遍历方式，auto关键字
	cout << "C++11,第三种遍历方式，auto关键字" << endl;
	for (auto iter = myvector1.begin(); iter != myvector1.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	//第四种遍历方式，auto关键字的另一种方式
	cout << "C++11,第四种遍历方式，auto关键字" << endl;
	for (auto i : myvector1)
	{
		cout << i << " ";
	}
	cout << endl;
}

// 容器vector的增删改查
void myvect_operator() {
	vector<int> v1;
	v1.push_back(1);// 尾插  [1]
	v1.push_back(2);// 尾插  [1,2]
	v1.push_back(3);// 尾插  [1,2,3]
	print(v1);
	v1.pop_back();//尾删 [1,2]
	print(v1);
	auto pos = find(v1.begin(), v1.end(), 2);//注意：find不是vector的成员函数，返回一个迭代器
	v1.insert(pos, 4);//pos位置插入   [1,4,2]
	print(v1);
	//
	pos = find(v1.begin(), v1.end(), 4);
	v1.erase(pos);// [1,2,]
	print(v1);
	// 交换
	vector<char> s1{ 'h','e','l','l','o' };
	vector<char> s2{ 'w','o','r','d','!' };
	s1.swap(s2);// 交换s1 和 s2
	print(s1);//word!
	print(s2);//hello


}
/*
resize()是用来改变容器中元素个数的接口。
resize(n, value)将容器中的元素个数(size)改为n个，
若n大于容器中原有的元素个数（也就是说需要增添元素才能达到n个），则多出的元素使用value填充，填充的过程可能会改变容器的capacity的大小。
若n不大于容器原有的元素个数（也就无需增添元素），capacity也就不会变化。
*/
void myvect_resize() {
	vector<int> v;
	for (int i = 0; i < 5; i++)// [1,1,1,1,1]
	{
		v.push_back(1);
	}
	cout << v.size() << " " << v.capacity() << endl;

	v.resize(10, 2);	// [1,1,1,1,1,2,2,2,2,2]
	cout << v.size() << " " << v.capacity() << endl;

	v.resize(7, 3);//[1,1,1,1,1,2,2]
	cout << v.size() << " " << v.capacity() << endl;
}
/*
reverse()是改变capacity的大小，元素个数不变。reserve(new_capacity)来将容器的capacity设置为new_capacity，
如果new_capacity小于等于容器的capacity，则容器capacity不变；反之，则将容器capacity扩大到new_capacity。
其实现原理是：重新申请一块new_capacity大小的空间，再将原空间的元素拷贝过来，随即释放源空间资源。
*/
void myvect_reserve() {
	vector<string>  v1;
	int sz = v1.capacity();
	for (int i = 0; i < 200; i++)
	{
		v1.push_back("aaa");
		if (sz != v1.capacity())
		{
			sz = v1.capacity();
			cout << "v1.capacity=" << sz << endl;
		}
	}
	///
	vector<string>  v2;
	sz = v2.capacity();
	v2.reserve(200);
	for (int i = 0; i < 100; i++)
	{
		v2.push_back("aaa");
		if (sz != v2.capacity())
		{
			sz = v2.capacity();
			cout << "v2.capacity=" << sz << endl;
		}
	}
}

void test02vector() {
	myvect_for();
}



