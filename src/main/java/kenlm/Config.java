package kenlm;

import static kenlm.KenlmJNI.*;


/**
 * Wrapper around lm::ngram::Config.
 * Pass this to Model's constructor to set the load_method.
 */
public class Config {

    private final long _c_confi