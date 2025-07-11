#include<iostream>
#include<cstring>
#include<string>
using namespace std;
class MyString {
private:
    char* data;
    int len;
    int buffer_size;
public:
    MyString(const char* str) {
        len = strlen(str);
        buffer_size = len + 1;
        data = new char[buffer_size];
        strncpy(data, str, buffer_size);
        data[buffer_size - 1] = '\0';
    }

    ~MyString() {
        delete[] data;
    }
    int length() const {
        return len;
    }
    int capacity() const {
        return buffer_size - 1;
    }
    bool empty() const {
        return len == 0;
    }
    bool compare(const MyString& str) {
        return strcmp(data, str.data) == 0;
    }
    void insert(int pos, const MyString& str) {
        if (pos < 0 || pos > len) {
            cout << "Invalid position." << endl;
            return;
        }
        int new_len = len + str.len;
        if (new_len + 1 > buffer_size) {
            resize(new_len + 1);
        }
        for (int i = len; i >= pos; --i) {
            data[i + str.len] = data[i];
        }
        strncpy(data + pos, str.data, str.len);
        len = new_len;
    }
    void replace(int pos, int r_len, const MyString& str) {
        if (pos < 0 || pos + r_len > len) {
            cout << "Invalid position or length." << endl;
            return;
        }
        int new_len = len - r_len + str.len;
        if (new_len + 1 > buffer_size) {
            resize(new_len + 1);
        }
        strncpy(data + pos, str.data, str.len);
        strncpy(data + pos + str.len, data + pos + r_len, len - pos - r_len);
        len = new_len;
    }
    void append(const MyString& str) {
        insert(len, str);
    }
    void resize(int n) {
        if (n <= 0) {
            cout << "Invalid size." << endl;
            return;
        }
        char* ndata = new char[n];
        strncpy(ndata, data, n - 1);
        ndata[n - 1] = '\0';
        delete[] data;
        data = ndata;
        buffer_size = n;
        len = strlen(data);
    }
    void push_back(char c) {
        if (len + 1 >= buffer_size) {
            resize(buffer_size * 2);
        }
        data[len++] = c;
        data[len] = '\0';
    }
    char pop_back() {
        if (len == 0) {
            cout << "String is empty.\n";
            return '\0';
        }
        char last_char = data[--len];
        data[len] = '\0';
        return last_char;
    }
    int find(const MyString& str, int pos) const {
        if (pos < 0 || pos >= len) {
            cout << "Invalid starting position.\n";
            return -1;
        }
        char* ptr = strstr(data + pos, str.data);
        if (ptr != nullptr) {
            return ptr - data;
        }
        return -1;
    }
    int rfind(const MyString& str) const {
        for (int i = len - str.len; i >= 0; --i) {
            if (strncmp(data + i, str.data, str.len) == 0) {
                return i;
            }
        }
        return -1;
    }

    MyString substr(int pos, int n) const {
        if (pos < 0 || pos >= len || n <= 0) {
            cout << "Invalid position or length.\n";
            return MyString("");
        }
        int substr_len = std::min(n, len - pos);
        char* substr_data = new char[substr_len + 1];
        strncpy(substr_data, data + pos, substr_len);
        substr_data[substr_len] = '\0';
        return MyString(substr_data);
    }
    /* void clear() {
         delete[] data;
         data = new char[1];
         data[0] = '\0';
         len = 0;
         buffer_size = 1;
     }*/
    void display() const {
        cout << data << endl;
    }
};
int main() {

    MyString s("Hello World");
    s.display();

    cout << "Length: " << s.length() << endl;
    cout << "Capacity: " << s.capacity() << endl;

    s.append(MyString(" everyone"));


    s.push_back('~');
    s.pop_back();
    cout << "After append,push back and pop back: \n";
    s.display();
    cout << "Find 'World' at index: " << s.find(MyString("World"), 0) << endl;

    MyString sstr = s.substr(0, 5);
    sstr.display();

    cout << "rFind 'World' at index: " << s.rfind(MyString("World")) << endl;

    return 0;
}
