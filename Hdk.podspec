#
# Be sure to run `pod lib lint Hdk.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'Hdk'
  s.version          = '1.0.4'
  s.summary          = '好单库流量变现SDK'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = "好单库官方流量变现 SDK for iOS"

  s.homepage         =  'https://github.com/haodanku/bianxian_sdk_ios'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'WJCha' => 'weejie_chen@icloud.com' }
  s.source           = { :git => 'https://github.com/haodanku/bianxian_sdk_ios.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

#  s.ios.deployment_target = '9.0'

#  s.source_files = 'Hdk/Classes/**/*'
  
#  s.requires_arc = true
  s.resource = 'Hdk/Assets/HdkSDKResource.bundle'
  s.vendored_frameworks = 'Hdk/Classes/*.framework'
  s.frameworks  = 'UIKit', 'Foundation', 'WebKit'

  s.platform     = :ios, '9.0'
  s.ios.deployment_target = '9.0'
  
  s.pod_target_xcconfig = {
     'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
   }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  
  
  # s.resource_bundles = {
  #   'Hdk' => ['Hdk/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
