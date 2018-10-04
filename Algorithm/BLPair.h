//
//  BLPair.h
//  Algorithm
//
//  Created by linyongzhi on 2018/10/4.
//  Copyright © 2018年 Beenlong. All rights reserved.
//  使用矩阵的幂次推导出的公式计算Fibonacci

#import <Foundation/Foundation.h>

@interface BLPair : NSObject

@property (assign, nonatomic) long big;
@property (assign, nonatomic) long small;

+ (BLPair *)Fib:(NSInteger)n;

+ (BLPair *)FibPlus:(NSInteger)n;

- (instancetype)initWithBig:(long)big small:(long)small;

@end
