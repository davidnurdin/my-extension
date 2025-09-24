/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 6bdb19380b09d8f138360e74f15469f71c8b86e7 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_repeat_this, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, reverse, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_FUNCTION(repeat_this);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(repeat_this, arginfo_repeat_this)
	ZEND_FE_END
};
