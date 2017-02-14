
#include "ast.hpp"

#include <iostream>

Type*
check(Context& cxt, Expr* e)
{
  class V : public Expr::Visitor {
      public:
    Context& cxt;
    Type* r;
    V(Context& c) : cxt(c) { }
    void visit(Bool_expr* e) {
      r = &cxt.bool_type;
    }
     void visit(Int_expr* e) {
      r = &cxt.int_type;
    }
    void visit(And_expr* e) {
      // check that e->e1 is bool
      // check that e->e2 is bool
      r = &cxt.bool_type;
    }
    void visit(Or_expr* e) {
      // check that e->e1 is bool
      // check that e->e2 is bool
      r = &cxt.bool_type;
    }
     void visit(Xor_expr* e) {
      // check that e->e1 is bool
      // check that e->e2 is bool
      r = &cxt.bool_type;
    }
    void visit(Not_expr* e) {
      // check that e->e1 is bool
      r = &cxt.bool_type;
    }
    void visit(Equals_expr* e) {
      // check that e->e1 is bool
      r = &cxt.bool_type;
    }
    void visit(Not_Equals_expr* e) {
      // check that e->e1 is bool
      r = &cxt.bool_type;
    }
    void visit(Greater_expr* e) {
      // check that e->e1 is bool
     r = &cxt.int_type;
    }
    void visit(Greater_Equals_expr* e) {
      // check that e->e1 is bool
      r = &cxt.int_type;
    }
    void visit(Less_expr* e) {
      // check that e->e1 is bool
     r = &cxt.int_type;
    }
    void visit(Less_Equals_expr* e) {
      // check that e->e1 is bool
      r = &cxt.int_type;
    }
    void visit(Add_expr* e) {
      // check that e->e1 is bool
     r = &cxt.int_type;
    }
    void visit(Sub_expr* e) {
      // check that e->e1 is bool
     r = &cxt.int_type;
    }
    void visit(Div_expr* e) {
      // check that e->e1 is bool
     r = &cxt.int_type;
    }
    void visit(Mult_expr* e) {
      // check that e->e1 is bool
     r = &cxt.int_type;
    }
    void visit(Rem_expr* e) {
      // check that e->e1 is bool
     r = &cxt.int_type;
    }
    void visit(Neg_expr* e) {
      // check that e->e1 is bool
     r = &cxt.int_type;
    }
    void visit(Cond_expr* e) {
      // check that e->e1 is bool
     r = &cxt.int_type;
    }
  };
  V vis(cxt);
  e->accept(vis);
  return vis.r;
}
