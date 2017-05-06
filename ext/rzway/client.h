#ifndef RUBY_CLIENT
#define RUBY_CLIENT

#include <rzway.h>

void Init_client();
static VALUE client_allocate();
static VALUE client_initialize();
static VALUE client_terminate();

#endif
