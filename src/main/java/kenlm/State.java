
package kenlm;

import static kenlm.KenlmJNI.*;

/**
 * Wrapper around lm::ngram::State so that python code can make incremental queries.
 *
 * Notes:
 *     rich comparisons
 *     hashable
 */