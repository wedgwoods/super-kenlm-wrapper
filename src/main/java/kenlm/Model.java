
package kenlm;

import java.util.ArrayList;
import java.util.List;

import static kenlm.KenlmJNI.*;

/**
 * Wrapper around lm::ngram::Model.
 */
public class Model implements AutoCloseable {

    private long model;

    /**
     * Load the language model.
     * @param path path to an arpa file or a kenlm binary file.
     * @param config configuration options (see lm/config.hh for documentation)
     */
    public Model(String path, Config config) {
        this.model = ModelLoadVirtual(path, config.getCConfig());
    }

    /**
     * Return the log10 probability of a string.  By default, the string is
     * treated as a sentence.
     *   return log10 p(sentence </s> | <s>)
     *
     * If you do not want to condition on the beginning of sentence, pass
     *   bos = False
     * Never include <s> as part of the string.  That would be predicting the
     * beginning of sentence.  Language models are only supposed to condition
     * on it as context.
     *
     * Similarly, the end of sentence token </s> can be omitted with
     *   eos = False
     * Since language models explicitly predict </s>, it can be part of the
     * string.
     *
     * Examples:
     *
     * #Good: returns log10 p(this is a sentence . </s> | <s>)
     * model.score("this is a sentence .")
     * #Good: same as the above but more explicit
     * model.score("this is a sentence .", bos = True, eos = True)
     *
     * #Bad: never include <s>
     * model.score("<s> this is a sentence")
     * #Bad: never include <s>, even if bos = False.
     * model.score("<s> this is a sentence", bos = False)
     *