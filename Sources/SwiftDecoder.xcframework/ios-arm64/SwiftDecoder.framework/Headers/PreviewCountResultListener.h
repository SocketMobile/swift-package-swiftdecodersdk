//
//  Untitled.h
//  HSMDecoderAPI
//
//  Created by K N, Vinod on 07/04/25.
//

#import <Foundation/Foundation.h>
#import "PluginResultListener.h"
#import "HSMDecodeResultArray.h"

/**
 * @brief This protocol must be implemented by any class that wishes to receive decoder results in groups by Preview Count
 * 
 */
@protocol PreviewCountResultListener <PluginResultListener>

/**
 * @brief This method is called when the preview count result is available.
 *
 * @param previewResult
 *    This is an array of HSMDecodeResultArray objects that contains all the data associated with each barcode decoded.
 *
 * @param totalCount
 *         Total count of barcodes
 */

-(void)onPreviewCountResult:(NSArray<HSMDecodeResultArray*>*) previewResult withCount:(int) totalCount maxCountReached:(BOOL)maxCycleCountReached;


/**
 * @brief This method is called when every preview count cycle is completed.
 *
 * @param currentcycleCount
 *    This is current cycle count.
 *
 */
-(void)onPreviewCountCyclesCompleted:(int) currentcycleCount withCurrentCapturedCount:(int)currentCapturedCount;

@end
