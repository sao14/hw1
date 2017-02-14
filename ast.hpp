
#ifndef AST_HPP
#define AST_HPP

#include <cassert>


class Bool_type;
class Int_type;

class Bool_expr;
class Int_expr;
class And_expr;
class Or_expr;
class Xor_expr;
class Not_expr;
class Equals_expr;
class Not_Equals_expr;
class Greater_expr;
class Greater_Equals_expr;
class Less_expr;
class Less_Equals_expr;
class Add_expr;
class Sub_expr;
class Mult_expr;
class Div_expr;
class Rem_expr;
class Neg_expr;
class Cond_expr;


class Type {
    public:
  class Visitor;
  virtual ~Type() = default;
  virtual void accept(Visitor&) { }
};

class Bool_type : public Type { };
class Int_type : public Type { };


class Expr {
    public:
  class Visitor;
  virtual ~Expr() = default;
  virtual void accept(Visitor&) = 0;
};

class Expr::Visitor{
    public:
  virtual void visit(Bool_expr*) = 0;
  virtual void visit(Int_expr*) = 0;
  virtual void visit(And_expr*) = 0;
  virtual void visit(Or_expr*) = 0;
  virtual void visit(Xor_expr*) = 0;
  virtual void visit(Not_expr*) = 0;
  virtual void visit(Equals_expr*) = 0;
  virtual void visit(Not_Equals_expr*) = 0;
  virtual void visit(Greater_expr*) = 0;
  virtual void visit(Greater_Equals_expr*) = 0;
  virtual void visit(Less_expr*) = 0;
  virtual void visit(Less_Equals_expr*) = 0;
  virtual void visit(Add_expr*) = 0;
  virtual void visit(Sub_expr*) = 0;
  virtual void visit(Mult_expr*) = 0;
  virtual void visit(Div_expr*) = 0;
  virtual void visit(Neg_expr*) = 0;
  virtual void visit(Rem_expr*) = 0;
  virtual void visit(Cond_expr*) = 0;
};

class Bool_expr : public Expr {
    public:
  bool val;
  Bool_expr(bool b) : val(b) { }
  void accept(Visitor& v) { return v.visit(this); }
};

class Int_expr : public Expr {
    public:
  int val;
  Int_expr(int n) : val(n) { }
  void accept(Visitor& v) { return v.visit(this); }
};

class And_expr : public Expr {
    public:
  Expr* e1;
  Expr* e2;
  And_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

class Or_expr : public Expr {
    public:
  Expr* e1;
  Expr* e2;
  Or_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

class Xor_expr : public Expr {
    public:
  Expr* e1;
  Expr* e2;
  Xor_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

class Not_expr : public Expr {
    public:
  Expr* e1;
  Not_expr(Expr* e1) : e1(e1) { }
  void accept(Visitor& v) { return v.visit(this); }
};

class Equals_expr : public Expr {
     public:
  Expr* e1;
  Expr* e2;
  Equals_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

class Not_Equals_expr : public Expr {
     public:
  Expr* e1;
  Expr* e2;
  Not_Equals_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

class Greater_expr : public Expr {
     public:
  Expr* e1;
  Expr* e2;
  Greater_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

class Greater_Equals_expr : public Expr {
     public:
  Expr* e1;
  Expr* e2;
  Greater_Equals_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

class Less_expr : public Expr {
     public:
  Expr* e1;
  Expr* e2;
  Less_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

class Less_Equals_expr : public Expr {
     public:
  Expr* e1;
  Expr* e2;
  Less_Equals_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

class Add_expr : public Expr {
     public:
  Expr* e1;
  Expr* e2;
  Add_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

class Sub_expr : public Expr {
     public:
  Expr* e1;
  Expr* e2;
  Sub_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

class Mult_expr : public Expr {
     public:
  Expr* e1;
  Expr* e2;
  Mult_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

class Div_expr : public Expr {
     public:
  Expr* e1;
  Expr* e2;
  Div_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

class Rem_expr : public Expr {
     public:
  Expr* e1;
  Expr* e2;
  Rem_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

class Neg_expr : public Expr {
     public:
  Expr* e1;
  Expr* e2;
  Neg_expr(Expr* e1) : e1(e1) { }
  void accept(Visitor& v) { return v.visit(this); }
};

class Cond_expr : public Expr {
     public:
  Expr* e1;
  Expr* e2;
  Expr* e3;
  Cond_expr(Expr* e1, Expr* e2, Expr* e3) : e1(e1), e2(e2), e3(e3) { }
  void accept(Visitor& v) { return v.visit(this); }
};

class Context{
    public:
  Bool_type bool_type;
  Int_type int_type;
};


#endif
