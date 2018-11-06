#include "Vector2.h"

napi_value Init(napi_env env, napi_value exports) {
  return Vector2::Init(env, exports);
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
