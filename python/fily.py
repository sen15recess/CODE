import os

def fileapp():
    os.chdir("G:/")
    try:
        file = open('sketch.txt')
        for i in file:
            try:
                a,b = i.split(":",1)
                print(a,end='')
                print(' said :',end='')
                print(b,end='')
            except ValueError:
                pass

    except IOError:
        print("File not available!")

        
