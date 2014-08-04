//
//  Captuvo.h
//  Honeywell_SDK
//
//  Created by Edward Finegan (edward@dryraintechnologies.com) on 5/20/12.
//

#import <UIKit/UIKit.h>
#import <ExternalAccessory/ExternalAccessory.h>


#pragma mark -
#pragma mark Data Types

/**
 @brief Enumeration for connection status
 */
typedef enum {
   ProtocolConnectionStatusConnected,                                   /**< A successful connection was made */
   ProtocolConnectionStatusAlreadyConnected,                            /**< The protocol is already connected */
   ProtocolConnectionStatusBatteryDepleted,                             /**< The protocol is unable to be connected due to low battery */
   ProtocolConnectionStatusUnableToConnectIncompatiableSledFirmware,    /**< The protocol was unable to be connected due to an error */
   ProtocolConnectionStatusUnableToConnect,                             /**< The protocol was unable to be connected due to an error */
} ProtocolConnectionStatus;



/*
 @brief Enumeration for HID status
 */
typedef enum {

    HIDActiveLock,              /**<HID Active and locked       */
    HIDActiveUnlock,            /**<HID Active and Unlocked     */
    HIDUnactiveLock,            /**<HID UnActive and Locked     */
    HIDUnactiveUnlock           /**<HID UnActive and Unlocked   */

}HIDCurStatus;

/*
@brief Enumeration for Scan Key status
 */

typedef enum
{
    ScanKeyPressing,            /** Scan Key pressed    */
    ScanKeyReleased,            /** Scan Key released   */
}ScanKeyStatus;

/**
 @brief Enumeration for beeper volume
 */
typedef enum {
   BeeperVolumeLow,                 /**< Low volume */
   BeeperVolumeMedium,              /**< Medium volume */
   BeeperVolumeHigh,                /**< High volume */
   BeeperVolumeOff                  /**< Volume off */
} BeeperVolume;

/**
 @brief Enumeration for beeper pitch
 */
typedef enum {
   BeeperPitchLow,                  /**< Low pitch */
   BeeperPitchMedium,               /**< Medium pitch */
   BeeperPitchHigh                  /**< High pitch */
} BeeperPitch;

/**
 @brief Enumeration for beeper pitch on error
 */
typedef enum {
   BeeperErrorPitchRazz,            /**< Very Low pitch */
   BeeperErrorPitchMedium,          /**< Medium pitch */
   BeeperErrorPitchHigh             /**< High pitch */
} BeeperErrorPitch;

/**
 @brief Enumeration for beeper duration
 */
typedef enum {
   BeeperDurationShort,             /**< Short duration */
   BeeperDurationNormal             /**< Normal duration */
} BeeperDuration;

/**
 @brief Enumeration for selecting what tracts the MSR should read
 */
typedef enum {
   TrackSelectionAnyTrack,             /**< Any Track */
   TrackSelectionRequire1,             /**< Require Track 1 Only */
   TrackSelectionRequire2,             /**< Require Track 2 Only */
   TrackSelectionRequire1and2,         /**< Require Track 1 & Track 2 */
   TrackSelectionRequire3,             /**< Require Track 3 Only */
   TrackSelectionRequire1and3,         /**< Require Track 1 & Track 3 */
   TrackSelectionRequire2and3,         /**< Require Track 2 & Track 3 */
   TrackSelectionRequireAllTracks,     /**< Require All Three Tracks */
   TrackSelectionAnyTrack1or2,         /**< Any Track 1 & 2 */
   TrackSelectionAnyTrack2or3,         /**< Any Track 2 & 3 */
   TrackSelectionUndefined             /**< Error state */
} TrackSelection;


/**
 @brief Enumeration representing the current security level of the MSR
 */
typedef enum{
   SecurityLevel0,
   SecurityLevel1,
   SecurityLevel2,
   SecurityLevel3,
   SecurityLevel4,
   SecurityLevelUndefined
}SecurityLevel;

/**
 @brief Enumeration for selecting symbologies
 */
typedef enum {
   SymbologyAll,
   SymbologyAustralianPost,
   SymbologyAztecCode,
   SymbologyBritishPost,
   SymbologyCanadianPost,
   SymbologyChinaPost,
   SymbologyChineseSensibleCode,
   SymbologyCodabar,
   SymbologyCodablockA,
   SymbologyCodablockF,
   SymbologyCode11,
   SymbologyCode128,
   SymbologyGS1_128,
   SymbologyCode32Pharmaceutical,
   SymbologyCode39,
   SymbologyCode49,
   SymbologyCode93And93i,
   SymbologyDataMatrix,
   SymbologyEAN13,
   SymbologyEAN13WithAddOn,
   SymbologyEAN13WithExtendedCouponCode,
   SymbologyEAN8,
   SymbologyEAN8WithAddOn,
   SymbologyGS1Composite,
   SymbologyGS1DataBar,
   SymbologyInfoMail,
   SymbologyIntelligentMailBarcode,
   SymbologyInterleaved2Of5,
   SymbologyJapanesePost,
   SymbologyKIXPost,
   SymbologyKoreaPost,
   SymbologyMatrix2Of5,
   SymbologyMaxiCode,
   SymbologyMicroPDF417,
   SymbologyMSI,
   SymbologyNEC2Of5,
   SymbologyOCRMICR,
   SymbologyOCRSEMIFont,
   SymbologyOCRA,
   SymbologyOCRB,
   SymbologyPDF417,
   SymbologyPlanetCode,
   SymbologyPostal4i,
   SymbologyPostnet,
   SymbologyQRCodeAndMicroQRCode,
   SymbologyStraight2Of5IATA,
   SymbologyStraight2Of5Industrial,
   SymbologyTCIFLinkedCode39,
   SymbologyTelepen,
   SymbologyUPCA,
   SymbologyUPCAWithAddOn,
   SymbologyUPCAWithExtendedCouponCode,
   SymbologyUPCE,
   SymbologyUPCEWithAddOn,
   SymbologyUPCE1,
   SymbologyUndefined
} Symbology;


/**
 @brief Enumeration for the state of the battery and charging
 */
typedef enum {
   ChargeStatusNotCharging,         /**< The battery is not connected to external power. */
   ChargeStatusCharging,            /**< Device is connected to an external power source and is charging. */
   ChargeStatusChargeComplete,      /**< Device is connected to an external power but is not charing becuase the battery is full. */
   ChargeStatusUndefined            /**< The status of the battery can not be determined. This is often an error state. */
} ChargeStatus;


/**
 @brief Enumeration for the charge remaining in the battery.
 */
typedef enum {
   BatteryStatusPowerSourceConnected,        /**< Device is connected to a power source */
   BatteryStatus4Of4Bars,                    /**< Battery indicator should read 4 of 4 bars */
   BatteryStatus3Of4Bars,                    /**< Battery indicator should read 3 of 4 bars */
   BatteryStatus2Of4Bars,                    /**< Battery indicator should read 2 of 4 bars */
   BatteryStatus1Of4Bars,                    /**< Battery indicator should read 1 of 4 bars */
   BatteryStatus0Of4Bars,                    /**< Battery indicator should read 0 of 4 bars */
   BatteryStatusUndefined                    /**< Unable to determine the battery level */
} BatteryStatus;

#pragma mark -
#pragma mark Symbology Configuration Objects

/**
 @brief Enumeration of the UPC-A extended coupon code settings
 */
typedef enum {
    UPCA_EAN13_ExtendedCouponCodeOff,                       /**< Extended coupon code off */
    UPCA_EAN13_ExtendedCouponCodeAllowConcatenation,        /**< Allow concatenation of the extended coupon code */
    UPCA_EAN13_ExtendedCouponCodeRequireConcatenation       /**< Require concatenation of the extended coupon code */
} UPCA_EAN13_ExtendedCouponCode;


/**
 @brief Enumeration of the PartNumber configuration number serial number
 */

typedef struct
{
	Byte mfgSignature[4];
    Byte partNumber[18];
    Byte configurationNumber[20];
    Byte serialNumber[10];
    Byte finalAssemblyDate[8];
    Byte odmTrackingNumber[8];

} MfgBlockData;


/**
 @brief UPCA is the object used to configure the UPC-A symbology
 */
@interface UPCA : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) BOOL enableCheckDigit;
@property (assign,nonatomic) BOOL enableNumberSystem;
@property (assign,nonatomic) BOOL enable2DigitAddenda;
@property (assign,nonatomic) BOOL enable5DigitAddenda;
@property (assign,nonatomic) BOOL requireAddenda;
@property (assign,nonatomic) BOOL enableAddendaSeparator;
@property UPCA_EAN13_ExtendedCouponCode extendedCouponCode;

@end

/**
 @brief UPCE0 is the object used to configure the UPC-E0 symbology
 */
@interface UPCE0 : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) BOOL enableExpand;
@property (assign,nonatomic) BOOL requireAddenda;
@property (assign,nonatomic) BOOL enableAddendaSeparator;
@property (assign,nonatomic) BOOL enableCheckDigit;
@property (assign,nonatomic) BOOL enableNumberSystem;
@property (assign,nonatomic) BOOL enable2DigitAddenda;
@property (assign,nonatomic) BOOL enable5DigitAddenda;
@property (assign,nonatomic) BOOL enableUPCE1;

@end

/**
 @brief EAN13 is the object used to configure the EAN 13 symbology
 */
@interface EAN13 : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) BOOL enableCheckDigit;
@property (assign,nonatomic) BOOL enable2DigitAddenda;
@property (assign,nonatomic) BOOL enable5DigitAddenda;
@property (assign,nonatomic) BOOL requireAddenda;
@property (assign,nonatomic) BOOL enableAddendaSeparator;
@property (assign,nonatomic) BOOL enableISBNtranslate;

@end

/**
 @brief EAN8 is the object used to configure the EAN 8 symbology
 */
