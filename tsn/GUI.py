# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'GUI.ui'
#
# Created by: PyQt5 UI code generator 5.13.0
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1429, 729)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.wgt_video = myVideoWidget(self.centralwidget)
        self.wgt_video.setGeometry(QtCore.QRect(50, 20, 601, 281))
        self.wgt_video.setObjectName("wgt_video")
        self.btn_open = QtWidgets.QPushButton(self.centralwidget)
        self.btn_open.setGeometry(QtCore.QRect(0, 430, 161, 101))
        self.btn_open.setObjectName("btn_open")
        self.sld_video = QtWidgets.QSlider(self.centralwidget)
        self.sld_video.setGeometry(QtCore.QRect(50, 320, 551, 31))
        self.sld_video.setMaximum(100)
        self.sld_video.setOrientation(QtCore.Qt.Horizontal)
        self.sld_video.setObjectName("sld_video")
        self.btn_play = QtWidgets.QPushButton(self.centralwidget)
        self.btn_play.setGeometry(QtCore.QRect(220, 430, 141, 101))
        self.btn_play.setObjectName("btn_play")
        self.btn_stop = QtWidgets.QPushButton(self.centralwidget)
        self.btn_stop.setGeometry(QtCore.QRect(480, 430, 151, 101))
        self.btn_stop.setObjectName("btn_stop")
        self.lab_video = QtWidgets.QLabel(self.centralwidget)
        self.lab_video.setGeometry(QtCore.QRect(390, 270, 91, 31))
        self.lab_video.setObjectName("lab_video")
        self.btn_detection = QtWidgets.QPushButton(self.centralwidget)
        self.btn_detection.setGeometry(QtCore.QRect(750, 430, 151, 101))
        self.btn_detection.setObjectName("btn_detection")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1429, 22))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.btn_open.setText(_translate("MainWindow", "Open Video"))
        self.btn_play.setText(_translate("MainWindow", "Play"))
        self.btn_stop.setText(_translate("MainWindow", "Pause"))
        self.lab_video.setText(_translate("MainWindow", "0%"))
        self.btn_detection.setText(_translate("MainWindow", "Detect"))
from myVideoWidget import myVideoWidget
