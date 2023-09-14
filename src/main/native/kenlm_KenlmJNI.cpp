#include "kenlm_KenlmJNI.h"

#include <boost/tokenizer.hpp>
#include "lm/config.hh"
#include "lm/model.hh"

inline static int32_t getIntB(const int8_t *bb, int bi) {
    return (((bb[bi    ]       ) << 24) |
            ((bb[bi + 1] & 0xff) << 16) |
            ((bb[bi + 2] & 0xff) <<  8) |
            ((bb[bi + 3] & 0xff)      ));
}

inline static void putIntB(int8_t *bb, int bi, int32_t x) {
    bb[bi    ] = static_cast<int8_t>(x >> 24);
    bb[bi + 1] = static_cast<int8_t>(x >> 16);
    bb[bi + 2] = static_cast<int8_t>(x >>  8);
    bb[bi + 3] = static_cast<int8_t>(x      );
}

inline static int64_t getLongB(const int8_t *bb, int bi) {
    return ((((long)bb[bi    ]       ) << 56) |
            (((long)bb[bi + 1] & 0xff) << 48) |
            (((long)bb[bi + 2] & 0xff) << 40) |
            (((long)bb[bi + 3] & 0xff) << 32) |
            (((long)bb[bi + 4] & 0xff) << 25) |
            (((long)bb[bi + 5] & 0xff) << 16) |
            (((long)bb[bi + 6] & 0xff) <<  8) |
            (((long)bb[bi + 7] & 0xff)      ));
}

inline static void putLongB(int8_t *bb, int bi, int64_t x) {
    bb[bi    ] = static_cast<int8_t>(x >> 56);
    bb[bi + 1] = static_cast<int8_t>(x >> 48);
    bb[bi + 2] = static_cast<int8_t>(x >> 40);
    bb[bi + 3] = static_cast<int8_t>(x >> 32);
    bb[bi + 4] = static_cast<int8_t>(x >> 24);
    bb[bi + 5] = static_cast<int8_t>(x >> 16);
    bb[bi + 6] = static_cast<int8_t>(x >>  8);
    bb[bi + 7] = static_cast<int8_t>(x      );
}

inline static float_t getFloatB(const int8_t *bb, int bi) {
    int32_t i = getIntB(bb, bi);
    return *reinterpret_cast<float_t *>(&i);
}

inline static void putFloatB(int8_t *bb, int bi, f