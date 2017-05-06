#include <rzway.h>

VALUE mRZWay;

void Init_rzway()
{
  mRZWay = rb_define_module("RZWay");
  Init_client();
}
