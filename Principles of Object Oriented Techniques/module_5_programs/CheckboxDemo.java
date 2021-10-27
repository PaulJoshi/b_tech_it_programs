import java.awt.*;
import java.awt.event.*;
import java.applet.*;

/*
<applet code="CheckboxDemo" width=250 height=150>
</applet>
*/

public class CheckboxDemo extends Applet implements ItemListener {
	String msg = "";
	Checkbox winXP, win7;
	
	public void init() {
		winXP = new Checkbox("Windows XP", null, true);
		win7 = new Checkbox("Windows 7");
		
		add(winXP);
		add(win7);
		
		winXP.addItemListener(this);
		win7.addItemListener(this);
		
	}
	
	public void itemStateChanged(ItemEvent ie) {
		repaint();
	}
	
	public void paint(Graphics g) {
		msg = "Current state";
		g.drawString(msg, 6, 80);
		
		msg = "Windows XP : " + winXP.getState();
		g.drawString(msg, 6, 100);
		
		msg = "Windows 7 : " + win7.getState();
		g.drawString(msg, 6, 120);
	}
}
		