SPEC = Gem::Specification.new do |s|
  s.name          = "ripper"
  s.summary       = "Ripper parses Ruby source and tokenizes or builds an AST" 
  s.description   = <<-eof
    This gem is meant for Ruby 1.8.x builds. Ruby 1.9.x comes with a functioning
    ripper implementation out of the box. This gem is a port of the Ripper 1.9
    for Ruby 1.8.x. Ripper was written by Minero Aoki and ported by Loren Segal.
  eof
  s.version       = "1.0.0"
  s.date          = "2011-01-11"
  s.authors       = ["Loren Segal", "Minero Aoki"]
  s.email         = "lsegal@soen.ca"
  s.homepage      = "http://github.com/lsegal/ripper"
  s.files         = Dir.glob("{lib,ext}/**/*") + ['Rakefile', 'README']
  s.require_paths = ['lib', 'ext']
  s.extensions    = ['ext/extconf.rb']
  s.has_rdoc      = false
end