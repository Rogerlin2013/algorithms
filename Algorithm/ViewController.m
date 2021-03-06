//
//  ViewController.m
//  Algorithm
//
//  Created by linyongzhi on 2018/10/4.
//  Copyright © 2018年 Beenlong. All rights reserved.
//

#import "ViewController.h"

#import "BLPair.h"
#import "BLDeduplication.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UITextField *inputTextField;
@property (weak, nonatomic) IBOutlet UILabel *resultLabel;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)action:(id)sender {
    [self deDuplication];
}

- (void)deDuplication {
    NSArray<NSNumber *> *inputArray = @[@(9), @(2), @(8), @(9), @(2), @(1), @(7), @(8), @(2)];
    
    [BLDeduplication deDuplication:inputArray];
}

- (void)Fibonacci {
    NSString *inputString = self.inputTextField.text;
    
    BLPair *pair = [BLPair FibPlus:inputString.integerValue];
    
    [self.resultLabel setText:[NSString stringWithFormat:@"Result: %@", pair.description]];
}

@end
