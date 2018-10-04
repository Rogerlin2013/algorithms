//
//  BLPair.m
//  Algorithm
//
//  Created by linyongzhi on 2018/10/4.
//  Copyright © 2018年 Beenlong. All rights reserved.
//

#import "BLPair.h"

@implementation BLPair

- (instancetype)initWithBig:(long)big small:(long)small {
    self = [super init];
    
    if (self) {
        self.big = big;
        self.small = small;
    }
    
    return self;
}

- (NSString *)description {
    return [NSString stringWithFormat:@"Pair: (%ld, %ld)\n", self.big, self.small];
}

+ (BLPair *)Fib:(NSInteger)n {
    if (n == 2) {
        return [[BLPair alloc] initWithBig:2 small:1];
    }else if (n == 1) {
        return [[BLPair alloc] initWithBig:1 small:1];
    }
    
    if (n % 2 == 0) {
        long FmPlus = [BLPair Fib: n / 2 + 1].small;
        long Fm = [BLPair Fib: n / 2].small;
        
        long big = FmPlus * FmPlus + Fm * Fm;
        long small = Fm * (2 * FmPlus - Fm);
        
        return [[BLPair alloc] initWithBig:big small:small];
    }else {
        long FmPlus = [BLPair Fib : n / 2 + 1].small;
        long Fm = [BLPair Fib: n / 2].small;
        
        long big = FmPlus * (FmPlus + 2 * Fm);
        long small = FmPlus * FmPlus + Fm * Fm;
        
        return [[BLPair alloc] initWithBig:big small:small];
    }
}

+ (BLPair *)FibPlus:(NSInteger)n {
    if (n > 0) {
        BLPair *pair = [BLPair FibPlus: n / 2];
        long FmPlus = pair.big;
        long Fm = pair.small;
        
        if (n % 2 == 0) {
            long big = FmPlus * FmPlus + Fm * Fm;
            long small = Fm * (2 * FmPlus - Fm);
            
            return [[BLPair alloc] initWithBig:big small:small];
        }else {
            long big = FmPlus * (FmPlus + 2 * Fm);
            long small = FmPlus * FmPlus + Fm * Fm;
            
            return [[BLPair alloc] initWithBig:big small:small];
        }
    }
    
    return [[BLPair alloc] initWithBig:1 small:0];
}

@end
