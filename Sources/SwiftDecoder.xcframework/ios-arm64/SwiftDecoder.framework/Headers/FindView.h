//
//  FindView.h
//  SwiftDecoder
//
//  Created by H454944 on 27/09/23.
//

#import <UIKit/UIKit.h>
#import "AROverlayView.h"
#import "FindLayoutDataSource.h"
#import "SearchFindListener.h"
NS_ASSUME_NONNULL_BEGIN

@interface FindView : AROverlayView

@property(nonatomic,weak) id<FindLayoutDataSource> datasource;
@property(nonatomic,assign) BOOL isPresent;


-(id)initWithDataSource:(id<FindLayoutDataSource>) dataSource withDelegate:(id<SearchFindListener>) searchListener;
-(void)setImageForScan:(UIImage *)image;

@end

NS_ASSUME_NONNULL_END
