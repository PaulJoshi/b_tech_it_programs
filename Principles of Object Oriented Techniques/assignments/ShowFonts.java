
import java.applet.Applet; 
import java.awt.*;

public class ShowFonts extends java.applet.Applet {
    Font f;
    String m;

    public void init() { 
        f = new Font("Arial", Font.BOLD, 20);
        m = "Java Font Class"; 
        setFont(f);
    }

    public void paint(Graphics a) {  
        Graphics2D g = (Graphics2D)a;
        a.drawString(m, 180, 60);

        Font plainFont = new Font("Serif", Font.PLAIN, 24);
        g.setFont(plainFont);
        g.drawString("Welcome to Java - normal font", 100, 120);

        Font italicFont = new Font("Serif", Font.ITALIC, 24);
        g.setFont(italicFont);
        g.drawString("Welcome to Java - Italic font", 100, 180);

        Font boldFont = new Font("Serif", Font.BOLD, 24);
        g.setFont(boldFont);
        g.drawString("Welcome to Java - Bold font", 100, 230);
    } 
}

/* <APPLET CODE ="ShowFonts" WIDTH=500 HEIGHT=300> </APPLET> */
