import java.awt.*;
import java.awt.event.*;
import java.applet.*;

/*
<applet code="AdapterDemo" width=300 height=100>
</applet>
*/

public class AdapterDemo extends Applet {
	public void init() {
		addMouseListener(new MyMouseAdapter(this));
	}
}

class MyMouseAdapter extends MouseAdapter {
	AdapterDemo ademo;

	public MyMouseAdapter(AdapterDemo ademo) {
		this.ademo=ademo;
	}
	
	public void mouseClicked(MouseEvent me) {
		ademo.showStatus("Mouse clicked");
	}
}
