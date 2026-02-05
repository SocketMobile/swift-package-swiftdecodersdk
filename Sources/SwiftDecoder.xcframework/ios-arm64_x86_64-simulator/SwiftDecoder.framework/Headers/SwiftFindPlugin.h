//
//  SwiftFindPlugin.h
//  SwiftDecoder
//
//  Created by H454944 on 27/09/23.
//

#import <Foundation/Foundation.h>
#import "BarcodeARBasePlugin.h"
#import "SearchAndFindLayoutDataSource.h"
#import "SearchView.h"
#import "FindView.h"

NS_ASSUME_NONNULL_BEGIN
/**
  * @brief The mode of search. this could be text search or scan search
  */
typedef enum {

    SEARCH_TYPE_TEXT = 0,
    SEARCH_TYPE_SCAN

}SearchType;


/**
 * @brief A SwiftPlugin for finding barcodes within a camera preview.\n
 * It supports both single and multiple barcode find modes.\n
 * For single mode to get the find input this plugin overlays bounding boxes on the preview, enabling users to select barcodes by touch or enter barcode data manually.
 * For multiple mode, the plugin allows loading a list of barcodes from a CSV file or QR code, and scans the camera preview to find and match these barcodes.
 * The application can register a `SwiftFindListener` callback to receive find results, progress updates, and error notifications.
 */

@interface SwiftFindPlugin : BarcodeARBasePlugin<SearchListener,SearchLayoutDataSource,FindLayoutDataSource>


/**
 * @brief this method is a constructor which takes datasource as a parameter
 *
 * @param  dataSource - datasource for layouts to be passed
 */
-(id)initWithDataSource:(id<SearchAndFindLayoutDataSource>) dataSource;

/**
 * @brief this method is a constructor which takes multiple datasource as a parameter
 *
 * @param  dataSource - datasource for layouts to be passed
 */

-(id)initWithDataSourceMultiple:(id<SearchAndFindLayoutDataSource>) dataSource;

/**
 * @brief this method is used to set the barcode data to to be searched when the data to be searched is entered manually
 *
 * @param  barcodeText entered  barcode data
 */
-(void) setSearchBarcode:(NSString*) barcodeText;
/**
   * @brief set search type
   *
   * @param  searchType
   */
-(void) setSearchType:(SearchType) searchType;

/**
    * @brief set search and Find Listener to start the process
    *
    * @param  listener instance
    */
-(void) setSearchFindListener:(id<SearchFindListener>) listener;
/**
 * @brief start the find operation. Once the data that has to be searched is manually entered or scanned, use this method to start the Find opertaion
 *
 * @param  decodeResult entered or scanned barcode data
 */
-(void)setStartFind:(HSMDecodeResult*)decodeResult;

/**
   * @brief reset serach and find. clears all the data
   *
   *
   */
-(void)resetSearchFind;
/**
 * @brief This method is used to load the CSV file containing the list of barcodes to be used in multiple find mode. The application can call this API to load the CSV file containing the list of barcodes to find.
 *
 * @param filePath The file path of the CSV file containing the list of barcodes to find.
 *                    The content of csv file should be in below format example:
 *                    Barcode Data
 *                    123456789012
 *                    987654321098
 *                    123456789012
 */
-(void) loadSwiftFindCSVFIle:(NSString*)filePath;

/**
    * @brief This method is used to reset the master list scan.
 */
-(void)scanAgainSwiftFindList;

/**
 * @brief This method is used to get the current swift find multiple result.
 */
-(void)getCurrentSwiftFindMultipleResult;

@end


NS_ASSUME_NONNULL_END
