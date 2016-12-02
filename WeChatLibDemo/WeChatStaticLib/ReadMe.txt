所有回调都是在主线程回调，可以直接写更新界面的代码

配置：
需要添加
引用库libxml2.tbd
在build settings里linking的Other linker flags设置-lz

需要在程序入口处初始化
#import "WeChatApi.h"
[WeChatApi init];
