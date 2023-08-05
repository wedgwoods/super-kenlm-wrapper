#include "kenlm_KenlmJNI.h"

#include <boost/tokenizer.hpp>
#include "lm/config.hh"
#include "lm/model.hh"

inline static int32_t getIntB(const int8_t *bb, int bi) {
    return (((bb[b