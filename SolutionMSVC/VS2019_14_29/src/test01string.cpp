#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// 字符串的创建和赋值
void my_creat() {
    int myInt = 42;
    double myDouble = 3.14;
    float myFloat = 2.718f;
    long myLong = 1234567890L;
    string intString = to_string(myInt);
    string doubleString = to_string(myDouble);
    string floatString = to_string(myFloat);
    string longString = to_string(myLong);
    string string_cStyle = "hello";                                     // C风格
    string string_cStyle2 = string("Hello, Hello, world!");             // C风格
    string string_copy = string_cStyle;                                 // 拷贝构造
    string string_copy2 = string(string_cStyle);                        // 拷贝构造
    string mystring;                                                    // 创建空字符串
    mystring = string_cStyle;                                           // 赋值操作符重载
    mystring = "aaa";                                                   // operator=(_In_z_ const _Elem* const _Ptr)

}

// 字符串操作
void my_operator() {
    string mystring = "0123456789A9876543210";
    char A = mystring[10];
    char c9 = mystring[9];
    printf("char %c %c\n", A, c9);
    string::size_type size = mystring.size();                           // size()
    string::size_type len = mystring.length();                          // length()
    printf("size, len %zu %zu\n", size, len);
    const char* c_str = mystring.c_str();
    char* data = mystring.data();
    mystring.clear();
    bool empty = mystring.empty();
    printf("empty %d\n", empty);
    mystring = "0123456789A9876543210";
    mystring.erase();
    empty = mystring.empty();
    printf("empty %d\n", empty);
    mystring = "0123456789A9876543210";
    mystring.insert(11, "B");
    printf("mystring %s\n", mystring.c_str());
}

void my_ostringstream() {
    int myInt = 42;
    double myDouble = 3.14;
    float myFloat = 2.718f;
    long myLong = 1234567890L;

    std::stringstream intStream;
    intStream << myInt;
    std::string intString = intStream.str();

    std::stringstream doubleStream;
    doubleStream << myDouble;
    std::string doubleString = doubleStream.str();

    std::stringstream floatStream;
    floatStream << myFloat;
    std::string floatString = floatStream.str();

    std::stringstream longStream;
    longStream << myLong;
    std::string longString = longStream.str();

    std::cout << "Integer string: " << intString << std::endl;
    std::cout << "Double string: " << doubleString << std::endl;
    std::cout << "Float string: " << floatString << std::endl;
    std::cout << "Long string: " << longString << std::endl;
}
// 字符串查找
void my_find() {
    string mystring = "0123456789876543210";
    string::size_type pos = mystring.find("2");
    printf("find %zu\n", pos);
    string::size_type rpos = mystring.rfind("2");
    printf("rfind %zu\n", rpos);

    std::string::size_type find_first_of_pos = mystring.find_first_of("92");    // 用于在字符串中查找第一个与指定字符序列中的任何一个字符匹配的字符。
    printf("find_first_of %zu\n", find_first_of_pos);

    std::string::size_type find_last_of_pos = mystring.find_last_of("92");    // 用于在字符串中查找最后一个与指定字符序列中的任何一个字符匹配的字符。
    printf("find_last_of %zu\n", find_last_of_pos);

    std::string::size_type find_first_not_of_pos = mystring.find_first_not_of("920");    // 用于在字符串中查找第一个与指定字符序列中的任何一个字符不匹配的字符。
    printf("find_first_not_of_pos %zu\n", find_first_not_of_pos);

    std::string::size_type find_last_not_of_pos = mystring.find_last_not_of("920");    // 用于在字符串中查找最后一个与指定字符序列中的任何一个字符不匹配的字符。
    printf("find_first_not_of_pos %zu\n", find_last_not_of_pos);



}

