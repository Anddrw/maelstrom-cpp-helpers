#pragma once
#include "Header.hpp"
#include <random>
#include <algorithm>
#include <iterator>

class maelstrom::random
{
	public:
		static uint32 
		range(uint32 tMin, uint32 tMax)
		{
			std::random_device				rd;
			std::mt19937					sd(rd());
			std::uniform_int_distribution<> uid(tMin, tMax);

			return uid(sd);
		}

		static char 
		letter(bool bUpper = false)
		{
			char letters[] = "abcdefghijklmnopqrstuvwxyz";
			char letter = letters[range(0, 25)];

			return (bUpper) ?
				toupper(letter) :
				letter;
		}

		static char
		symbol()
		{
			char symtable[] = "!@#$%^&*()_-+=|{}[];:'<>?/.";
			return symtable[range(0, 26)];
		}

		static string 
		alphanumeric(
			uint32 tSize = 9,
			bool bAllowUppercase = true,
			bool bAllowSymbols = true
		)
		{	
			auto randchar = [&]() -> string
			{
				uint32 _pick;
				string rch;
				(bAllowSymbols) ? _pick = range(1, 3) : _pick = range(1, 2);

				if (_pick == 1)
					rch = to_string(range(0, 9));
				if (_pick == 2)
					rch = (char)((bAllowUppercase && range(0, 3) == 1) ? letter(true) : letter());
				if (_pick == 3)
					rch = symbol();
				return rch;
			};

			string result;
			
			while (result.length() != tSize) result.append(randchar());

			return result;
		}
};
