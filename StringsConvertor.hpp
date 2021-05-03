#ifndef STRINGSCONVERTOR_H
#define STRINGSCONVERTOR_H
#include <codecvt>
#include <locale>
#include<msclr/marshal_cppstd.h>
using System::String;
using std::string;
using std::wstring;
using System::String;
ref class StringsConvertor
{
public:
	/// <summary>
	/// convert std string to std Wide string
	/// </summary>
	/// <param name="input">std string</param>
	/// <returns>wstring</returns>
	static std::wstring strTowstr(string input)
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
	/// <summary>
	/// convert std wstring to System String
	/// </summary>
	/// <param name="input">std wstring</param>
	/// <returns>String ^</returns>
	static System::String^ wstrToStr(wstring input)
	{
		String^ Text = gcnew String(input.c_str());
		return Text;
	}
	/// <summary>
	/// convert System String to std string 
	/// </summary>
	/// <param name="input">System ^</param>
	/// <returns>string</returns>
	static std::string StrTostr(String^ input)
	{

		msclr::interop::marshal_context context;
		std::string path = context.marshal_as<std::string>(input);
		return path;
	}
	/// <summary>
	/// convert std wstring to std string 
	/// </summary>
	/// <param name="input">wstring</param>
	/// <returns>string</returns>
	static std::string wstrTostr(wstring ws)
	{
		return std::string(ws.begin(), ws.end());
	}
	/// <summary>
	/// convert std System String to wstring 
	/// </summary>
	/// <param name="input">System ^</param>
	/// <returns>wstring</returns>
	static std::wstring Strtowstr(String^ input)
	{
		msclr::interop::marshal_context context;
		return context.marshal_as<std::wstring>(input);
	}
	/// <summary>
	/// convert std System String to string 
	/// </summary>
	/// <param name="input">System ^</param>
	/// <returns>string</returns>
	static std::string Strtostr(String^ input)
	{
		msclr::interop::marshal_context context;
		return context.marshal_as<std::string>(input);
	}
};

#endif // !STRINGSCONVERTOR_H
