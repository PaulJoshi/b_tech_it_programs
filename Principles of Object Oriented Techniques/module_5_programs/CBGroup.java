// Demonstrate check box group.

import java.awt.*;
import java.awt.event.*;
import java.applet.*;

/*
<applet code="CBGroup" width=240 height=200>
</applet>
*/

public class CBGroup extends Applet implements ItemListener {
    String msg = "";
    Checkbox winXP, win7;
    CheckboxGroup cbg;

    public void init() {
        cbg = new CheckboxGroup();
        winXP = new Checkbox("Windows XP", cbg, true);
        win7 = new Checkbox("Windows 7", cbg, false);

        add(winXP);
        add(win7);

        winXP.addItemListener(this);
        win7.addItemListener(this);
    }

    public void itemStateChanged(ItemEvent ie) {
        repaint();
    }

    // Display current state of the check boxes.
    public void paint(Graphics g) {
        msg = "Current selection: ";
        msg += cbg.getSelectedCheckbox().getLabel();
        g.drawString(msg, 6, 100);
    }
}