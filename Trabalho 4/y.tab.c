/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "tipos.y" /* yacc.c:339  */

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define YYSTYPE Atributos

int linha = 1;
int coluna = 1;

typedef string Tipo;

struct Atributos {
  string v = "";
  string c = "";
  Tipo t = "";
  vector<Tipo> temp;
  int linha;
};

map<string,Tipo> tsVar;
map<string,Tipo> relacaoTipos ={
{"I", "int"}, {"S", "string"}, {"C", "char"}, {"R", "real"}, {"B", "boolean"}
};
map<string,Tipo> relacaoOperadores ={
{"+","+"},{"-","-"},{"*","*"},{"/","/"},{"%","%"},
{"<","<"},{">",">"},{"<=","<="},{">=",">="},{"==","=="},{"<>","!="},
{"and","&&"},{"or","||"},{"not","!"},
};
map<string,Tipo> resOpr = {
{ "+II", "I" }, { "+IR", "R" }, { "+RI", "R" }, { "+RR", "R" },
{ "+CC", "S" }, { "+CS", "S" }, { "+SC", "S" }, { "+SS", "S" },
{ "+CI", "I" }, { "+IC", "I" }, { "+SS", "S" },

{ "-II", "I" }, { "-IR", "R" }, { "-RI", "R" }, { "-RR", "R" },
{ "-CC", "S" }, { "-CS", "S" }, { "-SC", "S" }, { "-SS", "S" },
{ "-CI", "I" }, { "-IC", "I" },

{ "*II", "I" }, { "*IR", "R" }, { "*RI", "R" }, { "*RR", "R" },
{ "*CI", "I" }, { "*IC", "I" },

{ "/II", "I" }, { "/IR", "R" }, { "/RI", "R" }, { "/RR", "R" },
{ "/CI", "I" }, { "/IC", "I" },

{ "%II", "I" }, { "%IR", "R" }, { "'%RI", "R" }, { "%RR", "R" },
{ "%CI", "I" }, { "%IC", "I" },

{ ">II", "B" }, { ">RR", "B" }, { ">CC", "B" }, { ">SS", "B" }, { ">BB", "B" },
{ ">IR", "B" }, { ">RI", "B" }, { ">IC", "B" }, { ">CI", "B" }, { ">SC", "B" },
{ ">CS", "B" }, { ">IB", "B" }, { ">BI", "B" },

{ "<II", "B" }, { "<RR", "B" }, { "<CC", "B" }, { "<SS", "B" }, { "<BB", "B" },
{ "<IR", "B" }, { "<RI", "B" }, { "<IC", "B" }, { "<CI", "B" }, { "<SC", "B" },
{ "<CS", "B" }, { "<IB", "B" }, { "<BI", "B" },

{ ">=II", "B" }, { ">=RR", "B" }, { ">=CC", "B" }, { ">=SS", "B" }, { ">=BB", "B" },
{ ">=IR", "B" }, { ">=RI", "B" }, { ">=IC", "B" }, { ">=CI", "B" }, { ">=SC", "B" },
{ ">=CS", "B" }, { ">=IB", "B" }, { ">=BI", "B" },

{ "<=II", "B" }, { "<=RR", "B" }, { "<=CC", "B" }, { "<=SS", "B" }, { "<=BB", "B" },
{ "<=IR", "B" }, { "<=RI", "B" }, { "<=IC", "B" }, { "<=CI", "B" }, { "<=SC", "B" },
{ "<=CS", "B" }, { "<=IB", "B" }, { "<=BI", "B" },

{ "==II", "B" }, { "==RR", "B" }, { "==CC", "B" }, { "==SS", "B" }, { "==BB", "B" },
{ "==IR", "B" }, { "==RI", "B" }, { "==IC", "B" }, { "==CI", "B" }, { "==SC", "B" },
{ "==CS", "B" }, { "==IB", "B" }, { "==BI", "B" },

{ "<>II", "B" }, { "<>RR", "B" }, { "<>CC", "B" }, { "<>SS", "B" }, { "<>BB", "B" },
{ "<>IR", "B" }, { "<>RI", "B" }, { "<>IC", "B" }, { "<>CI", "B" }, { "<>SC", "B" },
{ "<>CS", "B" }, { "<>IB", "B" }, { "<>BI", "B" },

{ "andBB", "B" }, { "andII", "B" }, { "andIB", "B" }, { "andBI", "B" }, { "andRB", "B" }, { "andBR", "B" },

{ "orBB", "B" }, { "orII", "B" }, { "orIB", "B" }, { "orBI", "B" }, { "orRB", "B" }, { "orBR", "B" },

{ "notB", "B" }, { "notI", "B" },
};

