#include <iostream>
#include <string>
using namespace std;

// 字符串的创建和赋值
void my_creat() {
    string string_cStyle = "hello";                                     // C风格
    string string_cStyle2 = string("Hello, Hello, world!");             // C风格
    std::string string_copy = string_cStyle;                            // 拷贝构造
    std::string string_copy2 = string(string_cStyle);                   // 拷贝构造
    string mystring;                                                    // 创建空字符串
    mystring = string_cStyle;                                           // 赋值操作符重载
    mystring = "aaa";                                                   // operator=(_In_z_ const _Elem* const _Ptr)
}

//// 替换字符
//void my_replace() {
//    string mystring;
//}

// 替换字符
void my_replace() {
    string mystring = "1old1";
    mystring.replace(mystring.begin()+1, mystring.begin() + 4, { 'n', 'e', 'w' });
    cout << mystring << endl;
    mystring.replace(1, 3, "new");
    // Replace a substring with another substring
    std::basic_string<char> str1 = "old string";
    str1.replace(str1.find("old"), 3, "new");
    // Result: "new string"

    // Replace a substring with a character
    std::basic_string<char> str2 = "old string";
    str2.replace(str2.find("old"), 3, 1, 'n');
    // Result: "n string"

    // Replace a range of characters with another substring
    std::basic_string<char> str3 = "old string";
    str3.replace(0, 3, "new");
    // Result: "new string"

    // Replace a range of characters with a character
    std::basic_string<char> str4 = "old string";
    str4.replace(0, 3, 1, 'n');
    // Result: "n string"

    // Replace a range of characters with the contents of another string
    std::basic_string<char> str5 = "old string";
    std::basic_string<char> new_str = "new";
    str5.replace(0, 3, new_str);
    // Result: "new string"
}




void test01string() {
    my_replace();
}


/*
std::string 是 C++ 标准库中专门用来管理字符串的类，常用功能包括但不限于以下几点：

1. 字符串的创建和赋值

- std::string()：创建一个空字符串

- std::string(const char* s)：使用 C 风格字符串创建字符串

- std::string(const std::string& str)：拷贝构造函数，使用另一个字符串创建新字符串

- operator=()：赋值操作符重载，可以将一个字符串赋值给另一个字符串

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

5. 字符串的格式化输出

- to_string()：将数值类型转换为字符串

- std::ostringstream：格式化输出流，可以将多个类型的数据格式化为一个字符串
*/