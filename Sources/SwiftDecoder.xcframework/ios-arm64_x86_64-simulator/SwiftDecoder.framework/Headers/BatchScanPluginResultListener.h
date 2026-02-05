//
//  PanoramicPluginResultListener.h
//  SwiftDecoderDemo
//
//  Created by Misra, Vaibhav on 10/21/15.
//  Copyright © 2015 Honeywell. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PluginResultListener.h"

@protocol BatchScanPluginResultListener <PluginResultListener>

@optional

/**
 * @brief This method is called when the batch scan result is available.
 * @param results
 *    This is an array of HSMDecodeResultArray objects that contains all the data associated with each barcode decoded.
 *
 * @param barcodeImages
 *         This is an array of UIImage objects that contains all the barcode images decoded in the batch scan.
 */
- (void) onBatchScanPluginResults:(HSMDecodeResultArray*)results barcodeImages:(NSMutableArray*)barcodeImages;

/**
 * @brief This method is called when the batch scan async result is available.
 *
 * @param barcodeData
 *   The barcode data for the batch scan result.
 *

 */
- (void) onBatchScanAsyncResult:(HSMDecodeResult *)barcodeData;
@end
