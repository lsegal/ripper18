require 'rubygems'
require 'rake/gempackagetask'
require 'rake/testtask'

WINDOWS = (PLATFORM =~ /win32|cygwin/ ? true : false) rescue false
SUDO = WINDOWS ? '' : 'sudo'

desc "Builds the gem"
task :gem do
  sh "cd ext && make clean"
  load 'ripper.gemspec'
  Gem::Builder.new(SPEC).build
end

desc "Installs the gem"
task :install => :gem do 
  sh "#{SUDO} gem install #{SPEC.name}-#{SPEC.version}.gem --no-rdoc --no-ri"
end

desc 'Build the extension'
task :build do
  sh "cd ext && ruby extconf.rb && make clean && make"
end

Rake::TestTask.new

