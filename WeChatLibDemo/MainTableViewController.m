//
//  MainTableViewController.m
//  WeChatLibDemo
//
//  Created by mac on 16/4/11.
//  Copyright © 2016年 mac. All rights reserved.
//

#import "MainTableViewController.h"
#import "WeChatApi.h"

#import "ContactTableViewCell.h"

@interface MainTableViewController ()
{
    NSMutableArray * m_chatRooms;//群列表
    NSMutableArray * m_contacts;//好友列表
}
@end

@implementation MainTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"联系人";
    
    m_contacts = [[NSMutableArray alloc]init];
    m_chatRooms = [[NSMutableArray alloc]init];
    
    NSLog(@"正在初始化...");
    
    __block UITableView * tableView = self.tableView;
    [[AsyncWeChatSimulationService stander] asyncWXInit:^(WX_INIT_RESULT initResult) {
        if (initResult == WIR_SUCCESS) {
            NSLog(@"加载成功!");
            
            //获取好友列表和群列表
            m_contacts = [AsyncWeChatSimulationService stander].m_contacts;
            m_chatRooms = [AsyncWeChatSimulationService stander].m_chatRooms;
            [tableView reloadData];
        }
        else if(initResult == WIR_GET_USER_INFO_FAIL){
            NSLog(@"获取用户信息失败！");
        }
        else if(initResult == WIR_INIT_FAIL){
            NSLog(@"初始化微信失败！");
        }
        else if(initResult == WIR_GET_CONTACT_FAIL){
            NSLog(@"获取联系人列表失败！");
        }
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 2;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    if (section == 0) {
        return m_chatRooms.count;
    }
    else {
        return m_contacts.count;
    }
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    WeChatContactModel * contactModel = nil;
    
    if (indexPath.section == 0) {
        contactModel = [m_chatRooms objectAtIndex:indexPath.row];
    }
    else{
        contactModel = [m_contacts objectAtIndex:indexPath.row];
    }
    
    ContactTableViewCell * contactTableViewCell = (ContactTableViewCell*)[tableView dequeueReusableCellWithIdentifier:@"ContactTableViewCell"];;
    if (contactTableViewCell == nil) {
        contactTableViewCell = [[[NSBundle mainBundle] loadNibNamed:@"ContactTableViewCell" owner:self options:nil] lastObject];
    }
    
    if (contactModel.m_remarkName != nil && contactModel.m_remarkName.length > 0) {
        contactTableViewCell.m_labelName.text = contactModel.m_remarkName;
    }
    else{
        contactTableViewCell.m_labelName.text = contactModel.m_nickName;
    }
    
    
    [[AsyncWeChatSimulationService stander]asyncGetHeadImg:contactModel.m_userName respBlock:^(UIImage *headImage) {
        [contactTableViewCell.m_imgHead setImage:headImage];
    }];
    
    return contactTableViewCell;
}

- (NSString*)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section{
    if (section == 0) {
        return @"群";
    }
    else{
        return @"联系人";
    }
}


@end
