//
//  ContactTableViewCell.h
//  WeChatRedBag
//
//  Created by srulos on 16/3/8.
//  Copyright © 2016年 srulos. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ContactTableViewCell : UITableViewCell
@property (weak, nonatomic) IBOutlet UIImageView *m_imgHead;
@property (weak, nonatomic) IBOutlet UILabel *m_labelName;
@property (weak, nonatomic) IBOutlet UILabel *m_labelTime;

@end
