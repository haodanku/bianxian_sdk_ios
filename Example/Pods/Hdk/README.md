# Hdk

[![CI Status](https://img.shields.io/travis/WJCha/Hdk.svg?style=flat)](https://travis-ci.org/WJCha/Hdk)
[![Version](https://img.shields.io/cocoapods/v/Hdk.svg?style=flat)](https://cocoapods.org/pods/Hdk)
[![License](https://img.shields.io/cocoapods/l/Hdk.svg?style=flat)](https://cocoapods.org/pods/Hdk)
[![Platform](https://img.shields.io/cocoapods/p/Hdk.svg?style=flat)](https://cocoapods.org/pods/Hdk)

# 一、集成 SDK
## 方式一：CocoaPods 引入

<br />**第一步：在工程的 Podfile 里面添加以下代码：**
```ruby
pod 'Hdk'
```
**第二步：运行 **`**pod install**`** 命令安装 SDK**<br />如果找不到库，先执行 pod repo update。对于首次查找，可能需要删除索引文件，再通过 `pod search Hdk` 重新生成索引文件。
```shell
# 终端输入以下指令，删除索引文件
rm ~/Library/Caches/CocoaPods/search_index.json
```
## 方式二：手工导入
**下载 SDK 包**<br />点击 [Hdk](http://files-fqapps-com.cdn.fudaiapp.com/app-hdksdk2-20210818-183954.zip) 下载 SDK 包。<br />​

**集成 Framwork**

1. 将下载包解压后找到 **Hdk.framework** 静态库文件及其资源包 copy 或拖拽到工程中。

![image.png](https://cdn.nlark.com/yuque/0/2021/png/22021491/1628924578093-a611629c-d628-40cd-b90c-5109a90dcd9d.png#clientId=u9b14c792-06d5-4&from=paste&height=224&id=u8c818d05&margin=%5Bobject%20Object%5D&name=image.png&originHeight=448&originWidth=508&originalType=binary&ratio=1&size=273867&status=done&style=none&taskId=u9a126241-19ee-41f9-aad3-e1aa02a2f93&width=254)

2. 然后在 Target -> General -> Frameworks, Libraries,and Embedded Content 添加 Hdk.framework。

![image.png](https://cdn.nlark.com/yuque/0/2021/png/22021491/1628926219976-bae6d3ce-ab5e-4fec-be97-f701d86492b9.png#clientId=uc1774e45-a8cc-4&from=paste&height=170&id=BZG5r&margin=%5Bobject%20Object%5D&name=image.png&originHeight=340&originWidth=1070&originalType=binary&ratio=1&size=31896&status=done&style=none&taskId=u8f0d0279-1264-431b-a0fa-515cc0852ed&width=535)<br />

# 二、工程配置

- **添加编译参数，在 TARGETS->Build Settings->Other Linker Flags 增加 **`**-ObjC**`** ，注意大小写。**

![image.png](https://cdn.nlark.com/yuque/0/2021/png/22021491/1628921097333-4fb6e84b-1434-418c-89ac-0a5c4716223c.png#clientId=u97d89b08-e395-4&from=paste&height=356&id=ude3659e3&margin=%5Bobject%20Object%5D&name=image.png&originHeight=712&originWidth=1400&originalType=binary&ratio=1&size=127059&status=done&style=none&taskId=ud271a4b4-219d-4d8b-b5b8-9a3fcfacc84&width=700)<br />​<br />

- **info.plist 配置 ATS, 允许 HTTP 请求。**

![image.png](https://cdn.nlark.com/yuque/0/2021/png/22021491/1628921298926-3deec292-96f3-4bac-b850-c799e7a9948e.png#clientId=u97d89b08-e395-4&from=paste&height=41&id=u19e1baa9&margin=%5Bobject%20Object%5D&name=image.png&originHeight=82&originWidth=1216&originalType=binary&ratio=1&size=18402&status=done&style=none&taskId=u22a89188-cca1-4cf7-b314-88f3390ff3e&width=608)<br />

- **关闭 Bitcode**

![image.png](https://cdn.nlark.com/yuque/0/2021/png/22021491/1628921374967-72b85ec6-de51-4b69-b7d2-ec76a1b7d886.png#clientId=u97d89b08-e395-4&from=paste&height=147&id=u7abb179d&margin=%5Bobject%20Object%5D&name=image.png&originHeight=294&originWidth=1334&originalType=binary&ratio=1&size=41598&status=done&style=none&taskId=ucb883392-27f2-48f0-80be-f94ed96edc8&width=667)<br />​<br />

- **info.plist 配置相册使用权限**
```xml
    <key>NSPhotoLibraryAddUsageDescription</key>
    <string>该标识符用于请求相册访问</string>

    <key>NSPhotoLibraryUsageDescription</key>
    <string>该标识符用于请求相册访问</string>
```


- **info.plist 配置位置访问权限**
```xml
<key>NSLocationWhenInUseUsageDescription</key>
<string>该标识符用于请求位置信息</string>
```


- **info.plist  增加 **`LSApplicationQueriesScheme`** 添加白名单**
```xml
    <key>LSApplicationQueriesSchemes</key>
    <array>
        <string>tbopen</string>
        <string>tmall</string>
        <string>wechat</string>
        <string>weixin</string>
        <string>alipays</string>
        <string>aplipayshare</string>
        <string>alipay</string>
        <string>pinduoduo</string>
        <string>openApp.jdMobile</string>
        <string>openapp.jdmobile</string>
        <string>vipshop</string>
        <string>suning</string>
        <string>kaola</string>
        <string>youpin</string>
        <string>imeituan</string>
        <string>meituanwaimai</string>
        <string>sinaweibo</string>
        <string>tenvideo</string>
        <string>iqiyi</string>
        <string>baidumap</string>
        <string>iosamap</string>
        <string>appleMap</string>
        <string>qqmap</string>
    </array>
```


- **IDFA 采集**

SDK 默认采集 IDFA 标识，用来分析核对数据，从 iOS 14 开始，若开发者设置 App Tracking Transparency 向用户申请跟踪授权，在用户授权之前 IDFA 将不可用。 如果用户拒绝此请求，应用获取到的 IDFA 为空。<br />要获取 App Tracking Transparency 权限，请更新您的 Info.plist，添加 NSUserTrackingUsageDescription 字段和自定义文案描述。
```xml
<key>NSUserTrackingUsageDescription</key>
<string>该标识符将用于向您投放个性化广告</string>
```
向用户申请权限时，请调用 `requestTrackingAuthorizationWithCompletionHandler:`方法。
```objectivec
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <AdSupport/AdSupport.h>
  
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [self requestIDFA];
    return YES;
}

- (void)requestIDFA {
    if (@available(iOS 14, *)) {
        [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
            // Tracking authorization completed. 
        }];
    } else {
        // Fallback on earlier versions
    }
}
```
对于宿主应用本身原来没有获取 IDFA 的情况，将应用提交至 AppStore 时要注意 APP 隐私的设置。<br />​

​<br />
# 三、SDK 使用
## 初始化方法
```objectivec
#import <Hdk/Hdk.h>

/// note: 初始化前请确保已经获得网络访问权限。
[[Hdk shareInstance] initWithAppKey:@"Your AppKey" appSecret:@"Your AppSecret" onResult:^(int code, NSString * _Nonnull message) {
    if (code == 200) { // Success } 
}];
```


## Log 打印
如果想打开日志，可以通过以下方式设置：
```objectivec
#ifdef DEBUG
    [[Hdk shareInstance] setDebug:YES];
#else
    [[Hdk shareInstance] setDebug:NO];
#endif
```
## 打开好单库页面
通过 Hdk 操作类，使用以下方法，可以在相应的控制器通过打开好单库页面。SDK 内部将采用 present 的形式弹出。
```objectivec
#import <Hdk/Hdk.h>

/// 打开页面
/// @param controller 控制器
- (BOOL)openIndexPageFromViewController:(UIViewController *)controller;
```
具体用法：
```objectivec
// UIViewController.h

[[Hdk shareInstance] openIndexPageFromViewController:self];
```


## License

Hdk is available under the MIT license. See the LICENSE file for more info.


