#
# Be sure to run `pod lib lint EAModularity.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'EABluetooth'
  s.version          = '1.0.68.4'
  s.summary          = 'A short description of EABluetooth.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/EastApex/EASDKTool_iOS'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Aye' => 'aye.zhang@qq.com' }
  s.source           = { :git => 'https://github.com/EastApex/EASDKTool_iOS.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'

  s.source_files = 'SDK_File/EABluetooth/Classes/**/*'
  
  # s.resource_bundles = {
  #   'EAModularity' => ['EAModularity/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'

  s.dependency 'Protobuf'
  s.dependency 'YYKit'
  s.dependency 'Realm'  # realm 数据库
  s.dependency 'SAMKeychain'

  
# s.resources = "Resources/*"  #工程需要引入的资源文件（图片，xib等）
   s.resource_bundles = {'EAWatchFace' => ['SDK_File/EAWatchFace.bundle/*']} #工程需要引入的bundle
  s.ios.vendored_frameworks = 'SDK_File/EABluetooth.framework'




  
end
