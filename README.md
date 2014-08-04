Cordova Honeywell Captuvo Plugin
============

This is a Cordova/Phonegap plugin to interact with Honeywell Captuvo sled for iPhones, iPod Touches and iPad Minis (https://www.honeywellaidc.com/en-US/Pages/Product.aspx?category=enterprise-sleds-for-apple-devices&cat=HSM&pid=CaptuvoSL22). The plugin works by interacting with the native SDK provided by Honeywell to handle barcode scans and magstripe reads.

NOTE 1: the SL62 has a different SDK that needs to be swapped out in this plugin

NOTE: this plugin includes version 2.13.611 of the SL42 SDK.  **You must independently agree to the EULA from HoneyWell.**

=============

This plugin is compatible with plugman.  To install, run the following from your project command line: 
```$ cordova plugin add https://github.com/BlueFletch/cordova-plugin-honeywell-captuvo.git```


==============


<h3>To Use:</h3>

Register for callbacks for barcode scanning and/or magnetic stripe reads:
```
   document.addEventListener("deviceready", function(){ 
       ...
       captuvo.registerScannerCallback(function(barcode){
           
           console.log("Barcode scanned: " + barcode);
           
           //TODO: handle barcode/label type
       });
       //This function will send the first readable track
       captuvo.registerMagstripeCallback(function(track){
       	    //track 1 uses carets as dividers (NOTE: won't work if track 2 is read)
       	    if (track.indexOf("%B") == 0) {
              track = track.split('^');
            
              var cc = {
                 number : track[0].substr(2), //strip leading %B
                 name : track[1].trim(),
                 expr : '20' + track[2].substr(0,2) + '-' + track[2].substr(2,2)
              };
            } else {
              //handle track 2
            }
		
       });
       
```


=============
<h3>More API options:</h3>

<h5>Battery Monitor</h5>
```
  captuvo.registerBatteryCallback(function(level){
    console.log("BATTERY: " + level + " of 4");
  });
```

<h5>Ready Events</h5>
Document level events will be broadcast to let you know when the hardware is ready.
```
  document.addEventListener("magstripeReady", function(){
      console.log("MSR READY");
  });
```
<h6>Events:</h6>
* `magstripeReady` - the magnetic stripe hardware is ready for swipes.  NOTE: You must register a callback to initialize the hardware.
* `scannerReady` - the barcode scanner is ready for scans.  NOTE: You must register a callback to initialize the hardware.
* `captuvoConnected` - the captuvo sled is connected and ready for use.  NOTE: this event will not fire if your app is launched after the device is already in the sled
* `captuvoDisconnected` - the captuvo sled has been disconnected


==============
Copyright 2014 BlueFletch Mobile

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