int yylex();
int yyparse();
void yyerror(const char *);

string geraNomeVar( Tipo t );
string declaraTemps();
Atributos geraCodigoOperador( Atributos a, string operador, Atributos b );
string geraGoTo();
void montaTabelaDeVariaveis(vector<Tipo> variaveis, Tipo tipo);
Tipo buscaTipoVar(string variavel);
string geraCodigoAtribuicao(Atributos ID, Atributos Exp);
map<Tipo,int> nVar;
int nGoTo = 0;


#line 165 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CINT = 258,
    CDOUBLE = 259,
    TK_ID = 260,
    TK_STR = 261,
    TK_STR2 = 262,
    TK_BOOL = 263,
    TK_CONSOLE = 264,
    TK_SHIFTR = 265,
    TK_SHIFTL = 266,
    TK_FOR = 267,
    TK_IN = 268,
    TK_2PT = 269,
    TK_IF = 270,
    TK_THEN = 271,
    TK_ELSE = 272,
    TK_ENDL = 273,
    TK_BEGIN = 274,
    TK_END = 275,
    TK_AND = 276,
    TK_OR = 277,
    TK_NOT = 278,
    TK_VAR_INT = 279,
    TK_VAR_REAL = 280,
    TK_VAR_CHAR = 281,
    TK_VAR_STRING = 282,
    TK_VAR_BOOL = 283
  };
#endif
/* Tokens.  */
#define CINT 258
#define CDOUBLE 259
#define TK_ID 260
#define TK_STR 261
#define TK_STR2 262
#define TK_BOOL 263
#define TK_CONSOLE 264
#define TK_SHIFTR 265
#define TK_SHIFTL 266
#define TK_FOR 267
#define TK_IN 268
#define TK_2PT 269
#define TK_IF 270
#define TK_THEN 271
#define TK_ELSE 272
#define TK_ENDL 273
#define TK_BEGIN 274
#define TK_END 275
#define TK_AND 276
#define TK_OR 277
#define TK_NOT 278
#define TK_VAR_INT 279
#define TK_VAR_REAL 280
#define TK_VAR_CHAR 281
#define TK_VAR_STRING 282
#define TK_VAR_BOOL 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 269 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   317

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  150

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    36,     2,     2,
      41,    42,    34,    32,    38,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
      29,    31,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   123,   124,   127,   128,   129,   130,   131,
     134,   136,   137,   140,   141,   144,   146,   150,   151,   152,
     153,   156,   157,   160,   162,   165,   169,   171,   176,   178,
     185,   190,   192,   194,   196,   200,   212,   227,   230,   234,
     237,   241,   245,   249,   256,   257,   258,   261,   262,   265,
     269,   276,   278,   280,   282,   284,   286,   288,   290,   292,
     294,   296,   298,   300,   302,   304,   308,   312,   313,   314,
     315,   316,   317,   318
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CINT", "CDOUBLE", "TK_ID", "TK_STR",
  "TK_STR2", "TK_BOOL", "TK_CONSOLE", "TK_SHIFTR", "TK_SHIFTL", "TK_FOR",
  "TK_IN", "TK_2PT", "TK_IF", "TK_THEN", "TK_ELSE", "TK_ENDL", "TK_BEGIN",
  "TK_END", "TK_AND", "TK_OR", "TK_NOT", "TK_VAR_INT", "TK_VAR_REAL",
  "TK_VAR_CHAR", "TK_VAR_STRING", "TK_VAR_BOOL", "'<'", "'>'", "'='",
  "'+'", "'-'", "'*'", "'/'", "'%'", "';'", "','", "'['", "']'", "'('",
  "')'", "$accept", "S", "CMDS", "CMD", "DECLVAR", "VARS", "VAR", "TIPO",
  "VARS2", "VAR2", "ENTRADA", "PARAMETRO_ENTRADA", "SAIDA",
  "PARAMETRO_SAIDA", "FOR", "IF", "COMANDOS_1", "COMANDOS_2", "ATR", "E",
  "V", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    60,
      62,    61,    43,    45,    42,    47,    37,    59,    44,    91,
      93,    40,    41
};
# endif