@interface EAN8 : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) BOOL enableCheckDigit;
@property (assign,nonatomic) BOOL enable2DigitAddenda;
@property (assign,nonatomic) BOOL enable5DigitAddenda;
@property (assign,nonatomic) BOOL requireAddenda;
@property (assign,nonatomic) BOOL enableAddendaSeparator;

@end

/**
 @brief Enumeration of the Codabar checks character settings
 */
typedef enum {
    CodabarCheckCharNoCheckChar,                        /**< Disable the check character */
    CodabarCheckCharValidateNotTransmitted,             /**< validate the check character but do not send it with the barcode data */
    CodabarCheckCharValidateAndTransmit                 /**< validate the check character and send it with the barcode data */
} CodabarCheckChar;

/**
 @brief Enumeration of the Codabar concatenation settings
 */
typedef enum {
    CodabarConcatenationOn,                             /**< Concatenation on */
    CodabarConcatenationOff,                            /**< Concatenation off */
    CodabarConcatenationRequired                        /**< Concatenation required */
} CodabarConcatenation;

/**
 @brief Codabar is the object used to configure the Codabar symbology
 */
@interface Codabar : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) BOOL transmitStatStopChar;
@property (assign,nonatomic) CodabarCheckChar checkCharStatus;
@property (assign,nonatomic) CodabarConcatenation concatenationStatus;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;

@end

/**
 @brief Enumeration of the Code 39 check character settings
 */
typedef enum {
    Code39CheckCharNoCheckChar,                         /**< Disable the check character */
    Code39CheckCharValidateNotTransmitted,              /**< Vaildate the check character but do not send it with the barcode data */
    Code39CheckCharValidateAndTransmit                  /**< Vaildate the check character and send it with the barcode data */
} Code39CheckChar;

/**
 @brief Code39 is the object used to configure the Code 39 symbology
 */
@interface Code39 : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) BOOL transmitStatStopChar;
@property (assign,nonatomic) Code39CheckChar checkCharStatus;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;
@property (assign,nonatomic) BOOL enableAppendMode;
@property (assign,nonatomic) BOOL enableCode32Pharmaceutical;
@property (assign,nonatomic) BOOL enableFullASCII;

@end

/**
 @brief Enumeration of the Interleaved2of5 object's check character settings
 */
typedef enum {
    Interleaved2of5CheckCharNoCheckChar,                    /**< Disable the check character */
    Interleaved2of5CheckCharValidateNotTransmitted,         /**< validate the check character but do not send it with the barcode data */
    Interleaved2of5CheckCharValidateAndTransmit             /**< validate the check character and send it with the barcode data */
} Interleaved2of5CheckChar;

/**
 @brief Interleaved2of5 is the object used to configure the Interleaved 2 of 5 symbology
 */
@interface Interleaved2of5 : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) Interleaved2of5CheckChar checkCharStatus;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;

@end

/**
 @brief Enumeration of the NEC2of5CheckChar object's check character settings
 */
typedef enum {
    NEC2of5CheckCharNoCheckChar,                            /**< Disable the check character */
    NEC2of5CheckCharValidateNotTransmitted,                 /**< validate the check character but do not send it with the barcode data */
    NEC2of5CheckCharValidateAndTransmit                     /**< validate the check character and send it with the barcode data */
} NEC2of5CheckChar;

/**
 @brief NEC2of5 is the object used to configure the NEC 2 of 5 symbology
 */
@interface NEC2of5 : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) NEC2of5CheckChar checkCharStatus;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;

@end

/**
 @brief Code93 is the object used to configure the Code 93 symbology
 */
@interface Code93 : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;

@end

/**
 @brief Straight2of5Industrial is the object used to configure the Straight 2 of 5 Industrial symbology
 */
@interface Straight2of5Industrial : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;

@end

/**
 @brief Straight2of5IATA is the object used to configure the Straight 2 of 5 IATA symbology
 */
@interface Straight2of5IATA : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;

@end

/**
 @brief Matrix2of5 is the object used to configure the Matrix 2 of 5 symbology
 */
@interface Matrix2of5 : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;

@end

/**
 @brief Enumeration of the Code11 object's check digit settings
 */
typedef enum {
    Code11CheckDigit1,              /**< Check digit one */
    Code11CheckDigit2               /**< Check digit two */
} Code11CheckDigit;

/**
 @brief Code11 is the object used to configure the Code 11 symbology
 */
@interface Code11 : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;
@property (assign,nonatomic) Code11CheckDigit checkDigit;

@end

/**
 @brief Code128 is the object used to configure the Code 128 symbology
 */
@interface Code128 : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;
@property (assign,nonatomic) BOOL enableISBTconcatenation;

@end

/**
 @brief GS1_128 is the object used to configure the GS1-128 symbology
 */
@interface GS1_128 : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;

@end


/**
 @brief Enumeration of the Telepen object's output settings
 */
typedef enum {
    TelepenOutputAIM,               /**< AIM Telepen output */
    TelepenOutputOriginal           /**< Original Telepen output */
} TelepenOutput;

/**
 @brief Telepen is the object used to configure the Telepen symbology
 */
@interface Telepen : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;
@property (assign,nonatomic) TelepenOutput output;

@end

/**
 @brief Enumeration of the MIS object's check character settings
 */
typedef enum {
    MSICheckCharValidateType10NotTransmitted,                   /**< Validate type 10 but do not transmit with barcode data */
    MSICheckCharValidateType10AndTransmit,                      /**< Validate type 10 and transmit with barcode data */
    MSICheckCharValidate2Type10NotTransmitted,                  /**< Validate 2 type 10 characters but do not transmit with barcode data */
    MSICheckCharValidate2Type10AndTransmit,                     /**< Validate 2 type 10 characters and transmit with barcode data */
    MSICheckCharValidateType10And11NotTransmitted,              /**< Validate type 10 then they 11 characters but do not transmit with barcode data */
    MSICheckCharValidateType10And11AndTransmit,                 /**< Validate type 10 then they 11 characters and transmit with barcode data */
    MSICheckCharDisableCeckChar                                 /**< Disasble check characters */
} MSICheckChar;

/**
 @brief MSI is the object used to configure the MSI symbology
 */
@interface MSI : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;
@property (assign,nonatomic) MSICheckChar checkChar;

@end

/**
 @brief Enumeration of the GS1 global emulation settings
 */
typedef enum {
   GS1Emulation128,                                             /**< GS1-128 emulation */
   GS1EmulationdDatabar,                                        /**< GS1 DataBar emulation */
   GS1EmulationdExpansionCodeOff,                               /**< GS1 Code Expansion off */
   GS1EmulationdEAN8toEAN13Conversion,                          /**< EAN8 to EAN13 conversion */
   GS1EmulationdOff                                             /**< Emulation off */
} GS1Emulation;

/**
 @brief GS1DataBarOmnidirectional is the object used to configure the GS1 DataBar Omnidirectional symbology
 */
@interface GS1DataBarOmnidirectional : NSObject

@property (assign,nonatomic) BOOL enabled;
//Global GS1 parameters
@property (assign,nonatomic) BOOL enableGS1CompositeCodes;
@property (assign,nonatomic) BOOL enableUPC_EANversion;
@property (assign,nonatomic) int compositeCodeMinMessageLength;
@property (assign,nonatomic) int compositeCodeMaxMessageLength;
@property (assign,nonatomic) GS1Emulation emulationMode;
@end

/**
 @brief GS1DataBarLimited is the object used to configure the GS1 DataBar Limited symbology
 */
@interface GS1DataBarLimited : NSObject

@property (assign,nonatomic) BOOL enabled;
//Global GS1 parameters
@property (assign,nonatomic) BOOL enableGS1CompositeCodes;
@property (assign,nonatomic) BOOL enableUPC_EANversion;
@property (assign,nonatomic) int compositeCodeMinMessageLength;
@property (assign,nonatomic) int compositeCodeMaxMessageLength;
@property (assign,nonatomic) GS1Emulation emulationMode;

@end

/**
 @brief GS1DataBarExpanded is the object used to configure the GS1 DataBar Expanded symbology
 */
@interface GS1DataBarExpanded : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;
//Global GS1 parameters
@property (assign,nonatomic) BOOL enableGS1CompositeCodes;
@property (assign,nonatomic) BOOL enableUPC_EANversion;
@property (assign,nonatomic) int compositeCodeMinMessageLength;
@property (assign,nonatomic) int compositeCodeMaxMessageLength;
@property (assign,nonatomic) GS1Emulation emulationMode;

@end

/**
 @brief CodablockA is the object used to configure the Codablock A symbology
 */
@interface CodablockA : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;

@end

/**
 @brief CodablockF is the object used to configure the Codablock F symbology
 */
@interface CodablockF : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;

@end

/**
 @brief PDF417 is the object used to configure the PDF417 symbology
 */
@interface PDF417 : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;

@end

/**
 @brief ChineseSensible is the object used to configure the Chinese Sensible symbology
 */
@interface ChineseSensible : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;

@end

/**
 @brief Aztec is the object used to configure the Aztec symbology
 */
@interface Aztec : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;

@end

/**
 @brief MaxiCode is the object used to configure the MaxiCode symbology
 */
@interface MaxiCode : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;

@end

/**
 @brief DataMatrix is the object used to configure the Data Matrix symbology
 */
@interface DataMatrix : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;

@end

/**
 @brief MicroPDF417 is the object used to configure the MicroPDF417 symbology
 */
@interface MicroPDF417 : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;

@end

/**
 @brief TCIFLinkedCode39 is the object used to configure the TCIF Linked Code 39 symbology
 */
@interface TCIFLinkedCode39 : NSObject

@property (assign,nonatomic) BOOL enabled;

@end

/**
 @brief QRCode is the object used to configure the QR Code symbology
 */
@interface QRCode : NSObject

