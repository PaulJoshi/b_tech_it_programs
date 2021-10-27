import java.awt.*;
import java.awt.event.*;
import java.applet.*;

/*
<applet code="KeyboardEvent" width=300 height=100>
</applet>
*/

public class KeyboardEvent extends Applet implements KeyListener {
	String msg="";
	
	public void init() {
		addKeyListener(this);
	}
	
	public void keyPressed(KeyEvent ke) {
		showStatus("Key Down");
	}
	
	public void keyReleased(KeyEvent ke) {
		showStatus("Key up");
	}
	
	public void keyTyped(KeyEvent ke) {
		msg += ke.getKeyChar();
		repaint();
	}
	
	public void paint(Graphics g) {
		g.drawString(msg, 10, 20);
	}
}