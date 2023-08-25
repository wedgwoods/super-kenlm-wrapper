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
 