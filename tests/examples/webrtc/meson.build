examples = ['webrtc', 'webrtcbidirectional', 'webrtcswap', 'webrtctransceiver', 'webrtcrenego']

foreach example : examples
  exe_name = example
  src_file = '@0@.c'.format(example)

  executable(exe_name,
    src_file,
    install: false,
    include_directories : [configinc],
    dependencies : [glib_dep, gst_dep, gstwebrtc_dep],
    c_args : ['-DHAVE_CONFIG_H=1', '-DGST_USE_UNSTABLE_API'],
  )
endforeach

