import java.awt.*;
import java.awt.event.*;
import java.applet.*;

/*
<applet code="ButtonDemo" width=250 height=150>
</applet>
*/

public class ButtonDemo extends Applet implements ActionListener {
	String msg = "";
	Button yes,no;

	public void init() {
		yes = new Button("Yes");
		no = new Button("No");
		
		add(yes);
		add(no);
		
		yes.addActionListener(this);
		no.addActionListener(this);
		
	}
	
	public void actionPerformed(ActionEvent ae) {
		String str = ae.getActionCommand();

		if(str.equals("Yes")) {
			msg = "You pressed Yes";
		}

		else if(str.equals("No")) {
			msg = "You pressed No";
		}
		repaint();
	}
	
	public void paint(Graphics g) {
		g.drawString(msg,6,100);
	}
}		
