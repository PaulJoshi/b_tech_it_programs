import java.awt.*;
import java.awt.event.*;
import java.applet.*;

/*<applet code="Addition" width=250 height=150>
</applet>
*/

public class Addition extends Applet implements ActionListener {

	String msg = "";
	Button addt;
	private static Dialog d;
	TextField no1;
	
	public void init() {
		addt = new Button("Add");
		Label label1 =  new Label("No 1 :");
		no1 = new TextField(12);
		
		add(label1);
		add(no1);
		add(addt);
		
		addt.addActionListener(this);
	}

	public void actionPerformed(ActionEvent ae) {
		repaint();
	}

	public void paint(Graphics g) {
		String s1 = no1.getText();
		int n1 = Integer.parseInt(s1);
		int s = n1 + n1;
		Frame f = new Frame();
		d = new Dialog(f,"Result",true);
		d.setLayout(new FlowLayout());
		Button b = new Button("OK");

		b.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				d.setVisible(false);
			}
		});
		
		d.add(new Label(Integer.toString(s)));
		d.add(b);
		d.setSize(200,100);
		d.setVisible(true);
		
		g.drawString(Integer.toString(s),6,100);
	}
}
