# CPP std string to wstring (utf8)
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

        String ^ Text = gcnew String(convert(MyWideStringUTF8Object).c_str());
