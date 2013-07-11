
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_u4u_functions.h"

/* If you declare any globals in php_u4u_functions.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(u4u_functions)
*/

/* True global resources - no need for thread safety here */
static int le_u4u_functions;

/* {{{ u4u_functions_functions[]
 *
 * Every user visible function must have an entry in u4u_functions_functions[].
 */
const zend_function_entry u4u_functions_functions[] = {
	PHP_FE(get_percentage,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in u4u_functions_functions[] */
};
/* }}} */

/* {{{ u4u_functions_module_entry
 */
zend_module_entry u4u_functions_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"u4u_functions",
	u4u_functions_functions,
	PHP_MINIT(u4u_functions),
	PHP_MSHUTDOWN(u4u_functions),
	PHP_RINIT(u4u_functions),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(u4u_functions),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(u4u_functions),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_U4U_FUNCTIONS
ZEND_GET_MODULE(u4u_functions)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("u4u_functions.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_u4u_functions_globals, u4u_functions_globals)
    STD_PHP_INI_ENTRY("u4u_functions.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_u4u_functions_globals, u4u_functions_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_u4u_functions_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_u4u_functions_init_globals(zend_u4u_functions_globals *u4u_functions_globals)
{
	u4u_functions_globals->global_value = 0;
	u4u_functions_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(u4u_functions)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(u4u_functions)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(u4u_functions)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(u4u_functions)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(u4u_functions)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "u4u_functions support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto float get_percentage(int original_number, int desired_percentage[, boolean rounded_value=false])
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(get_percentage)
{
	double original_number, desired_percentage, end_value;
	zend_bool rounded_value = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd|b", &original_number, &desired_percentage, &rounded_value) == FAILURE) {
		return;
	}
	end_value = (original_number * desired_percentage) / 100;

	if (rounded_value == 0) {
		RETURN_LONG(end_value);
	}

	RETURN_DOUBLE(end_value);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
