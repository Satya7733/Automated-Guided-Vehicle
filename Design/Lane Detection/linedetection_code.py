import cv2
import numpy as np

linePos_1 = 380 #Threshold of the area to be scaned
linePos_2 = 430
lineColorSet = 0 #colour of line


# frame_image = cv2.imread('REsources/test6.jpeg')

cap = cv2.VideoCapture("REsources/DarkR.mp4")
while(cap.isOpened()):
    _, frame_image = cap.read()
#alpha is the contrast value. To lower the contrast, use 0 < alpha < 1. And for higher contrast use alpha > 1.
#beta is the brightness value. A good range for brightness value is [-127, 127]

    frame_image = cv2.resize(frame_image, (640, 480))#640,480
    cv2.imshow("Normal",frame_image)
   # frame_image = cv2.convertScaleAbs(frame_image,1.1,40)
    #frame_image = cv2.rotate(frame_image, cv2.ROTATE_90_CLOCKWISE)
        #cv2.imshow("Orignal", frame_image)
    #  cv2.imshow("Final", frame_image1)


    frame_findline = cv2.cvtColor(frame_image,cv2.COLOR_BGR2GRAY)
 #   frame_findline= cv2.convertScaleAbs(frame_findline, 1.1, 40)
    cv2.imshow("brightened image", frame_findline)
    frame_findline = cv2.GaussianBlur(frame_findline,(5,5), 0)
    cv2.imshow("Gaussian Blur", frame_findline)
    retval, frame_findline = cv2.threshold(frame_findline, 0, 255, cv2.THRESH_OTSU) #Image Segmentation
    frame_findline = cv2.erode(frame_findline, None, iterations=6) #Remove NOISE and Blurred edges
    cv2.imshow("Otsu", frame_findline)
    colorPos_1 = frame_findline[linePos_1]
    colorPos_2 = frame_findline[linePos_2]

    try:
        lineColorCount_Pos1 = np.sum(colorPos_1 == lineColorSet) #gets the count of black pixels
        lineColorCount_Pos2 = np.sum(colorPos_2 == lineColorSet)

        lineIndex_Pos1 = np.where(colorPos_1 == lineColorSet) #gets the pos of black pixels
        lineIndex_Pos2 = np.where(colorPos_2 == lineColorSet)

        if lineColorCount_Pos1 == 0:
            lineColorCount_Pos1 = 1
        if lineColorCount_Pos2 == 0:
            lineColorCount_Pos2 = 1

        left_Pos1 = lineIndex_Pos1[0][lineColorCount_Pos1 - 1]
        right_Pos1 =lineIndex_Pos1[0][0]
        center_Pos1 = int((left_Pos1+right_Pos1)/2)

        left_Pos2 = lineIndex_Pos2[0][lineColorCount_Pos2 - 1]
        right_Pos2 = lineIndex_Pos2[0][0]
        center_Pos2 = int((left_Pos2 + right_Pos2) / 2)
        center = int((center_Pos1 + center_Pos2)/2)

    except:
        center = None
        pass
    print(center)

    try:
        cv2.line(frame_image, (left_Pos1, (linePos_1+30)), (left_Pos1, (linePos_1-30)), (255,128,64),1)
        cv2.line(frame_image, (right_Pos1, (linePos_1+30)), (right_Pos1, (linePos_1-30)), (64,128,255),)
        cv2.line(frame_image, (0,linePos_1), (640,linePos_1), (255,255,64),1)
        cv2.line(frame_image, (left_Pos2, (linePos_2+30)), (left_Pos2, (linePos_2-30)), (255,128,64),1)
        cv2.line(frame_image, (right_Pos2, (linePos_2+30)), (right_Pos2, (linePos_2-30)), (64,128,255),1)
        cv2.line(frame_image, (0,linePos_2), (640,linePos_2), (255, 255,64),1)
        cv2.line(frame_image, ((center-20), int((linePos_1+ linePos_2)/2)), ((center+20), int((linePos_1 + linePos_2)/2)),(0,0,0),1)
        cv2.line(frame_image, ((center), int((linePos_1+linePos_2)/2+20)), ((center), int((linePos_1+ linePos_2)/2-20)),(0,0,0),1)
    except:
        pass



    cv2.imshow("Final1", frame_image)
    cv2.waitKey(1)