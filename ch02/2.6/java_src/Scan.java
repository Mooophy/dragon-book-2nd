import java.io.*;
import lexer.*;

public class Scan
{
    public static void main(String[] args) throws IOException
    {
        System.out.println("enter statements");
        Lexer lex = new Lexer();
        Token t = lex.scan();
        System.out.println("tag is ");
        System.out.println(t.tag);
    }
}
