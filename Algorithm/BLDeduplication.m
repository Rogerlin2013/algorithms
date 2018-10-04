//
//  BLDeduplication.m
//  Algorithm
//
//  Created by linyongzhi on 2018/10/4.
//  Copyright © 2018年 Beenlong. All rights reserved.
//

#import "BLDeduplication.h"

@implementation BLDeduplication

+ (void)deDuplication:(NSArray<NSNumber *> *)inputArray {
    if (!inputArray || inputArray.count < 1) {
        return;
    }
    
    // sort
    NSArray<NSNumber *> *sortedArray = [inputArray sortedArrayUsingComparator:^NSComparisonResult(id  _Nonnull obj1, id  _Nonnull obj2) {
        return [obj1 compare:obj2];
    }];
    
    NSInteger left = 0;
    NSInteger right = left + 1;
    
    while (left < sortedArray.count) {
        for (right = left + 1; right < sortedArray.count; ++right) {
            if (![sortedArray[right] isEqualToNumber:sortedArray[left]]) {
                break;
            }
        }
        
        NSLog(@"%@: %d\n", sortedArray[left], (uint32_t)(right - left));
        left = right;
    }
}

@end
