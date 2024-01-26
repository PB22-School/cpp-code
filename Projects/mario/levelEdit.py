import pygame
import time
from tkinter import Tk
from tkinter.filedialog import askopenfilename

pygame.init()

width, height = (400,400)

window = pygame.display.set_mode((width,height))

selected = 0
running = True
lastTime = time.time_ns()

objects = []
pressedKeys = []
tileIndex = []
speed = 5
sText = ""
takeInput = 0

scale = 1
tileSize = 16

class point:
    def __init__(self, x = 0, y = 0):
        if type(x) == type((0,0)):
            self.x = x[0]
            self.y = x[0]
        else:
            self.x = 0
            self.y = 0

viewOffset = point()

class tile:
    def __init__(self, filename = "base.png", x = 0, y = 0):
        self.x = 0
        self.y = 0
        self.custom = 0
        self.filename = filename
    def draw(self, window):
        # try every frame loads, probably slow so maybe switch it
        window.blit(pygame.image.load(self.filename),(self.x,self.y))

def pan(delta, viewOffset):
    if pressedKeys != []:
        print(pressedKeys)
    xDir = ('a' in pressedKeys) - ('d' in pressedKeys)
    yDir = ('s' in pressedKeys) - ('w' in pressedKeys) 
    viewOffset.x -= xDir * speed * delta
    viewOffset.y -= yDir * speed * delta
    for i in objects:
        i.x += speed * delta * xDir
        i.y += speed * delta * yDir
    return viewOffset

def draw(window):
    for i in objects:
        i.draw(window)

def prompt_file():
    top = Tk()
    top.withdraw()
    file_name = askopenfilename(parent=top)
    top.destroy()
    return file_name

def changeSelect(text):
    if int(text) >= len(tileIndex):
        tileIndex.append(pygame.image.load(prompt_file()))
        return tileIndex[-1]
    return tileIndex[int(text)]

while running:
    for i in pygame.event.get():
        if i.type == pygame.QUIT:
            running = False
        elif i.type == pygame.KEYDOWN:
            if not (i.unicode in pressedKeys):
                pressedKeys.append(i.unicode)
        elif i.type == pygame.KEYUP:
            if i.unicode in pressedKeys:
                if takeInput and i.unicode.isdecimal:
                    sText += i.unicode
                elif takeInput and i.key == pygame.K_BACKSPACE:
                    sText = sText[:-1]
                elif takeInput and i.key == pygame.K_RETURN:
                    selected = takeInput(sText)
                pressedKeys.remove(i.unicode)
        elif i.type == pygame.MOUSEBUTTONUP:
            click = point(pygame.mouse.get_pos())
            click.x += viewOffset.x
            click.y += viewOffset.y
            bRect = pygame.Rect((0,0),(tileSize,tileSize) * scale)
            can = True
            for i in objects:
                bRect.x = i.x
                bRect.y = i.y
                if bRect.collidepoint(click):
                    can = False
                    break
            if can:
                if not selected:
                    takeInput = changeSelect
                else:
                    objects.append(tile(selected,click.x,click.y))
    curTime = time.time_ns()
    delta = (lastTime - curTime) * pow(10,9)
    lastTime = curTime

    viewOffset = pan(delta, viewOffset)


