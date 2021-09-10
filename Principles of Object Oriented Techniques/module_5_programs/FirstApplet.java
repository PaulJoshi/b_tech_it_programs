import java.applet.Applet;
import java.awt.Graphics;

public class FirstApplet extends Applet {
    public void paint(Graphics g) {
        g.drawString("Welcome to my Applet", 20, 20);
    }
}

/*
<applet code="FirstApplet.class" width="100" height="100">
</applet>
*/
