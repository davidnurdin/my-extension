#include <php.h>
#include <Zend/zend_API.h>
#include <Zend/zend_hash.h>
#include <Zend/zend_types.h>
#include <stddef.h>

#include "my_extension.h"
#include "my_extension_arginfo.h"
#include "_cgo_export.h"

#define VALIDATE_GO_HANDLE(intern) \
    do { \
        if ((intern)->go_handle == 0) { \
            zend_throw_error(NULL, "Go object not found in registry"); \
            RETURN_THROWS(); \
        } \
    } while (0)

static zend_object_handlers object_handlers_my_extension;

typedef struct {
    uintptr_t go_handle;
    zend_object std; /* This must be the last field in the structure: the property store starts at this offset */
} my_extension_object;

static inline my_extension_object *my_extension_object_from_obj(zend_object *obj) {
    return (my_extension_object*)((char*)(obj) - offsetof(my_extension_object, std));
}

static zend_object *my_extension_create_object(zend_class_entry *ce) {
    my_extension_object *intern = ecalloc(1, sizeof(my_extension_object) + zend_object_properties_size(ce));
    
    zend_object_std_init(&intern->std, ce);
    object_properties_init(&intern->std, ce);
    
    intern->std.handlers = &object_handlers_my_extension;
    intern->go_handle = 0; /* will be set in __construct */

    return &intern->std;
}

static void my_extension_free_object(zend_object *object) {
    my_extension_object *intern = my_extension_object_from_obj(object);

    if (intern->go_handle != 0) {
        removeGoObject(intern->go_handle);
    }
    
    zend_object_std_dtor(&intern->std);
}

void init_object_handlers() {
    memcpy(&object_handlers_my_extension, &std_object_handlers, sizeof(zend_object_handlers));
    object_handlers_my_extension.free_obj = my_extension_free_object;
    object_handlers_my_extension.clone_obj = NULL;
    object_handlers_my_extension.offset = offsetof(my_extension_object, std);
}

static zend_class_entry *User_ce = NULL;

PHP_METHOD(My_Extension_User, __construct) {
    ZEND_PARSE_PARAMETERS_NONE();

    my_extension_object *intern = my_extension_object_from_obj(Z_OBJ_P(ZEND_THIS));

    /* Constructor is called more than once, make it no-op */
    if (intern->go_handle != 0) {
        return;
    }

    intern->go_handle = create_UserStruct_object();
}


PHP_METHOD(My_Extension_User, getName) {
    my_extension_object *intern = my_extension_object_from_obj(Z_OBJ_P(ZEND_THIS));
    
    VALIDATE_GO_HANDLE(intern);
    ZEND_PARSE_PARAMETERS_NONE();
    
    zend_string* result = getName_wrapper(intern->go_handle);
    RETURN_STR(result);
}

void register_all_classes() {
    init_object_handlers();
    User_ce = register_class_My_Extension_User();
    if (!User_ce) {
        php_error_docref(NULL, E_ERROR, "Failed to register class User");
        return;
    }
    User_ce->create_object = my_extension_create_object;
}

PHP_MINIT_FUNCTION(my_extension) {
    register_all_classes();
    REGISTER_LONG_CONSTANT("STATUS_ACTIVE", 1, CONST_CS | CONST_PERSISTENT);
    return SUCCESS;
}

zend_module_entry my_extension_module_entry = {STANDARD_MODULE_HEADER,
                                         "my_extension",
                                         ext_functions,             /* Functions */
                                         PHP_MINIT(my_extension),  /* MINIT */
                                         NULL,                      /* MSHUTDOWN */
                                         NULL,                      /* RINIT */
                                         NULL,                      /* RSHUTDOWN */
                                         NULL,                      /* MINFO */
                                         "1.0.0",                   /* Version */
                                         STANDARD_MODULE_PROPERTIES};

