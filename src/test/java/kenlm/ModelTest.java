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
        Assert.assertEquals(-49.579346, model.score("this is a sentence .", true, true), 0.000001);
    }

    @Test
    public void testFullScores() {
        List<FullScoreReturn> returns = model.fullScores("this is a sentence .", true, true);

        Assert.assertEquals(6, returns.size());
        Assert.assertEquals(-2.4106083, returns.get(0).getLogProb(), 0.0000001);
        Assert.assertEquals(1, returns.get(0).getNgramLength());
        Assert.assertEquals(-21.6878719329834, returns.get(1).getLogProb(), 0.0000001);
        Assert.assertEqual