@property (assign,nonatomic) BOOL enabled;
@property (assign,nonatomic) int minMessageLength;
@property (assign,nonatomic) int maxMessageLength;

@end

#pragma mark -
#pragma mark Event Protocol
/**
 @brief The protocol that must be implemented to become a SDK delegate.

 Each method defined in the protocol represents a specific response from SDK actions. Each is optional and only needs to be implemented by delegate objects that are interested in the specific response.
  */
@protocol CaptuvoEventsProtocol <NSObject>

@optional

/**
 @brief This delegate method is called when the Captuvo hardware connects to the iOS device.
 */
-(void)captuvoConnected;//

/**
 @brief This delegate method is called when the Captuvo hardware disconnects from the iOS device.
 */
-(void)captuvoDisconnected;//

/**
 @brief This <em>decoderReady<em> delegate method is called when the Decoder session is ready.
 */
- (void)decoderReady;

/**
 @brief This <em>msrReady<em> delegate method is called when the MSR session is ready.
 */
- (void)msrReady;

/**
 @brief This <em>pmReady<em> delegate method is called when the PM session is ready.
 */
- (void)pmReady ;

/**
 @brief This delegate method is called when the decoder read string data from a barcode.

 @param (NSString*)data The data as a string.
 */
-(void)decoderDataReceived:(NSString*)data;//


/**
 @brief This delegate method is called when the decoder reads raw data from a barcode.

 @param (NSData*)data The data as a string.
 */
-(void)decoderRawDataReceived:(NSData*)data;//


/**
 @brief This delegate method is called when the decoder revision is requested.

 The delegate message passes the decoder revision data from the <em>-(void)requestDecoderRevision</em> method. This revision number is for the decoder subsystem in the device.

 @param (NSString*)revision The raw data from the decoder.
 */
-(void)decoderRevisionReceived:(NSString*)revision;//

/**
 @brief This delegate method is called when the decoder software revision is requested.

 The delegate message passes the decoder software revision data from the <em>-(void)requestDecoderSoftwareRevision</em> method. This revision number is for the decoder software on the device.

 @param (NSString*)revision The raw data from the decoder.
 */
-(void)decoderSoftwareRevision:(NSString*)revision;//

/**
 @brief This delegate method is called when the decoder driver revision is requested.

 The delegate message passes the decoder driver revision data from the <em>-(void)requestDecoderDriverRevision</em> method. This revision number is for the decoder driver for the device.

 @param (NSString*)revision The raw data from the decoder.
 */
-(void)decoderDriverRevision:(NSString*)revision;//

/**
 @brief This delegate method is called when the decoder driver revision is requested.

 The delegate message passes the decoder serial number data from the <em>-(void)requestDecoderSerialNumber</em> method. This decoder serial number is for the decoder serial number of the device.

 @param (NSString*)The decoder serial number.
 */
-(void)decoderSerialNumber:(NSString*)seralNumber;//

/**
 @brief This delegate method is called when the status of the beep for a good read is requested.

 The delegate message passes the status of the good read beeper. It is requested from the <em>-(void)requestDecoderBeeperForGoodReadStatus</em> method.

 @param (BOOL)isEnabled Yes if the beeper is enabled for a good read.
 */
-(void)decoderBeeperForGoodReadStatus:(BOOL)isEnabled;//

/**
 @brief This delegate method is called when the status of the trigger click is requested.

 The delegate message passes the status of the trigger click. It is requested from the <em>-(void)requestDecoderTriggerClickStatus</em> method.

 @param (BOOL)isEnabled Yes if the trigger click is enabled.
 */
-(void)decoderTriggerClickStatus:(BOOL)isEnabled;//

/**
 @brief This delegate method is called when the status of the power up beep is requested.

 The delegate message passes the status of the power up beep. It is requested from the <em>-(void)requestDecoderPowerUpBeepStatus</em> method.

 @param (BOOL)isEnabled Yes if the power up beep is enabled.
 */
-(void)decoderPowerUpBeepStatus:(BOOL)isEnabled;//

/**
 @brief This delegate method is called when the volume of the beeper is requested for a good read.

 The delegate message passes the volume of the beeper on a good read. It is requested from the <em>-(void)requestDecoderGoodReadBeeperVolumeStatus</em> method.

 @param (BeeperVolume)volume The volume of the beeper after a good read.
 */
-(void)decoderGoodReadBeeperVolumeStatus:(BeeperVolume)volume;//

/**
 @brief This delegate method is called when the pitch of the beeper is requested for a good read.

 The delegate message passes the pitch of the beeper on a good read. It is requested from the <em>-(void)requestDecoderBeeperPitchGoodReadStatus</em> method.

 @param (BeeperPitch)pitch The pitch of the beeper after a good read.
 */
-(void)decoderBeeperPitchGoodReadStatus:(BeeperPitch)pitch;//

/**
 @brief This delegate method is called when the pitch of the beeper after an error is requested.

 The delegate message passes the pitch of the beeper after an error. It is requested from the <em>-(void)requestDecoderBeeperPitchErrorStatus</em> method.

 @param (BeeperErrorPitch)pitch The pitch of the beeper after an error.
 */
-(void)decoderBeeperPitchErrorStatus:(BeeperErrorPitch)pitch;//

/**
 @brief This delegate method is called when the duration of the beeper after a good read is requested.

 The delegate message passes the duration of the beeper after a good read. It is requested from the <em>-(void)requestDecoderBeeperDurationGoodReadStatus</em> method.

 @param (BeeperDuration)duration The duration of the beeper after a good read.
 */
-(void)decoderBeeperDurationGoodReadStatus:(BeeperDuration)duration;//

/**
 @brief This delegate method is called when the number of beeps after a good read is requested.

 The delegate message passes the number of beeps after a good read. It is requested from the <em>-(void)requestDecoderNumberOfBeepsGoodReadStatus</em> method.

 @param (int)numberOfBeeps The number of beeps after a good read.
 */
-(void)decoderNumberOfBeepsGoodReadStatus:(int)numberOfBeeps;//

/**
 @brief This delegate method is called when the number of beeps after an error is requested.

 The delegate message passes the number of beeps after an error. It is requested from the <em>-(void)requestDecoderNumberOfBeepsErrorStatus</em> method.

 @param (int)numberOfBeeps The number of beeps after an error read.
 */
-(void)decoderNumberOfBeepsErrorStatus:(int)numberOfBeeps;//

/**
 @brief This delegate method is called when the delay between good reads is requested.

 The delegate message passes the number milliseconds that must pass before a second good read can be done. It is requested from the <em>-(void)requestDecoderGoodReadDelayInMilliSecondsStatus</em> method.

 @param (int)milliseconds The delay in milliseconds between two good reads.
 */
-(void)decoderGoodReadDelayInMilliSecondsStatus:(int)milliseconds;//

/**
 @brief This delegate method is called when the trigger timeout is requested.

 The delegate message passes the trigger timeout in milliseconds. It is requested from the <em>-(void)requestDecoderSerialTriggerTimeoutInMilliSecondsStatus</em> method.

 @param (int)milliseconds The trigger timeout in milliseconds.
 */
-(void)decoderSerialTriggerTimeoutInMilliSecondsStatus:(int)milliseconds;//

/**
 @brief This delegate method is called when the status of the interlaced aimer is requested.

 The delegate message passes the status of the interlaced aimer. It is requested from the <em>-(void)requestDecoderInterlacedAimerModeStatus</em> method.

 @param (BOOL)isEnabled YES if the interlaced aimer is enabled.
 */
-(void)decoderInterlacedAimerModeStatus:(BOOL)isEnabled;//

/**
 @brief This delegate method is called when the status of the preferred symbology setting is requested.

 The delegate message passes the status of if the preferred symbology setting is enabled. It is requested from the <em>-(void)requestDecoderPreferredSymbologyStatus</em> method.

 @param (BOOL)isEnabled YES if the preferred symbology is enabled.
 */
-(void)decoderPreferredSymbologyStatus:(BOOL)isEnabled;//

/**
 @brief This delegate method is called when the high priority symbology is requested.

 The delegate message passes the symbology that is set as high priority. It is requested from the <em>-(void)requestDecoderHighPrioritySymbologyStatus</em> method.

 @param (Symbology)symbology The symbology that is currently set as high priority.
 */
-(void)decoderHighPrioritySymbologyStatus:(Symbology)symbology;//

/**
 @brief This delegate method is called when the low priority symbology is requested.

 The delegate message passes the symbology that is set as low priority. It is requested from the <em>-(void)requestDecoderLowPrioritySymbologyStatus</em> method.

 @param (Symbology)symbology The symbology that is currently set as low priority.
 */
-(void)decoderLowPrioritySymbologyStatus:(Symbology)symbology;//

/**
 @brief This delegate method is called when the preferred symbology timeout is requested.

 The delegate message passes the preferred symbology timeout. It is requested from the <em-(void)requestDecoderPreferredSymbologyTimeoutInMilliSecondsStatus</em> method.

 @param (int)milliseconds The timeout period in milliseconds.
 */
-(void)decoderPreferredSymbologyTimeoutInMilliSecondsStatus:(int)milliseconds;//

/**
 @brief This delegate method is called when the status of the centering feature is requested.

 The delegate message passes the status of the centering feature. It is requested from the <em-(void)requestDecoderCenteringStatus</em> method.

 @param (BOOL)isEnabled Yes if centering is enabled.
 */
-(void)decoderCenteringStatus:(BOOL)isEnabled;//

/**
 @brief This delegate method is called when the top of centering window location is requested.

 The delegate message passes the location of the top of centering window as a percent of the height. It is requested from the <em-(void)requestDecoderTopOfCenteringWindowStatus</em> method.

 @param (int)locationAsPrecent The location of the top of the centering window.
 */
-(void)decoderTopOfCenteringWindowLocation:(int)locationAsPrecent;//

