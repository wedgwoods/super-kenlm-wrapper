package kenlm;

import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import java.util.List;

public class ModelTest {

    private Model model;

    @Before
    public void setUp() {
        model = new Model("test.arpa", new Config());
    }

    @After
    public void tearDown() {
   