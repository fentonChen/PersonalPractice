#include <iostream>

//define struct 1
typedef struct {
  int a;
  int b;  
}_Struct1;

class Example{
 public:
  Example() {
    _Struct1 struct1;
    struct1.a = 10;
    struct1.b = 12;
    struct_ = &struct1;  
  }

  void TransmitPointer(_Struct1 *recv_struct);
 private:
  _Struct1 *struct_;
};

void Example::TransmitPointer(_Struct1 *recv_struct) {
  if (recv_struct ==nullptr) {
    std::cout <<"recv_struct is empty" << std::endl;  
  }
  recv_struct = struct_;
  if (struct_ != NULL) {
    std::cout <<"struct_, a = " << struct_->a << std::endl;
  }

  if (recv_struct != NULL) {
    std::cout <<"recv_struct is not empty, b= " << recv_struct->b << std::endl;  
  }
}


//define a object of Example, also defined a pointer to the struct '_Struct1' in main() called 'another_stct',
//transmit the pointer of _Struct1 within the class 'Example' to  'another_stct'
//Would it be success ?
int main() {
  Example example_obj;
  _Struct1 *another_stct = NULL;
  example_obj.TransmitPointer(another_stct);
  if (another_stct != NULL) {
    std::cout <<"inspect : another_stct.a = " << another_stct->a << std::endl;
  }

  return 0;
}
