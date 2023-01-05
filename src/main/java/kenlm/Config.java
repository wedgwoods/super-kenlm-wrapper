package kenlm;

import static kenlm.KenlmJNI.*;


/**
 * Wrapper around lm::ngram::Config.
 * Pass this to Model's constructor to set the load_method.
 */
public class Config {

    private final long _c_config;

    public Config() {
        this._c_config = ConfigNew();
        CleanerUtil.createAndRegister(this, new Deallocator(_c_config));
    }

    public LoadMethod getLoadMethod() {
        return LoadMethod.values()[ConfigGetLoadMethod(_c_config)];
    }

    public void setLoadM