# Cpp string


## std::string class in C++
1. C++ has in its definition a way to represent sequence of characters as an object of class. 
2. Need : `string` Library 
3. and `std namespce`

       #include<string> 
       using namespace std;
       string str = "Hello World !";

## System::String class in C++ (VC)
The Windows Runtime and common language runtime represent strings as objects whose allocated memory is managed automatically. That is, you are not required to explicitly discard the memory for a string when the string variable goes out of scope or your application ends. To indicate that the lifetime of a string object is to be managed automatically, declare the string type with the handle-to-object (^) modifier.

    using namespace System;
    System::String^ MyString1 = gcnew String();
    String^ MyString2 = "jumped over the lazy dog.";

## std::wstring class in C++

1. String class for wide characters.
2. This is an instantiation of the basic_string class template that uses wchar_t as the character type, with its default char_traits and allocator types (see basic_string for more info on the template).
3. Need : `string` Library 
4. and `std namespce`

       #include<string> 
       using namespace std;
       wstring str = L"سلام دنیا!";



## convert std string to System String 
        String ^ Text = gcnew String(Mystdstring_Object.c_str());
	
## convert std wstring to System String 
        String ^ Text = gcnew String(MystdWidestring_Object.c_str());	
		
## convert std string to std wstring (wide string)
  
        #include <codecvt>
        #include <locale>
        using std::string;
        using std::wstring;
        using std::wstring_convert;
        using std::range_error;

        wstring convert(string input)
        {
            try
        	{
        		wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        		return converter.from_bytes(input);
	        }
	        catch (range_error& e)
	        {
		        size_t length = input.length();
		        wstring result;
		        result.reserve(length);
                for (size_t i = 0; i < length; i++)
	            {
		            result.push_back(input[i] & 0xFF);
		        }
		        return result;
	        }
        }
        int main()
        {
            wstring stdWidestr = convert("std string or UTF8 in std string");
	    wcout << stdWidestr;
        }
			
## convert std wstring  to std string 
        #include <string>
        #include <iostream>
        #include <locale>
        using  std::string;
        using  std::wstring;
        string wstrTostr(wstring ws)
        {
            return std::string(ws.begin(), ws.end());
        }
	int main()
        {
            string str = wstrTostr(L"سلام");
        }

## convert System String  to std string 
        #include<msclr/marshal_cppstd.h>

        msclr::interop::marshal_context context;
        std::string wstr = context.marshal_as<std::string>(MySystemString_Object);
	
## convert System String  to std wString 
        #include <msclr\marshal.h>
        #include <msclr\marshal_cppstd.h>

        msclr::interop::marshal_context context;
        std::wstring wstr = std::wstring result = msclr::interop::marshal_as<std::wstring>(MySystemString_Object);

