
#ifndef _ERROR_COMMON_H_
#define _ERROR_COMMON_H_

// SUCCESS
#define ERROR_SUCCESS 0x00000000

// GENERAL ERRORS
#define ERROR_UNKNOWN 0x80000000
#define ERROR_NOT_IMPLEMENTED 0x80000001
#define ERROR_NOT_SUPPORTED 0x80000002
#define ERROR_NOT_FOUND 0x80000003

// INVALID OPTIONS
#define ERROR_INVALID_PARAMETER 0x8F000001
#define ERROR_INVALID_OPTION 0x8F000002
#define ERROR_INVALID_FILE 0x8F000003
#define ERROR_INVALID_FORMAT 0x8F000004

#endif // _ERROR_COMMON_H_