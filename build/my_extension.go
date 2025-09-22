package my_extension

/*
#include <stdlib.h>
#include "my_extension.h"
*/
import "C"

func init() {
	frankenphp.RegisterExtension(unsafe.Pointer(&C.my_extension_module_entry))
}
const STATUS_ACTIVE = 1




type UserStruct struct {
}

//export registerGoObject
func registerGoObject(obj interface{}) C.uintptr_t {
	handle := cgo.NewHandle(obj)
	return C.uintptr_t(handle)
}

//export getGoObject
func getGoObject(handle C.uintptr_t) interface{} {
	h := cgo.Handle(handle)
	return h.Value()
}

//export removeGoObject
func removeGoObject(handle C.uintptr_t) {
	h := cgo.Handle(handle)
	h.Delete()
}
//export create_UserStruct_object
func create_UserStruct_object() C.uintptr_t {
	obj := &UserStruct{}
	return registerGoObject(obj)
}
func (u *UserStruct) GetName() unsafe.Pointer {
    return frankenphp.PHPString("John Doe", false)
}

//export getName_wrapper
func getName_wrapper(handle C.uintptr_t) unsafe.Pointer {
	obj := getGoObject(handle)
	if obj == nil {
		return nil
	}
	structObj := obj.(*UserStruct)
	return structObj.GetName()
}

