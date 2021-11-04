#include <node.h>
#include <nan.h>
#include <onesdk.h>

using namespace v8;

using Nan::GetFunction;
using Nan::New;
using Nan::Set;

const char *NanToCString(v8::Local<v8::Value> &value)
{
  Nan::Utf8String val(value);
  return *val ? *val : "<string conversion failed>";
}

NAN_METHOD(dt_onesdk_initialize) {
  onesdk_result_t const onesdk_init_result = onesdk_initialize();
  // printf("ONESDK initialized:   %s\n", (onesdk_init_result == ONESDK_SUCCESS) ? "yes" : "no");
}

NAN_MODULE_INIT(initAll)
{
  Nan::Set(target, New<String>("onesdk_initialize").ToLocalChecked(),
      GetFunction(New<FunctionTemplate>(dt_onesdk_initialize)).ToLocalChecked());
}

NODE_MODULE(dynatrace_wrapper, initAll)