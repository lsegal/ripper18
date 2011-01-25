require "test/unit"
require File.dirname(__FILE__) + '/../lib/ripper'

class TestRipper < Test::Unit::TestCase
  def test_ripper
    sexp = Ripper.sexp("module Foo; def v=(value) value += 1 end end")
    assert_equal sexp, [:program, 
      [[:module, [:const_ref, [:@const, "Foo", [1, 7]]], [:bodystmt, [[:void_stmt], 
      [:def, [:@ident, "v=", [1, 16]], [:paren, [:params, [[:@ident, "value", [1, 19]]], 
      nil, nil, nil, nil]], [:bodystmt, [[:opassign, [:var_field, [:@ident, "value", 
        [1, 26]]], [:@op, "+=", [1, 32]], [:@int, "1", [1, 35]]]], nil, nil, nil]]], 
        nil, nil, nil]]]]
  end
end