Pod::Spec.new do |s|
s.name = 'HHPodWXTest'
s.version = '1.0'
s.license = 'MIT'
s.summary = '牛奶微信登录测试.'
s.homepage = 'https://github.com/h451298138/PodTest'
s.authors = { 'HH' => '451298138@qq.com' }
s.source = { :git => 'https://github.com/h451298138/PodTest.git', :tag => s.version}
s.requires_arc = true
s.platform     = :ios
s.ios.deployment_target = '8.0'
s.source_files  = "WeChatLibDemo/WeChatStaticLib/**/*.{h,m}"
 s.resource_bundles = {
     'MyPodBundle' => ['WeChatLibDemo/WeChatStaticLib/**/*.xib']
 }
 s.libraries = "xml2","c++"
 s.xcconfig = { "Other Linker Flags" => "-lz" }
 s.vendored_libraries = 'WeChatLibDemo/**/*.a'
end



