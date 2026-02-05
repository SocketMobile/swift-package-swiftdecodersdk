//
//  PinchZoomListener.h
//  HSMDecoderAPI
//

#import <Foundation/Foundation.h>

/**
 * @brief PinchZoomListener provides listner method that returns current camera zoom level/ratio
 *
 */
@protocol PinchZoomListener <NSObject>
/**
 * @brief Listner method that returns current camera zoom level/ratio
 * @param zoomratio returns current zoom ratio
 *
 */
- (void) currentZoomRatio:(CGFloat) zoomratio;
@end
