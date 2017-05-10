//Implement a simple example ,used to inspect static callback method use with
//class.
#include <iostream>

typedef void (*fun_ptr)(int a);

static void just_one_caller(fun_ptr callback_mtd) {
  callback_mtd(10000);
}

class VP {
  public:
  void set_inta(int a) { a_ = a; }
  int get_inta() { return a_; }
  private:  
  int a_;
};

class CLS {
  public:
  static void static_method(int a);
  void set_vp_value(int a) {vp_.set_inta(a);}
  int get_vp_a() { return vp_.get_inta();}
  private:  
  VP vp_;
};

void CLS::static_method(int a) {
  std::cout <<"+++++++++++++++static_method++++++++++++++++++++++\n";
  std::cout <<"a " << a << std::endl;
}

int main() {
  CLS cls1;
  cls1.set_vp_value(10);

  just_one_caller(cls1.static_method);
  return 0;
}
