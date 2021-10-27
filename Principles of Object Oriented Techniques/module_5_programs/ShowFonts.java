import java.applet.*;
import java.awt.*;

/*
<applet code="ShowFonts" width=500 height=60>
</applet>
*/

public class ShowFonts extends Applet {
	public void paint(Graphics g) {
		String msg = "";
		String FontList[];
		GraphicsEnvironment ge  = 
		GraphicsEnvironment.getLocalGraphicsEnvironment();
		FontList = ge.getAvailableFontFamilyNames();
		
		for(int i = 0; i < FontList.length; i++)
			msg += FontList[i]+ "  ";

		g.drawString(msg, 4, 16);
	}
}
		