

#ifndef VS_FLANN_DEFINES_H_
#define VS_FLANN_DEFINES_H_

#include "vs_config.h"

#ifdef FLANN_EXPORT
#undef FLANN_EXPORT
#endif
#ifdef WIN32
/* win32 dll export/import directives */
#ifdef FLANN_EXPORTS
#define FLANN_EXPORT __declspec(dllexport)
#elif defined(FLANN_STATIC)
#define FLANN_EXPORT
#else
#define FLANN_EXPORT __declspec(dllimport)
#endif
#else
/* unix needs nothing */
#define FLANN_EXPORT
#endif

#ifdef FLANN_DEPRECATED
#undef FLANN_DEPRECATED
#endif
#ifdef __GNUC__
#define FLANN_DEPRECATED __attribute__ ((deprecated))
#elif defined(_MSC_VER)
#define FLANN_DEPRECATED __declspec(deprecated)
#else
#pragma message("WARNING: You need to implement FLANN_DEPRECATED for this compiler")
#define FLANN_DEPRECATED
#endif

#undef FLANN_PLATFORM_64_BIT
#undef FLANN_PLATFORM_32_BIT
#if __amd64__ || __x86_64__ || _WIN64 || _M_X64
#define FLANN_PLATFORM_64_BIT
#else
#define FLANN_PLATFORM_32_BIT
#endif

#undef FLANN_ARRAY_LEN
#define FLANN_ARRAY_LEN(a) (sizeof(a)/sizeof(a[0]))

#ifdef __cplusplus
namespace vs_flann {
#endif

    /* Nearest neighbour index algorithms */
    enum flann_algorithm_t
    {
        FLANN_INDEX_LINEAR = 0,
        FLANN_INDEX_KDTREE = 1,
        FLANN_INDEX_KMEANS = 2,
        FLANN_INDEX_COMPOSITE = 3,
        FLANN_INDEX_KDTREE_SINGLE = 4,
        FLANN_INDEX_HIERARCHICAL = 5,
        FLANN_INDEX_LSH = 6,
#ifdef FLANN_USE_CUDA
        FLANN_INDEX_KDTREE_CUDA = 7,
#endif
        FLANN_INDEX_SAVED = 254,
        FLANN_INDEX_AUTOTUNED = 255,

    };

    enum flann_centers_init_t
    {
        FLANN_CENTERS_RANDOM = 0,
        FLANN_CENTERS_GONZALES = 1,
        FLANN_CENTERS_KMEANSPP = 2,
        FLANN_CENTERS_GROUPWISE = 3,
    };

    enum flann_log_level_t
    {
        FLANN_LOG_NONE = 0,
        FLANN_LOG_FATAL = 1,
        FLANN_LOG_ERROR = 2,
        FLANN_LOG_WARN = 3,
        FLANN_LOG_INFO = 4,
        FLANN_LOG_DEBUG = 5
    };

    enum flann_distance_t
    {
        FLANN_DIST_EUCLIDEAN = 1,
        FLANN_DIST_L2 = 1,
        FLANN_DIST_MANHATTAN = 2,
        FLANN_DIST_L1 = 2,
        FLANN_DIST_MINKOWSKI = 3,
        FLANN_DIST_MAX = 4,
        FLANN_DIST_HIST_INTERSECT = 5,
        FLANN_DIST_HELLINGER = 6,
        FLANN_DIST_CHI_SQUARE = 7,
        FLANN_DIST_KULLBACK_LEIBLER = 8,
        FLANN_DIST_HAMMING = 9,
        FLANN_DIST_HAMMING_LUT = 10,
        FLANN_DIST_HAMMING_POPCNT = 11,
        FLANN_DIST_L2_SIMPLE = 12,
    };

    enum flann_datatype_t
    {
        FLANN_NONE = -1,
        FLANN_INT8 = 0,
        FLANN_INT16 = 1,
        FLANN_INT32 = 2,
        FLANN_INT64 = 3,
        FLANN_UINT8 = 4,
        FLANN_UINT16 = 5,
        FLANN_UINT32 = 6,
        FLANN_UINT64 = 7,
        FLANN_FLOAT32 = 8,
        FLANN_FLOAT64 = 9
    };

    enum flann_checks_t {
        FLANN_CHECKS_UNLIMITED = -1,
        FLANN_CHECKS_AUTOTUNED = -2,
    };

#ifdef __cplusplus
}
#endif


#endif /* FLANN_DEFINES_H_ */
