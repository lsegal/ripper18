#!ruby -s

require 'mkmf'
require 'rbconfig'
require 'fileutils'

def main
  unless find_executable('bison')
    unless File.exist?('ripper.c') or File.exist?("#{$srcdir}/ripper.c")
      Logging.message 'missing bison; abort'
      return
    end
  end
  $objs = %w(ripper.o)
  $cleanfiles.concat %w(ripper.y ripper.c ripper.E ripper.output y.output eventids1.c eventids2table.c)
  $defs << '-DRIPPER'
  $defs << '-DRIPPER_DEBUG' if $debug
  $VPATH = []
  if RUBY_VERSION < "1.9.1"
    $INCFLAGS << ' -I$(srcdir)/backports'
  else
    $INCFLAGS << ' -I$(srcdir)/extra'
  end
  create_makefile 'ripper'
end

main
