require 'rbconfig'

def exec(cmd)
  system "#{cmd}" or exit
end

def isMacOS?
  (RbConfig::CONFIG['host_os'] =~ /darwin|mac os/) != nil
end

def compiler 
  isMacOS? ? 'CC=/usr/bin/clang CXX=/usr/bin/clang++' : ''
end

def do_build(path, test, action)
  testing = "-DENABLE_TEST=#{test}"
  building = "-DCMAKE_BUILD_TYPE=Debug"
  
  prep = "mkdir -p #{path}/build && cd #{path}/build"
  make = "#{compiler} cmake #{testing} #{building} .. && make"
  
  sh "#{prep} && #{make} && #{action}"
end

def do_clean(modular)
  system "sudo rm -rf /usr/local/include/#{modular}"
  system "sudo rm -rf /usr/local/lib/lib#{modular}.a"
end

def do_install(path) 
  do_build(path, "off", "sudo make install")
end

def do_test(path, modular)
  do_build(path, "on", "test/#{modular}-test")
end

DEPS = %w[cub cum cpo]

task :clone_deps do
  system "rm -rf lib/cub"
  sh "git clone https://github.com/ccock/cub.git lib/cub"
end

task :uninstall_deps do
  DEPS.each { |m| do_clean(m) }
end

task :clean_deps => :uninstall_deps do
  DEPS.each { |m| sh "cd lib/#{m} && rm -rf build" }
end

task :test_deps => :install_deps do
  DEPS.each { |m| do_test("lib/#{m}", m) }
end

task :install_deps => :uninstall_deps do
  DEPS.each { |m| do_install("lib/#{m}") }
end

task :uninstall do
  do_clean :cut
end

task :clean => :uninstall do
  sh 'rm -rf build'
end

task :test => :install do
  do_test('.', :cut)
end

task :install => :uninstall do
  do_install('.')
end

task :all => [:clone_deps, :install_deps, :install, :test_deps, :test]
task :default => :all