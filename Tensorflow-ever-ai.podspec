Pod::Spec.new do |s|
  
  s.name            = 'Tensorflow-ever-ai'
  s.version         = '1.2.0'
  s.summary         = 'Ever.ai Tensorflow Fork'
  s.homepage        = 'https://github.com/everalbum/tensorflow'
  s.license         = 'MIT'
  s.author          = { 'ever.ai' => 'ops@ever.ai' }
  
  s.platform        = :ios, '9.0'
  
  s.source          = { :http => 'https://download.everalbum.com/ios/deps/tensorflow/#{s.version}/tensorflow.zip' }
  s.preserve_paths  = 'include/**'
  
  s.ios.framework  = 'Accelerate'
  s.ios.vendored_libraries = 'lib/libtensorflow-core.a', 'lib/libprotobuf-lite.a', 'lib/libprotobuf.a'

  s.xcconfig = { 
    'HEADER_SEARCH_PATHS' => [
      '${PODS_ROOT}/#{s.name}/include',
      '${PODS_ROOT}/#{s.name}/include/tensorflow/contrib/makefile/downloads/protobuf/src',
      '${PODS_ROOT}/#{s.name}/include/tensorflow/contrib/makefile/downloads',
      '${PODS_ROOT}/#{s.name}/include/tensorflow/contrib/makefile/downloads/eigen',
      '${PODS_ROOT}/#{s.name}/include/tensorflow/contrib/makefile/gen/proto',
    ],
    'OTHER_LDFLAGS' => '-force_load $(PODS_ROOT)/#{s.name}/lib/libtensorflow-core.a' 
  }
  s.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }

end