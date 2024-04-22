from tkinter import *
from tkinter import ttk

root = Tk()

root.title("Przycisk")
root.geometry("800x600")

def click1():
    return root.destroy


def click2():
    print("Napis cwiczebny")
    text1 = Label(root, text = "Sroda")
    text1.place(x = 390, y = 300)


def napis1():
    tekst2 = Blok1.get()
    napis = Label(root, text = tekst2)
    napis.place(x = 350, y = 100)


Blok1 = Entry(root, text = "", command = napis1())
Blok1.place(x = 350, y = 50)

P1 = Button(root, text="Przycisk 1", command = click1())
P1.place(x = 380, y = 200)

P2 = Button(root, text="Zamknij okno", command = root.destroy)
P2.place(x = 700, y = 550)

P3 = Button(root, text="Przycisk 2", command = click2())
P3.place(x = 380, y = 250)

root.mainloop()
