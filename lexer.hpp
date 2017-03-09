

#ifndef LEXER_HPP
#define LEXER_HPP
#include "ast.hpp"
#include<iostream>

enum Token_Kind{
Int_Tok, Bool_Tok, Colon_Tok,
EoF_Tok, LParen_Tok, RParen_Tok,
Plus_Tok, Minus_Tok, Mult_Tok,
Div_Tok, And_Tok, Or_Tok,
Not_Tok, Equal_Tok, NEqual_Tok,
Less_Tok, Greater_Tok, LessEq_Tok,
};

class Token{
    public:
    //virtual ~Token();
    int kind;
    int attribute;
    Token(){}
    Token(Token_Kind, int n) : kind(n), attribute(n){}
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

bool EoF() const{
    return first == last;
}

char lookahead() const{
    return *first;
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
                return new Token(LessEq_Tok, 0);
    }
                Buf = "";
                return new Token(Less_Tok, 0);
    case '>': consume();
            if (lookahead() == '='){
                consume();
                Buf = "";
                return new Token(GreaterEq_Tok, 0);
    }
                Buf = "";
                return new Token(Greater_Tok, 0);
    case '+': consume();
                Buf = "";
                return new Token(Plus_Tok, 0);
    case '-': consume();
                Buf = "";
                return new Token(Minus_Tok, 0);
    case '*': consume();
                Buf = "";
                return new Token(Mult_Tok, 0);
    case '/': consume();
                Buf = "";
                return new Token(Div_Tok, 0);
    case '%': consume();
                Buf = "";
                return new Token(Mod_Tok, 0);
    case '&': consume();
            if (lookahead() == '&') {
                consume();
                Buf = "";
                return new Token(And_Tok, 0);
            } else {
                    return 0;
            }
    case '|': consume();
            if(lookahead() == '|') {
                consume();
                Buf = "";
                return new Token(Or_Tok, 0);
    }
    case '=': consume();
            if (lookahead() == '='){
                consume();
                Buf = "";
                return new Token(Equal_Tok, 0);
    }
    case '!': consume();
            if (lookahead() == '='){
                consume();
                Buf = "";
                return new Token(NEqual_Tok, 0);
    }
    else {
                Buf = "";
                return new Token(Not_Tok, 0);
    }
    case ')': consume();
                Buf = "";
                return new Token(LParen_Tok, 0);
    case '(': consume();
                Buf = "";
                return new Token(RParen_Tok, 0);
    case 't':consume();
            if (lookahead() == 'r') {
                consume();
            if (lookahead() == 'u') {
                consume();
            if (lookahead() == 'e') {
                consume();
                Buf = "";
                return new Token(Bool_Tok, 1);
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
            int n = 0;
            // std::std(Buf);
            Tok = new Token(Int_Tok, n);
            Buf = "";
            return Tok;
            return new Token(Bool_Tok, 0);
    }
};
#endif
