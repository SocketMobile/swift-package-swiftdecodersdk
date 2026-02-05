//
//  MasterListScanPlugin.h
//  SwiftDecoder
//
//  Created by K N, Vinod on 14/04/25.
//

#import <Foundation/Foundation.h>
#import "BarcodeARBasePlugin.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief A SwiftPlugin used for counting the number of barcodes scanned in the current preview.
 * This plugin specifically supports scanning of similar barcodes in current preview or FOV
 * This plugin allows the user to capture the current preview data and count the number of similar or unique barcodes scanned.
 * It also provides options for cycle counting.
 */

@interface MasterListScanPlugin : BarcodeARBasePlugin
/**
    * @brief This method is used to get the master list barcodes using CSV file.
    * @param   path of the CSV file.
 */
-(void) loadMasterListCSVFile:(NSString*)filePath;
/**
 * @brief This method is used to get the current master list scan.
 */
-(void) getCurrentMasterListScanResult;

/**
  * @brief Allows to fetch the Overlay result list for a given preview .
  *  The overlays for same barcode values is also supported with this feature.
  */
-(void) capturePreviewData;
/**
    * @brief This method is used to reset the master list scan.
 */
-(void)scanAgainMasterList;
@end

NS_ASSUME_NONNULL_END
