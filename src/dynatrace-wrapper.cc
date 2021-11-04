#include <inttypes.h>

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

// initialize
NAN_METHOD(dt_onesdk_initialize) {
  onesdk_stub_set_logging_level(0);
  onesdk_result_t const onesdk_init_result = onesdk_initialize();
  // printf("ONESDK initialized:   %s\n", (onesdk_init_result == ONESDK_SUCCESS) ? "yes" : "no");
  info.GetReturnValue().Set(onesdk_init_result);
}

// create web app
NAN_METHOD(dt_onesdk_webapplicationinfo_create) {
  onesdk_webapplicationinfo_handle_t const m_web_application_info_handle = onesdk_webapplicationinfo_create(
            onesdk_asciistr("example.com"),             // web server name
            onesdk_asciistr("sample1.web_service"),     // unique application/service name
            onesdk_asciistr("/sample1/web-service/"));  

  // printf("create_web_app, web_application_handle=%d\n", m_web_application_info_handle);
  // printf("%" PRIu64 "\n\n", m_web_application_info_handle);
  info.GetReturnValue().Set((double)m_web_application_info_handle);
}


// create incoming web request tracer
NAN_METHOD(dt_onesdk_incomingwebrequesttracer_create) {

  onesdk_webapplicationinfo_handle_t web_application_handle = info[0]->NumberValue();
  printf("create_tracer, web_application_handle=%" PRIu64 "\n", web_application_handle);

  onesdk_tracer_handle_t const tracer = onesdk_incomingwebrequesttracer_create(web_application_handle,
            onesdk_utf8str("https://localhost:8080"),
            onesdk_utf8str("GET"));

  info.GetReturnValue().Set((double)tracer);
}

// tracer start
NAN_METHOD(dt_onesdk_tracer_start) {
  onesdk_tracer_handle_t tracer = info[0]->NumberValue();
  onesdk_tracer_start(tracer);
}

// tracer end
NAN_METHOD(dt_onesdk_tracer_end) {
  onesdk_tracer_handle_t tracer = info[0]->NumberValue();
  onesdk_tracer_end(tracer);
}


NAN_MODULE_INIT(initAll)
{
  Nan::Set(target, New<String>("onesdk_initialize").ToLocalChecked(),
      GetFunction(New<FunctionTemplate>(dt_onesdk_initialize)).ToLocalChecked());

  Nan::Set(target, New<String>("onesdk_webapplicationinfo_create").ToLocalChecked(),
      GetFunction(New<FunctionTemplate>(dt_onesdk_webapplicationinfo_create)).ToLocalChecked());

  Nan::Set(target, New<String>("onesdk_incomingwebrequesttracer_create").ToLocalChecked(),
      GetFunction(New<FunctionTemplate>(dt_onesdk_incomingwebrequesttracer_create)).ToLocalChecked());

  Nan::Set(target, New<String>("onesdk_tracer_start").ToLocalChecked(),
      GetFunction(New<FunctionTemplate>(dt_onesdk_tracer_start)).ToLocalChecked());

  Nan::Set(target, New<String>("onesdk_tracer_end").ToLocalChecked(),
      GetFunction(New<FunctionTemplate>(dt_onesdk_tracer_end)).ToLocalChecked());
}

NODE_MODULE(dynatrace_wrapper, initAll)