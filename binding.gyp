{
    "targets": [
        {
            "target_name": "dynatrace_wrapper",
            "cflags!": ["-fno-exceptions"],
            "cflags_cc!": ["-fno-exceptions"],
            "sources": ["src/dynatrace-wrapper.cc"],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")",
                "<(module_root_dir)/src/onesdk",
                "<!(node -e \"require('nan')\")"
            ],
            "defines": ["NAPI_DISABLE_CPP_EXCEPTIONS"],
            "link_settings": {
                "libraries": [
                    "<(module_root_dir)/lib/windows-x86_64/onesdk_shared.lib",
                ]
            }
        },
         {
         "target_name": "copy_binary",
         "type":"none",
         "dependencies" : [ "dynatrace_wrapper" ],
         "copies":
         [
            {
               'destination': '<(module_root_dir)/build/Release/',
               'files': ['<(module_root_dir)/lib/windows-x86_64/onesdk_shared.dll']
            }
         ]
      }
    ]
}