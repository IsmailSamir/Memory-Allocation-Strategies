
#ifndef MEMORY_EXPORT_H
#define MEMORY_EXPORT_H

#ifdef MEMORY_STATIC_DEFINE
#  define MEMORY_EXPORT
#  define MEMORY_NO_EXPORT
#else
#  ifndef MEMORY_EXPORT
#    ifdef memory_EXPORTS
        /* We are building this library */
#      define MEMORY_EXPORT 
#    else
        /* We are using this library */
#      define MEMORY_EXPORT 
#    endif
#  endif

#  ifndef MEMORY_NO_EXPORT
#    define MEMORY_NO_EXPORT 
#  endif
#endif

#ifndef MEMORY_DEPRECATED
#  define MEMORY_DEPRECATED __declspec(deprecated)
#endif

#ifndef MEMORY_DEPRECATED_EXPORT
#  define MEMORY_DEPRECATED_EXPORT MEMORY_EXPORT MEMORY_DEPRECATED
#endif

#ifndef MEMORY_DEPRECATED_NO_EXPORT
#  define MEMORY_DEPRECATED_NO_EXPORT MEMORY_NO_EXPORT MEMORY_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MEMORY_NO_DEPRECATED
#    define MEMORY_NO_DEPRECATED
#  endif
#endif

#endif /* MEMORY_EXPORT_H */
