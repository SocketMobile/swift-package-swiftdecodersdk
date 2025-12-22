//
//  MasterListScanResultListener.h
//  SwiftDecoder
//
//  Created by K N, Vinod on 14/04/25.
//

#import <Foundation/Foundation.h>
#import "PluginResultListener.h"
#import "MasterListScanPlugin.h"
/**
 * @brief This protocol must be implemented by any class that wishes to receive decoder results in groups by Master List Scan
 *
 */
@protocol MasterListScanResultListener <PluginResultListener>
     /**
      * @brief This method is called when the master list scan is completed to trigger to fetch interim result is initiated.
      * @param masterListScanResults The results of the master list scan.
      *                              The key is the master item ID, and the value is a map containing the scanned data.
      *                              The key values are items "ItemsPresent" and "ItemsMissing" and "ItemsScanned".
      * @param totalMasterCount The total number of master items.
      */
-(void)onMasterListScanResult:(NSDictionary*)masterListScanResults withTotalMasterCount:(int)totalMasterCount;
 
     /**
      * @brief This method is called to update the status of Master List Scan.
      * @param totalScannedCount The current Scanned Count.
      * @param totalMasterCount The total number of master items.
      */
-(void)onMasterListScanProgressStatus:(int) totalScannedCount withMasterCount: (int) totalMasterCount;
 
     /**
      * @brief This method is called when the master list data is received.
      * @param totalMasterCount The total number of master items.
      */
-(void)onMasterListDataReceived:(int) totalMasterCount;

/**
        * @brief This method is called when there is an error in receiving the master list data.
        * @param error The error that occurred while receiving the master list data. Note:  The error value is of type MasterListScanError.
 */
-(void)onMasterListDataReceiveError:(MasterListScanError) error;


@end
