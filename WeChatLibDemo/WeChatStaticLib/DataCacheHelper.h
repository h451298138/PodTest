//
//  QQCacheHelper.h
//  NewMedia
//
//  Created by mac on 15/3/11.
//  Copyright (c) 2015年 zk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class MHttpRequest;
@interface QQCacheRequest : NSObject
enum DATA_TYPE{
    DT_IMAGE,
    DT_DATA,
};

@property(nonatomic,retain) NSString * _httpUrl;
@property(nonatomic,retain) UIImageView * _imageView;
@property enum DATA_TYPE _dataType;
@property id _delegate;
@property SEL _selector;
@property id _backCode;
@end

@interface DataCacheHelper : NSObject
{
    NSMutableDictionary * _dicRequestingUrl;
    NSMutableDictionary * _dicData;
}
//
+ (DataCacheHelper *)standard;
-(void)writeFile:(NSData *)data fileName:(NSString *)fileHttpUrl;
-(void)deleteFile:(NSString *)fileHttpUrl;
-(NSString*)getFileName:(NSString*)fileHttpUrl;
-(NSData*)getFile:(NSString*)fileHttpUrl;
-(NSString*)getCacheDirectoryPath;
-(BOOL)fileExistsAtPath:(NSString*)filePath isDirectory:(BOOL)isDirectory;
//
- (UIImage*)getImage:(NSString *)httpUrl imageView:(UIImageView*)imageView scale:(CGFloat)scale;
//
- (UIImage*)getImage:(NSString *)httpUrl imageView:(UIImageView*)imageView scale:(CGFloat)scale delegate:(id)delegate selector:(SEL)selector backCode:(id)backCode;
//
- (void)getData:(NSString*)httpUrl delegate:(id)delegate selector:(SEL)selector backCode:(id)backCode;
//return deletefile dataSize byte
- (double)clearFileCacheData;
//return dataSize byte
- (double)getCacheDataSize;
//
- (void)clearMemoryCacheData;
@end
