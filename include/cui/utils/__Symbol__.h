#ifndef HFBBD9E09_2084_46FE_BCC4_C44FDB7FC15A
#define HFBBD9E09_2084_46FE_BCC4_C44FDB7FC15A

////////////////////////////////////////////////////////////////////////////////
#define __DO_CUI_STRINGIZE( symbol ) #symbol
#define CUI_STRINGIZE(symbol) __DO_CUI_STRINGIZE(symbol)

////////////////////////////////////////////////////////////////////////////////
#define __DO_CUI_JOIN_AGAIN(symbol1, symbol2) symbol1##symbol2
#define __CUI_DO_JOIN(symbol1, symbol2) __DO_CUI_JOIN_AGAIN(symbol1, symbol2)

////////////////////////////////////////////////////////////////////////////////
#define CUI_JOIN(symbol1, symbol2) __CUI_DO_JOIN(symbol1, symbol2)

////////////////////////////////////////////////////////////////////////////////
#ifdef __COUNTER__
# define CUI_UNIQUE_ID __COUNTER__
#else
# define CUI_UNIQUE_ID __LINE__
#endif

////////////////////////////////////////////////////////////////////////////////
# define CUI_UNIQUE_NAME(prefix) CUI_JOIN(prefix, CUI_UNIQUE_ID)

#endif