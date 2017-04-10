#include "lexer.hpp"

#include <deque>
#include <vector>

/*
struct Parser {

    std::deque<Token*> tokens;

    Parser(std::vector<Token*> toks) {
        for (int i = 0; i < toks.size(); i++) {
            tokens.push_back(toks[i]);
        }
    }

    bool EoF() {
        return tokens.empty();
    }

    Token* peek() {
        if(!tokens.empty())
            return tokens.front();
        else
            return nullptr;
    }

    Token_Kind lookahead() {
        if (Token* Tok = peek())
            return Tok->kind;
        else
            return EoF_Tok;
    }

    Token* consume() {
        assert(!EoF());

        Token* Tok = tokens.front();
        tokens.pop_front();

        return Tok;
    }

    Token* match(Token_Kind k) {
        if (lookahead() == k)
            return consume();
        else {
                return 0;
        }
    }

    Token* match_if(Token_Kind k) {
        if (lookahead() == k) {
            return consume();
        }
        else {
            return nullptr;
        }
    }



    void parse() {

        std::vector<Expr*> es = expression_seq();
    }

    std::vector<Expr*> expression_seq() {
        std::vector<Expr*> es;
        while(!EoF()) {
            Expr* e = get_expression();
            es.push_back(e);
        }
        return es;
    }

    Expr* get_expression() {

        return expression_statement();


    }

    Expr* expression_statement() {


        Expr* e = expression();


        match(Colon_Tok);
        return e;
    }

    Expr* expression() {
        return additive_expression();
    }


    Expr* additive_expression() {
        Expr* e1 = mutliplicative_exprssion();
        while (true) {
            if (match_if(Plus_Tok)) {
                Expr* e2 = unary_expression();
                e1 = new Add_expr(e1, e2);
            }
            else if (match_if(Minus_Tok)) {
                Expr* e2 = unary_exprssion();
                e1 = new Sub_expr(e1, e2);
            }
            else
                break;
        }
        return e1;

    }

    Expr* multiplicative_expression() {
        while (true) {
            if (match_if(Mult_Tok)) {
                Expr* e2 = unary_expression();
                e1 = new Mult_expr(e1, e2);
            }
            else if (match_if(Div_Tok)) {
                Expr* e2 = unary_exprssion();
                e1 = new Div_expr(e1, e2);
            }
            else if (match_if(Rem_Tok)) {
                Expr* e2 = unary_exprssion();
                e1 = new Rem_expr(e1, e2);
            }
            else
                break;
        }
        return e1;
    }


    Expr* unary_expression() {


        if (match_if(Minus_Tok)) {
            expr* e = unary_expression();
            return new Not_expr(e);
        }
        else {
            return primary_expression();
        }
    }

    Expr* primary_expression() {
        switch (lookahead()) {
            case true_kw:
                consume();
                return new Bool_expr(true);
            case false_kw:
                consume();
                return new Bool_expr(false);
            case Int_Tok:
                Int_token* Tok = consume();
                return new Int_expr(tok->value);
            case ID_Tok:
                return id_expression();
            case LParen_Tok: {
                consume();
                Expr* e = expression();
                match(RParen_Tok);
                return e;
            }

            default:
                break;
        }
        std::cout << peek() << "\n";
        return 0;
    }

    Expr* ID_expression() {

    }


};
*/
