Pod::Spec.new do |s|

  s.name            = "Tensorflow-ever-ai"
  s.version         = "1.4.0"
  s.summary         = "Ever.ai Tensorflow Fork"
  s.homepage        = "https://github.com/everalbum/tensorflow"
  s.license         = "MIT"
  s.author          = { "ever.ai" => "ops@ever.ai" }

  s.platform        = :ios, "9.0"

  s.source          = { :http => "https://download.everalbum.com/ios/deps/tensorflow/#{s.version}/tensorflow.zip" }
  s.preserve_paths  = "include/**"

  s.ios.framework  = "Accelerate"
  s.ios.vendored_libraries = 'lib/libtensorflow-core-eai.a', 'lib/libprotobuf-lite-eai.a', 'lib/libprotobuf-eai.a', 'lib/nsync-eai.a'
  s.module_name = 'tensorflow'
  s.xcconfig = {
    "HEADER_SEARCH_PATHS" => "\"${PODS_ROOT}/#{s.name}/include\" \"${PODS_ROOT}/#{s.name}/include/third_party/eigen3\" \"${PODS_ROOT}/#{s.name}/include/third_party/nsync\"",
    "OTHER_LDFLAGS" => "-lc++ $(PODS_ROOT)/#{s.name}/lib/nsync-eai.a -force_load $(PODS_ROOT)/#{s.name}/lib/libtensorflow-core-eai.a"
  }
  s.pod_target_xcconfig = { "ENABLE_BITCODE" => "NO" }


# Must add the following to your Podfile...sorry :(
#   post_install do |installer|
#     path = installer.sandbox.target_support_files_root.to_path.gsub("\s", "\\\s")
#     system("sed -i \"\" 's/-l\"nsync-eai\"//g' #{path}/**/*.xcconfig")
#   end


end
