#include "Vector2.h"
#include <assert.h>

napi_ref Vector2::constructor;

Vector2::Vector2(double x, double y)
    : x_(x),  y_(y), env_(nullptr), wrapper_(nullptr) {}

Vector2::~Vector2() { napi_delete_reference(env_, wrapper_); }

void Vector2::Destructor(napi_env env, void* nativeObject, void* /*finalize_hint*/) {
  reinterpret_cast<Vector2*>(nativeObject)->~Vector2();
}

#define DECLARE_NAPI_METHOD(name, func)                          \
  { name, 0, func, 0, 0, 0, napi_default, 0 }

napi_value Vector2::New(napi_env env, napi_callback_info info) {
  napi_status status;

  napi_value target;
  status = napi_get_new_target(env, info, &target);
  assert(status == napi_ok);
  bool is_constructor = target != nullptr;

  if (is_constructor) {
    // Invoked as constructor: `new Vector2(...)`
    size_t argc = 2;
    napi_value args[2];
    napi_value jsthis;
    status = napi_get_cb_info(env, info, &argc, args, &jsthis, nullptr);
    assert(status == napi_ok);

    double x = 0;

    napi_valuetype valuetypeX;
    status = napi_typeof(env, args[0], &valuetypeX);
    assert(status == napi_ok);

    if (valuetypeX != napi_undefined) {
      status = napi_get_value_double(env, args[0], &x);
      assert(status == napi_ok);
    }

    double y = 0;

    napi_valuetype valuetypeY;
    status = napi_typeof(env, args[1], &valuetypeY);
    assert(status == napi_ok);

    if (valuetypeY != napi_undefined) {
      status = napi_get_value_double(env, args[1], &y);
      assert(status == napi_ok);
    }

    Vector2* obj = new Vector2(x, y);

    obj->env_ = env;
    status = napi_wrap(env,
                       jsthis,
                       reinterpret_cast<void*>(obj),
                       Vector2::Destructor,
                       nullptr,  // finalize_hint
                       &obj->wrapper_);
    assert(status == napi_ok);

    return jsthis;
  } else {
    // Invoked as plain function `Vector2(...)`, turn into construct call.
    size_t argc_ = 1;
    napi_value args[1];
    status = napi_get_cb_info(env, info, &argc_, args, nullptr, nullptr);
    assert(status == napi_ok);

    const size_t argc = 1;
    napi_value argv[argc] = {args[0]};

    napi_value cons;
    status = napi_get_reference_value(env, constructor, &cons);
    assert(status == napi_ok);

    napi_value instance;
    status = napi_new_instance(env, cons, argc, argv, &instance);
    assert(status == napi_ok);

    return instance;
  }
}

napi_value Vector2::GetY(napi_env env, napi_callback_info info) {
  napi_status status;

  napi_value jsthis;
  status = napi_get_cb_info(env, info, nullptr, nullptr, &jsthis, nullptr);
  assert(status == napi_ok);

  Vector2* obj;
  status = napi_unwrap(env, jsthis, reinterpret_cast<void**>(&obj));
  assert(status == napi_ok);

  napi_value num;
  status = napi_create_double(env, obj->y_, &num);
  assert(status == napi_ok);

  return num;
}



napi_value Vector2::SetY(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 1;
  napi_value value;
  napi_value jsthis;
  status = napi_get_cb_info(env, info, &argc, &value, &jsthis, nullptr);
  assert(status == napi_ok);


  Vector2* obj;
  status = napi_unwrap(env, jsthis, reinterpret_cast<void**>(&obj));
  assert(status == napi_ok);

  status = napi_get_value_double(env, value, &obj->y_);
  assert(status == napi_ok);

  return nullptr;
}

napi_value Vector2::Init(napi_env env, napi_value exports) {
    napi_status status;
    // First you declare a set of properties.
    napi_property_descriptor properties[] = {
        {"x", 0, 0, GetX, SetX, 0, napi_default, 0},
        {"y", 0, 0, GetY, SetY, 0, napi_default, 0},
        // DECLARE_NAPI_METHOD("add", Add),
        // DECLARE_NAPI_METHOD("sub", Sub),
        // DECLARE_NAPI_METHOD("dot", Dot),
        // DECLARE_NAPI_METHOD("multiply", Multiply),
        // DECLARE_NAPI_METHOD("divide", Divide),
        // DECLARE_NAPI_METHOD("cross", Cross),
    };

    napi_value cons;

    // Then you define a class
    status = napi_define_class(env, "Vector2", NAPI_AUTO_LENGTH, New, nullptr, 2, properties, &cons);
    assert(status == napi_ok);

    // Then you create a reference
    status = napi_create_reference(env, cons, 1, &constructor);
    assert(status == napi_ok);

    status = napi_set_named_property(env, exports, "Vector2", cons);
    assert(status == napi_ok);
    return exports;
}

napi_value Vector2::GetX(napi_env env, napi_callback_info info) {
  napi_status status;

  napi_value jsthis;
  status = napi_get_cb_info(env, info, nullptr, nullptr, &jsthis, nullptr);
  assert(status == napi_ok);

  Vector2* obj;
  status = napi_unwrap(env, jsthis, reinterpret_cast<void**>(&obj));
  assert(status == napi_ok);

  napi_value num;
  status = napi_create_double(env, obj->x_, &num);
  assert(status == napi_ok);

  return num;
}

napi_value Vector2::SetX(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 1;
  napi_value value;
  napi_value jsthis;
  status = napi_get_cb_info(env, info, &argc, &value, &jsthis, nullptr);
  assert(status == napi_ok);


  Vector2* obj;
  status = napi_unwrap(env, jsthis, reinterpret_cast<void**>(&obj));
  assert(status == napi_ok);

  status = napi_get_value_double(env, value, &obj->x_);
  assert(status == napi_ok);

  return nullptr;
}

