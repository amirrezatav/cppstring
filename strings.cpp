#include <codecvt>
#include <locale>
#include<msclr/marshal_cppstd.h>
using System::String;
using std::string;
using std::wstring;


std::wstring stringTowstring(string input)
		{
			try
			{
				std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
				return converter.from_bytes(input);
			}
			catch (std::range_error& e)
			{
				size_t length = input.length();
				std::wstring result;
				result.reserve(length);
				for (size_t i = 0; i < length; i++)
				{
					result.push_back(input[i] & 0xFF);
				}
				return result;
			}
		}
System::String wstringToString(wstring input)
		{
                         String ^ Text = gcnew String(input.c_str());
                         return Text;
		}
std::string StringTowsstring(String input)
		{

			msclr::interop::marshal_context context;
			std::string path = context.marshal_as<std::string>(input);
			return path;
		}

