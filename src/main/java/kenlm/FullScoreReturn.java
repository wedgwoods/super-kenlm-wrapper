
package kenlm;

/**
 * Wrapper around FullScoreReturn.
 *
 * Notes:
 *     `prob` has been renamed to `log_prob`
 *     `oov` has been added to flag whether the word is OOV
 */
public class FullScoreReturn {
    private final float log_prob;
    private final int ngram_length;
    private final boolean independent_left;
    private final long extend_left;
    private final float rest;
    private final boolean oov;

    /**
     * @param array lm::FullScoreReturn {
     *                float prob;
     *                unsigned char ngram_length;
     *                bool independent_left;
     *                uint64_t extend_left;
     *                float rest;
     *              }
     * @param offset The offset of the subarray to be used.
     */
    FullScoreReturn(byte[] array, int offset) {
        this.log_prob = getFloatB(array, offset);
        this.ngram_length = array[4 + offset];
        this.independent_left = array[5 + offset] != 0;
        this.extend_left = getLongB(array, 6 + offset);
        this.rest = getFloatB(array, 14 + offset);
        this.oov = array[18 + offset] != 0;
    }

    static final int SIZE = 19;

    public float getLogProb() {
        return log_prob;
    }
