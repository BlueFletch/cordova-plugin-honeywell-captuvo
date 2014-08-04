#import <Cordova/CDVPlugin.h>
#import <Cordova/CDVPluginResult.h>

#import "Captuvo.h"

@interface CaptuvoCDV : CDVPlugin <CaptuvoEventsProtocol>

@property (strong, atomic) NSString* scannerCallbackId;
@property (atomic) BOOL isMonitoringScanner;

@property (strong, atomic) NSString* msrCallbackId;
@property (atomic) BOOL isMonitoringMSR;

@property (strong, atomic) NSString* batteryCallbackId;
@property (atomic)  BOOL isMonitoringBattery;

@property (strong, atomic) Captuvo *device;

//Scanner
- (void)registerScannerCallback:(CDVInvokedUrlCommand*)command;
- (void)unregisterScanner:(CDVInvokedUrlCommand*)command;

- (void)startScanning:(CDVInvokedUrlCommand*)command;
- (void)stopScanning:(CDVInvokedUrlCommand*)command;

/**
 * Pass in params to setup beeps
 */
- (void)configureScanner:(CDVInvokedUrlCommand*)command;

//MSR
- (void)registerMagstripeCallback:(CDVInvokedUrlCommand*)command;
- (void)unregisterMagstripe:(CDVInvokedUrlCommand*)command;


//Battery
- (void)registerBatteryCallback:(CDVInvokedUrlCommand*)command;

@end