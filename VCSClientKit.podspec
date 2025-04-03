#
# Be sure to run `pod lib lint VCSClientKit.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'VCSClientKit'
  s.version          = '0.1.2'
  s.summary          = 'VCSClientKit 集成UI的视频客服SDK'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/ti-net-project/VCSClientKit-iOS'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'gyb1314' => 'gyb_1314@126.com' }
  s.source           = { :git => 'https://github.com/ti-net-project/VCSClientKit-iOS.git', :tag => s.version.to_s }

  s.ios.deployment_target = '11.0'

  s.resource      = 'VCSClient.bundle'
  s.vendored_frameworks  = "VCSClientLib.xcframework","VCSClientKit.xcframework","AgoraRtmKit.xcframework","FTMobileSDK.xcframework"
  s.pod_target_xcconfig = {'VALID_ARCHS'=>'armv7 x86_64 arm64 armv7s'}
  # s.dependency 'AgoraRtcEngine_iOS', '4.3.0'
  s.dependency 'AgoraRtcEngine_iOS/RtcBasic', '4.3.0'
  s.dependency 'AgoraRtcEngine_iOS/ReplayKit', '4.3.0'
  #s.dependency 'AgoraRtm', '2.2.0'
  # s.dependency 'FTMobileSDK', '1.5.2'
end
