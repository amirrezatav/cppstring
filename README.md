# Cpp string

## convert System String  to std String 
        #include<msclr/marshal_cppstd.h>

        msclr::interop::marshal_context context;
        std::string path = context.marshal_as<std::string>(MySystemString_Object);

## convert std string to System String 
        String ^ Text = gcnew String(Mystdstring_Object.c_str());

## convert std string to std wstring (wide string)
  
        #include <codecvt>
        #include <locale>

        std::wstring convert(string input)
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
## convert std wstring (wide string) to System String 

        String ^ Text = gcnew String(convert(MyWideStringUTF8_Object).c_str());
