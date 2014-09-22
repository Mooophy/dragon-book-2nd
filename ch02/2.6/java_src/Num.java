package lexer;  //File Num.java
public class Num extends Token
{
    public final int value;
    public Num(int v)
    {
        super (Tag.NUM);
        value = v;
    }
}
