#pragma once
#include "Header.hpp"
#include <fstream>
#include <algorithm>

class maelstrom::filesystem
{
public:
	enum io_mode
	{
		IO_MODE_CREATE,
		IO_MODE_APPEND,
		IO_MODE_READ,
		IO_MODE_WRITE,
		IO_MODE_DEFAULT
	};
public:
	filesystem(const std::string& filePath, io_mode eMode = IO_MODE_DEFAULT)
	{
		_filePath = filePath;
		mode = eMode;

		if (!file_exists(filePath) && (mode == IO_MODE_CREATE || mode == IO_MODE_DEFAULT))
			file_create(filePath);

		io_file_path(path);
		io_file_name(name);
		io_file_ext(extension);
		io_file_nlen(name_length);
		io_file_size(file_size);
	}


public:
	bool file_exists(const std::string sFilePath)
	{
		std::ifstream f(sFilePath.c_str());
		return f.good();
	}

	bool file_create(std::string sFilePath)
	{
		return (std::ofstream{ sFilePath }) ? true : false;
	}

	bool append(std::string format, ...) 
	{
		std::ofstream out(_filePath, std::ofstream::app);
		va_list args;
		va_start(args, format);
		char buff[2048];
		vsnprintf(buff, 2048, format.c_str(), args);
		out << buff;
		va_end(args);

		return out.good();
	}

	bool clean() 
	{
		std::ofstream out(_filePath, std::ofstream::out | std::ofstream::trunc);
		return (out << "") ? true : false;
	}

	bool write(string format, ...) 
	{
		std::ofstream out(_filePath, std::ofstream::out);
		va_list args;
		va_start(args, format);
		char buff[2048];
		vsnprintf(buff, 2048, format.c_str(), args);
		out << buff;
		va_end(args);

		return out.good();
	}

	string read() 
	{
		std::string result;
		std::ifstream in(_filePath);
		result.assign(
			(std::istreambuf_iterator<char>(in)),
			(std::istreambuf_iterator<char>())
		);
		return result;
	}

	void replace(std::string& source, const std::string& from, const std::string& to)
	{
		std::string newString;
		newString.reserve(source.length());  // avoids a few memory allocations

		std::string::size_type lastPos = 0;
		std::string::size_type findPos;

		while ((std::string::npos != (findPos = source.find(from, lastPos))))
		{
			newString.append(source, lastPos, findPos - lastPos);
			newString += to;
			lastPos = findPos + from.length();
		}

		// Care for the rest after last occurrence
		newString += source.substr(lastPos);

		source.swap(newString);
	}

	uint32 find(std::string _find) {}
	
	bool move(std::string _newPath) {}

	bool is_file() { return true; }
	bool is_dir() { return true; }
	bool is_readable() { return true; }
	bool is_writable() { return true; }

private:
	void io_file_path(std::string& cPath) 
	{
		size found = _filePath.find_last_of("/\\");
		cPath = _filePath.substr(0, found); 
	}

	void io_file_name(std::string& cName) 
	{
		cName = _filePath.substr(_filePath.find_last_of("/\\") + 1);
		std::string::size_type const sst(cName.find_last_of('.'));
		cName = cName.substr(0, sst);
	}

	void io_file_ext(std::string& cExt) 
	{
		cExt = _filePath.substr(_filePath.find_last_of("/\\") + 1);
		cExt = cExt.substr(cExt.find_last_of('.') + 1);
	}

	void io_file_nlen(uint32& cNameLen) 
	{
		cNameLen = name.length();
	}

	void io_file_size(uint32& cSize) 
	{
		std::ifstream in(_filePath, std::ifstream::ate | std::ifstream::binary);
		cSize = (uint32)in.tellg();
	}

private:
	std::string _filePath;

public:
	std::string path;
	std::string name;
	std::string extension;
	uint32 name_length;
	uint32 file_size;
	io_mode mode;
};
