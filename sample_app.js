const dt = require("./index");

const initCode = dt.onesdk_initialize();
console.log(initCode);

const web_app_handle = dt.onesdk_webapplicationinfo_create("my-web-app", "test-service", "/");
const tracer = dt.onesdk_incomingwebrequesttracer_create(web_app_handle, "http://localhost:3000", "GET");

dt.onesdk_tracer_start(tracer);
setTimeout(function(){
    dt.onesdk_tracer_end(tracer);
}, 3000);

console.log("Sleeping");
setTimeout(function(){
    console.log("Exiting");
}, 60 * 10 * 1000);



