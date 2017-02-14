
#include "ast.hpp"

bool
eval(Expr* e)
{
  class V : public Expr::Visitor {
      public:
    bool r;
    int n;
    void visit(Bool_expr* e) { r = e->val; }
    void visit(Int_expr* e) { n = e->val; }
    void visit(And_expr* e) { r = eval(e->e1) & eval(e->e2); }
    void visit(Or_expr* e) { r = eval(e->e1) | eval(e->e2); }
    void visit(Xor_expr* e) { r = eval(e->e1) ^ eval(e->e2); }
    void visit(Not_expr* e) { r = !eval(e->e1); }
    void visit(Equals_expr* e) { r = eval(e->e1) == eval(e->e2); }
    void visit(Not_Equals_expr* e) { r = eval(e->e1) != eval(e->e2); }
    void visit(Greater_expr* e) { r = eval(e->e1) > eval(e->e2); }
    void visit(Greater_Equals_expr* e) { r = eval(e->e1) >= eval(e->e2); }
    void visit(Less_expr* e) { r = eval(e->e1) < eval(e->e2); }
    void visit(Less_Equals_expr* e) { r = eval(e->e1) <= eval(e->e2); }
    void visit(Add_expr* e) { n = eval(e->e1) + eval(e->e2); }
    void visit(Sub_expr* e) { n = eval(e->e1) - eval(e->e2); }
    void visit(Mult_expr* e) { n = eval(e->e1) * eval(e->e2); }
    void visit(Div_expr* e) { n = eval(e->e1) / eval(e->e2); }
    void visit(Rem_expr* e) { n = eval(e->e1) % eval(e->e2); }
    void visit(Neg_expr* e) { n = 0 - eval(e->e1); }
    void visit(Cond_expr* e) { n = 0; } //if (eval(e->e1) == true){ n = eval(e->2); } else n = eval(e->e3); }
  };
  V vis;
  e->accept(vis);
  return vis.r;
}