#define YYPACT_NINF -105

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-105)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      74,  -105,  -105,  -105,     6,  -105,    17,   118,    14,   -11,
      87,  -105,  -105,   -21,   139,    31,   112,   118,  -105,    16,
      26,  -105,  -105,    38,    44,   114,  -105,   104,    74,     6,
     112,   112,   117,    85,  -105,  -105,   115,  -105,  -105,    95,
    -105,  -105,  -105,   112,   112,   172,  -105,  -105,  -105,  -105,
    -105,   133,    74,    14,    98,  -105,  -105,   273,   209,    -4,
     143,   110,   123,   112,   281,   150,    11,   112,   112,    18,
     106,   144,   112,   112,   112,   112,   112,   136,  -105,  -105,
    -105,   146,   112,  -105,  -105,  -105,   112,   225,  -105,   118,
     141,   152,   170,   153,   281,   281,   112,   112,   125,   112,
     125,   112,    70,    70,  -105,  -105,  -105,  -105,   112,   241,
     134,  -105,   118,   171,  -105,  -105,    45,  -105,   125,   125,
     125,   125,   273,   185,   112,    -8,   112,   118,  -105,  -105,
     257,    42,  -105,   193,   176,    76,   118,  -105,    53,   160,
     118,  -105,   178,  -105,  -105,   179,   163,   173,  -105,  -105
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      11,    17,    18,    19,     0,    20,     0,     0,     0,    24,
       0,    22,     1,     0,     0,     0,     0,     2,     4,     0,
       0,     8,     9,     0,    16,     0,    14,     0,    11,     0,
       0,     0,     0,     0,    25,    30,     0,    68,    69,    67,
      70,    71,    72,     0,     0,     0,    65,     3,     5,     6,
       7,     0,    11,     0,     0,    12,    21,    49,     0,    28,
      34,    33,     0,     0,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    13,
      23,     0,     0,    26,    32,    31,     0,     0,    73,    48,
       0,     0,    39,     0,    62,    63,     0,     0,    56,     0,
      57,     0,    51,    52,    53,    54,    55,    15,     0,     0,
       0,    66,    47,     0,    44,    45,     0,    46,    61,    58,
      59,    60,    50,    29,     0,     0,     0,    48,    40,    27,
       0,     0,    37,     0,     0,     0,    48,    41,     0,     0,
      48,    35,     0,    43,    42,     0,     0,     0,    38,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,   204,   -15,   -20,  -105,   159,  -105,  -105,   184,
     -61,   -55,   -59,   113,  -105,  -105,  -104,   -54,   -51,   -30,
    -105
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,   112,    18,     7,    25,    26,     8,    10,    11,
      19,    34,    20,    35,    21,    22,    92,   113,    23,    45,
      46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    58,    47,    61,    83,    90,    32,    91,    55,   131,
      30,     9,   128,    64,    65,    93,    13,    12,    31,    24,
      14,    37,    38,    39,    40,    41,    42,   137,    27,   132,
      89,   141,    78,    87,   143,    82,    36,    94,    95,    98,
     100,    43,   102,   103,   104,   105,   106,    13,    96,    97,
      13,    14,   109,    48,    14,    90,   110,    91,    13,    44,
     126,   136,    14,    49,   127,    93,   118,   119,   129,   120,
      90,   121,    91,   134,    90,    50,    91,    90,   122,    91,
      93,    13,   142,    51,    93,    14,   145,    93,    37,    38,
      39,    40,    41,    42,   130,   140,   133,    47,     1,     2,
       3,     4,     5,    60,    74,    75,    76,    54,    43,    37,
      38,    39,    40,    41,    42,    37,    38,    39,    40,    41,
      42,    33,    59,    13,    28,    29,    44,    14,    62,    43,
      15,    67,    68,    16,    63,    43,    77,    99,    80,    69,
      70,    71,    72,    73,    74,    75,    76,    44,   124,    32,
      33,    52,    53,    44,    33,    67,    68,    72,    73,    74,
      75,    76,    86,    69,    70,    71,    72,    73,    74,    75,
      76,    67,    68,    84,    85,   101,   107,   108,   114,    69,
      70,    71,    72,    73,    74,    75,    76,   116,    66,   115,
     117,   125,    88,    67,    68,    32,   139,   144,   146,   147,
     148,    69,    70,    71,    72,    73,    74,    75,    76,   138,
     149,    17,    79,    56,    67,    68,     0,     0,     0,     0,
       0,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      67,    68,     0,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    67,    68,     0,    81,
       0,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    67,    68,     0,   111,     0,     0,     0,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    67,    68,
       0,   123,     0,     0,     0,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    67,    68,     0,   135,     0,     0,
       0,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      69,    70,    71,    72,    73,    74,    75,    76
};

