#pragma once

#include <fstream>
#include <iostream>
#include <iterator>
#include <streambuf>
#include <string>

namespace aux
{


inline int fileSize( const std::string& file )
{
    std::ifstream f( file, std::ios::binary | std::ios::ate );
    return f.tellg();
}

inline bool filesAreEqual( const std::string& file1, const std::string& file2 )
{
    std::ifstream     stream1{ file1 };
    const std::string data1{ std::istreambuf_iterator< char >{ stream1 }, std::istreambuf_iterator< char >{} };

    std::ifstream     stream2{ file2 };
    const std::string data2{ std::istreambuf_iterator< char >{ stream2 }, std::istreambuf_iterator< char >{} };

    return data1 == data2;
}


inline bool fileIsEmpty( const std::string& file )
{
    std::ifstream stream{ file };
    if (stream.peek() == std::ifstream::traits_type::eof() || stream.peek() == '\n')
    	return true;
    else
    	return false;
}


} // namespace aux
