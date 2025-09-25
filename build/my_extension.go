package my_extension

/*
#include <stdlib.h>
#include "my_extension.h"
*/
import "C"
import "unsafe"
import "github.com/dunglas/frankenphp"
import "strings"

func init() {
	frankenphp.RegisterExtension(unsafe.Pointer(&C.my_extension_module_entry))
}




//export repeat_this
func repeat_this(s *C.zend_string, count int64, reverse bool) unsafe.Pointer {
    str := frankenphp.GoString(unsafe.Pointer(s))

    result := strings.Repeat(str, int(count)*2)
    if reverse {
        runes := []rune(result)
        for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
            runes[i], runes[j] = runes[j], runes[i]
        }
        result = string(runes)
    }

    return frankenphp.PHPString(result, false)
}