static const yytype_int16 yycheck[] =
{
      30,    31,    17,    33,    59,    66,    10,    66,    28,    17,
      31,     5,   116,    43,    44,    66,     5,     0,    39,     5,
       9,     3,     4,     5,     6,     7,     8,   131,    39,    37,
      19,   135,    52,    63,   138,    39,     5,    67,    68,    69,
      70,    23,    72,    73,    74,    75,    76,     5,    30,    31,
       5,     9,    82,    37,     9,   116,    86,   116,     5,    41,
      15,    19,     9,    37,    19,   116,    96,    97,   123,    99,
     131,   101,   131,   127,   135,    37,   135,   138,   108,   138,
     131,     5,   136,    39,   135,     9,   140,   138,     3,     4,
       5,     6,     7,     8,   124,    19,   126,   112,    24,    25,
      26,    27,    28,    18,    34,    35,    36,     3,    23,     3,
       4,     5,     6,     7,     8,     3,     4,     5,     6,     7,
       8,    11,     5,     5,    37,    38,    41,     9,    13,    23,
      12,    21,    22,    15,    39,    23,     3,    31,    40,    29,
      30,    31,    32,    33,    34,    35,    36,    41,    14,    10,
      11,    37,    38,    41,    11,    21,    22,    32,    33,    34,
      35,    36,    39,    29,    30,    31,    32,    33,    34,    35,
      36,    21,    22,    60,    61,    31,    40,    31,    37,    29,
      30,    31,    32,    33,    34,    35,    36,    17,    16,    37,
      37,    20,    42,    21,    22,    10,    20,    37,    20,    20,
      37,    29,    30,    31,    32,    33,    34,    35,    36,    16,
      37,     7,    53,    29,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    21,    22,    -1,    40,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    21,    22,    -1,    40,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    21,    22,
      -1,    40,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    21,    22,    -1,    40,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      29,    30,    31,    32,    33,    34,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    25,    26,    27,    28,    44,    47,    50,     5,
      51,    52,     0,     5,     9,    12,    15,    45,    46,    53,
      55,    57,    58,    61,     5,    48,    49,    39,    37,    38,
      31,    39,    10,    11,    54,    56,     5,     3,     4,     5,
       6,     7,     8,    23,    41,    62,    63,    46,    37,    37,
      37,    39,    37,    38,     3,    47,    52,    62,    62,     5,
      18,    62,    13,    39,    62,    62,    16,    21,    22,    29,
      30,    31,    32,    33,    34,    35,    36,     3,    47,    49,
      40,    40,    39,    54,    56,    56,    39,    62,    42,    19,
      53,    55,    59,    61,    62,    62,    30,    31,    62,    31,
      62,    31,    62,    62,    62,    62,    62,    40,    31,    62,
      62,    40,    45,    60,    37,    37,    17,    37,    62,    62,
      62,    62,    62,    40,    14,    20,    15,    19,    59,    54,
      62,    17,    37,    62,    60,    40,    19,    59,    16,    20,
      19,    59,    60,    59,    37,    60,    20,    20,    37,    37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    46,    46,
      47,    47,    47,    48,    48,    49,    49,    50,    50,    50,
      50,    51,    51,    52,    52,    53,    54,    54,    54,    54,
      55,    56,    56,    56,    56,    57,    57,    58,    58,    58,
      58,    58,    58,    58,    59,    59,    59,    60,    60,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     2,     2,     2,     1,     1,
       4,     0,     4,     3,     1,     4,     1,     1,     1,     1,
       1,     3,     1,     4,     1,     2,     3,     6,     2,     5,
       2,     3,     3,     2,     2,     9,    12,     7,    11,     4,
       6,     8,     9,     9,     2,     2,     2,     1,     0,     3,
       6,     3,     3,     3,     3,     3,     3,     3,     4,     4,
       4,     4,     3,     3,     2,     1,     4,     1,     1,     1,
       1,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 114 "tipos.y" /* yacc.c:1646  */
    {cout << "#include<stdio.h>\n"
                    "#include <iostream>\n"
                    "#include <string.h>\n"
                    "using namespace std;\n\n"
                    "int main(){\n" + (yyvsp[-1]).c + declaraTemps() + "\n"
                     + (yyvsp[0]).c + "\n"
                   "return 0;\n}" << endl;}
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 123 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c; }
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 135 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-3]).c + (yyvsp[-2]).c + ";\n" + (yyvsp[0]).c; montaTabelaDeVariaveis((yyvsp[-2]).temp, (yyvsp[-3]).t);}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 136 "tipos.y" /* yacc.c:1646  */
    {(yyval).c = "";}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 137 "tipos.y" /* yacc.c:1646  */
    {(yyval).c = "char " + (yyvsp[-2]).c + ";\n" + (yyvsp[0]).c;  montaTabelaDeVariaveis((yyvsp[-2]).temp, "S");}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 140 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + ", " + (yyvsp[0]).c; (yyval).temp = (yyvsp[-2]).temp; (yyval).temp.push_back((yyvsp[0]).temp[0]);}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 141 "tipos.y" /* yacc.c:1646  */
    {(yyval).temp = (yyvsp[0]).temp;}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 145 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-3]).v + "[" + (yyvsp[-1]).v + "]"; (yyval).temp.push_back((yyvsp[-3]).v);}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 147 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).v; (yyval).temp.push_back((yyvsp[0]).v);}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 150 "tipos.y" /* yacc.c:1646  */
    {(yyval).c = "int "; (yyval).t = "I";}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 151 "tipos.y" /* yacc.c:1646  */
    {(yyval).c = "double "; (yyval).t = "R";}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 152 "tipos.y" /* yacc.c:1646  */
    {(yyval).c = "char "; (yyval).t = "C";}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 153 "tipos.y" /* yacc.c:1646  */
    {(yyval).c = "int "; (yyval).t = "B";}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 156 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + ", " + (yyvsp[0]).c; (yyval).temp = (yyvsp[-2]).temp; (yyval).temp.push_back((yyvsp[0]).temp[0]);}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 157 "tipos.y" /* yacc.c:1646  */
    {(yyval).temp = (yyvsp[0]).temp;}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 161 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-3]).v + "[" + (yyvsp[-1]).v + "]" + "[257]"; (yyval).temp.push_back((yyvsp[-3]).v);}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 163 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).v + "[257]"; (yyval).temp.push_back((yyvsp[0]).v);}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 166 "tipos.y" /* yacc.c:1646  */
    {(yyval).c = (yyvsp[0]).c;}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 170 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = "cin >> " + (yyvsp[-1]).v + ";\n" + (yyvsp[0]).c; }
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 172 "tipos.y" /* yacc.c:1646  */
    { (yyval).v = geraNomeVar("I");
                    (yyval).c = (yyvsp[-2]).c
                         + "cin >> " + (yyval).v + ";\n"
                         + (yyvsp[-4]).v + "[" + (yyvsp[-2]).v + "] = " + (yyval).v + ";\n" + (yyvsp[0]).c; }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 177 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = "cin >> " + (yyvsp[0]).v + ";\n"; }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 179 "tipos.y" /* yacc.c:1646  */
    { (yyval).v = geraNomeVar("I");
                    (yyval).c = (yyvsp[-1]).c
                         + "cin >> " + (yyval).v + ";\n"
                         + (yyvsp[-3]).v + "[" + (yyvsp[-1]).v + "] = " + (yyval).v + ";\n"; }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 186 "tipos.y" /* yacc.c:1646  */
    {(yyval).c = (yyvsp[0]).c;}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 191 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c + "cout << " + (yyvsp[-1]).v + ";\n" + (yyvsp[0]).c; }
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 193 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = "cout << endl;\n" + (yyvsp[0]).c; }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 195 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c + "cout << " + (yyvsp[0]).v + ";\n"; }
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 197 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = "cout << endl;\n"; }
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 201 "tipos.y" /* yacc.c:1646  */
    {  string cond = geraNomeVar("I"); string label = geraGoTo(); string label2 = geraGoTo();

         (yyval).c = (yyvsp[-4]).c + (yyvsp[-2]).c
              + (yyvsp[-7]).v + " = " + (yyvsp[-4]).v + ";\n"
              + label + ":\n" + cond + " = " + (yyvsp[-7]).v + " > " + (yyvsp[-2]).v + ";\n"
              + "if( " + cond + ") goto " + label2 + ";\n"
              + (yyvsp[0]).c
              + (yyvsp[-7]).v + " = " + (yyvsp[-7]).v + " + 1;\n"
              + "goto "+ label + ";\n"
              + label2 + ":\n";
      }
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 213 "tipos.y" /* yacc.c:1646  */
    {  string cond = geraNomeVar("I");  string label = geraGoTo(); string label2 = geraGoTo();

           (yyval).c = (yyvsp[-7]).c + (yyvsp[-5]).c
                + (yyvsp[-10]).v + " = " + (yyvsp[-7]).v + ";\n"
                + label + ":\n" + cond + " = " + (yyvsp[-10]).v + " > " + (yyvsp[-5]).v + ";\n"
                + "if( " + cond + ") goto " + label2 + ";\n"
                + (yyvsp[-2]).c
                + (yyvsp[-10]).v + " = " + (yyvsp[-10]).v + " + 1;\n"
                + "goto "+ label + ";\n"
                + label2 + ":\n";
        }
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 228 "tipos.y" /* yacc.c:1646  */
    {string label = geraGoTo(); string cond = geraNomeVar("I");
      (yyval).c = (yyvsp[-5]).c + cond + " = !" + (yyvsp[-5]).v +";\nif(" + cond + ") goto " + label +";\n"+ (yyvsp[-2]).c + "\n" + label + ":\n";}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 231 "tipos.y" /* yacc.c:1646  */
    {string label = geraGoTo(); string label2 = geraGoTo();string cond = geraNomeVar("I");
      (yyval).c = (yyvsp[-9]).c + cond + " = !" + (yyvsp[-9]).v +";\nif(" + cond + ") goto " + label +";\n"+ (yyvsp[-6]).c + "\n" + label + ":\n"+
                    "if(" + (yyvsp[-9]).v + ") goto "+ label2 + ";\n"+ (yyvsp[-2]).c + "\n" + label2 + ":\n";}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 235 "tipos.y" /* yacc.c:1646  */
    {string label = geraGoTo(); string cond = geraNomeVar("I");
         (yyval).c = (yyvsp[-2]).c + cond + " = !" + (yyvsp[-2]).v +";\nif(" + cond + ") goto " + label +";\n"+ (yyvsp[0]).c + "\n" + label + ":\n";}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 238 "tipos.y" /* yacc.c:1646  */
    {string label = geraGoTo(); string label2 = geraGoTo();string cond = geraNomeVar("I");
      (yyval).c = (yyvsp[-4]).c + cond + " = !" + (yyvsp[-4]).v +";\nif(" + cond + ") goto " + label +";\n"+ (yyvsp[-2]).c + "\n" + label + ":\n"+
                    "if(" + (yyvsp[-4]).v + ") goto "+ label2 + ";\n"+ (yyvsp[0]).c + "\n" + label2 + ":\n";}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 242 "tipos.y" /* yacc.c:1646  */
    {string label = geraGoTo(); string label2 = geraGoTo();string cond = geraNomeVar("I");
           (yyval).c = (yyvsp[-6]).c + cond + " = !" + (yyvsp[-6]).v +";\nif(" + cond + ") goto " + label +";\n"+ (yyvsp[-4]).c + "\n" + label + ":\n"+
                         "if(" + (yyvsp[-6]).v + ") goto "+ label2 + ";\n"+ (yyvsp[0]).c + "\n" + label2 + ":\n";}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 246 "tipos.y" /* yacc.c:1646  */
    {string label = geraGoTo(); string label2 = geraGoTo();string cond = geraNomeVar("I");
          (yyval).c = (yyvsp[-7]).c + cond + " = !" + (yyvsp[-7]).v +";\nif(" + cond + ") goto " + label +";\n"+ (yyvsp[-5]).c + "\n" + label + ":\n"+
                   "if(" + (yyvsp[-7]).v + ") goto "+ label2 + ";\n"+ (yyvsp[-2]).c + "\n" + label2 + ":\n";}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 250 "tipos.y" /* yacc.c:1646  */
    {string label = geraGoTo(); string label2 = geraGoTo();string cond = geraNomeVar("I"); string cond2 = geraNomeVar("I");
         (yyval).c = (yyvsp[-7]).c + cond + " = !" + (yyvsp[-7]).v +";\n" + (yyvsp[-2]).c + cond2 + " = !" + (yyvsp[-2]).v +";\n" +
          "if(" + cond + ") goto " + label +";\n"+ (yyvsp[-5]).c + "\ngoto "+ label2 + ";\n" + label + ":\n"+
                  "if(" + cond2 + ") goto "+ label2 + ";\n"+ (yyvsp[0]).c + "\n" + label2 + ":\n";}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 266 "tipos.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v;
        (yyval).c = (yyvsp[0]).c + geraCodigoAtribuicao((yyvsp[-2]),(yyvsp[0]));
      }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 270 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-3]).c + (yyvsp[0]).c
             + (yyvsp[-5]).v + "[" + (yyvsp[-3]).v + "] = " + (yyvsp[0]).v + ";\n";
        (yyval).v = (yyvsp[0]).v;
      }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 277 "tipos.y" /* yacc.c:1646  */
    { (yyval) = geraCodigoOperador( (yyvsp[-2]), (yyvsp[-1]).v, (yyvsp[0]) ); }
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 279 "tipos.y" /* yacc.c:1646  */
    { (yyval) = geraCodigoOperador( (yyvsp[-2]), (yyvsp[-1]).v, (yyvsp[0]) ); }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 281 "tipos.y" /* yacc.c:1646  */
    { (yyval) = geraCodigoOperador( (yyvsp[-2]), (yyvsp[-1]).v, (yyvsp[0]) ); }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 283 "tipos.y" /* yacc.c:1646  */
    { (yyval) = geraCodigoOperador( (yyvsp[-2]), (yyvsp[-1]).v, (yyvsp[0]) ); }
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 285 "tipos.y" /* yacc.c:1646  */
    { (yyval) = geraCodigoOperador( (yyvsp[-2]), (yyvsp[-1]).v, (yyvsp[0]) ); }
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 287 "tipos.y" /* yacc.c:1646  */
    { (yyval) = geraCodigoOperador( (yyvsp[-2]), (yyvsp[-1]).v, (yyvsp[0]) ); }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 289 "tipos.y" /* yacc.c:1646  */
    { (yyval) = geraCodigoOperador( (yyvsp[-2]), (yyvsp[-1]).v, (yyvsp[0]) ); }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 291 "tipos.y" /* yacc.c:1646  */
    { (yyval) = geraCodigoOperador( (yyvsp[-3]), (yyvsp[-2]).v + (yyvsp[-1]).v, (yyvsp[0]) ); }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 293 "tipos.y" /* yacc.c:1646  */
    { (yyval) = geraCodigoOperador( (yyvsp[-3]), (yyvsp[-2]).v + (yyvsp[-1]).v, (yyvsp[0]) ); }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 295 "tipos.y" /* yacc.c:1646  */
    { (yyval) = geraCodigoOperador( (yyvsp[-3]), (yyvsp[-2]).v + (yyvsp[-1]).v, (yyvsp[0]) ); }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 297 "tipos.y" /* yacc.c:1646  */
    { (yyval) = geraCodigoOperador( (yyvsp[-3]), (yyvsp[-2]).v + (yyvsp[-1]).v, (yyvsp[0]) ); }
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 299 "tipos.y" /* yacc.c:1646  */
    { (yyval) = geraCodigoOperador( (yyvsp[-2]), "and", (yyvsp[0]) ); }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 301 "tipos.y" /* yacc.c:1646  */
    { (yyval) = geraCodigoOperador( (yyvsp[-2]), "or", (yyvsp[0]) ); }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 303 "tipos.y" /* yacc.c:1646  */
    {  Atributos a; a.t = ""; a.v = ""; a.c = ""; (yyval) = geraCodigoOperador( a, "not", (yyvsp[0]) ); }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 309 "tipos.y" /* yacc.c:1646  */
    { (yyval).v = geraNomeVar((yyvsp[-1]).t);
      (yyval).c = (yyvsp[-1]).c + (yyval).v + " = " + (yyvsp[-3]).v + "[" + (yyvsp[-1]).v + "];\n";
    }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 312 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = ""; (yyval).v = (yyvsp[0]).v; (yyval).t = buscaTipoVar( (yyvsp[0]).v ); }
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 313 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = ""; (yyval).v = (yyvsp[0]).v; (yyval).t = "I"; }
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 314 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = ""; (yyval).v = (yyvsp[0]).v; (yyval).t = "R"; }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 315 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = ""; (yyval).v = (yyvsp[0]).v; (yyval).t = "S"; }
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 316 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = ""; (yyval).v = (yyvsp[0]).v; (yyval).t = "C"; }
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 317 "tipos.y" /* yacc.c:1646  */
    { (yyval).c = ""; (yyval).v = (yyvsp[0]).v; (yyval).t = "B"; }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 318 "tipos.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1888 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 321 "tipos.y" /* yacc.c:1906  */


