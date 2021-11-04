# Dynatrace NodeJS Native Wrapper

This is a wrapper around the C/C++ SDK, to monitor applications where the NodeJS agent is not supported.  
This was built for Node 6.X applications


> :warning: **Not supported**: This project is not supported by Dynatrace, it is a personal project, use at your own risk. 

## Requirements

* https://github.com/nodejs/node-gyp#on-windows 
* https://github.com/nodejs/node-gyp#on-unix 

## Building

The project uses `node-gyp 6.1.0`

Edit `bidings.gyp` `link_settings` and `copies` sections to use the correct lib for your architecture, by default it is using `windows-x86_64`

After that, run

* `npm install -g node-gyp@6.1.0`
* `npm config set msvs_version 2017`
* `npm install`
* `node-gyp rebuild`

## Running

You need the OneAgent installed on the machine.  
You can run `node sample_app.js` for a small demo.  