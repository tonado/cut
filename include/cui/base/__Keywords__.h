#ifndef H24444E71_BA4A_444A_8ED4_03C92F43DBF5
#define H24444E71_BA4A_444A_8ED4_03C92F43DBF5

#include <cui/base/__Default__.h>

#define CUI_ABSTRACT(...) virtual __VA_ARGS__ = 0
#define CUI_OVERRIDE(...) virtual __VA_ARGS__

#define CUI_EXTENDS(...) , ##__VA_ARGS__
#define CUI_IMPLEMENTS(...) CUI_EXTENDS(__VA_ARGS__)

#endif

