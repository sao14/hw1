#ifndef SYMBOL_HPP
#define SYMBOL_HPP

#include <string>
#include <unordered_map>

using symbol = const std::string;

struct symbol_map
{
	std::unordered_map<std::string, void*> symbolMap;

	symbol* insert(const std::string& str) {
		auto result = symbolMap.insert({str, nullptr});
		return &result.first->first;
	}
	symbol* find(const std::string& str) {
		auto iter = symbolMap.find(str);
		return &iter->first;
	}
};


#endif
