/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 863933eaa0dc6d6c54bd7b37f1eadbb04a1ac55c */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_My_Extension_User___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_My_Extension_User_getName, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(My_Extension_User, __construct);
ZEND_METHOD(My_Extension_User, getName);

static const zend_function_entry class_My_Extension_User_methods[] = {
	ZEND_ME(My_Extension_User, __construct, arginfo_class_My_Extension_User___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(My_Extension_User, getName, arginfo_class_My_Extension_User_getName, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static void register_my_extension_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("My\\Extension\\STATUS_ACTIVE", 1, CONST_PERSISTENT);
}

static zend_class_entry *register_class_My_Extension_User(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "My\\Extension", "User", class_My_Extension_User_methods);
	class_entry = zend_register_internal_class(&ce);

	return class_entry;
}
