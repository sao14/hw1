#ifndef STMT_HPP
#define STMT_HPP

class Expr;
class Decl;

class Stmt {
    public:
  virtual ~Stmt() = default;
};

class expr_stmt : public Stmt {
    public:
  expr_stmt(expr* e) : exp(e) {}
  expr* exp;
};

class decl_stmt : public Stmt {
    public:
  decl_stmt(decl* d) : dec(d) {}
  decl* dec;
};

#endif
