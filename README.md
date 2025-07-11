# MyStringCPP

A custom C++ implementation of the `std::string` class that uses dynamic memory (`char*`) to handle string operations manually. This project is designed to demonstrate how strings work under the hood, with full control over buffer management, resizing, and manipulation.

---

## 📚 Description

`MyStringCPP` is a handcrafted string class that offers core string functionalities such as appending, inserting, replacing, resizing, finding substrings, and more — all without using C++ STL classes. It is a great learning tool for understanding pointers, memory allocation, and string manipulation at a low level.

---

## ✨ Features

- 🛠 Constructor from C-style string (`const char*`)
- 📦 Destructor to handle memory deallocation
- 📏 `length()` and `capacity()` methods
- 🔍 Search:
  - `find(str, pos)`
  - `rfind(str)`
- ✏️ Modification:
  - `insert(pos, str)`
  - `replace(pos, len, str)`
  - `append(str)`
  - `resize(new_size)`
  - `push_back(c)`
  - `pop_back()`
- ✂️ `substr(pos, len)` for substring extraction
- 🖨️ `display()` for output

---

## 📌 Example Usage

```cpp
MyString s("Hello World");
s.append(MyString(" everyone"));
s.push_back('!');
s.pop_back();
int index = s.find(MyString("World"), 0);
MyString part = s.substr(0, 5);
part.display();
