import java.awt.*;
import java.applet.*;

/*
<applet code="ColorDemo" width=300 height=200>
</applet>
*/

public class ColorDemo extends Applet {
	public void paint(Graphics g) {
		Color c1 = new Color(255,100,100);
		Color c2 = new Color(100,255,100);
		Color c3 = new Color(100,100,255);
		
		g.setColor(c1);
		g.drawLine(0,0,100,100);
	}
}
