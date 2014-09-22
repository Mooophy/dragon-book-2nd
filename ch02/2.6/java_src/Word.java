package lexer;  //File Word.java
public class Word extends Token
{
    public final String lexeme;
    
    public Word(int t, String s)
    {
        supter(t);
        lexeme = new String(s);
    }
}



