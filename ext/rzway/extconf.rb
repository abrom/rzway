require 'mkmf'

HEADER_DIRS = ['libzway']
LIB_DIRS = ['lib']

dir_config('rzway', HEADER_DIRS, LIB_DIRS)

ENV['PATH'] = File.expand_path('lib', __FILE__) + ":#{ENV['PATH']}"
ENV['LD_LIBRARY_PATH'] = File.expand_path('lib', __FILE__) + ":#{ENV['LD_LIBRARY_PATH']}"

unless find_library('zway', 'zway_init')
  abort 'libzway is missing. Please install libzway'
end

create_makefile('rzway/rzway')
