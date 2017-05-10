//Implement a simple example ,used to inspect static callback method use with
//class. mainly to check how to access a class's member variable within a static
//method.
#include <iostream>

class CLS;
typedef void (*fun_ptr)(CLS *cls);


class VP {
  public:
  void set_inta(int a) { a_ = a; }
  int get_inta() { return a_; }
  private:  
  int a_;
};

class CLS {
  public:
  static void static_method(CLS *cls);
  void set_vp_value(int a) {vp_.set_inta(a);}
  int get_vp_a() { return vp_.get_inta();}
  int be_access;
  private:  
  VP vp_;
};

void CLS::static_method(CLS *cls) {
  std::cout <<"+++++++++++++++static_method++++++++++++++++++++++\n";
  //could access CLS::vp_ ?
  cls->be_access = 100;
  std::cout <<"be_access = " << cls->be_access << std::endl;
}

void just_one_caller(CLS *cls) {
  if (cls != NULL) {
    cls->static_method(cls);  
  }
}

int main() {
  CLS cls1;
  cls1.set_vp_value(10);

  //worked very well
  cls1.static_method(&cls1);

  //use callback to inspect again, still worked expected
  just_one_caller(&cls1);
  return 0;
}
