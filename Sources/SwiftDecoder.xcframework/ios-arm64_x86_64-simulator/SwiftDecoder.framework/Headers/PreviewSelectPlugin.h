//
//  PreviewSelectPlugin.h
//  HSMDecoderAPI
//
//  Created by eltodesc on 11/19/13.
//
//


typedef  enum {
    /**
     * Multiple select requires frame to be frozen for selection
     */
    SINGLE_AND_MULTI_SELECT = 0,
    SINGLE_SELECT
} PreviewSelectMode;


#import "DecodeBasePlugin.h"
#import "BarcodeARBasePlugin.h"

/**
 * @brief A SwiftPlugin used for rendering Augmented Reality Overlay over detected barcodes within the preview.\n
 * This plugin allows "Preview & Select" functionality, supporting both single and multiple barcode selection.\n
 * Overlays on the preview enable touch functionality to select single barcodes.\n
 * Multiple barcode selection is available only when the frame is frozen, by double tap on the preview component.\n
 * Freeze/Unfreeze callbacks are provided to the application using FreezeFrameListener API in HSMDecoder.\n
 * The application can register a DecodeResultListener callback using HSMDecoder::addResultListener API for actions on selected barcodes.\n
 * Use HSMDecoder::registerPlugin and HSMDecoder::unRegisterPlugin APIs to register/unregister any plugin on SwiftDecoder.\n
 * **The Counting API in this plugin will be deprecated in future releases; use PreviewCountPlugin for counting functionality.**
 */

@interface PreviewSelectPlugin : BarcodeARBasePlugin{
    @private
    HSMDecodeResultArray *ARresults;
}

@property (nonatomic, strong) UIColor *frameColor;
@property (nonatomic, strong) UIColor *touchColor;

/**
 @brief This method initializes the PreviewSelectPlugin with the given selection mode

 * @param mode
 *     The preview selection mode to be used based on the input provided
 */
- (id)initWithPreviewSelectionMode:(PreviewSelectMode)mode;

/**
 @brief This method changes the color of the Accent(frame and number text)

 @param color color that has to be set
 */
- (void)setAccentColor:(UIColor *)color;

/**
 @brief  Only override drawRect: if you perform custom drawing. An empty implementation adversely affects performance during animation.

 @param rect The portion of the view’s bounds that needs to be updated.
 */
-(void)drawRect:(CGRect)rect;

/**
 * @brief Called when video preview comes to the foreground. This should be used to initialize the plug-in on each scan attempt.
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
 * @brief Called each time a frame cannot be successfully decoded
 */
-(void)onDecodeFailed;

/**
 @brief Touch Delegate methods of begin

 @param touches A set of UITouch instances
 @param event The event to which the touches belong.
 */
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;

/**
 @brief Touch Delegate methods of move

 @param touches A set of UITouch instances
 @param event The event to which the touches belong.
 */
- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;

/**
 @brief Touch Delegate method of end

 @param touches A set of UITouch instances
 @param event The event to which the touches belong.
 */
- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;

/**
 @brief Touch Delegate method of cancel

 @param touches A set of UITouch instances
 @param event The event to which the touches belong.
 */
- (void)touchesCancelled:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;

/**
 * @brief Allows to fetch the Overlay result list for a given preview .
 *           The overlays for same barcode values is also supported with this feature.
 * @return HSMDecodeResultArray list for the detected barcodes with overlay List
 */
-(HSMDecodeResultArray *)getPreviewResult;

/**
 * @brief This method returns the Image saved when calling getPreviewResult
 * @return UIImage of the last AR decoded image
 */
-(UIImage*) getLastARDecodedImage;

/**
 * @brief This method returns the results of the selected previews (applicable only for AR plugin)
 */
-(BOOL)getResultforSelectedBarcodes;

/**
 * @brief This method helps to select all previews at once (applicable only for AR plugin)
 */
-(BOOL)toggleSelectAll;

/**
 * @brief This method helps to know whether all previews are selected or not (applicable only for AR plugin)
 */
-(BOOL)isSelectAll;

/**
 * @brief This method helps to get the current preview select mode (applicable only for AR plugin)
 */
- (PreviewSelectMode)getPreviewSelectMode;

@end
