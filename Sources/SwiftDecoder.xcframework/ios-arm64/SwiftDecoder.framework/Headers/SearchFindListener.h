//
//  SearchFindListener.h
//  SwiftDecoder
//
//  Created by H454944 on 16/10/23.
//

/**
 * @brief This protocol must be implemented by any class that wishes to receive decoder results
 * @author E412474
 */
#import "PluginResultListener.h"
#import "HSMDecodeResultArray.h"
#import "BarcodeARBasePlugin.h"

@protocol SearchFindListener <PluginResultListener>

-(void) onFindResultSelected:(HSMDecodeResult*) barcodeSelected;
-(void) onSearchResultEnd:(HSMDecodeResult*) barcodeSelected;

@optional
-(void) onSearchResultEndMultiple:(HSMDecodeResultArray*) barcodeSelected;

/**
        * @brief This method is called when there is an error in receiving the swift find result data.
        * @param error The error that occurred while receiving the swift find result data. Note:  The error value is of type MasterListScanError.
 */
-(void) onSwiftFindReceiveDataError:(SwiftFindError) error;

/**
 * @brief This method is called to update the status of Swift Find Multiple Scan.
 * @param swiftFindScanResults The results of the SwiftFindMultiple.
 *                              The key is the master item ID, and the value is a map containing the find data.
 *                              The key values are items "itemFound" and "itemNotFound".

 * @param totalFindCount The current Find Count.
 */
-(void) onSwiftFindMultipleResultStatus:(NSDictionary*)swiftFindScanResults withfindCount: (int)totalFindCount;

- (void) onSwiftFindProgressStatus:(int)totalScannedCount withFindCount:(int)totalFindCount;
@end