/**
 @brief This delegate method is called when the bottom of centering window location is requested.

 The delegate message passes the location of the bottom of centering window as a percent of the height. It is requested from the <em-(void)requestDecoderBottomOfCenteringWindowStatus</em> method.

 @param (int)locationAsPrecent The location of the bottom of the centering window.
 */
-(void)decoderBottomOfCenteringWindowLocation:(int)locationAsPrecent;//

/**
 @brief This delegate method is called when the left of the centering window location is requested.

 The delegate message passes the location of the left of centering window as a percent from the left edge. It is requested from the <em-(void)requestDecoderLeftOfCenteringWindowStatus</em> method.

 @param (int)locationAsPrecent The location of the left of the centering window.
 */
-(void)decoderLeftOfCenteringWindowLocation:(int)locationAsPrecent;//

/**
 @brief This delegate method is called when the right of the centering window location is requested.

 The delegate message passes the location of the right of centering window as a percent from the right edge. It is requested from the <em-(void)requestDecoderRightOfCenteringWindowStatus</em> method.

 @param (int)locationAsPrecent The location of the right of the centering window.
 */
-(void)decoderRightOfCenteringWindowLocation:(int)locationAsPrecent;//

/**
 @brief This delegate method is called when data is returned from using the direct pass though method for the decoder.

 The delegate message passes response data from the use of the <em>-(void)decoderPassThrough:(NSData*)data expectingReturnData:(BOOL)returnData</em> method. The data received for this method is directly returned as an NSData.

 @param (NSData*)data The raw data from the decoder.
 */
-(void)decoderPassThroughReturnData:(NSData*)data;//

/**
 @brief This delegate method is called when data is returned from using the enable.

 The delegate message passes response data from the use of the <em>-(void)enableDecoderEnhancedManualTriggerMode:(BOOL)enable persistSetting:(BOOL)persist/em> method. The data received for this method is directly returned as an NSData.

 @param (NSData*)data The manual trigger mode.
 */
-(void)DecoderEnhancedManualTriggerMode:(NSData*)data;


//MSR Delegates

/**
 @brief This delegate method is called when the MSR has data to send to its delegates from a card swipe.

 When data from a card swipe is read it is sent to delegates using this method. The <em>status</EM> parameter will be <em>YES</em> if the checksum received from the MSR matches the expected calculated checksum. In most cases this can be ignored because it will always be <em>YES</em> except for the rare occasions of a hardware issue.

 @param (NSString*)data The data as a string.
 @param (BOOL)status Yes if the checksum is correct for the data received from the Captuvo.
 */
-(void)msrStringDataReceived:(NSString*)data validData:(BOOL)status;//

/**
 @brief This delegate method is called when the MSR has data to send to its delegates from a card swipe.

 When data from a card swipe is read it is sent to delegates using this method. The <em>status</EM> parameter will be <em>YES</em> if the checksum received from the MSR matches the expected calculated checksum. In most cases this can be ignored because it will always be <em>YES</em> except for the rare occasions of a hardware issue.

 @param (NSData*)data The raw data from the MSR.
 @param (BOOL)status Yes if the checksum is correct for the data received from the Captuvo.
 */
-(void)msrRawDataReceived:(NSData*)data validData:(BOOL)status;//

/**
 @brief This delegate method is called to return the firmware version of the MSR after it was requested.

  When the <em>-(void)requestMSRFirmwareVersion</em> method is called, this delegate method will be called to return the requested data. The <em>status</em> parameter will be <em>YES</em> if the checksum received from the MSR matches the expected calculated checksum. In most cases this can be ignored because it will always be <em>YES</em> except for the rare occasion of a hardware issue.

 @param (NSString*)data The data as a string.
 @param (BOOL)status Yes if the checksum is correct for the data received from the Captuvo.
 */
-(void)msrFirewareVersion:(NSString*)data validData:(BOOL)status;//

/**
 @brief This delegate method is called to return the serial number of the MSR after it was requested.

 When the <em>-(void)getSerialNumber</em> method is called, this delegate method will be called to return the requested data. The <em>status</em> parameter will be <em>YES</em> if the checksum received from the MSR matches the expected calculated checksum. In most cases this can be ignored because it will always be <em>YES</em> except for the rare occasion of a hardware issue.

 @param (NSString*)data The data as a string.
 @param (BOOL)status Yes if the checksum is correct for the data received from the Captuvo.
 */
-(void)msrSerialNumber:(NSString*)data validData:(BOOL)status;//

/**
 @brief This delegate method is called to return the current track selection of the MSR after it was requested.

 When the <em>-(void)requestMSRTrackSettings</em> method is called, this delegate method will be called to return the requested data. The <em>status</em> parameter will be <em>YES</em> if the checksum received from the MSR matches the expected calculated checksum. In most cases this can be ignored because it will always be <em>YES</em> except for the rare occasion of a hardware issue.

 @param (TrackSelection)trackSelection The current track selection.
 @param (BOOL)status Yes if the checksum is correct for the data received from the Captuvo.
 */
-(void)msrCurrentTrackSelection:(TrackSelection)trackSelection validData:(BOOL)status;

/**
 @brief This delegate method is called to return the current security level of the MSR after it was requested.

 When the <em>-(void)requestMSRSecurityLevel</em> method is called, this delegate method will be called to return the requested data. The <em>status</em> parameter will be <em>YES</em> if the checksum received from the MSR matches the expected calculated checksum. In most cases this can be ignored because it will always be <em>YES</em> except for the rare occasion of a hardware issue.

 @param (SecurityLevel)securityLevel The current security level.
 @param (BOOL)status Yes if the checksum is correct for the data received from the Captuvo.
 */
-(void)msrCurrentSecurityLevel:(SecurityLevel)securityLevel validData:(BOOL)status;

/**
 @brief This delegate method is called when data is returned from using the direct pass though method for the MSR.

 The delegate message passes response data from the use of the <EM>-(void)msrPassThrough:(NSData*)data expectingReturnData:(BOOL)returnDataa</em> method. The data received for this method is directly returned as an NSData.

 @param (NSData*)data The raw data from the MSR.
 */
-(void)msrPassThroughReturnData:(NSData*)data;

//PM Delegates

/**
 @brief This delegate method is called when their is a change in the status of the battery charging state.

 This delegate method is called when their is a change in battery charging state. The new state is sent via a parameter.

 @param (ChargeStatus)newChargeStatus The new charging state.
 */
-(void)pmChargeStatusChange:(ChargeStatus)newChargeStatus;//


/**
 @brief This delegate method is called when their is a change in the remaining charge of the battery.

 This delegate method is called when their is a change in remain battery life. The new status is sent via a parameter.

 @param (BatteryStatus)newBatteryStatus The new battery status.
 */
-(void)pmBatteryStatusChange:(BatteryStatus)newBatteryStatus;//

/**
 @brief This delegate method is called when the battery is critically low.

 This delegate method is called when the remaining battery life reaches a critically state. This delegate method will get called repeatedly while the battery remains critically low and not connected to an external power source. Every app should respond to this delegate method
 */
-(void)pmLowBatteryWarning;

/**
 @brief This delegate method is called when the battery is no longer able to power the Captuvo device.

 This delegate method is called when the remaining battery life becomes to low to continue powering the Captuvo device. When this occours both the MSR and Decoder will be shutdown. This delegate will be called repeatedly while in this state and not conencted to a external power source. Every app should respond to this delegate method.
 */
-(void)pmLowBatteryShutdown;



/**
 @brief This delegate method is called when data is returned from unsing the direct read Captuvo part number&Configure number&Serial Number.

 The delegate message passes repsonse data from the use of the <em>requestPMMfgBlockData method. The data received from this method is directly returned as a MfgBlockData enum.

 @param (MfgBlockData*)data The enum data from the Configuration of Munifactor.
 */

-(void)pmMfgBlockData:(MfgBlockData*)blockData;



/**
 @brief This delegate method is called when data is returned from unsing the direct read Captuvo part current update firmware data steps.

 This method when enables firmware, can call.

 @param (NSData*) data response when update firmware data process from Captuvo, received data and parser which type.
 */

-(void)upFirmware:(NSData*)data;




/**
 @brief This method is used to get the current HID status.

 This can be called to get the current status of the HID

 @return HIDCurStatus The status of the HID.
 */
-(void)stateHID:(HIDCurStatus)status ;


/**
 @brief This method is used to get the current current user tap left/right hardkey action.

 This can be called to get the current status of the HardKey event

 @return ScanKeyStatus The status of the ScanKey(Pressed/Release).
 */
- (void)scanKeyAction:(ScanKeyStatus)status ;
@end


#pragma mark -
#pragma mark Captuvo SDK

/**
 @brief Main public interface for the Captuvo SDK Library.

 This should be included in all projects that intend to use the Honeywell Captuvo sled. All methods in this SDK should be assumed to not be thread safe. The ExternalAccessory.framework
 */
@interface Captuvo : NSObject


#pragma mark -
#pragma mark General Methods

/**
 @brief This method is used to get the shared instance of the Captuvo object.

 When using this SDK, this is the proper way to initialize and get a reference to a Captuvo object.

 @return A Captuvo object that is shared between all callers of this method.
 */
+(Captuvo*)sharedCaptuvoDevice;//

/**
 @brief This method is used to get the shared instance of the Captuvo object and place the SDK into debug mode with verbose logging.

 This will behave the same as the <em>+ (Captuvo*) sharedCaptuvoDevice</em> method with the addition of placing the SDK into debug mode. This only needs to be called once to enter debug mode. Debug mode can be turned off by using the <em>-(void)enableCaptuvoDebug:(BOOL)enable</em> method.

 @return A Captuvo object that is shared between all callers of this method.
 */
+(Captuvo*)sharedCaptuvoDeviceDebug;//

/**
 @brief This method is used to turn debug mode on or off.

 When debug mode is enabled the SDK will log verbosely what it is doing.

 @param (BOOL)enabled A BOOL to enable (YES) or disable (NO) debug mode.
 */