#include "lex.yy.c"

void yyerror( const char* st ) {
   puts( st );
   printf( "Linha %d, coluna %d, proximo a: %s\n", linha, coluna, yytext );
   exit( 0 );
}

Tipo buscaTipoOperacao( Tipo a, string operador, Tipo b ) {
  return resOpr[operador + a + b];
  // TODO: usar o find. Perda de performance de 1e-9 s
}

Atributos geraCodigoOperador( Atributos a, string operador, Atributos b ) {
  Atributos r;
  string tamString1, tamString2, atrA, atrB;
  atrA = a.v;
  atrB = b.v;

  r.t = buscaTipoOperacao( a.t, operador, b.t );
  if( r.t == "" ) {
    string temp = "Operacao '" + operador + "' inválida entre " + relacaoTipos[a.t] + " e " + relacaoTipos[b.t];
    yyerror( temp.c_str() );
  }

  r.v = geraNomeVar( r.t );
  if(((a.t == "S" && b.t == "S") || (a.t == "C" && b.t == "C") || (a.t == "S" && b.t == "C") || (a.t == "C" && b.t == "S")) && (operador == "+")){
    tamString1 = geraNomeVar("I");
    tamString2 = geraNomeVar("I");
    r.c = a.c + b.c;

    if(a.t == "C"){
      atrA = geraNomeVar("S");
      r.c += atrA + "[0] = " + a.v + ";\n";
/*      r.c += atrA + "[1] = " + "\'\\0\'" + ";\n";*/
      r.c += tamString1 + " = 1;";
    }else{
      r.c += tamString1 + " = strlen(" + a.v + ");\n";
    }

    if(b.t == "C"){
      atrB = geraNomeVar("S");
      r.c += atrB + "[0] = " + b.v + ";\n";
/*      r.c += atrB + "[1] = " + "\'\\0\'" + ";\n";*/
      r.c += tamString2 + " = 1;";
    }else{
      r.c += tamString2 + " = strlen(" + b.v + ");\n";
    }

    r.c += "strncpy("+ r.v + ",\"\",257);\n" + "strncpy("+ r.v +","+ atrA +","+ tamString1 +");\n" + "strncat("+ r.v + "," + atrB + ","+ tamString2 +");\n";

  }else if( ((a.t == "S" && b.t == "S") || (a.t == "C" && b.t == "C") || (a.t == "S" && b.t == "C") || (a.t == "C" && b.t == "S")) &&
  (operador == ">" || operador == "<" || operador == ">=" || operador == "<=" || operador == "==" || operador == "<>")){
    string temp;
    r.c = a.c + b.c;

    if(a.t == "C"){
      atrA = geraNomeVar("S");
      r.c += atrA + "[0] = " + a.v + ";\n";
    }

    if(b.t == "C"){
      atrB = geraNomeVar("S");
      r.c += atrB + "[0] = " + b.v + ";\n";
    }

    if(operador == "=="){
      temp = geraNomeVar("I");
      r.c += temp + "= strcmp(" + atrA +","+ atrB + ");\n";
      r.c += r.v + " = "+ temp + " == 0;\n";
    }
    if(operador == ">"){
      temp = geraNomeVar("I");
      r.c += temp + "= strcmp(" + atrA +","+ atrB + ");\n";
      r.c += r.v + " = "+ temp + " == 1;\n";
    }
    if(operador == "<"){
      temp = geraNomeVar("I");
      r.c += temp + "= strcmp(" + atrA +","+ atrB + ");\n";
      r.c += r.v + " = "+ temp + " < 0;\n";
    }
    if(operador == "<>"){
      temp = geraNomeVar("I");
      r.c += temp + "= strcmp(" + atrA +","+ atrB + ");\n";
      r.c += r.v + " = "+ temp + " != 0;\n";
    }
    if(operador == "<="){
      temp = geraNomeVar("I");
      r.c += temp + "= strcmp(" + atrA +","+ atrB + ");\n";
      r.c += r.v + " = "+ temp + " <= 0;\n";
    }
    if(operador == ">="){
      temp = geraNomeVar("I");
      r.c += temp + "= strcmp(" + atrA +","+ atrB + ");\n";
      r.c += r.v + " = "+ temp + " >= 0;\n";
    }

  }else{
    r.c = a.c + b.c +
          r.v + " = " + a.v + relacaoOperadores[operador] + b.v + ";\n";
  }
  return r;
}

