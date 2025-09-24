/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 5e42bc2deb9e10b6ee0df8bad9156320b0fc3069 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_My_Extension_repeat_this, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, reverse, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_FUNCTION(My_Extension_repeat_this);

static const zend_function_entry ext_functions[] = {
	ZEND_RAW_FENTRY(ZEND_NS_NAME("My\\Extension", "repeat_this"), zif_My_Extension_repeat_this, arginfo_My_Extension_repeat_this, 0, NULL, NULL)
	ZEND_FE_END
};
