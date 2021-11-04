const dynatrace = require("bindings")("dynatrace_wrapper");

// Init
function onesdk_initialize() {
    return dynatrace.onesdk_initialize();
}
module.exports.onesdk_initialize = onesdk_initialize;

// Web Application Info
function onesdk_webapplicationinfo_create(web_server_name, service_name, context_root) {
    return dynatrace.onesdk_webapplicationinfo_create(web_server_name, service_name, context_root);
}
module.exports.onesdk_webapplicationinfo_create = onesdk_webapplicationinfo_create;

// Incoming Web Request - Create
function onesdk_incomingwebrequesttracer_create(web_application_handle, url, method) {
    return dynatrace.onesdk_incomingwebrequesttracer_create(web_application_handle, url, method);
}
module.exports.onesdk_incomingwebrequesttracer_create = onesdk_incomingwebrequesttracer_create;

// Trace - Start
function onesdk_tracer_start(tracer_handle) {
    return dynatrace.onesdk_tracer_start(tracer_handle);
}
module.exports.onesdk_tracer_start = onesdk_tracer_start;

// Trace - End
function onesdk_tracer_end(tracer_handle) {
    return dynatrace.onesdk_tracer_end(tracer_handle);
}
module.exports.onesdk_tracer_end = onesdk_tracer_end;

