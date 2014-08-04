var exec = require("cordova/exec");

module.exports.isConnected = false;

var isDeviceConnected = false;

module.exports.registerScannerCallback = function(callback) {
    exec(callback, null, 'CaptuvoCDV', 'registerScannerCallback', [] );
};
module.exports.registerMagstripeCallback = function(callback) {
    exec(callback, null, 'CaptuvoCDV', 'registerMagstripeCallback', [] );
};
module.exports.registerBatteryCallback = function(callback) {
    exec(callback, null, 'CaptuvoCDV', 'registerBatteryCallback', [] );
};
module.exports.configureScanner = function(beepOnStart, beepOnSuccessfulScan, soundOnTriggerClick) {
    exec(null, null, 'CaptuvoCDV', 'configureScanner', [beepOnStart, beepOnSuccessfulScan, soundOnTriggerClick] );
};

module.exports.msrReady = function(){
    var event = new Event('magstripeReady');
    document.dispatchEvent(event);
};

module.exports.captuvoConnected = function(){
    module.exports.isConnected = true;
    var event = new Event('captuvoConnected');
    document.dispatchEvent(event);
};

module.exports.captuvoDisconnected = function(){
    module.exports.isConnected = false;
    var event = new Event('captuvoDisconnected');
    document.dispatchEvent(event);
};

module.exports.decoderReady = function(){
    console.log("decoder ready event");
    var event = new Event('scannerReady');
    document.dispatchEvent(event);
};

['unregisterScanner','startScanning', 'stopScanning', 'unregisterMagstripe'].forEach(function(func){
    module.exports[func] = function() {
        exec(null, null, 'CaptuvoCDV', func, [] );
    };
});