-(void)enableCaptuvoDebug:(BOOL)enable;

/**
 @brief This method is used to stop active monitor battery status.
 */
- (void)stopbatterymonitor;


/**
 @brief This method is used to register an object as a delegate for SDK events.

 To receive data back from the SDK delegates most be registered with it. Delegate objects are unable to be added twice and objects that are referenced are automatically removed.

 @param (id<CaptuvoEventsProtocol>) delegate The object to be registered as an active delegate.
 */
-(void)addCaptuvoDelegate:(id<CaptuvoEventsProtocol>)delegate;//

/**
 @brief This method is used to unregistered an object as a delegate for SDK events.

 This method will unregister an object as a delegate for the SDK. If the object is not a valid dialog no changes will take place.

 @param (id<CaptuvoEventsProtocol>) delegate The object to be unregistered as an active delegate.
 */
-(void)removeCaptuvoDelegate:(id<CaptuvoEventsProtocol>)delegate;//

/**
 @brief This method returns the name of the device.

 This method will return the name of the device as stored in its firmware.

 @return A NSString that is the name of the device.
 */
-(NSString*)getCaptuvoName;//

/**
 @brief This method returns the model number of the device.

 This method will return the model number of the device as stored in its firmware.

 @return A NSString that is the model number of the device.
 */
-(NSString*)getCaptuvoModelNumber;//

/**
 @brief This method returns the serial number of the device.

 This method will return the unique serial number of the device as stored in its firmware.

 @return A NSString that is the device serial number.
 */
-(NSString*)getCaptuvoSerialNumber;//

/**
 @brief This method returns the firmware revision of the device.

 This method will return the firmware revision of the device.

 @return A NSString that is the device firmware revision.
 */
-(NSString*)getCaptuvoFirmwareRevision;//

/**
 @brief This method returns the hardware revision of the device.

 This method will return the hardware revision of the device.

 @return A NSString that is the device hardware revision.
 */
-(NSString*)getCaptuvoHardwareRevision;//

/**
 @brief This method returns the manufacturer information of the device.

 This method will return the manufacturer information of the device.

 @return A NSString that is the device manufacturer information.
 */
-(NSString*)getCaptuvoManufacturer;//


#pragma mark -
#pragma mark Library Information Methods

/**
 @brief This method returns the build number of the Captuvo SDK library.

 @return A NSString representing the build number.
 */
-(NSString*)getSDKbuildNumber;//

/**
 @brief This method returns the short version number of the Captuvo SDK library.

 This method will return the short version number of the SDK. For example <em>1.0.0</em>.

 @return A NSString representing the short version number.
 */
-(NSString*)getSDKshortVersion;//

/**
 @brief This method returns the full version information of the Captuvo SDK library.

 This method will return the full version information of the SDK. This includes the short version number and the build number. For example <em>1.0.0 20120711</em>.

 @return A NSString representing the full version number.
 */
-(NSString*)getSDKfullVersion;//

#pragma mark -
#pragma mark Decoder Methods


/**
 @brief This method is used to turn on the decoder hardware in the device.

 This must be called before any other decoder methods. Until this method is called the decoder hardware is not initialized. Use <em>-(void)stopDecoderHarware</em> to shut down the decoder hardware

 @return ProtocolConnectionStatus The status of the requested action.
 */
-(ProtocolConnectionStatus)startDecoderHardware;//

/**
 @brief This method is used to turn on the decoder hardware in the device.

 It will retry to turn on the decoder hardware every 250ms until succeeded or timeout.

 This must be called before any other decoder methods. Until this method is called the decoder hardware is not initialized. Use <em>-(void)stopDecoderHarware</em> to shut down the decoder hardware

 @param (double)timeout The time to wait for decoder hardware to reply to the turn on request.

 @return ProtocolConnectionStatus The status of the requested action.
 */
//-(ProtocolConnectionStatus)startDecoderHardware:(double)timeout;//
- (void)startDecoderHardware:(double)timeout;
/**
 @brief This method is used to turn off the decoder hardware in the device.

 Once this method is called the decoder hardware is inactivated. No scanning methods can be called untill <em>-(void)startDecoderHardware</em> is called again to re-initialize the decoder hardware
 */
-(void)stopDecoderHardware;//

/**
 @brief This method is used to determine if the decoder hardware is currently running.

 This method is used to determine if the decoder is currently running. It can be started and stopped with the methods <em>-(void)startDecoderHardware</em> and <em>-(void)stopDecoderHarware</em> respectively.

 @return BOOL YES if the decoder is running.
 */
-(BOOL)isDecoderRunning;

/**
 @brief This method is used to start scanning for a barcode.

 This method enables the scanner to be controlled by software. Once this command is sent the scanner will search for a barcode until either it finds one, time-outs or the <em>-(void)stopDecoderScanning</em> method is called.

 */
-(void)startDecoderScanning;//

/**
 @brief This method is used to stop the scanning.

 This method can be used to stop the scanner after the <em>-(void)startDecoderScanning</em> was called. If the decoder is not scanned at the time there will be no effect of this method call.
 */
-(void)stopDecoderScanning;//

/**
 @brief This method is used to enable scanning.

 This method enables the scanner.   The method <em>-(void)disableDecoderScanning</em> should be used to enable scanning.  Calling <em>-(void)disableDecoderScanning</em> does not enable/disable power to the decoder.

 */
-(void)enableDecoderScanning;//

/**
 @brief This method is used to disable scanning.

 This method disables the scanner.   The method <em>-(void) enableDecoderScanning</EM> should be used to enable scanning.  Calling <em>-(void)disableDecoderScanning</em> does not enable/disable power to the decoder.
 */
-(void)disableDecoderScanning;//

/**
 @brief Enable a beep at power up.

 This method sets whether an audible beep will be heard when the decoder is powered up. The default setting is no beep.

 @param (BOOL)enabled A BOOL to enable (YES) or disable (NO) the power up beep.
 */
-(void)enableDecoderPowerUpBeep:(BOOL)enabled;//

/**
 @brief This method is used to request the serial number of the decoder.

 This method is used to request the serial number of decoder from the engine firmware.The result of this method is returned with the <em>--(void)decoderSerialNumber:(NSString*)seralNumber;</em> delegate method.

 */

-(void)requestDecoderSerialNumber;

/**
 @brief This method is used to request the status of the power up beep.

 The power up beep is the noise heard when the decoder hardware is started. This method will request the status of this beep. The result of this method is returned with the <em>-(void)decoderPowerUpBeepStatus:(BOOL)isEnabled</em> delegate method.
 */
-(void)requestDecoderPowerUpBeepStatus;//

/**
 @brief Enable a trigger click.

 This method sets whether an audible click will be heard when the hardware scan button is pressed. The default setting is no click.

 @param (BOOL)enabled A BOOL to enable (YES) or disable (NO) the trigger click.
 @param (BOOL)persist A BOOL if YES the setting to be saved in non-volatile memory and will be still apply after the decoder has been power cycled.
 */
-(void)enableDecoderTriggerClick:(BOOL)enabled persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the status of the trigger click sound.

 The trigger click sound is the a click that is heard when the decoder starts to scan. This method will request the status of this click. The result of this method is returned with the <em>-(void)decoderTriggerClickStatus:(BOOL)isEnabled</em> delegate method.
 */
-(void)requestDecoderTriggerClickStatus;//

/**
 @brief Enable a beeper for good reads.

 @param enabled A BOOL to enable (YES) or disable (NO) the beeper on good reads.
 @param (BOOL)persist A BOOL if YES the setting to be saved in non-volatile memory and will be still apply after the decoder has been power cycled.
 */
-(void)enableDecoderBeeperForGoodRead:(BOOL)enable persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the status of the beeper after a successful read.

 After the decoder successfully scans a barcode it may make a beep sound. This method requests the status of the beep setting. The result of this method is returned with the <em>-(void)decoderBeeperForGoodReadStatus:(BOOL)isEnabled</em> delegate method.
 */
-(void)requestDecoderBeeperForGoodReadStatus;//

/**
 @brief Set the beeper volume on a good read.

 This allows the volume of the beeper to be set after a successful read.

 @param (BeeperVolume)beeperVolume The desired volume.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderGoodReadBeeperVolume:(BeeperVolume)beeperVolume persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the volume of the beeper after a successful read.

 After the decoder successfully scans a barcode it may make a beep sound. This method requests the volume of this beep. The result of this method is returned with the <em>-(void)decoderGoodReadBeeperVolumeStatus:(BeeperVolume)volume</em> delegate method.
 */
-(void)requestDecoderGoodReadBeeperVolumeStatus;//

/**
 @brief Set the beeper pitch on a good read.

 This allows the pitch of the beeper to be set after a successful read.

 @param (BeeperPitch)beeperPitch The desired pitch.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderBeeperPitchGoodRead:(BeeperPitch)beeperPitch persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the pitch of the beeper after a successful read.

 After the decoder successfully scans a barcode it may make a beep sound. This method requests the pitch of this beep. The result of this method is returned with the <em>-(void)decoderBeeperPitchGoodReadStatus:(BeeperPitch)pitch</em> delegate method.
 */
-(void)requestDecoderBeeperPitchGoodReadStatus;//

/**
 @brief Set the beeper pitch on an error read.

 This allows the pitch of the beeper to be set after an error.

 @param (BeeperErrorPitch)beeperPitch The desired pitch.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderBeeperPitchError:(BeeperErrorPitch)beeperPitch persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the pitch of the beeper after an error.

 When the decoder encounters an error it may make a beep sound. This method requests the pitch of this beep. The result of this method is returned with the <em>-(void)decoderBeeperPitchErrorStatus:(BeeperErrorPitch)pitch</em> delegate method.
 */
