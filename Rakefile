require 'rake/extensiontask'
require './lib/rzway/version'

spec = Gem::Specification.new do |s|
  s.name        = 'rzway'
  s.version     = RZWay::Version
  s.summary     = 'Ruby wrapper around the ZWay C library'
  s.description = 'Ruby wrapper around the zway C library'
  s.authors     = ['Andrew Bromwich']
  s.email       = 'andrew@bromwi.ch'
  s.files       = FileList['lib/rzway.rb', 'lib/rzway/rzway.bundle', 'ext/lib/*'].to_a
  s.extensions  = ['ext/rzway/extconf.rb']
  s.homepage    = 'http://github.com/abrom/rzway'
  s.license     = 'MIT'
end

Gem::PackageTask.new(spec) do |pkg|
end

Rake::ExtensionTask.new do |ext|
  ext.name     = 'rzway'
  ext.ext_dir  = 'ext/rzway'
  ext.lib_dir  = 'lib/rzway'
  ext.gem_spec = spec
end
