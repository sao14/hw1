
#include <iostream>

#include "ast.hpp"
#include "eval.hpp"
#include "print.hpp"
#include "value.hpp"
#include "type.hpp"

int
main() {
  Context cxt;
  // or, not
  {
    Expr* e =
      new Or_expr(
        new Not_expr(
          new Bool_expr(true)
        ),
        new Bool_expr(true)
      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e).data.b << '\n';
  }
// and
  {
    Expr* e =
      new And_expr(
                   new Not_expr(
          new Bool_expr(true)
                                ),
          new Bool_expr(true)
      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e).data.b << '\n';
  }
  // equals
  {
    Expr* e =
      new Equals_expr(
        new Not_expr(
          new Bool_expr(false)
        ),
        new Bool_expr(true)
      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e).data.b << '\n';
  }
//not equals
  {
    Expr* e =
      new Not_Equals_expr(

          new Bool_expr(false)
        ,
        new Bool_expr(false)
      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e).data.b << '\n';
  }
  //Xor
  {
    Expr* e =
      new Xor_expr(

          new Bool_expr(true)
        ,
        new Bool_expr(false)
      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e).data.b << '\n';
  }
  // >
  {
    Expr* e =
      new Greater_expr(

          new Int_expr(6)
        ,
        new Int_expr(4)
      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e).data.b << '\n';
  }
  // <
  {
    Expr* e =
      new Less_expr(

          new Int_expr(6)
        ,
        new Int_expr(1)
      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e).data.b << '\n';
  }
  // >=
  {
    Expr* e =
      new Greater_Equals_expr(

          new Int_expr(7)
        ,
        new Int_expr(3)
      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e).data.b << '\n';
  }
  // <=
  {
    Expr* e =
      new Less_Equals_expr(

          new Int_expr(8)
        ,
        new Int_expr(3)
      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e).data.b << '\n';
  }
  //add
  {
    Expr* e =
      new Add_expr(

          new Int_expr(2)
        ,
        new Int_expr(5)
      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e).data.n << '\n';
  }
  // sub
  {
    Expr* e =
      new Sub_expr(

          new Int_expr(2)
        ,
        new Int_expr(6)
      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e).data.n << '\n';
  }
  // mult
  {
    Expr* e =
      new Mult_expr(

          new Int_expr(1)
        ,
        new Int_expr(3)
      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e).data.n << '\n';
  }
  // div
  {
    Expr* e =
      new Div_expr(

          new Int_expr(9)
        ,
        new Int_expr(4)
      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e).data.n << '\n';
  }
  //remainder
  {
    Expr* e =
      new Rem_expr(

          new Int_expr(3)
        ,
        new Int_expr(5)
      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e).data.n << '\n';
  }
  //Negative
  {
    Expr* e =
      new Neg_expr(

          new Int_expr(1)

      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e).data.n << '\n';
  }
// conditional
  {
    Expr* e =
      new Cond_expr(

          new Bool_expr(false)
                    ,
                    new Int_expr(2)
                    ,
                    new Int_expr(4)

      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e).data.n << '\n';
  }

}