string toString( int n ) {
  char buf[20] = "";

  sprintf( buf, "%d", n );

  return buf;
}

string geraNomeVar( Tipo t ) {
  return "temp_" + t + "_" + toString( nVar[t]++ );
}

string declaraTemps() {
  string res;

  for( auto p : nVar )
    for( int i = 0; i < p.second; i ++ ) {
      string nomeTipo;
      string string = "";
      if( p.first == "I" )
        nomeTipo = "int";
      else if( p.first == "R" )
        nomeTipo = "double";
      else if( p.first == "C" )
        nomeTipo = "char";
      else if( p.first == "S" ){
        nomeTipo = "char";
        string = "[257]";
      }else if( p.first == "B" )
        nomeTipo = "int";

      res += nomeTipo + " temp_" + p.first + "_" + toString( i ) + string + ";\n";
     }

  return res;
}


string geraGoTo() {
  char buf[20] = "";

  sprintf( buf, "Local%d", nGoTo++ );

  return buf;
}

void montaTabelaDeVariaveis(vector<Tipo> variaveis, Tipo tipo){
  for(int i = 0; i < variaveis.size(); i++){
    tsVar[variaveis[i]] = tipo;
  }
}

Tipo buscaTipoVar(string variavel ){
 return tsVar[variavel];
}

string geraCodigoAtribuicao(Atributos ID, Atributos Exp){
  string tamString;
  if(Exp.t == "S" && buscaTipoVar(ID.v) == "S"){
    tamString = geraNomeVar("I");
    return tamString + " = strlen(" +  Exp.v + ");\n" + "strncpy("+ ID.v + ",\"\",257);\n" + "strncpy(" + ID.v + "," + Exp.v + "," + tamString + ");\n";
  }
  return ID.v + " = " + Exp.v + ";\n";
}

int main( int argc, char* st[]) {
  yyparse();

  return 0;
}
