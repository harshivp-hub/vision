import speech_recognition as sr
import pyttsx3
import cv2
import mss
import numpy
import pytesseract
import pyttsx3

def SpeechToText():
    r = sr.Recognizer()
    MyText = ""

    def SpeakText(command):
        engine = pyttsx3.init()
        engine.say(command)
        engine.runAndWait()
    try:
        with sr.Microphone() as source2:
            r.adjust_for_ambient_noise(source2, duration=0.2)
            audio2 = r.listen(source2)
            MyText = r.recognize_google(audio2)
            MyText = MyText.lower()
            print(MyText)
            SpeakText(MyText)
            fp = open("txt.txt", "w+")
            fp.write(MyText)
            fp.close()
    except sr.RequestError as e:
        print("Could not request results; {0}".format(e))
    except sr.UnknownValueError:
        print("unknown error occured")
    return MyText
SpeechToText()