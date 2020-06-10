import serial
import tkinter as tk

def keypress(event):
    if event.keysym == 'Escape':
        root.destroy()
    x = event.char
    if x == "w":
        entrada="w"
        print ("avanzar")
    elif x == "a":
        entrada="a"
        print ("izquierda")
    elif x == "s":
        entrada="s"
        print ("detener")
    elif x == "d":
        entrada="d"
        print ("derecha")
    elif x == "z":
        entrada="z"
        print ("reversa")
    elif x == "-":
        entrada="-"
        print ("Menor velocidad")
    elif x == "+":
        entrada="+"
        print ("Mayor Velocidad")
    else:
        print (x)
        entrada="0"
    ser.write(str(entrada).encode())
    

    
ser = serial.Serial('COM7', 9600)
print("Lista de comandos:")
print("'w' - Avanzar")
print("'z' - Retroceder")
print("'a' - Izquierda")
print("'d' - Derecha")
print("'s' - Detener")
print("'+' - Aumentar Velocidad")
print("'-' - Disminuir Velocidad")
print("Introduce un caracter)Esc para salir): ")
root = tk.Tk()
root.bind_all('<Key>', keypress)
# don't show the tk window
root.withdraw()
root.mainloop()
