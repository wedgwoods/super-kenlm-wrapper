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
        model.close();
    }

    @Test
    public void testScore() {
        Assert.assertEquals(-49.579346, model.score("this is a sentence .", tru