-(void)requestDecoderBeeperPitchErrorStatus;//

/**
 @brief Set the beeper duration on a good read.

 This allows the duration of the beeper to be set after a successful read.

 @param (BeeperDuration)beeperDuration The desired duration.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderBeeperDurationGoodRead:(BeeperDuration)beeperDuration persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the duration of the beeper after a successful read.

 After the decoder successfully scans a barcode it may make a beep sound. This method requests the duration of this beep. The result of this method is returned with the <em>-(void)requestDecoderBeeperDurationGoodReadStatus</em> delegate method.
 */
-(void)requestDecoderBeeperDurationGoodReadStatus;//

/**
 @brief Set the number of beeps on a good read.

 This allows the numbers of beeps to be set after a successful read. The number of beeps must be set to between 1 and 9 inclusively. A number outside of this range will be rounded to the nearest valid number.

 @param (int)numberOfBeeps The desired number of beeps.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderNumberOfBeepsGoodRead:(int)numberOfBeeps persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the number of beeps that the beeper makes after a successful read.

 After the decoder successfully scans a barcode it may make a beep sound. This method requests the number of beeps that will be made. The result of this method is returned with the <em>-(void)decoderNumberOfBeepsGoodReadStatus:(int)numberOfBeeps</em> delegate method.
 */
-(void)requestDecoderNumberOfBeepsGoodReadStatus;//


/**
 @brief Set the number of beeps on a error read.

 This allows the numbers of beeps to be set after an error. The number of beeps must be set to between 1 and 9 inclusively. A number outside of this range will be rounded to the nearest valid number.

 @param (int)numberOfBeeps The desired number of beeps.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderNumberOfBeepsError:(int)numberOfBeeps persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the number of beeps made after an error.

 When the decoder encounters an error it may make a beep sound. This method requests the number of beeps made. The result of this method is returned with the <em>-(void)decoderNumberOfBeepsErrorStatus:(int)numberOfBeeps</em> delegate method.
 */
-(void)requestDecoderNumberOfBeepsErrorStatus;//

/**
 @brief Set the delay between successful reads.

 This allows a delay in milliseconds to be set between reads. The decoder will not read a second barcode until after the delay period. The delay can be between 0 and 30,000 milliseconds inclusively. A number outside of this range will be rounded to the nearest valid number.

 @param (int)delay The desired delay in milliseconds.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderGoodReadDelayInMilliSeconds:(int)delay persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the delay in milliseconds between successful reads.

 After the decoder successfully scans it will not scan another until the delay timer times out. This method requests the duration of this delay in milliseconds. The result of this method is returned with the <em>-(void)requestDecoderGoodReadDelayInMilliSecondsStatus</em> delegate method.
 */
-(void)requestDecoderGoodReadDelayInMilliSecondsStatus;

/**
 @brief Set enhanced manual trigger mode.

 This allows enhanced manual trigger modes to be activated. Normal mode offers good scan speed and the longest working ranges (depth of field). Enhanced mode will give you the highest possible scan speed but slightly less range than Normal mode. Enhanced mode is best used when you require a very fast scan speed and don’t require a longer working range.

 @param (BOOL)enable Set to YES to enter enhanced mode.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)enableDecoderEnhancedManualTriggerMode:(BOOL)enable persistSetting:(BOOL)persist;//

/**
 @brief Set the timeout period of a scan initiated from software.

 This allows the timeout period of a scan that was initiated by software (not the hardware button) to have a timeout period set. The timeout can be set from 0 to 300,000 milliseconds inclusively. A number outside of this range will be rounded to the nearest valid number.

 @param (int)timeout The desired timeout in milliseconds.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderSerialTriggerTimeoutInMilliSeconds:(int)timeout persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the delay in milliseconds for the scanner to turn off if unable to find a barcode.

 Once the decoder is fired this timeout in milliseconds is the amount of time it will remain searching for a barcode until is turned off. This method requests the duration of this delay in milliseconds. The result of this method is returned with the <em>-(void)decoderSerialTriggerTimeoutInMilliSecondsStatus:(int)milliseconds</em> delegate method.
 */
-(void)requestDecoderSerialTriggerTimeoutInMilliSecondsStatus;

/**
 @brief Set the decoder to optimized for reading mobile phone screens.

 When this mode is enabled the decoder is optimized to read bar codes from a mobile phone or other LED displays. However, the speed of scanning printed bar codes may be slightly lower when this mode is enabled.

 @param (BOOL)enable Set to YES to enable mobile phone reading optimizations.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)enableDecoderOptimizationsForMobilePhoneReading:(BOOL)enable persistSetting:(BOOL)persist;//


/**
 @brief Set the use of the interlaced aimer line.

 This allows the interlaced aimer line to be enabled or disabled.

 @param (BOOL)enable Set to YES to enable the interlaced aimer line.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)enableDecoderInterlacedAimerMode:(BOOL)enable persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the status of the interlaced aimer.

 While the decoder is firing it can display an interlaced aimer to guide the user where to place the barcode. This method requests the status of this setting. The result of this method is returned with the <em>-(void)decoderInterlacedAimerModeStatus:(BOOL)isEnabled</em> delegate method.
 */
-(void)requestDecoderInterlacedAimerModeStatus;//

/**
 @brief Enable the use of high and low priority symbology.

 This allows the use of high and low priority symbology. When this is enabled a corresponding high and low priority symbology must be set. The decoder will favor reading the higher priority symbology over others.

 @param (BOOL)enable Set to YES to enable preferred symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)enableDecoderPreferredSymbology:(BOOL)enable persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the status of the preferred symbology setting.

 The decoder is able to perform one symbology over another. This method requests the status of this setting. The result of this method is returned with the <em>-(void)decoderPreferredSymbologyStatus:(BOOL)isEnabled</em> delegate method.
 */
-(void)requestDecoderPreferredSymbologyStatus;

/**
 @brief Set the preferred symbology back to its default settings

 This allows the decoder to be set back to its default settings for preferred symbology.

 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderPreferredSymbologyToDefaultPersistSetting:(BOOL)persist;//

/**
 @brief Set the preferred symbology timeout in milliseconds

 This allows the preferred symbology timeout to be set. The timeout represents the time decoder will defer reading a lower priority symbology in hopes of finding a higher priority one. The time out must be set 100 and 3000 milliseconds inclusively.

 @param (int)timeout The desired timeout in milliseconds.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderPreferredSymbologyTimeoutInMilliSeconds:(int)timeout persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the delay in milliseconds for the preferred symbology setting.

 If the decoder finds a barcode which is not its preferred symbology it will continue to look for another bar code with a higher priority. This method requests the duration of this delay in milliseconds. The result of this method is returned with the <em>-(void)decoderPreferredSymbologyTimeoutInMilliSecondsStatus:(int)milliseconds</em> delegate method.
 */
-(void)requestDecoderPreferredSymbologyTimeoutInMilliSecondsStatus;//

/**
 @brief Set the high priority symbology

 This allows the high priority to be set. Preferred symbology must be enabled by the <em>-(void)enableDecoderPreferredSymbology:(BOOL)enable persistSetting:(BOOL)persist</em> method for this to have an effect.

 @param (Symbology)symbology The symbology to use with a high priority.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderHighPrioritySymbology:(Symbology)symbology persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the symbology that is set to the high priority.

 If preferred symbology is enabled this can be used to request what symbology is set to be high priority. The result of this method is returned with the <em>-(void)decoderHighPrioritySymbologyStatus:(Symbology)symbology</em> delegate method.
 */
-(void)requestDecoderHighPrioritySymbologyStatus;//

/**
 @brief Set the low priority symbology

 This allows the low priority to be set. Preferred symbology must be enabled by the <em>-(void)decoderHighPrioritySymbologyStatus:(Symbology)symbology</em> method for this to have an effect.

 @param (Symbology)symbology The symbology to use with a low priority.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderLowPrioritySymbology:(Symbology)symbology persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the symbology that is set to the low priority.

 If preferred symbology is enabled this can be used to request what symbology is set to be low priority. The result of this method is returned with the <em>-(void)decoderLowPrioritySymbologyStatus:(Symbology)symbology</em> delegate method.
 */
-(void)requestDecoderLowPrioritySymbologyStatus;//

/**
 @brief Enable the decoder to use its centering feature

 The decoder can enable the centering feature to restrict its field of view to the center of the scan area. This method will turn on this feature.

 @param (BOOL)enable Set to YES to enable centering mode.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)enableDecoderCentering:(BOOL)enable persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the status of the centering setting.

 The decoder can be configured to limit its field of view to just the center area. This method will request the status of the centering setting. The result of this method is returned with the <em>-(void)decoderCenteringStatus:(BOOL)isEnabled</em> delegate method.
 */
-(void)requestDecoderCenteringStatus;//

/**
 @brief Set the location of the top of the centering windows

 The decoder can enable the centering feature to restrict its field of view to the center of the scan area. This method will configure the location of the top of the centering window in relation to the top of the maximum field of view as a present.

 @param (int) locationAsPercent The present from the top of the maximum field of view to place the top of the centering window.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderTopOfCenteringWindow:(int)locationAsPercent persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the location of the top of centering the window.

 The decoder can be configured to limit its field of view to just the center area. This method will request the location of the top of centering the window. The result of this method is returned with the <em>-(void)decoderTopOfCenteringWindowLocation:(int)locationAsPrecent</em> delegate method.
 */
-(void)requestDecoderTopOfCenteringWindowStatus;//

/**
 @brief Set the location of the bottom of the centering windows

 The decoder can enable the centering feature to restrict its field of view to the center of the scan area. This method will configure the location of the bottom of the centering window in relation to the top of the maximum field of view as a present.

 @param (int) locationAsPercent The present from the top of the maximum field of view to place the bottom of the centering window.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderBottomOfCenteringWindow:(int)locationAsPercent persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the location of the bottom of the centering window.

 The decoder can be configured to limit its field of view to just the center area. This method will request the location of the bottom of centering the window. The result of this method is returned with the <em>-(void)decoderBottomOfCenteringWindowLocation:(int)locationAsPrecent</em> delegate method.
 */
