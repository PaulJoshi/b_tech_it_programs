import java.awt.*;
import java.awt.event.*;
import java.applet.*;

/*
<applet code="MouseEvents" width=300 height=100>
</applet>
*/

public class MouseEvents extends Applet implements MouseListener {
	String msg = "";
	
	public void init() {
		addMouseListener(this);
	}

	public void mouseClicked(MouseEvent me) {
		msg = "Mouse clicked";
		repaint();
	}
	
	public void mouseEntered(MouseEvent me) {
		msg = "Mouse entered";
		repaint();
	}
	
	public void mouseExited(MouseEvent me) {
		msg = "Mouse Exited";
		repaint();
	}

	public void mousePressed(MouseEvent me) {
		msg = "Mouse Pressed";
		repaint();
	}
	
	public void mouseReleased(MouseEvent me) {
		msg = "Mouse Released";
		repaint();
	}
	
	public void paint(Graphics g) {
		g.drawString(msg, 50, 50);
	}
}