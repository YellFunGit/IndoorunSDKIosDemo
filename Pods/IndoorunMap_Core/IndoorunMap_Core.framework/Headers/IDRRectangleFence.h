//
//  IDRRectangleFence.h
//  IndoorunMap_Core
//
//  Created by ky on 27/12/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import "IDRFence.h"

@interface IDRRectangleFence : IDRFence

@property (nonatomic) IDRPosition *leftTop;

@property (nonatomic) IDRPosition *rightBottom;

- (id)init:(IDRPosition*)leftTop rightBottom:(IDRPosition*)rightBottom enterBlock:(void(^)(IDRFence *fence))enterBlock leaveBlock:(void(^)(IDRFence *fence))leaveBlock;

@end