-(void)requestDecoderBottomOfCenteringWindowStatus;//

/**
 @brief Set the location of the left side of the centering windows

 The decoder can enable the centering feature to restrict its field of view to the center of the scan area. This method will configure the location of the left side of the centering window in relation to the left side of the maximum field of view as a present.

 @param (int) locationAsPercent The present from left side of the maximum field of view to place the left side of the centering window.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderLeftOfCenteringWindow:(int)locationAsPercent persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the location of the bottom of the centering window.

 The decoder can be configured to limit its field of view to just the center area. This method will request the location of the left side of centering the window. The result of this method is returned with the <em>-(void)decoderLeftOfCenteringWindowLocation:(int)locationAsPrecent</em> delegate method.
 */
-(void)requestDecoderLeftOfCenteringWindowStatus;//

/**
 @brief Set the location of the right side of the centering windows

 The decoder can enable the centering feature to restrict its field of view to the center of the scan area. This method will configure the location of the right side of the centering window in relation to the left side of the maximum field of view as a present.

 @param (int) locationAsPercent The present from left side of the maximum field of view to place the right side of the centering window.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderRightOfCenteringWindow:(int)locationAsPercent persistSetting:(BOOL)persist;//

/**
 @brief This method is used to request the location of the right of the centering window.

 The decoder can be configured to limit its field of view to just the center area. This method will request the location of the right side of centering the window. The result of this method is returned with the <em>-(void)decoderRightOfCenteringWindowLocation:(int)locationAsPrecent</em> delegate method.
 */
-(void)requestDecoderRightOfCenteringWindowStatus;//

/**
 @brief This method requests the revision number from the decoder subsystem.

 This method is used to request the revision number from the decoder subsystem. This is not the device revision number, only the subsystem that contains the decoder.
 */
-(void)requestDecoderRevision;//

/**
 @brief This method requests the revision number from the decoder subsystem.

 This method is used to request the revision number from the decoder subsystem. This is not the device revision number, only the subsystem that contains the decoder.
 */
-(void)requestDecoderDriverRevision;//

/**
 @brief This method enables all available symbologies to be decoded.

 This method is used to enable the decoder to scan all available symbologies.

 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)enableAllSymbologiesPersistSetting:(BOOL)persist;

/**
 @brief This method enables the aimer.

 This method is used to enable the aimer.

 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)enableDecoderAimer:(BOOL)persist;
/**
 @brief This method disable the aimer.

 This method is used to disable the aimer.

 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)disableDecoderAimer:(BOOL)persist;
/**
 @brief This method enables the illumination.

 This method is used to enable the illumination.

 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)enableDecoderIllumination:(BOOL)persist;
/**
 @brief This method disables the illumination.

 This method is used to disable the illumination.

 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)disableDecoderIllumination:(BOOL)persist;

/**
 @brief This method disables all symbologies.

 This method is used to disable the decoding of all symbologies. This is normally used in the case where an application only wants to scan a select few symbols. First this will be used to turn off all of the symbologies and then the symbologies that are required are turned on one by one.

 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)disableAllSymbologiesPersistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the UPC-A symbology.

 This method is used to configure the UP-CA symbology. An UPCA object is used to hold the configuration options.

 @param (UPCA*)upca A UPCA object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderUPCAConfiguration:(UPCA*)upca persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the EAN-13 symbology.

 This method is used to configure the EAN-13 symbology. An EAN13 object is used to hold the configuration options.

 @param (EAN13*)ean13 A EAN13 object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderEAN13Configuration:(EAN13*)ean13 persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the UPC-E0 symbology.

 This method is used to configure the UPC-E0 symbology. An UPCE0 object is used to hold the configuration options.

 @param (UPCE0*)upce0 A UPCE0 object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderUPCE0Configuration:(UPCE0*)upce0 persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the EAN-8 symbology.

 This method is used to configure the EAN-8 symbology. An EAN8 object is used to hold the configuration options.

 @param (EAN8*)ean8 A EAN8 object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderEAN8Configuration:(EAN8*)ean8 persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the Codabar symbology.

 This method is used to configure the Codabar symbology. A Codabar object is used to hold the configuration options.

 @param (Codabar*)codabar A Codabar object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderCodabarConfiguration:(Codabar*)codabar persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the Code 39 symbology.

 This method is used to configure the Code 39 symbology. A Code39 object is used to hold the configuration options.

 @param (Code39*)code39 A Code39 object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderCode39Configuration:(Code39*)code39 persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the Interleaved 2 of 5 symbology.

 This method is used to configure the Interleaved 2 of 5 symbology. An Interleaved2of5 object is used to hold the configuration options.

 @param (Interleaved2of5*)interleaved2of5 A Interleaved2of5 object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderInterleaved2of5Configuration:(Interleaved2of5*)interleaved2of5 persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the NEC 2 of 5 symbology.

 This method is used to configure the NEC 2 of 5 symbology. A NEC2of5 object is used to hold the configuration options.

 @param (NEC2of5*)nec2of5 A NEC2of5 object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderNEC2of5Configuration:(NEC2of5*)nec2of5 persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the Code 93 symbology.

 This method is used to configure the Code 93 symbology. A Code93 object is used to hold the configuration options.

 @param (Code93*)code93 A Code93 object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderCode93Configuration:(Code93*)code93 persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the Straight 2 of 5 Industrial symbology.

 This method is used to configure the Straight 2 of 5 Industrial symbology. A Straight2of5Industrial object is used to hold the configuration options.

 @param (Straight2of5Industrial*)straight2of5Industrial A Straight2of5Industrial object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderStraight2of5IndustrialConfiguration:(Straight2of5Industrial*)straight2of5Industrial persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the Straight 2 of 5 Industrial symbology.

 This method is used to configure the Straight 2 of 5 Industrial symbology. A Straight2of5Industrial object is used to hold the configuration options.

 @param (Straight2of5Industrial*)straight2of5Industrial A Straight2of5Industrial object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderStraight2of5IATAConfiguration:(Straight2of5IATA*)straight2of5IATA persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the Matrix 2 of 5 symbology.

 This method is used to configure the Matrix 2 of 5 symbology. A Matrix2of5 object is used to hold the configuration options.

 @param (Matrix2of5*)matrix2of5 A Matrix2of5 object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderMatrix2of5Configuration:(Matrix2of5*)matrix2of5 persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the Code 11 symbology.

 This method is used to configure the Code 11 symbology. A Code11 object is used to hold the configuration options.

 @param (Code11*)code11 A Code11 object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderCode11Configuration:(Code11*)code11 persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the Code 128 symbology.

 This method is used to configure the Code 128 symbology. A Code128 object is used to hold the configuration options.

 @param (Code128*)code128 A Code128 object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderCode128Configuration:(Code128*)code128 persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the GS1-128 symbology.

 This method is used to configure the GS1-128 symbology. A GS1_128 object is used to hold the configuration options.

 @param (GS1_128*)gs1_128 A GS1_128 object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderGS1_128Configuration:(GS1_128*)gs1_128 persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the Telepen symbology.

 This method is used to configure the Telepen symbology. A Telepen object is used to hold the configuration options.

 @param (Telepen*)telepen A Telepen object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderTelepenConfiguration:(Telepen*)telepen persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the MSI symbology.

 This method is used to configure the MSI symbology. An MSI object is used to hold the configuration options.

 @param (MSI*)msi A MSI object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderMSIConfiguration:(MSI*)msi persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the GS1 DataBar Omnidirectional symbology.

 This method is used to configure the GS1 DataBar Omnidirectional symbology. A GS1DataBarOmnidirectional object is used to hold the configuration options.

 @param (GS1DataBarOmnidirectional*)gs1DataBarOmnidirectional A GS1DataBarOmnidirectional object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderGS1DataBarOmnidirectionalConfiguration:(GS1DataBarOmnidirectional*)gs1DataBarOmnidirectional persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the GS1 DataBar Limited symbology.

 This method is used to configure the GS1 DataBar Limited symbology. A GS1DataBarLimited object is used to hold the configuration options.

 @param (GS1DataBarLimited*)gs1DataBarLimited A GS1DataBarLimited object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderGS1DataBarLimitedConfiguration:(GS1DataBarLimited*)gs1DataBarLimited persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the GS1 DataBar Expanded symbology.

 This method is used to configure the GS1 DataBar Expanded symbology. A GS1DataBarExpanded object is used to hold the configuration options.

 @param (GS1DataBarExpanded*)gs1DataBarExpanded A GS1DataBarExpanded object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderGS1DataBarExpandedConfiguration:(GS1DataBarExpanded*)gs1DataBarExpanded persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the Codablock A symbology.

 This method is used to configure the Codablock A symbology. A CodablockA object is used to hold the configuration options.

 @param (CodablockA*)codablockA A CodablockA object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderCodablockAConfiguration:(CodablockA*)codablockA persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the Codablock F symbology.

 This method is used to configure the Codablock F symbology. A CodablockF object is used to hold the configuration options.

 @param (CodablockF*)codablockF A CodablockF object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderCodablockFConfiguration:(CodablockF*)codablockF persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the PDF417 symbology.

 This method is used to configure the PDF417 symbology. A PDF417 object is used to hold the configuration options.

 @param (PDF417*)pdf417 A PDF417 object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderPDF417Configuration:(PDF417*)pdf417 persistSetting:(BOOL)persist;


/**
 @brief This method is used to configure the Data Matrix symbology.

 This method is used to configure the Data Matrix symbology. A DataMatrix object is used to hold the configuration options.

 @param (DataMatrix*)dataMatrix A DataMatrix object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderDataMatrixConfiguration:(DataMatrix*)dataMatrix persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the MaxiCode symbology.

 This method is used to configure the MaxiCode symbology. A MaxiCode object is used hold the configuration options.

 @param (MaxiCode*)maxiCode A MaxiCode object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderMaxiCodeConfiguration:(MaxiCode*)maxiCode persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the Aztec symbology.

 This method is used to configure the Aztec symbology. An Aztec object is used to hold the configuration options.

 @param (Aztec*)aztec A Aztec object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderAztecConfiguration:(Aztec*)aztec persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the Chinese Sensible symbology.

 This method is used to configure the Chinese Sensible symbology. A ChineseSensible object is used to hold the configuration options.

 @param (ChineseSensible*)chineseSensible A Aztec object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderChineseSensibleConfiguration:(ChineseSensible*)chineseSensible persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the MicroPDF417 symbology.

 This method is used to configure the MicroPDF417 symbology. A MicroPDF417 object is used to hold the configuration options.

 @param (MicroPDF417*)microPDF417 A MicroPDF417 object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderMicroPDF417Configuration:(MicroPDF417*)microPDF417 persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the TCIF Linked Code 39 symbology.

 This method is used to configure the TCIF Linked Code 39 symbology. A TCIFLinkedCode39 object is used to hold the configuration options.

 @param (TCIFLinkedCode39*)tcifLinkedCode39 A TCIFLinkedCode39 object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderTCIFLinkedCode39Configuration:(TCIFLinkedCode39*)tcifLinkedCode39 persistSetting:(BOOL)persist;

/**
 @brief This method is used to configure the QR Code symbology.

 This method is used to configure the QR Code symbology. A QRCode object is used to hold the configuration options.

 @param (QRCode*)qrCode A QRCode object with the settings desired for this symbology.
 @param (BOOL)persist Set to YES to save the setting between power cycles.
 */
