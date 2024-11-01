//
//  DLResultListener.h
//  SwiftDecoder
//

#import "LicenseData.h"
@protocol DLResultListener <PluginResultListener>


-(void) onDLResult:(LicenseData*) dlResult;

@end
