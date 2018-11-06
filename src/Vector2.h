#ifndef TEST_ADDONS_NAPI_6_OBJECT_WRAP_VECTOR2_H_
#define TEST_ADDONS_NAPI_6_OBJECT_WRAP_VECTOR2_H_

#include <node_api.h>

class Vector2 {
public:
    // Serves as constructor
    static napi_value Init(napi_env env, napi_value exports);
    static void Destructor(napi_env env, void* nativeObject, void* finalize_hint);
    
private:
    explicit Vector2(double x_ = 0, double y_ = 0);
    ~Vector2();

    static napi_value New (napi_env env, napi_callback_info info);
    static napi_value GetX(napi_env env, napi_callback_info info);
    static napi_value SetX(napi_env env, napi_callback_info info);
    static napi_value GetY(napi_env env, napi_callback_info info);
    static napi_value SetY(napi_env env, napi_callback_info info);
    static napi_value AddScalar(napi_env env, napi_callback_info info);
    // static napi_value Sub(napi_env env, napi_callback_info info);
    // static napi_value Dot(napi_env env, napi_callback_info info);
    // static napi_value Multiply(napi_env env, napi_callback_info info);
    // static napi_value Divide(napi_env env, napi_callback_info info);
    // static napi_value Cross(napi_env env, napi_callback_info info);

    static napi_ref constructor;
    double x_;
    double y_;
    napi_env env_;
    napi_ref wrapper_;
};

#endif  // TEST_ADDONS_NAPI_6_OBJECT_WRAP_VECTOR2_H_