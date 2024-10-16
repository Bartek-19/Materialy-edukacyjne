package com.mycompany.lab7_1;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import java.io.*;
import java.util.ArrayList;
import javax.swing.JPanel;
import javax.swing.Timer;

public class Panel extends JPanel {
    private ArrayList<Kula> listaKul;
    private int size = 20;
    private Timer timer;
    private final int DELAY = 33; 
    private File zapis = new File("Kolizje.txt");
    
    
    public Panel() {
        
        listaKul = new ArrayList<>();
        setBackground(Color.BLACK);
        addMouseListener(new Event());
        timer = new Timer(DELAY, new Event());
        timer.start();
    }
    
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        for (Kula k : listaKul) {
            g.setColor(k.color);
            g.drawOval(k.x, k.y, k.size, k.size);
        }
        g.setColor(Color.YELLOW);
        g.drawString(Integer.toString(listaKul.size()),40,40);
    }
    
    private class Event implements MouseListener, ActionListener, MouseWheelListener {
        
        @Override
        public void mouseWheelMoved(MouseWheelEvent e) {
            size += e.getWheelRotation();
            if(size<10)
                size = 10;
        }
        
        @Override
        public void mouseClicked(MouseEvent e) {
        }

        @Override
            public void mousePressed(MouseEvent e) {
            listaKul.add(new Kula(e.getX(), e.getY(), size));
            repaint();
        }
        
        @Override
        public void mouseReleased(MouseEvent e) {
        }
        
        @Override
        public void mouseEntered(MouseEvent e) {
        }
        
        @Override
        public void mouseExited(MouseEvent e) {
        }
        
        @Override
        public void actionPerformed(ActionEvent e) {
            for (Kula k : listaKul) {
                k.update();
            }
            repaint();
        }
    }
    
    private class Kula {
        public int x, y, size, xspeed, yspeed;
        public Color color;
        private final int MAX_SPEED = 5;
        
        public Kula(int x, int y, int size) {
            this.x = x;
            this.y = y;
            this.size = size;
            color = new Color((float) Math.random(), (float) Math.random(), (float) Math.random());
            do {
                xspeed = (int) (Math.random() * MAX_SPEED * 2 - MAX_SPEED);
                yspeed = (int) (Math.random() * MAX_SPEED * 2 - MAX_SPEED);
            }while(xspeed==0 || yspeed==0);
        }
        
        public void update() {
            int  tempx, tempy, odlKul, granica;
            x += xspeed;
            y += yspeed;
            if (x <= 0 || x >= getWidth()) {
                xspeed = -xspeed;
            }
            if (y <= 0 || y >= getHeight()) {
                yspeed = -yspeed;
            }
            for(Kula k : listaKul)
            {
                odlKul = (int)Math.sqrt(Math.pow((k.x-this.x), 2)+Math.pow((k.y-this.y), 2));
                granica = this.size + k.size;
                if(odlKul < granica && k!=this)
                {
                    tempx = this.xspeed;
                    this.xspeed = k.xspeed;
                    k.xspeed = tempx;
                    tempy = this.yspeed;
                    this.yspeed = k.yspeed;
                    k.yspeed = tempy;
                    try{
                        FileWriter strumienZapisu = new FileWriter(zapis, true);
                        strumienZapisu.append("k"+listaKul.indexOf(this)+", k"+listaKul.indexOf(k)+
                        ", ("+((this.x+k.x)/2)+", "+((this.y+k.y)/2)+");\n");
                        strumienZapisu.close();
                    } catch(IOException ex) {
                        System.err.print(ex.getCause());
                    }
                }
            }
        }
    }
}
