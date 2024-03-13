#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Test {
public:
    Test(std::string name) {
        m_name = name;
        std::cout << m_name << "    Test constructor.\n" << std::endl;
    }
    ~Test() {
        std::cout << m_name << "    Test destructor.\n" << std::endl;
    }
    void print() {
        std::cout << m_name << "    Hello, Test!\n" << std::endl;
    }
    std::string m_name;
};
void myptr_creat() {
    std::unique_ptr<Test> ptr1 = std::make_unique<Test>("ptr1");  // 通过 make_unique 创建 unique_ptr
    ptr1->print();

    std::unique_ptr<Test> ptr2 = std::unique_ptr<Test>(new Test("ptr2"));  // 通过 new 创建 unique_ptr
    ptr2->print();

    std::unique_ptr<Test> ptr21(new Test("ptr21"));  // 通过 new 创建 unique_ptr
    ptr21->print();

    std::unique_ptr<Test> ptr3 = std::move(ptr2);  // 通过传递已有 unique_ptr 创建新的 unique_ptr (移动构造函数)
    ptr3->print();
    std::cout << "ptr2: " << (ptr2 ? "not null" : "null") << '\n\n' << std::endl;

    std::unique_ptr<Test> ptr4;     // 默认构造了一个空的unique_ptr对象
    ptr4 = std::move(ptr1);
    ptr4->print();

    ptr1 = std::move(ptr3);
    ptr1->print();

    std::unique_ptr<Test> ptr5(nullptr);        // 显式构造了一个空的unique_ptr对象
    ptr5 = std::move(ptr4);
    ptr5->print();
    std::cout << "\n\n";
}
class Object
{
private:
    int value;
public:
    Object(int val = 0) :value(val) { cout << "construct Object:" << value << endl; }
    ~Object() { cout << "destruct Object:" << value << endl; }
    int Value() { return value; }
    const int  Value() const { return value; }

};
void myptr_release() {
    unique_ptr<Object> pO(new Object(10));
    unique_ptr<Object> pO2(new Object(20));
    unique_ptr<int> pi(new int(1));
    cout << "p0:" << pO->Value() << endl;
    cout << *pi << endl;
    //pO = pO2;								// 编译不通过，不能拷贝构造或者赋值
    pO = std::move(pO2);					// 移动之后pO就析构掉了 p02指向null
    //cout << pO2->Value() << endl;			// 错误：如果不注释掉就执行失败，因为pO2已经没有对象资源的所有权了
    cout << pO->Value() << endl;            // p0指向20
    int* p = pi.release();
    // cout << *pi << endl;					//错误：release之后也会释放资源的所有权
    cout << "*p=" << *p << endl; delete p;

    cout << endl;
    unique_ptr<int[]> ps1(new int[10]{ 1,2,3,4,5,6,7,8,9,10 });
    //cout << *ps1 << endl;    特化版本不重载* ->
    for (int i = 0; i < 10; i++)
    {
        cout << ps1[i] << " ";
    }
    cout << endl;
    Object* Obj = new Object[]{ 10,20,30 };
    delete[]Obj;
    unique_ptr<Object[] > pobj(new Object[]{ 10,20,30 });

    cout << pobj[0].Value() << endl;
}


void test04ptr() {
    myptr_release();
}
