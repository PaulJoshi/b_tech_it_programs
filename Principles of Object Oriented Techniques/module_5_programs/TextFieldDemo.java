import java.awt.*;
import java.awt.event.*;
import java.applet.*;

/*
<applet code="TextFieldDemo" width=250 height=150>
</applet>
*/

public class TextFieldDemo extends Applet implements ActionListener {
	TextField name,pass;

	public void init() {
		Label namep = new Label("Name : ");
		Label passp = new Label("Password : ");
		
		name = new TextField(12);
		pass = new TextField(12);
		pass.setEchoChar('*');
		
		add(namep);
		add(name);
		
		add(passp);
		add(pass);
		
		name.addActionListener(this);
		pass.addActionListener(this);
	}

	public void actionPerformed(ActionEvent ae) {
		repaint();
	}
	
	public void paint(Graphics g) {
		String nameText = name.getText();
		String passText = pass.getText();
		g.drawString("Name : " + nameText, 6, 80);
		g.drawString("Password : " + passText, 6, 120);
	}
}	
		
		
		
		