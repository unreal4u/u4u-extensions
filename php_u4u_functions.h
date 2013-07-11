
#ifndef PHP_U4U_FUNCTIONS_H
#define PHP_U4U_FUNCTIONS_H

extern zend_module_entry u4u_functions_module_entry;
#define phpext_u4u_functions_ptr &u4u_functions_module_entry

#ifdef PHP_WIN32
#	define PHP_U4U_FUNCTIONS_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_U4U_FUNCTIONS_API __attribute__ ((visibility("default")))
#else
#	define PHP_U4U_FUNCTIONS_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(u4u_functions);
PHP_MSHUTDOWN_FUNCTION(u4u_functions);
PHP_RINIT_FUNCTION(u4u_functions);
PHP_RSHUTDOWN_FUNCTION(u4u_functions);
PHP_MINFO_FUNCTION(u4u_functions);

PHP_FUNCTION(get_percentage);	/* For testing, remove later. */

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(u4u_functions)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(u4u_functions)
*/

/* In every utility function you add that needs to use variables 
   in php_u4u_functions_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as U4U_FUNCTIONS_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define U4U_FUNCTIONS_G(v) TSRMG(u4u_functions_globals_id, zend_u4u_functions_globals *, v)
#else
#define U4U_FUNCTIONS_G(v) (u4u_functions_globals.v)
#endif

#endif	/* PHP_U4U_FUNCTIONS_H */

