#ifndef SCOPE_HPP
#define SCOPE_HPP

#include <unordered_map>
#include "symbol.hpp"

struct Context;
struct Token;
struct Stmt;
struct Expr;
struct Type;
struct Decl;


struct symbols
{
    std::unordered_map<symbol*, Decl*> scope;

    Decl* find(symbol* s) {
    	auto iter = scope.find(s);
    	if (iter != scope.end()) {
        	return iter->second;
    	}
    	else {
        	return nullptr;
        }
    }

    void insert(symbol* s, Decl* d) {
    	scope.insert({s,d});
    }

};

#endif
