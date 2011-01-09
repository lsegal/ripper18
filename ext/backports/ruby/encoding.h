/**********************************************************************

  encoding.h -

  $Author: matz $
  created at: Thu May 24 11:49:41 JST 2007

  Copyright (C) 2007 Yukihiro Matsumoto

**********************************************************************/

#ifndef RUBY_ENCODING_H
#define RUBY_ENCODING_H 1

#include <stdarg.h>

typedef struct rb_encoding_s {
	int ruby_encoding_index;
	int min_enc_len;
	char *name;
} rb_encoding;

static rb_encoding __default_encoding_s = {1, 1, "default"};
static rb_encoding *__default_encoding = &__default_encoding_s;
int rb_char_to_option_kcode(int c, int *option, int *kcode) { return 0; }

#define ENC_CODERANGE_7BIT 0
#define ENC_CODERANGE_UNKNOWN -1
#define rb_enc_str_coderange(s) ENC_CODERANGE_7BIT
#define MBCLEN_CHARFOUND_P(x) 1
#define rb_enc_str_new(s,l,e) rb_str_new(s,l)
#define rb_enc_reg_new(s,l,e,i) rb_reg_new(s,l,i)
#define rb_external_str_new_with_enc(s,l,e) rb_str_new(s,l)
#define rb_enc_from_index(idx) 0
#define rb_enc_find(name) 0
#define rb_enc_name(enc) (enc)->name
#define rb_enc_mbminlen(enc) (enc)->min_enc_len
#define rb_enc_mbmaxlen(enc) (enc)->max_enc_len
#define rb_enc_mbclen(p,e,enc) (e-p)
#define rb_enc_fast_mbclen(p,e,enc) (e-p)
#define rb_enc_isascii(c,enc) isascii(c)
#define rb_enc_isalpha(c,enc) isalpha(c)
#define rb_enc_islower(c,enc) islower(c)
#define rb_enc_isupper(c,enc) isupper(c)
#define rb_enc_ispunct(c,enc) ispunct(c)
#define rb_enc_isalnum(c,enc) isalnum(c)
#define rb_enc_isprint(c,enc) isprint(c)
#define rb_enc_isspace(c,enc) isspace(c)
#define rb_enc_isdigit(c,enc) isdigit(c)
#define rb_enc_toupper(c,e) toupper(c)
#define rb_enc_tolower(c,e) tolower(c)
#define rb_enc_str_asciicompat_p(str) rb_enc_asciicompat(rb_enc_get(str))
#define rb_enc_from_encoding(e) Qnil
#define rb_enc_precise_mbclen(s,l,e) 1
#define rb_enc_unicode_p(e) 0
#define rb_ascii8bit_encoding() __default_encoding
#define rb_utf8_encoding() __default_encoding
#define rb_usascii_encoding() __default_encoding
#define rb_locale_encoding() __default_encoding
#define rb_filesystem_encoding() __default_encoding
#define rb_default_external_encoding() __default_encoding
#define rb_default_internal_encoding() __default_encoding
#define rb_enc_associate(s,e) 0
#define rb_usascii_str_new2(s) rb_str_new2(s)
#define rb_enc_get(n) 0
#define rb_enc_asciicompat(e) 1

#endif /* RUBY_ENCODING_H */
