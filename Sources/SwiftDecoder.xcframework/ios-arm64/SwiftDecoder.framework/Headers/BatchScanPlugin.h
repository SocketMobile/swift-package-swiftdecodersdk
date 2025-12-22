//
//  BatchScanPlugin.h
//  SwiftDecoderDemo
//
//  Created by Misra, Vaibhav on 10/19/15.
//  Copyright © 2015 Honeywell. All rights reserved.
//

#import "DecodeBasePlugin.h"
#import "BarcodeARBasePlugin.h"
/**
 @brief A SwiftPlugin used for ensuring that a number of bar codes are decoded before the results are returned to the business logic.
 */
@interface BatchScanPlugin : BarcodeARBasePlugin

@property (nonatomic,assign) int requiredScanCount;
@property (nonatomic, strong) UIColor *overlayFrameColor;

typedef enum
{
    PAUSED,
    RESUMED
}ScanState;

/**
 @brief Sets the number of unique barcodes required

 @param barcodeCount The number of unique barcodes required
 @return return a BatchScanPlugin
 */
- (instancetype)initWithRequiredScanCount:(int)barcodeCount;


- (id)initWithAsyncResults:(BOOL)asyncResults;

/**
 @brief This method changes the color of the Accent(frame and number text)

 @param color The color to set.
 */
-(void)setAccentColor:(UIColor *)color;

/**
 @brief Called when video preview comes to the foreground.  This should be used to initialize the plug-in on each scan attempt.
 */
- (void)onStart;

/**
 * @brief Called when a barcode(s) has been decoded in the image
 *
 * @param results
 *      An array results for all decode barcodes
 */
-(void)onDecode:(HSMDecodeResultArray *)results;


/**
 @brief Only override drawRect: if you perform custom drawing. An empty implementation adversely affects performance during animation.

 @param rect The portion of the view’s bounds that needs to be updated.
 */
-(void)drawRect:(CGRect)rect;

/**
 * @brief Allows to fetch the Overlay result list for a given preview .
 *
 * @return HSMDecodeResultArray list for the detected barcodes with overlay List
 */
-(HSMDecodeResultArray *)getScannedBatchResult;

/**
 @brief Returns the current state of the batch scan.
 *
 *@return the current state of the batch scan *
 */
-(ScanState ) getCurrentScanState;

/**
 @brief This API allows the user  to pause the batch scan while the preview is still on.
 *
 */
-(void)pauseScan;

/**
 @brief This API allows the user to resume the batch scan after it has been paused.
 *
 */
-(void)resumeScan;

/**
 @brief This API allows the user to reset the scanned barcodes and restart the batch scan.
 *
 */
-(void)resetScan;

/**
 @brief This API allows the user to start the  batch scan after it has been stopped..
 *
 */
-(void)startAsyncScan;

/**
 @brief This API allows the user to stop the  batch scan after it has been started..
 *
 */
-(void)stopAsyncScan;

@end
