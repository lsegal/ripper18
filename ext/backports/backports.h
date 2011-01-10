#ifndef BACKPORTS_H
#define BACKPORTS_H 1

#include <stdarg.h>
#define TRUE 1
#define FALSE 0
#define SIGNED_VALUE long
#define RSTRING_NOEMBED FL_USER1
#define rb_isascii(c) 1
#define rb_isalpha(c) isalpha(c)
#define rb_islower(c) islower(c)
#define rb_isupper(c) isupper(c)
#define rb_ispunct(c) ispunct(c)
#define rb_isalnum(c) isalnum(c)
#define rb_isprint(c) isprint(c)
#define rb_isspace(c) isspace(c)
#define rb_isdigit(c) isdigit(c)
#define FL_USER8 (((VALUE)1)<<(FL_USHIFT+8))
#define DBL2NUM(dbl)  rb_float_new(dbl)
#define RB_TYPE_P(obj, type) ( \
	((type) == T_FIXNUM) ? FIXNUM_P(obj) : \
	((type) == T_TRUE) ? ((obj) == Qtrue) : \
	((type) == T_FALSE) ? ((obj) == Qfalse) : \
	((type) == T_NIL) ? ((obj) == Qnil) : \
	((type) == T_UNDEF) ? ((obj) == Qundef) : \
	((type) == T_SYMBOL) ? SYMBOL_P(obj) : \
	(!SPECIAL_CONST_P(obj) && BUILTIN_TYPE(obj) == (type)))

#define rb_intern3(s,l,e) rb_intern(s)
#define rb_intern2(s, l) rb_intern(s)
#define rb_intern_const(str) rb_intern(str)
#define local_cnt(x)     3

#define STRCASECMP(s1, s2) (strcasecmp(s1, s2))
#define STRNCASECMP(s1, s2, n) (strncasecmp(s1, s2, n))

unsigned long ruby_strtoul(const char *str, char **endptr, int base);
#define STRTOUL(str, endptr, base) (ruby_strtoul(str, endptr, base))

#define TypedData_Get_Struct(a,b,c,d) Data_Get_Struct(a,b,d)
#define TypedData_Wrap_Struct(klass, type, p) \
	Data_Wrap_Struct(klass, (type)->dmark, (type)->dfree, p)

typedef struct rb_data_type_struct {
    const char *wrap_struct_name;
    void (*dmark)(void*);
    void (*dfree)(void*);
    size_t (*dsize)(const void *);
    void *reserved[3]; /* For future extension.
                          This array *must* be filled with ZERO. */
    void *data;        /* This area can be used for any purpose
                          by a programmer who define the type. */
} rb_data_type_t;

#define CONST_ID_CACHE(result, str)			\
    {							\
	static ID rb_intern_id_cache;			\
	if (!rb_intern_id_cache)			\
	    rb_intern_id_cache = rb_intern2(str, (long)strlen(str)); \
	result rb_intern_id_cache;			\
    }
#define CONST_ID(var, str) \
    do CONST_ID_CACHE(var =, str) while (0)

VALUE
rb_vsprintf(const char *fmt, va_list ap)
{
	char buffer[1024];
	int len = vsnprintf(buffer, 1023, fmt, ap);
	return rb_str_new(buffer, len);
}

#define ruby_scan_oct(s, l, r) ruby_scan_oct2(s, l, r)
#define ruby_scan_hex(s, l, r) ruby_scan_hex2(s, l, r)

unsigned long
ruby_scan_oct2(const char *start, size_t len, size_t *retlen)
{
    register const char *s = start;
    register unsigned long retval = 0;

    while (len-- && *s >= '0' && *s <= '7') {
	retval <<= 3;
	retval |= *s++ - '0';
    }
    *retlen = (int)(s - start);	/* less than len */
    return retval;
}

unsigned long
ruby_scan_hex2(const char *start, size_t len, size_t *retlen)
{
    static const char hexdigit[] = "0123456789abcdef0123456789ABCDEF";
    register const char *s = start;
    register unsigned long retval = 0;
    const char *tmp;

    while (len-- && *s && (tmp = strchr(hexdigit, *s))) {
	retval <<= 4;
	retval |= (tmp - hexdigit) & 15;
	s++;
    }
    *retlen = (int)(s - start);	/* less than len */
    return retval;
}

#endif
