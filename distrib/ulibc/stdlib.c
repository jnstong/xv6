#include <ulibc/stdlib.h>

#include <ulibc/ulibc.h>
#include <ulibc/ctype.h>
#include <ulibc/assert.h>

double atof(const char* nptr)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

int atoi(const char* nptr)
{
  int result = 0;
  int mul = 1;

  while (isspace(*nptr))
    ++nptr;

  switch (*nptr)
  {
    case '-': mul = -1;
    case '+': ++nptr;
  }

  while (isdigit(*nptr))
    result = 10*result + (*nptr++-'0');

  return mul * result;
}

long int atol(const char* nptr)
{
  long result = 0;
  long mul = 1;

  while (isspace(*nptr))
    ++nptr;

  switch (*nptr)
  {
    case '-': mul = -1;
    case '+': ++nptr;
  }

  while (isdigit(*nptr))
    result = 10*result + (*nptr++-'0');

  return mul * result;
}

double strtod(const char* nptr, char** endptr)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

long int strtol(const char* nptr, char** endptr, int base)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

unsigned long int strtoul(const char* nptr, char** endptr, int base)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

// XOR shift 128, from Marsaglia, George: http://www.jstatsoft.org/v08/i14/paper
// Maximal entropy: 2^128-1
static unsigned int __ulibc_srand_seed_x;
static unsigned int __ulibc_srand_seed_y;
static unsigned int __ulibc_srand_seed_z;
static unsigned int __ulibc_srand_seed_w;

void srand(unsigned int seed)
{
  __ulibc_srand_seed_x = seed;
}

int rand(void)
{
  unsigned int t = (__ulibc_srand_seed_x^(__ulibc_srand_seed_x<<11));
  __ulibc_srand_seed_x = __ulibc_srand_seed_y;
  __ulibc_srand_seed_y = __ulibc_srand_seed_z;
  __ulibc_srand_seed_z = __ulibc_srand_seed_w;
  __ulibc_srand_seed_w = (__ulibc_srand_seed_w^(__ulibc_srand_seed_w>>19))^(t^(t>>8));
  return __ulibc_srand_seed_w % RAND_MAX;
}

void* calloc(size_t nmemb, size_t size)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

void free(void* ptr)
{
  //TODO
  __ulibc_free(ptr);
}

void* malloc(size_t size)
{
  //TODO
  return __ulibc_malloc(size);
}

void* realloc(void* ptr, size_t size)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

void abort(void)
{
  //TODO
  __ulibc_printf(2, "Abort.\n");
  sysexit();
}

// TODO: posix requires this 32 to be ATEXIT_MAX
static void (*__ulibc_atexit_func[32])(void);
static void (**__ulibc_atexit_func_cur)(void) = __ulibc_atexit_func;

int atexit(void (*func)(void))
{
  if (__ulibc_atexit_func_cur<__ulibc_atexit_func+32)
  {
    *(__ulibc_atexit_func_cur++) = func;
    return 0;
  }
  return 1;
}

void exit(int status)
{
  while (__ulibc_atexit_func_cur>=__ulibc_atexit_func)
    (*__ulibc_atexit_func_cur--)();
  sysexit();
}

char* getenv(const char* name)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

int system(const char* string)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

void* bsearch(const void* key, const void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*))
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

void qsort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*))
{
  //TODO
  assert(0 && "not implemented yet.");
}

int abs(int j)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

div_t div(int numer, int denom)
{
  //TODO
  assert(0 && "not implemented yet.");
  div_t r;
  return r;
}

long int labs(long int j)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

ldiv_t ldiv(long int numer, long int denom)
{
  //TODO
  assert(0 && "not implemented yet.");
  ldiv_t r;
  return r;
}

int mblen(const char* s, size_t n)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

int mbtowc(wchar_t* pwc, const char* s, size_t n)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

int wctomb(char* s, wchar_t wchar)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

size_t mbstowcs(wchar_t* pwcs, const char* s, size_t n)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

size_t wcstombs(char* s, const wchar_t* pwcs, size_t n)
{
  //TODO
  assert(0 && "not implemented yet.");
  return 0;
}

