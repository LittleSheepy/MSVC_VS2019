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
    std::string m_name="test";
};
void myptr_creat() {
    std::unique_ptr<Test> ptr1 = std::make_unique<Test>("ptr1");  // ͨ�� make_unique ���� unique_ptr
    ptr1->print();

    std::unique_ptr<Test> ptr2 = std::unique_ptr<Test>(new Test("ptr2"));  // ͨ�� new ���� unique_ptr
    ptr2->print();

    std::unique_ptr<Test> ptr21(new Test("ptr21"));  // ͨ�� new ���� unique_ptr
    ptr21->print();

    std::unique_ptr<Test> ptr3 = std::move(ptr2);  // ͨ���������� unique_ptr �����µ� unique_ptr (�ƶ����캯��)
    ptr3->print();
    std::cout << "ptr2: " << (ptr2 ? "not null" : "null") << '\n\n' << std::endl;

    // unique_ptr��������Ȩ��ת�� move
    std::unique_ptr<Test> ptr60(new Test("ptr60"));  // ͨ�� new ���� unique_ptr
    std::unique_ptr<Test> ptr61;     // Ĭ�Ϲ�����һ���յ�unique_ptr����
    ptr61 = std::move(ptr60);
    ptr61->print();
    // Ϊʲôʹ��move����Խ���ptr_3�Ĺ��죬����Ϊunique_ptr���н�����һ������Ϊ��ֵ���õĿ���������
    unique_ptr<Test> ptr62(move(ptr61));
    ptr62->print();

    Test* ptr63 = ptr62.release();
    ptr63->print();

    ptr1 = std::move(ptr3);
    ptr1->print();

    std::unique_ptr<Test> ptr5(nullptr);        // ��ʽ������һ���յ�unique_ptr����
    ptr5 = std::move(ptr1);
    ptr5->print();
    std::cout << "\n\n";

    // ѭ��
    vector<unique_ptr<Test>> ptrs(4);
    for (auto& ptr : ptrs) { // error ��ǿforѭ�������л�copyÿһ��Ԫ�أ����Լ�& ʹ�����ã����ò�copy
        ptr = std::unique_ptr<Test>(new Test("ptr7"));
        ptr->print();
        ptr->m_name = "ptrs";
        ptr->print();
    }
    //unique_ptr<Test> ptr8 = make_unique<Test>("ptr8");
    //vector<unique_ptr<Test>> v;
    //v.push_back(ptr8); // error push_back�´��һ�ݸ����Ž�vector	
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
    //pO = pO2;								// ���벻ͨ�������ܿ���������߸�ֵ
    pO = std::move(pO2);					// �ƶ�֮��pO���������� p02ָ��null
    //cout << pO2->Value() << endl;			// ���������ע�͵���ִ��ʧ�ܣ���ΪpO2�Ѿ�û�ж�����Դ������Ȩ��
    cout << pO->Value() << endl;            // p0ָ��20
    int* p = pi.release();                  // piָ��empty
    // cout << *pi << endl;					// ����release֮��Ҳ���ͷ���Դ������Ȩ
    cout << "*p=" << *p << endl; delete p;  // 1

    cout << endl;
    unique_ptr<int[]> ps1(new int[10]{ 1,2,3,4,5,6,7,8,9,10 });
    //cout << *ps1 << endl;    �ػ��汾������* ->
    for (int i = 0; i < 10; i++)
    {
        cout << ps1[i] << " ";
    }
    cout << endl;
    Object* Obj = new Object[]{ 1000,2000,3000 };
    delete[]Obj;
    unique_ptr<Object[] > pobj(new Object[]{ 100,200,300 });

    cout << pobj[0].Value() << endl;
}


void test04ptr() {
    myptr_creat();
    //myptr_release();
}
