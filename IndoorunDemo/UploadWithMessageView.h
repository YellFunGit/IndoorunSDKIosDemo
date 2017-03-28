//
//  UploadWithMessageView.h
//  YFTools
//
//  Created by ky on 31/10/2016.
//  Copyright © 2016 Sincere. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol UploadWithMessageViewDelegate <NSObject>

- (void)UploadWithMessageView:(id)sender ok:(BOOL)ok message:(NSString*)message;

@end

@interface UploadWithMessageView : UIView

@property(nonatomic, weak) id<UploadWithMessageViewDelegate> delegate;

@end
