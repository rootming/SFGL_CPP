#ifndef __SFGL_DEBUG_H__
#define __SFGL_DEBUG_H__
#include <cstdio>

#define BRED				"\E[41m"
#define BGREEN				"\E[42m"
#define BYELLOW				"\E[43m"
#define BBLUE				"\E[44m"
#define BWHITE				"\E[40m"

#define SFGL_DEBUG

/*
Terminal color
 [30m30
 [31m31
 [32m32
 [33m33
 [34m34
 [35m35
 [36m36
 [37m37
 [38m38
 [39m39
 [40m40
 [41m41
 [42m42
 [43m43
 [44m44
 [45m45
 [46m46
 [47m47
 [48m48
 [49m49
 [90m90
 [91m91
 [92m92
 [93m93
 [94m94
 [95m95
 [96m96
 [97m97
 [98m98
 [99m99
*/
#ifdef SFGL_DEBUG

#define SFGL_DEBUG_ERROR(...)		fprintf(stderr, "%s[ERROR]%s%s[FileName]%s%s%s[Line]%s%d\n\t" ,BRED, BWHITE, BBLUE,	BWHITE, __FILE__, BBLUE, BWHITE,__LINE__) ;\
fprintf(stderr, __VA_ARGS__);

#define SFGL_DEBUG_WORRY(...)		fprintf(stderr, "%s[WORRY]%s%s[FileName]%s%s%s[Line]%s%d\n\t" ,BYELLOW, BWHITE, BBLUE,	BWHITE, __FILE__, BBLUE, BWHITE,__LINE__) ;\
fprintf(stderr, __VA_ARGS__);

#define SFGL_DEBUG_INFO(...)		fprintf(stdout, "%s[INFO]%s%s[FileName]%s%s%s[Line]%s%d\n\t" ,BGREEN, BWHITE, BBLUE,	BWHITE, __FILE__, BBLUE, BWHITE,__LINE__) ;\
fprintf(stdout, __VA_ARGS__);

#else

#define SFGL_DEBUG_ERROR(...)
#define SFGL_DEBUG_WORRY(...)
#define SFGL_DEBUG_INFO(...)

#endif
#endif
