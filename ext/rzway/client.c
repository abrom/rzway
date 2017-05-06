#include <client.h>

void Init_client()
{
  VALUE cClient = rb_define_class_under(mRZWay, "Client", rb_cObject);

  rb_define_alloc_func(cClient, client_allocate);
  rb_define_method(cClient, "initialize", client_initialize, -1);
  rb_define_method(cClient, "terminate!", client_terminate, 0);
}

static VALUE client_allocate(VALUE klass)
{
  ZWay zway = NULL;
  return Data_Wrap_Struct(klass, NULL, NULL, &zway);
}

static VALUE client_initialize(int argc, VALUE* argv, VALUE self)
{
  printf("client init\n");

  VALUE device_path;
  rb_scan_args(argc, argv, "01", &device_path);

//  printf("FOO: %"PRIsVALUE"\n", (char*) device_path);

  ZWay *zway;
  Data_Get_Struct(self, ZWay, zway);

  ZWError r = zway_init(zway, ZSTR((char*)device_path), NULL, NULL, NULL, NULL, NULL);

  if (r != NoError)
  {
    rb_raise(rb_eRuntimeError, "Could not initialize ZWay");
  }
  else
  {
    printf("Initialized!\n");
  }
  return self;
}

static VALUE client_terminate(VALUE self)
{
  ZWay *zway;
  Data_Get_Struct(self, ZWay, zway);

  zway_stop(*zway);
  zway_terminate(zway);

  return Qnil;
}
