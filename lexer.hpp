

#ifndef LEXER_HPP
#define LEXER_HPP
#include "ast.hpp"
#include<iostream>
#include <string>
#include <sstream>

enum Token_Kind{
Int_Tok, Bool_Tok, Colon_Tok,
EoF_Tok, LParen_Tok, RParen_Tok,
Plus_Tok, Minus_Tok, Mult_Tok,
Div_Tok, And_Tok, Or_Tok,
Not_Tok, Equal_Tok, NEqual_Tok,
Less_Tok, Greater_Tok, LessEq_Tok,
GreaterEq_Tok, Rem_Tok, ID_Tok
};

template <typename T>
std::string to_string(T value)
{
	std::ostringstream os ;
	os << value ;
	return os.str() ;
}

class Token{
    public:
    virtual ~Token() = default;
    int kind;
    std::string attribute;
    Token(){}
    //Token(Token_Kind k, int n) : kind(k), attribute(std::to_string(n)){}
    Token(Token_Kind k, std::string String): kind(k), attribute(String){}
};

class Int_Token : Token{
    public:
    int val;
};

class Bool_Token : Token{
    public:
    bool val;
};



class Lexer{
    public:
    const char *first, *last;
    std::string Buf;
    int n;

    Lexer(){
    const char *first = nullptr;
    const char *last = nullptr;
    n=0;
    Buf = " ";
    }

    Lexer(std::string String){
    first = &String[0];
    last = &String[String.size() - 1];
    }

bool EoF() const{
    return first == last;
}

char lookahead() const{
    if(EoF()){
        return 0;
    }
    else{
    return *first;
    }
}

void consume(){
    Buf += *first++;
}
    Token *next();
};

Token *Lexer::next() {
    Token *Tok;
    if (lookahead() == ' ') {
        consume();
    }
    switch (lookahead()) {
    case '<': consume();
            if (lookahead() == '=') {
                consume();
                Buf = "";
                return new Token(LessEq_Tok, " ");
    }
                Buf = "";
                return new Token(Less_Tok, " ");
    case '>': consume();
            if (lookahead() == '='){
                consume();
                Buf = "";
                return new Token(GreaterEq_Tok, " ");
    }
                Buf = "";
                return new Token(Greater_Tok, " ");
    case '+': consume();
                Buf = "";
                return new Token(Plus_Tok, " ");
    case '-': consume();
                Buf = "";
                return new Token(Minus_Tok, " ");
    case '*': consume();
                Buf = "";
                return new Token(Mult_Tok, " ");
    case '/': consume();
                Buf = "";
                return new Token(Div_Tok, " ");
    case '%': consume();
                Buf = "";
                return new Token(Rem_Tok, " ");
    case '&': consume();
            if (lookahead() == '&') {
                consume();
                Buf = "";
                return new Token(And_Tok, " ");
            } else {
                    return 0;
            }
    case '|': consume();
            if(lookahead() == '|') {
                consume();
                Buf = "";
                return new Token(Or_Tok, " ");
    }
    case '=': consume();
            if (lookahead() == '='){
                consume();
                Buf = "";
                return new Token(Equal_Tok, " ");
    }
    case '!': consume();
            if (lookahead() == '='){
                consume();
                Buf = "";
                return new Token(NEqual_Tok, " ");
    }
    else {
                Buf = "";
                return new Token(Not_Tok, " ");
    }
    case ')': consume();
                Buf = "";
                return new Token(LParen_Tok, " ");
    case '(': consume();
                Buf = "";
                return new Token(RParen_Tok, " ");
    case 't':consume();
            if (lookahead() == 'r') {
                consume();
            if (lookahead() == 'u') {
                consume();
            if (lookahead() == 'e') {
                consume();
                Buf = "";
                return 0;//new Token(Bool_Tok, 1);
            }
        }
    }
    case 'f': consume();
            if (lookahead() == 'a') {
                consume();
            if (lookahead() == 'l') {
                consume();
            if (lookahead() == 's') {
                consume();
            if (lookahead() == 'e') {
                consume();
                Buf = "";
                return new Token(Bool_Tok, 0);
                }
            }
        }
    }
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
                consume();
            while(std::isdigit(lookahead())) {
                consume();
    }

            //int n = stoi(Buf);
            //Token *Tok = new Int_Tok(std::stoi(Buf);
            Buf = "";
            return Tok;
            return new Token(Bool_Tok, 0);
    }
};
#endif
