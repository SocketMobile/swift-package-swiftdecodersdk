//
//  MasterListScanView.h
//  SwiftDecoder
//
//  Created by K N, Vinod on 05/05/25.
//

#import <UIKit/UIKit.h>
#import "AROverlayView.h"
NS_ASSUME_NONNULL_BEGIN

@interface MasterListScanView : AROverlayView

@property(nonatomic,assign) BOOL isPresent;

-(void)setImageForScan:(UIImage *)image;
@end

NS_ASSUME_NONNULL_END
