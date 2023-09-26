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

inline static void putFloatB(int8_t *bb, int bi, float_t x) {
    int32_t i = *reinterpret_cast<int32_t *>(&x);
    putIntB(bb, bi, i);
}

static const int FullScoreReturnSize = 19;

static void FullScoreReturn(const lm::FullScoreReturn &ret, int8_t* se, bool oov) {
    putFloatB(se, 0, ret.prob);
    se[4] = ret.ngram_length;
    se[5] = static_cast<unsigned char>(ret.independent_left);
    putLongB(se, 6, ret.extend_left);
    putFloatB(se, 14, ret.rest);
    se[18] = static_cast<unsigned char>(oov);
}

typedef boost::tokenizer<boost::char_separator<char>, StringPiece::const_iterator> Tokenizer;

/*
 * Class:     kenlm_KenlmJNI
 * Method:    ConfigNew
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_kenlm_KenlmJNI_ConfigNew
  (JNIEnv *, jclass) {
      auto *config = new lm::ngram::Config();
      return reinterpret_cast<jlong>(config);
  }

/*
 * Cla