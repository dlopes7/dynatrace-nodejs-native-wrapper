var dynatrace = require("bindings")("dynatrace_wrapper");

function onesdk_initialize() {
    return dynatrace.onesdk_initialize();
}

module.exports.onesdk_initialize = onesdk_initialize;