// 替换字符
void my_replace() {
    string mystring = "123456789abcde";
    mystring.replace(0, 1, "a");        // 用另一个子字符串替换字符范围
    mystring.replace(1, 1, "b", 1);
    mystring.replace(2, 1, 1, 'c');     // 将一系列字符替换为一个字符
    mystring.replace(3, 2, 2, 'd');     // 将一系列字符替换为N个字符
    mystring.replace(mystring.find("6"), 1, "e");
    cout << mystring << endl;
    mystring = "123456789abcde";
    mystring.replace(mystring.begin(), mystring.begin() + 1, "a");
    mystring.replace(mystring.begin() + 1, mystring.begin() + 2, "b", 1);
    mystring.replace(mystring.begin() + 2, mystring.begin() + 3, 1, 'c');
    mystring.replace(mystring.begin() + 3, mystring.begin() + 5, 2, 'd');
    mystring.replace(mystring.begin() + 5, mystring.begin() + 8, { 'e', 'f', 'g' });
    cout << mystring << endl;
    mystring = "123456789abcde";
    string mystring1 = "a";
    mystring.replace(0, 1, mystring1);
    mystring1 = "ab";
    mystring.replace(1, 1, mystring1, 1, 1);
    std::string_view view = "c";
    mystring.replace(2, 1, view);
    view = "cd";
    mystring.replace(3, 1, view, 1, 1);
    cout << mystring << endl;

    mystring = "123456789abcde";
    mystring1 = "a";
    mystring.replace(mystring.begin(), mystring.begin() + 1, mystring1);
    view = "b";
    mystring.replace(mystring.begin() + 1, mystring.begin() + 2, view);

    mystring = "123456789abcde";
    std::string str3 = "everyone";
    mystring.replace(mystring.begin(), mystring.end(), str3.begin(), str3.end());
    cout << mystring << endl;

    std::vector<int> vec{ 'a', 'b', 'c' };
    mystring = "123456789abcde";
    mystring.replace(mystring.begin(), mystring.end(), vec.begin(), vec.end());
    cout << mystring << endl;
}

// 末尾添加字符
void my_append() {
    string mystring = "123456789";
    mystring.append("a", 1);            // 向string 的后面加C-string 的一部分
    cout << mystring << endl;
    mystring.append("b");               // 向string 的后面加C-string
    cout << mystring << endl;
    string mystring2 = "c";
    mystring.append(mystring2);
    cout << mystring << endl; 
    mystring2 = "cd";
    mystring.append(mystring2, 1, 1);
    cout << mystring << endl;
    mystring2 = "de";
    mystring.append(mystring2.begin() + 1, mystring2.end());
    cout << mystring << endl;
    mystring.append(1, 'f');
    cout << mystring << endl;
}

void test01string() {
    my_creat();
}


/*
std::string 是 C++ 标准库中专门用来管理字符串的类，常用功能包括但不限于以下几点：

1. 字符串的创建和赋值

- std::string()：创建一个空字符串

- std::string(const char* s)：使用 C 风格字符串创建字符串

- std::string(const std::string& str)：拷贝构造函数，使用另一个字符串创建新字符串

- operator=()：赋值操作符重载，可以将一个字符串赋值给另一个字符串
- assign()

2. 字符串操作

- operator[]()：访问指定下标的字符

- at()：访问指定下标的字符，同时进行下标越界检查

- size() 和 length()：获取字符串的长度

- c_str()：返回以 C 风格字符串为格式表示的字符串

- data()：返回字符串中的字符数组

- empty()：判断字符串是否为空

- clear()：清空字符串

- erase()：删除字符串中的指定子串或单个字符

- insert()：向字符串中插入指定字符或子串

- replace()：用新的子串替换字符串中的旧子串

3. 字符串的查找和比较

- find()：查找指定子串在字符串中的位置

- rfind()：从字符串尾部开始查找指定子串的位置

- find_first_of()：查找字符串中第一个匹配指定字符集中字符的位置

- find_last_of(): 查找字符串中最后一个匹配指定字符集中字符的位置

- find_first_not_of(): 查找字符串中第一个不匹配指定字符集中字符的位置

- find_last_not_of(): 查找字符串中最后一个不匹配指定字符集中字符的位置

- compare()：比较两个字符串的大小关系

4. 字符串的拼接

- operator+()：字符串相加，将两个字符串拼接为一个字符串

- operator+=()：字符串相加，将另一个字符串拼接到当前字符串末尾
append()

5. 字符串的格式化输出

- to_string()：将数值类型转换为字符串

- std::ostringstream：格式化输出流，可以将多个类型的数据格式化为一个字符串
*/