//
//  UploadWithMessageView.m
//  YFTools
//
//  Created by ky on 31/10/2016.
//  Copyright © 2016 Sincere. All rights reserved.
//

#import "UploadWithMessageView.h"

@interface UploadWithMessageView()

@property (nonatomic, weak) IBOutlet UIView *ibBg;
@property (nonatomic, weak) IBOutlet UITextView *ibTextView;

@end

@implementation UploadWithMessageView

- (void)awakeFromNib {
    
    [super awakeFromNib];
    
    _ibBg.layer.cornerRadius = 5;
    
    _ibTextView.layer.cornerRadius = 5;
    
    self.backgroundColor = [UIColor colorWithRed:1 green:1 blue:1 alpha:0.2];
}

- (IBAction)onOk:(id)sender {
    
    [_delegate UploadWithMessageView:self ok:YES message:_ibTextView.text];
    
    [self removeFromSuperview];
}

- (IBAction)onCancel:(id)sender {
    
    [self removeFromSuperview];
}

- (IBAction)onBgClick:(id)sender {
    
    [_ibTextView resignFirstResponder];
}

@end
