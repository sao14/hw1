
#include "ast.hpp"
#include "value.hpp"

Value
eval(Expr* e)
{
  class V : public Expr::Visitor {
      public:
    Value r;
    void visit(Bool_expr* e) { r.data.b = e->val; }
    void visit(Int_expr* e) { r.data.n = e->val; }
    void visit(And_expr* e) { r.data.b = eval(e->e1).data.b & eval(e->e2).data.b; }
    void visit(Or_expr* e) { r.data.b = eval(e->e1).data.b | eval(e->e2).data.b; }
    void visit(Xor_expr* e) { r.data.b = eval(e->e1).data.b ^ eval(e->e2).data.b; }
    void visit(Not_expr* e) { r.data.b = !eval(e->e1).data.b; }
    void visit(Equals_expr* e) { r.data.b = eval(e->e1).data.b == eval(e->e2).data.b; }
    void visit(Not_Equals_expr* e) { r.data.b = eval(e->e1).data.b != eval(e->e2).data.b; }
    void visit(Greater_expr* e) { r.data.b = eval(e->e1).data.b > eval(e->e2).data.b; }
    void visit(Greater_Equals_expr* e) { r.data.b = eval(e->e1).data.b >= eval(e->e2).data.b; }
    void visit(Less_expr* e) { r.data.b = eval(e->e1).data.b < eval(e->e2).data.b; }
    void visit(Less_Equals_expr* e) { r.data.b = eval(e->e1).data.b <= eval(e->e2).data.b; }
    void visit(Add_expr* e) { r.data.n = eval(e->e1).data.n + eval(e->e2).data.n; }
    void visit(Sub_expr* e) { r.data.n = eval(e->e1).data.n - eval(e->e2).data.n; }
    void visit(Mult_expr* e) { r.data.n = eval(e->e1).data.n * eval(e->e2).data.n; }
    void visit(Div_expr* e) { r.data.n = eval(e->e1).data.n / eval(e->e2).data.n; }
    void visit(Rem_expr* e) { r.data.n = eval(e->e1).data.n % eval(e->e2).data.n; }
    void visit(Neg_expr* e) { r.data.n = 0 - eval(e->e1).data.n; }
    void visit(Cond_expr* e) {
        if (eval(e->e1).data.b){r.data.b = eval(e->e2).data.b;}
        else{ r.data.b = eval(e->e3).data.b;} }
  };
  V vis;
  e->accept(vis);
  return vis.r;
}