-(void)setDecoderQRCodeConfiguration:(QRCode*)qrCode persistSetting:(BOOL)persist;

/**
 @breif This method requests the revision number of the software found in the decoder subsystem.

 This method is used to request the revision number of the software found in the decoder subsystem.
 */
-(void)requestDecoderSoftwareRevision;//

/**
 @brief This method is used to send data directly to the decoder.

 The data is directly sent without any manipulation of the SDK. The caller is responsible for formatting the message correctly, The caller of this method must indicate if they expect a return message.

 @param (NSData*) data at the NSData object that contains the raw data to send to the decoder.
 @param (BOOL)enabled A BOOL if YES the SDK will attempt to return a message from the decoder with the <em>-(void)decoderPassThroughReturnData:(NSData*)data</em> delegate method.
 */
-(void)decoderPassThrough:(NSData*)data expectingReturnData:(BOOL)returnData;

/**
 @brief This method is used to erase all your settings and reset the engine to the original factory defaults.

 This method is used to erase all your settings and reset the engine to the original factory defaults. We should be careful to use this interface.
 */
-(void)FactoryResetting;

#pragma mark -
#pragma mark MSR Methods

/**
 @brief This method is used to turn on the MSR hardware in the device.

 This must be called before any other MSR methods. Until this method is called the MSR hardware is not initialized. Use -stopMSRHarware to shut down the MSR hardware.

 @return ProtocolConnectionStatus The status of the requested action.
 */
-(ProtocolConnectionStatus)startMSRHardware;//

/**
 @brief This method is used to turn on the MSR hardware in the device.

 It will retry to turn on the MSR hardware every 250ms until succeeded or timeout.

 This must be called before any other MSR methods. Until this method is called the MSR hardware is not initialized. Use -stopMSRHarware to shut down the MSR hardware.

 @param (double)timeout The time to wait for decoder hardware to reply to the turn on request.

 @return ProtocolConnectionStatus The status of the requested action.
 */
//-(ProtocolConnectionStatus)startMSRHardware:(double)timeout;//
- (void)startMSRHardware:(double)timeout ;
/**
 @brief This method is used to turn off the MSR hardware in the device.

 Once this method is called the MSR hardware is inactivated. No MSR methods can be called until -startMSRHardware is called again to re-initialize the MSR hardware.
 */
-(void)stopMSRHardware;//

/**
 @brief This method is used to determine if the MSR hardware is currently running.

 This method is used to determine if the MSR is currently running. It can be started and stopped with the methods <em>-(void)startMSRHardware</em> and <em>-(void)stopMSRHarware</em> respectivly.

 @return BOOL YES if the MSR is running.
 */
-(BOOL)isMSRRunning;

/**
 @brief This method places the MSR reader in an enabled state.

 When this method is called the MSR reader will be active and will return data to its delegates when a card is swiped through the MSR reader.
 */
-(void)enableMSRReader;//

/**
 @brief This method places the MSR reader in an un-enabled state.

 When this method is called the MSR reader will be deactivated and will not read any data from cards when swiped.
 */
-(void)disableMSRReader;//

/**
 @brief This method requests the firmware version of the MSR hardware.

 When this method is called a request is sent to the MSR hardware for its firmware version. This data is returned with the <em>-(void)msrFirewareVersion:(NSString*)data validData:(BOOL)status</em> delegate method.
 */
-(void)requestMSRFirmwareVersion;//

/**
 @brief This method requests the serial number from the MSR hardware.

 When this method is called a request is sent to the MSR hardware from its serial number. This data is returned with the <em>-(void)msrSerialNumber:(NSString*)data validData:(BOOL)status</em> delegate method.
 */
-(void)requestMSRSerialNumber;//

/**
 @brief This method is used to set what tracks the MSR will read.

 This is used to select what tracks are read when a card is swiped. If any of the required multiple tracks fail to read for any reason, no data for any track will be sent.

 @param (TrackSelection)selectio An enum that represents what tracks to read..
 */
-(void)setMSRTrackSelection:(TrackSelection)selection;//

/**
 @brief This method requests the security level from the MSR hardware.

 When this method is called a request is sent to the MSR hardware for its current security level. This data is returned to the <em>-(void)msrCurrentSecurityLevel:(SecurityLevel)securityLevel validData:(BOOL)status</em> delegate method.
 */
-(void)requestMSRSecurityLevel;

/**
 @brief This method requests the track settings for the MSR hardware.

 When this method is called a request is sent to the MSR hardware for the current tacks that the device will read. This data is returned to the <em>-(void)msrCurrentTrackSelection:(TrackSelection)trackSelection validData:(BOOL)status</em> delegate method.
 */
-(void)requestMSRTrackSettings;

/**
 @brief This method is used to send data directly to the MSR.

 The data is directly sent without any manipulation of the SDK. The caller is responsible for formatting the message correctly and applying the correct checksum. The caller must also indicate if they expect a return message.

 @param (NSData*) data at the NSData object that contains the raw data to send to the MSR.
 @param (BOOL)enabled A BOOL if YES the SDK will attempt to return a message from the MSR with the <em>-(void)msrPassThroughReturnData:(NSData*)data</em> delegate method.
 */
-(void)msrPassThrough:(NSData*)data expectingReturnData:(BOOL)returnData;

#pragma mark -
#pragma mark Power Management Methods

/**
 @brief This method is used to get the current charging status.

 This can be called to get the current status of the battery charging

 @return ChargeStatus The status of the battery charging.
 */
-(ChargeStatus)getChargeStatus;//

/**
 @brief This method is used to get the current remaining battery life.

 This can be called to get the current status of battery life remaining.

 @return BatteryStatus The current status of the battery.
 */
-(BatteryStatus)getBatteryStatus;//

#pragma mark -
#pragma mark Mfg Block Data
/**
 @brief This method requests the current battery voltage of the device.

 When this method is called to request the current battery voltage of the device. This data is returned with the <em>-(void)pmBatteryVoltage:(float)voltage</em> delegate method. To track the battery status it is better to use the <em>-(BatteryStatus)requestBatteryStatus</em> method.
 */
-(void)requestBatteryVoltage;


/**
 @brief This method requests the current charge status of a battery.

 When this method is called to request the current charge status of the device. This data is returned with the <em>-(void)pmChargeStatus:(ChargeStatus)chargeStatus</em> delegate method.
 */
-(void)requestChargeStatus;

/**
 @brief This method requests the current device manufacture information.

 When this method is called to request the current charge status of the device. This data is returned with the <em>-(void)pmChargeStatus:(ChargeStatus)chargeStatus</em> delegate method.
 */

-(void)requestPMMfgBlockData;

/**
 Start pm hardware
 */
-(ProtocolConnectionStatus)startPMHardware;

/**
 Start pm hardware
 */
-(void)startPMHardware:(double)timeout;

/**
 Stop pm hardware
 */
-(void)stopPMHardware;


/**
 Force shuts down when battery low.
 */
-(void)forceBatteryLowShutdown;

/**
 Debug status, return YES can debug, NO can not debug.
 */
-(BOOL)debug;


/**
 Enable Query Battery
 */
- (void)enableBatteryQuery ;

/**
 Disable Query Battery
 */
- (void)disableBatteryQuery;

/**
 Enable HID Query
 */
- (void)activateHID;
/**
 Disable HID Query
 */
- (void)deActivateHID ;

/**
 Open HID Query
 */
- (void)unLockHIDMode;

/**
 Close HID Query
 */
- (void)lockHIDMode;

/**
 @brief This method requests the current HID Status of the device.

 When this method is called to request the current HID State of the device. This data is returned with the <em>-(void)stateHID:(HIDCurStatus)status</em> delegate method. To track the HID status it is better to use the <em>-(HIDCurStatus)requestHIDStatus</em> method.
 */

- (void)requestHIDStatus;


/**
 normal=YES--Normal Level, normal=NO---HIGH Level
 */
- (void)esdSecurityQuery:(BOOL)normal;


@end



