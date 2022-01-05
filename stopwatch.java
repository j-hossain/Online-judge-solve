
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.io.Console;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;



public class stopwatch {
	public static int posX,posY,timerState;
	public static timer tt;
	public static JLabel hour,minute,second;
	public static void main(String[] args) {
		timerState = 0;
		JFrame mainFrame = new JFrame();
		JPanel timePanel = new JPanel(true);
		hour = new JLabel("0");
		minute = new JLabel("0");
		second = new JLabel("0");
		tt = new timer(hour,minute,second);
		hour.setForeground(Color.white);
		minute.setForeground(Color.white);
		second.setForeground(Color.white);
		timePanel.add(hour);
		timePanel.add(minute);
		timePanel.add(second);
		mainFrame.add(timePanel,BorderLayout.CENTER);
		timePanel.setBackground(Color.black);
		mainFrame.setBackground(Color.black);
		mainFrame.setSize(new Dimension(60,20));
		mainFrame.setUndecorated(true);
		mainFrame.setAlwaysOnTop(true);
		mainFrame.setVisible(true);
		
		timePanel.addMouseListener(new MouseListener() {
			
			@Override
			public void mouseReleased(MouseEvent e) {
				
			}
			
			@Override
			public void mousePressed(MouseEvent e) {
				posX = e.getX();
				posY = e.getY();
			}
			
			@Override
			public void mouseExited(MouseEvent e) {
			}
			
			@Override
			public void mouseEntered(MouseEvent e) {
			}
			
			@Override
			public void mouseClicked(MouseEvent e) {
				int cc = e.getClickCount();
				if(cc==1) {
					if(timerState==0 || timerState==2) {
						timerState=1;
						tt = new timer(tt.hour, tt.minute, tt.second);
						tt.start();
					}
					else if(timerState==1) {
						timerState=2;
						tt.stop();
					}
				}
				else if(cc==2) {
					timerState = 0;
					tt.stop();
					hour.setText("0");
					minute.setText("0");
					second.setText("0");
				}
				else if(cc==3) {
					mainFrame.dispose();
				}
			}
		});
		
		timePanel.addMouseMotionListener(new MouseMotionListener() {
			
			@Override
			public void mouseMoved(MouseEvent e) {
			}
			
			@Override
			public void mouseDragged(MouseEvent e) {
				mainFrame.setLocation(e.getXOnScreen()-posX,e.getYOnScreen()-posY);
			}
		});
		
	}
}

class timer extends Thread{
	public JLabel hour,minute,second;
	public timer(JLabel hour, JLabel minute, JLabel second){
		this.hour = hour;
		this.minute = minute;
		this.second = second;
	}
	@Override
	public void run() {
		int hr,mn,sc;
		hr = Integer.parseInt(hour.getText());
		mn = Integer.parseInt(minute.getText());
		sc = Integer.parseInt(second.getText());
		while(true) {
			try {
				Thread.sleep(1000);
			}catch (Exception e) {}
			
			sc++;
			if(sc==60) {
				sc=0;
				mn++;
				if(mn==60) {
					mn=0;
					hr++;
				}
			}
			hour.setText(Integer.toString(hr));
			minute.setText(Integer.toString(mn));
			second.setText(Integer.toString(sc));
		}
	}
}
