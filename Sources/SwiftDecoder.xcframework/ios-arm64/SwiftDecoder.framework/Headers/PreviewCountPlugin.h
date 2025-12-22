//
//  PreviewCountPlugin.h
//  SwiftDecoder
//
//  Created by K N, Vinod on 04/04/25.
//

#import <Foundation/Foundation.h>
#import "BarcodeARBasePlugin.h"

NS_ASSUME_NONNULL_BEGIN
/** * @brief A SwiftPlugin used for counting the number of barcodes scanned in the current preview. * This plugin specifically supports scanning of similar barcodes in current preview or FOV * This plugin allows the user to capture the current preview data and count the number of similar or unique barcodes scanned. * It also provides options for cycle counting. */
 
@interface PreviewCountPlugin : BarcodeARBasePlugin

/**
  * @brief This API will return whether the cycle count is enabled or not.
  *
  * @return BOOL - YES if enabled/ NO if disabled
  */
-(BOOL)isCycleCountEnabled;

/**
  * @brief This API will enable counting multiple preview results and returning the combined results.
  *
  * @param enable Enables/Disables cycle Count.
  */
-(void)enableCycleCount:(BOOL) enable;
/**
  * @brief This API will indicates the plugin that user wants to stop cycle counting and should return the results.
  *
  */
-(void) setCycleCountComplete;

/**
  * @brief Allows to fetch the Overlay result list for a given preview .
  *             The overlays for same barcode values is also supported with this feature.
  * @return HSMDecodeResult list for the detected barcodes with overlay List through callback
  */
-(void) capturePreviewData;

/**
 * @brief This method returns the Image saved when calling getPreviewResult
 * @return UIImage of the last AR decoded image
 */
-(UIImage*) getLastARDecodedImage;
@end

NS_ASSUME_NONNULL_END
