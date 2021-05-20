# Cpp string


## std::string class in C++
1. C++ has in its definition a way to represent sequence of characters as an object of class. 
2. Need : `string` Library 
3. and `std namespce`
```cpp
       #include<string> 
       using namespace std;
       string str = "Hello World !";
```
## System::String class in C++ (Just VC)
The Windows Runtime and common language runtime represent strings as objects whose allocated memory is managed automatically. That is, you are not required to explicitly discard the memory for a string when the string variable goes out of scope or your application ends. To indicate that the lifetime of a string object is to be managed automatically, declare the string type with the handle-to-object (^) modifier.
```cpp
    using namespace System;
    System::String^ MyString1 = gcnew String();
    String^ MyString2 = "jumped over the lazy dog.";
```
## std::wstring class in C++

1. String class for wide characters.
2. This is an instantiation of the basic_string class template that uses wchar_t as the character type, with its default char_traits and allocator types (see basic_string for more info on the template).
3. Need : `string` Library 
4. and `std namespce`
```cpp
       #include<string> 
       using namespace std;
       wstring str = L"سلام دنیا!";
```


## convert std string to System String 
        String ^ Text = gcnew String(Mystdstring_Object.c_str());
	
## convert std wstring to System String 
        String ^ Text = gcnew String(MystdWidestring_Object.c_str());	
		
		
		
		
		
## convert std string to std wstring (wide string)

```cpp
    #include <string>
    #include <codecvt>
    #include <locale>
    std::string input_str = "this is a -string-, which is a sequence based on the -char- type.";
    std::wstring str_turned_to_wstr = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(input_str);
```

## convert std wstring  to std string 
```cpp
    #include <string>
    #include <codecvt>
    #include <locale>
    std::wstring input_wstr = L"this is a -wide- string, which is based on the -wchar_t- type.";
    std::string wstr_turned_to_str = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(input_wstr);
```

## convert System String  to std string 
```cpp
        #include<msclr/marshal_cppstd.h>

        msclr::interop::marshal_context context;
        std::string wstr = context.marshal_as<std::string>(MySystemString_Object);
```	
## convert System String  to std wString 
```cpp
        #include <msclr\marshal.h>
        #include <msclr\marshal_cppstd.h>

        msclr::interop::marshal_context context;
        std::wstring wstr = std::wstring result = msclr::interop::marshal_as<std::wstring>(MySystemString_Object);
```
