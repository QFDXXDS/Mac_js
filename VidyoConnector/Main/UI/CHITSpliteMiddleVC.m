//
//  CHITListVC.m
//  VidyoConnector
//
//  Created by Xianxiangdaishu on 2019/6/20.
//  Copyright © 2019 Vidyo. All rights reserved.
//

#import "CHITSpliteMiddleVC.h"
#import "HConferenceRootModel.h"
#import "CHITTableBackView.h"
#import "CHITConfCell.h"


@interface CHITSpliteMiddleVC ()<NSTabViewDelegate,NSTableViewDataSource>

@property (weak) IBOutlet NSTableView *tableView;

@property (nonatomic,strong)NSMutableArray *tableArray;
@property (nonatomic,strong)CHITTableBackView *tableBackView;
@end

@implementation CHITSpliteMiddleVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do view setup here.
    [self initData];
    [self initView];
    
}
- (void)initData {
    
    _tableArray = [[NSMutableArray alloc]init];
}
- (void)initView {
    
    _tableView.target = self ;
    _tableView.action = @selector(didSelectTabViewItem) ;
    _tableView.delegate = self ;
    _tableView.dataSource = self ;
    [_tableView registerNib:[[NSNib alloc] initWithNibNamed:@"CHITConfCell" bundle:nil] forIdentifier:@"CELL"];
}
//2019-06-26 15:51:04.391499+0800 VidyoConnector[1237:3734308] POST-{
//    userToken = 1B1792E797E711E99FC6E1C068C81D49;
//}-http://cossdev.byshang.cn:7010/jc-portal/rest/conference/list
//
//2019-06-26 15:51:56.609731 长虹极视[2646:948574] POST-{
//    userToken = 04E0C69497E711E99FC6E1C068C81D49;
//}-http://cossdev.byshang.cn:7010/jc-portal/rest/conference/list

- (void)updateView {
    
    [self sendRequest:nil];
}

- (void)sendRequest:(void(^)(void))blcok{
    
    [CHITService confListWithUserId:[CTUserManager userid] success:^(id results) {
        
        HConferenceRootModel * confModel = [[HConferenceRootModel alloc] initWithDictionary:results error:nil];
        [self.tableArray removeAllObjects];
        
        [self.tableArray addObjectsFromArray:confModel.conferences];
        if (self.tableArray.count > 0) {
            _tableBackView.hidden = YES;
        } else {
            _tableBackView.hidden = NO;
        }
        [self.tableView reloadData];
    } fail:^(NSError *error) {

    }];
    
}

//- (BOOL)tabView:(NSTabView *)tabView shouldSelectTabViewItem:(nullable NSTabViewItem *)tabViewItem;
//- (void)tabView:(NSTabView *)tabView willSelectTabViewItem:(nullable NSTabViewItem *)tabViewItem;

- (void)didSelectTabViewItem {
    
    HConferenceModel *model =  _tableArray[_tableView.selectedRow] ;
    
    NSAlert *alert = [[NSAlert alloc] init];
    [alert setMessageText:@"确认加入会议"];
    [alert setInformativeText:@"即将加入谁的房间-9090809"];
    [alert addButtonWithTitle:@"确定"];
    [alert addButtonWithTitle:@"取消"];
    
    [alert setAlertStyle:NSAlertStyleInformational];
    
    [alert beginSheetModalForWindow:self.view.window completionHandler:^(NSModalResponse returnCode) {
        
//        点击确定
        if (returnCode == 1000) {
            
            [CHITService roomNumber:nil conferenceId:model.conferenceId subject:nil userName:nil invitedUsers:nil invitedTerminals:nil login:YES];
            
        } else {
            
            
        }
        
    }];
}

- (void)tabView:(NSTabView *)tabView didSelectTabViewItem:(nullable NSTabViewItem *)tabViewItem {
    
    
    NSAlert *alert = [[NSAlert alloc] init];
    [alert setMessageText:@"确认加入会议"];
    [alert setInformativeText:@"即将加入谁的房间-9090809"];
    [alert addButtonWithTitle:@"确定"];
    [alert addButtonWithTitle:@"取消"];
    
    [alert setAlertStyle:NSAlertStyleInformational];

    [alert beginSheetModalForWindow:self.view.window completionHandler:^(NSModalResponse returnCode) {
        
        if (returnCode == 0) {
            
            
        }
    }];
    
}
//- (void)tabViewDidChangeNumberOfTabViewItems:(NSTabView *)tabView;



- (NSInteger)numberOfRowsInTableView:(NSTableView *)tableView {
    
    return _tableArray.count;
}

- (nullable NSView *)tableView:(NSTableView *)tableView viewForTableColumn:(nullable NSTableColumn *)tableColumn row:(NSInteger)row NS_AVAILABLE_MAC(10_7){
    
    CHITConfCell *cell = [tableView makeViewWithIdentifier:@"CELL" owner:self];
    
    cell.confModel = _tableArray[row];
    return cell;

}

- (nullable id)tableView:(NSTableView *)tableView objectValueForTableColumn:(nullable NSTableColumn *)tableColumn row:(NSInteger)row {
    
    return [_tableArray objectAtIndex:row];
}




@end
